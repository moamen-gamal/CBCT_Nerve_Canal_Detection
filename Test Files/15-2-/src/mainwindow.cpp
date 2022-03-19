#include<mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpenFolder, SIGNAL(triggered()), this, SLOT(openFolder()));
    QObject::connect(ui->axialMaxScreen,&QPushButton::clicked ,this,&MainWindow::maxScreenAxial);
    QObject::connect(ui->axialMinScreen,&QPushButton::clicked ,this,&MainWindow::minScreenAxial);
    QObject::connect(ui->coronalMaxScreen,&QPushButton::clicked ,this,&MainWindow::maxScreenCoronal);
    QObject::connect(ui->coronalMinScreen,&QPushButton::clicked ,this,&MainWindow::minScreenCoronal);
    QObject::connect(ui->sagittalMaxScreen,&QPushButton::clicked ,this,&MainWindow::maxScreenSagittal);
    QObject::connect(ui->sagittalMinScreen,&QPushButton::clicked ,this,&MainWindow::minScreenSagittal);

    QObject::connect(ui->axialSlider, &QSlider::valueChanged,
                         this, &MainWindow::axialSliderCtrl);
    QObject::connect(ui->coronalSlider, &QSlider::valueChanged,
                         this, &MainWindow::coronalSliderCtrl);
    QObject::connect(ui->sagittalSlider, &QSlider::valueChanged,
                         this, &MainWindow::sagittalSliderCtrl);
//    QObject::connect(ui->volumeSlider, &QSlider::valueChanged,
//                         this, &MainWindow::volumeSliderCtrl);

    MainWindow::init();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init(){
    ui->panoramaWidget->hide();
    ui->serialWidget->hide();
    ui->curveWidget->hide();
}

void MainWindow::initSliders(){
    ui->axialSlider->setRange(0,axialImages.size()-1);
    ui->axialSlider->setValue(0);

    ui->coronalSlider->setRange(0,coronalImages.size()-1);
    ui->coronalSlider->setValue(0);

    ui->sagittalSlider->setRange(0,sagittalImages.size()-1);
    ui->sagittalSlider->setValue(0);

    ui->volumeSlider->setRange(-8192,0);
    ui->volumeSlider->setMaximum(0);
    ui->volumeSlider->setValue(-4096);

    ui->panoramaSlider->setRange(0,offset);
    ui->panoramaSlider->setValue(offset/2);
}

void MainWindow::initViews(){
    MainWindow::axialViewCtrl(0);
    MainWindow::coronalViewCtrl(0);
    MainWindow::sagittalViewCtrl(0);
}


void MainWindow::openFolder() {
    folderPath= QFileDialog::getExistingDirectory(this,
            tr("Open Folder"),
            "C:\\",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    QDir  Directory = folderPath;
    QStringList DICOMS = Directory.entryList(QStringList()<<"*.dcm", QDir::Files);
    foreach (QString Dicom, DICOMS){
        DICOM_Names.push_back(Dicom.toUtf8().constData());
    }
    SI::natural::sort(DICOM_Names);
    for(int i =0;i<DICOM_Names.size();i++){
         Full_Path_Names.push_back(folderPath.toStdString() + "//" + DICOM_Names[i]);
    }
    MainWindow::DicomTags(folderPath.toStdString());
    MainWindow::grayTransform();
    MainWindow::statistics();
    int id =MainWindow::panoramaSliceSelect();
    cv::Mat skeleton = MainWindow::SkeletonGenerate(id);
    MainWindow::ctrlPtsCalculate(skeleton);
    cv::Mat panorama = MainWindow::constructPanorama(offset/2);
    MainWindow::MPR();
    MainWindow::initViews();
    MainWindow::initSliders();

}
void MainWindow::DicomTags(std::string FolderPath) {
    using PixelType = signed short;
    constexpr unsigned int Dimension = 3;

    using ImageType = itk::Image<PixelType, Dimension>;
    using ReaderType = itk::ImageSeriesReader<ImageType>;
    ReaderType::Pointer reader = ReaderType::New();
    using ImageIOType = itk::GDCMImageIO;
    ImageIOType::Pointer dicomIO = ImageIOType::New();
    reader->SetImageIO(dicomIO);

    using NamesGeneratorType = itk::GDCMSeriesFileNames;
    NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();
    nameGenerator->SetInputDirectory(FolderPath);

    using FileNamesContainer = std::vector<std::string>;
    FileNamesContainer fileNames = nameGenerator->GetInputFileNames();

    reader->SetFileNames(fileNames);
    reader->Update();
    using DictionaryType = itk::MetaDataDictionary;
    const DictionaryType & dictionary = dicomIO->GetMetaDataDictionary();
    using MetaDataStringType = itk::MetaDataObject<std::string>;

    auto itr = dictionary.Begin();
    auto end = dictionary.End();

    while (itr != end)
    {
        itk::MetaDataObjectBase::Pointer entry = itr->second;

        MetaDataStringType::Pointer entryvalue = dynamic_cast<MetaDataStringType *>(entry.GetPointer());

        if (entryvalue)
        {
        std::string tagkey = itr->first;
        std::string tagvalue = entryvalue->GetMetaDataObjectValue();
        dicomTags.insert(std::pair<std::string, std::string>(tagkey, tagvalue));
        std::cout<<"key is "<<tagkey<<"  value is "<<tagvalue<<std::endl;
        }
        ++itr;
    }
}


void MainWindow::MPR(){

    std::vector<cv::Mat*>sagitialTempImages;
    for (int i = 0;i < axialImages[0]->rows; i++)
    {
        sagitialTempImages.push_back(new cv::Mat(axialImages[0]->rows, axialImages.size(), 0));
        coronalImages.push_back(new cv::Mat(axialImages.size(), axialImages[0]->rows, 0));
    }

    for (int K = axialImages.size() - 1;K >= 0;K--)
    {
        cv::Mat axialImage = *axialImages[K];

        for (int j = 0; j < axialImage.rows; j++)//To loop through all the pixels
        {
            for (int i = 0; i < axialImage.cols; i++)
            {
                coronalImages[j]->at<uchar>(K, i) = axialImage.at<uchar>(j, i);
                sagitialTempImages[j]->at<uchar>(i, K) = axialImage.at<uchar>(i,j);
            }
        }
    }
    for (int i = 0;i < coronalImages.size();i++)
    {
        //REMOVE IF NOT SAGITAL NO NEED TO ROTATE
        double angle = -90;
        // get rotation matrix for rotating the image around its center in pixel coordinates
        cv::Point2f center((sagitialTempImages[i]->cols - 1) / 2.0, (sagitialTempImages[i]->rows - 1) / 2.0);
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
        // determine bounding rectangle, center not relevant
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), sagitialTempImages[i]->size(), angle).boundingRect2f();
        // adjust transformation matrix
        rot.at<double>(0, 2) += bbox.width / 2.0 - sagitialTempImages[i]->cols / 2.0;
        rot.at<double>(1, 2) += bbox.height / 2.0 - sagitialTempImages[i]->rows / 2.0;

        cv::Mat* dst = new cv::Mat();
        cv::warpAffine(*sagitialTempImages[i], *dst, rot, bbox.size());
        cv::flip(*dst, *dst, 1);
        sagittalImages.push_back(dst);

    }
}

void MainWindow::grayTransform() {
    for(int i =0;i<Full_Path_Names.size();i++){
       DicomImages.push_back(new DicomImage(Full_Path_Names[i].c_str()));
       axialImages.push_back(new cv::Mat(int(DicomImages[i]->getWidth()), int(DicomImages[i]->getHeight()),
                                         CV_16U,(short*)DicomImages[i]->getOutputData(16)));
       cv::imshow("axial",*axialImages[i]);
       cv::waitKey(0);

    }
    for(int i=0;i<256;i++){
        histogram.push_back(0);
    }
    double max=axialImages[0]->at<ushort>(0,0),min=axialImages[0]->at<ushort>(0,1);
    for(int i =0;i<axialImages.size();i++){
        for(int j=0;j<axialImages[0]->rows;j++){
            for(int k=0;k<axialImages[0]->cols;k++){
                if(axialImages[i]->at<ushort>(j,k)<min)
                    min =axialImages[i]->at<ushort>(j,k);
                else if(axialImages[i]->at<ushort>(j,k)>max)
                    max =axialImages[i]->at<ushort>(j,k);
            }
        }
    }

    for(int i =0;i<axialImages.size();i++){
        for(int j=0;j<axialImages[0]->rows;j++){
            for(int k=0;k<axialImages[1]->cols;k++){
                int pixelValue = axialImages[i]->at<ushort>(j,k);
                int grayvalue = int(((pixelValue-min)/(max-min))*(pow(2,8)-1));
                axialImages[i]->at<ushort>(j,k) = grayvalue;
                histogram[grayvalue]++;
            }
        }
        axialImages[i]->convertTo(*axialImages[i],CV_8UC1 );
    }

};


void MainWindow::axialSliderCtrl(){
    int sliderValue = ui->axialSlider->value();
    MainWindow::axialViewCtrl(sliderValue);
}
void MainWindow::coronalSliderCtrl(){
    int sliderValue = ui->coronalSlider->value();
    MainWindow::coronalViewCtrl(sliderValue);
}
void MainWindow::sagittalSliderCtrl(){
    int sliderValue = ui->sagittalSlider->value();
    MainWindow::sagittalViewCtrl(sliderValue);
}


void MainWindow::axialViewCtrl(int id){
    sceneManager.sceneAxial = new Scenez(this);
    QPixmap axialPixmap= ASM::cvMatToQPixmap(*axialImages[id]);
    sceneManager.sceneAxial->addPixmap(axialPixmap);
    QRectF rc(QPoint(0, 0), axialPixmap.size());
    ui->axialView->fitInView(rc, Qt::KeepAspectRatio);
    ui->axialView->setScene(sceneManager.sceneAxial);
}
void MainWindow::coronalViewCtrl(int id){
    sceneManager.sceneCoronal = new Scenez(this);
    QPixmap coronalPixmap= ASM::cvMatToQPixmap(*coronalImages[id]);
    sceneManager.sceneCoronal->addPixmap(coronalPixmap);
    QRectF rc(QPoint(0, 0), coronalPixmap.size());
    ui->coronalView->fitInView(rc, Qt::KeepAspectRatio);
    ui->coronalView->setScene(sceneManager.sceneCoronal);
}
void MainWindow::sagittalViewCtrl(int id){
    sceneManager.sceneSagittal = new Scenez(this);
    QPixmap sagittalPixmap= ASM::cvMatToQPixmap(*sagittalImages[id]);
    sceneManager.sceneSagittal->addPixmap(sagittalPixmap);
    QRectF rc(QPoint(0, 0), sagittalPixmap.size());
    ui->sagittalView->fitInView(rc, Qt::KeepAspectRatio);
    ui->sagittalView->setScene(sceneManager.sceneSagittal);
}

void MainWindow::maxScreenAxial(){
    ui->coronalWidget->hide();
    ui->sagittalWidget->hide();
    ui->volumeWidget->hide();
    ui->panoramaWidget->hide();
    ui->serialWidget->hide();
    ui->curveWidget->hide();
}
void MainWindow::minScreenAxial(){
    ui->axialWidget->hide();
    ui->coronalWidget->show();
    ui->sagittalWidget->show();
    ui->volumeWidget->show();
}

void MainWindow::maxScreenCoronal(){
    ui->axialWidget->hide();
    ui->sagittalWidget->hide();
    ui->volumeWidget->hide();
    ui->panoramaWidget->hide();
    ui->serialWidget->hide();
    ui->curveWidget->hide();
}
void MainWindow::minScreenCoronal(){
    ui->coronalWidget->hide();
    ui->axialWidget->show();
    ui->sagittalWidget->show();
    ui->volumeWidget->show();
}

void MainWindow::maxScreenSagittal(){
    ui->axialWidget->hide();
    ui->coronalWidget->hide();
    ui->volumeWidget->hide();
    ui->panoramaWidget->hide();
    ui->serialWidget->hide();
    ui->curveWidget->hide();
}
void MainWindow::minScreenSagittal(){
    ui->sagittalWidget->hide();
    ui->coronalWidget->show();
    ui->axialWidget->show();
    ui->volumeWidget->show();
}

void MainWindow::statistics(){
      double sumFreq = 0;
      double sumNum=0;
      for(int i=0;i<256;i++){
          sumFreq +=i*histogram[i];
          sumNum +=histogram[i];
      }
      MainWindow::mean =sumFreq/sumNum;

}

int MainWindow::panoramaSliceSelect(){
    std::vector<int>whiteNum;
    int size = axialImages.size()-1;
    int selections[9] = {int(size*(4/(float)16)),int(size*(5/(float)16)),int(size*(6/(float)16)),int(size*(7/(float)16)),
                        int(size*(8/(float)16)),int(size*(9/(float)16)),int(size*(10/(float)16)),int(size*(9/(float)16)),
                                                                                               int(size*(12/(float)16))};


    double 	maxval = 255;
    double 	thresh= mean+ 3 * stddev;
    cv::Mat ThresImages[9];
    for(int i =0;i<9;i++){
        cv::threshold(*axialImages[selections[i]], ThresImages[i], thresh, maxval, 0);
    }
    for(int i=0;i<9;i++){
        whiteNum.push_back(0);
        whiteNum[i] =cv::countNonZero(ThresImages[i]);
    }
    int max =0;
    for(int i=1;i<9;i++){
        if(whiteNum[max]<whiteNum[i]){
            max =i;
        }
    }
    return selections[max];

}

cv::Mat MainWindow::SkeletonGenerate(int id){
        cv::Mat image = *axialImages[id];
        double 	maxval = 255;
        double 	thresh= mean +3*stddev;
        cv::Mat thresholdedImg;
        cv::threshold(image, thresholdedImg, thresh, maxval, 0);

        cv::Mat im_floodfill = thresholdedImg.clone();
        cv::floodFill(im_floodfill, cv::Point(0, 0), cv::Scalar(255));
        cv::Mat im_floodfill_inv;
        cv::bitwise_not(im_floodfill, im_floodfill_inv);
        cv::Mat holeFilled = (thresholdedImg | im_floodfill_inv);
        cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(30,30));
        cv::Mat closingImg;
        morphologyEx(holeFilled, closingImg,cv::MORPH_CLOSE, element,cv::Point(-1, -1), 2);

        cv::Mat labelImage(image.size(), CV_32S),dst(image.size(), CV_8UC3);
        int nLabels = connectedComponents(closingImg, labelImage, 8);
        std::vector<cv::Vec3b> colors(nLabels);
        colors[0] = cv::Vec3b(0, 0, 0);//background
        for(int label = 1; label < nLabels; ++label){
            colors[label] = cv::Vec3b(0, 0, 0);
            if(label ==1)
            colors[label] = cv::Vec3b(255, 255, 255);
        }
        for(int r = 0; r < dst.rows; ++r){
            for(int c = 0; c < dst.cols; ++c){
                int label = labelImage.at<int>(r, c);
                cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
                pixel = colors[label];
            }
        }
        cvtColor(dst, dst, cv::COLOR_RGB2GRAY);
        offset = Offset(dst);
        cv::Mat blur;
        cv::blur(dst,blur,cv::Size(9,9));
        cv::Mat SkeletonImg;
        cv::ximgproc::thinning (blur, SkeletonImg ,  0);
        return SkeletonImg;
}

int MainWindow::Offset(cv::Mat img) {
    std::vector<int>whiteNum;
    for (int y = 0; y < img.cols; y++) {
        int sum = 0;
        for (int x = 0; x < img.rows; x++)
        {
            if (img.at<uchar>(y, x) > 0)
            {
                sum++;
            }
        }
        whiteNum.push_back(sum);
    }
    int avg =0;
    for(int i =0;i<whiteNum.size();i++){
        avg += whiteNum[i];
    }
    avg /= whiteNum.size();
    return avg;
}

void MainWindow::ctrlPtsCalculate(cv::Mat skeleton){
    std::vector <int >ptsX;
    std::vector <int >ptsY;
    curveCtrlX.clear();
    curveCtrlY.clear();

    for (int i = 0; i < skeleton.cols; i++)//To loop through all the pixels
    {
        for (int j = 0; j < skeleton.rows; j++)
        {
            if (skeleton.at<uchar>(j, i) == 255)
            {
                ptsX.push_back(i);
                ptsY.push_back(j);
            }
        }
    }

    for (int i = 0; i <= 10; i++) {
        std::vector<int>::iterator csitX = (i* ((ptsX.end() - 1) - ptsX.begin()) / 10) + ptsX.begin();
        std::vector<int>::iterator csitY = (i* ((ptsY.end() - 1) - ptsY.begin()) / 10) + ptsY.begin();
        cv::Point cubicPoint = { *csitX ,  *csitY };
        curveCtrlX.push_back(*csitX);
        curveCtrlY.push_back(*csitY);
}
}

void MainWindow::shiftCurve(float shift) {

    tk::spline curve(curveCtrlX, curveCtrlY, tk::spline::cspline);
    std::vector<double>derivs;
    if(curveShiftX.size() != 0){
        curveShiftX.clear();
        curveShiftY.clear();
    }
    for (int i = 0;i < curveCtrlX.size();i++) {

        derivs.push_back(curve.deriv(1, curveCtrlX[i]));
        curveShiftX.push_back(0);
        curveShiftY.push_back(0);
    }
    if (shift - (offset / 2) > 0) {
        float shiftValue = (shift - offset/2 );
        for (int i = 0;i < curveCtrlX.size();i++) {
            curveShiftY[i] = curveCtrlY[i] - (shiftValue / sqrt(1 + pow(derivs[i], 2)));
            curveShiftX[i] = curveCtrlX[i] + ((derivs[i] * shiftValue) / sqrt(1 + pow(derivs[i], 2)));
        }
    }
    else if (shift - (offset / 2) < 0) {
        float shiftValue = (offset/2 - shift);
        for (int i = 0;i < curveCtrlX.size();i++) {
            curveShiftY[i] = curveCtrlY[i] + (shiftValue / sqrt(1 + pow(derivs[i], 2)));
            curveShiftX[i] = curveCtrlX[i] - ((derivs[i] * shiftValue) / sqrt(1 + pow(derivs[i], 2)));
        }
    }
    else {
        //control points stay the same if not required a shift
        double shiftValue = 0;
        for (int i = 0;i < curveCtrlX.size();i++) {
            curveShiftX[i] = curveCtrlX[i];
            curveShiftY[i] = curveCtrlY[i];
        }
    }

}


cv::Mat MainWindow::panoramaProjection(float shiftValue){
    shiftCurve(shiftValue);
    tk::spline curve(curveShiftX,curveShiftY,tk::spline::cspline);
    int colNum =curveShiftX[curveShiftX.size()-1] - curveShiftX[0] +2;
    cv::Mat Panorama(axialImages.size(),colNum,CV_8UC1);
    for(int i=0;i<axialImages.size();i++){
        int col=0;
        for(int j =curveShiftX[0];j<curveShiftX[curveShiftX.size()-1];j++){
            if(j < 0 || j> axialImages[i]->cols-1 || curve(j)<0 ||curve(j)>axialImages[i]->rows-1){
                Panorama.at<uchar>(i,col) = 0;
            }
            else{
                Panorama.at<uchar>(i,col) = axialImages[i]->at<uchar>(curve(j),j);
            }
            col++;
        }
    }
    return Panorama;
}
cv::Mat MainWindow::serialProjection(int id){
    tk::spline curve(curveCtrlX,curveCtrlY,tk::spline::cspline);
    cv::Mat serial(axialImages.size(),203*3,CV_8UC1);
    float slope = curve.deriv(1,id);
    int point_x =id, point_y = curve(id);
    int b = -1*slope*point_x+point_y;
    for(int i =0;i<axialImages.size();i++){
    int col=0;
    for(int x =id-100;x<id+100;x++){
       int y = slope*x+b;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;

    }
    }
    float slope_2 = curve.deriv(1,id+5);
    int point_x_2 =id+5, point_y_2 = curve(id+5);
    int b_2 = -1*slope_2*point_x_2+point_y_2;
    for(int i =0;i<axialImages.size();i++){
    int col=203;
    for(int x =id+5-100;x<id+5+100;x++){
       int y = slope_2*x+b_2;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;

    }
    }
    float slope_3 = curve.deriv(1,id+20);
    int point_x_3 =id+20, point_y_3 = curve(id+20);
    int b_3 = -1*slope_3*point_x_3+point_y_3;
    for(int i =0;i<axialImages.size();i++){
    int col=406;
    for(int x =id+20-100;x<id+20+100;x++){
       int y = slope_3*x+b_3;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;
    }
    }
    return serial;
}

//void MainWindow::volumeRender(int Mode)
//{
//    char* dirname = NULL;
//    double opacityWindow = 4096;
//    double opacityLevel = 2048;
//    double reductionFactor = 1.0;
//    double frameRate = 60.0;

//    QDir  TheDirectory = folderPath;
//    std::string welldoe = folderPath.toStdString();
//    const char * location;
//    location = welldoe.c_str();
//    size_t size = strlen(location) + 1;
//    dirname = new char[size];
//    snprintf(dirname, size, "%s", location);



//    vtkNew<vtkNamedColors> colors;
//    vtkNew<vtkRenderer> renderer2;
//    vtkNew<vtkRenderWindow> renWin;
//    renWin->AddRenderer(renderer2);
//    vtkNew<vtkRenderWindowInteractor> iren;
//    iren->SetRenderWindow(renWin);
//    iren->SetDesiredUpdateRate(frameRate );

//    iren->GetInteractorStyle()->SetDefaultRenderer(renderer2);
//    vtkSmartPointer<vtkAlgorithm> reader;
//    vtkSmartPointer<vtkImageData> input;

//    vtkNew<vtkDICOMImageReader> dicomReader;
//    dicomReader->SetDirectoryName(folderPath.toUtf8().constData());
//    dicomReader->Update();
//    input = dicomReader->GetOutput();
//    reader = dicomReader;

//    int dim[3];
//    input->GetDimensions(dim);
//    vtkNew<vtkImageResample> resample;

//    resample->SetInputConnection(reader->GetOutputPort());
//    resample->SetAxisMagnificationFactor(0, reductionFactor);
//    resample->SetAxisMagnificationFactor(1, reductionFactor);
//    resample->SetAxisMagnificationFactor(2, reductionFactor);


//    vtkNew<vtkVolume> volume;

//    vtkNew<vtkFixedPointVolumeRayCastMapper> mapper;


//    mapper->SetInputConnection(resample->GetOutputPort());


//    double spacing[3];

//    if (reductionFactor < 1.0)
//    {
//        resample->GetOutput()->GetSpacing(spacing);
//    }
//    else
//    {
//        input->GetSpacing(spacing);
//    }



//    // Create our transfer function
//    vtkNew<vtkColorTransferFunction> colorFun;
//    vtkNew<vtkPiecewiseFunction> opacityFun;
//    // Create the property and attach the transfer functions
//    vtkNew<vtkVolumeProperty> property;
//    property->SetIndependentComponents(true);
//    property->SetColor(colorFun);
//    property->SetScalarOpacity(opacityFun);
//    property->SetInterpolationTypeToLinear();
//    // connect up the volume to the property and the mapper
//    volume->SetProperty(property);
//    volume->SetMapper(mapper);



//    switch (Mode)
//    {
//        // MIP
//        // Create an opacity ramp from the window and level values.
//        // Color is white. Blending is MIP.
//        // MIP
//    case 0:
//        colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0);


//        opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
//            lightIntensity, 1.0);



//        mapper->SetBlendModeToMaximumIntensity();

//        break;
//    //bone
//    case 1:
//        colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0);
//        colorFun->AddRGBPoint(-1000, .62, .36, .18, 0.5, 0.0);
//        colorFun->AddRGBPoint(-500, .88, .60, .29, 0.33, 0.45);
//        colorFun->AddRGBPoint(3071, .83, .66, 1, 0.5, 0.0);

//        opacityFun->AddPoint(-3024, 0, 0.5, 0.0);
//        opacityFun->AddPoint(-1000, 0, 0.5, 0.0);
//        opacityFun->AddPoint(-500, 1.0, 0.33, 0.45);
//        opacityFun->AddPoint(3071, 1.0, 0.5, 0.0);

//        mapper->SetBlendModeToComposite();
//        property->ShadeOn();
//        property->SetAmbient(0.1);
//        property->SetDiffuse(0.9);
//        property->SetSpecular(0.2);
//        property->SetSpecularPower(10.0);
//        property->SetScalarOpacityUnitDistance(0.8919);
//        break;
//        //skeletal
//    case 2:
//        colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0);
//        colorFun->AddRGBPoint(-155, .55, .25, .15, 0.5, .92);
//        colorFun->AddRGBPoint(217, .88, .60, .29, 0.33, 0.45);
//        colorFun->AddRGBPoint(420, 1, .94, .95, 0.5, 0.0);
//        colorFun->AddRGBPoint(3071, .83, .66, 1, 0.5, 0.0);

//        opacityFun->AddPoint(-3024, 0, 0.5, 0.0);
//        opacityFun->AddPoint(-155, 0, 0.5, 0.92);
//        opacityFun->AddPoint(217, .68, 0.33, 0.45);
//        opacityFun->AddPoint(420, .83, 0.5, 0.0);
//        opacityFun->AddPoint(3071, .80, 0.5, 0.0);

//        mapper->SetBlendModeToComposite();
//        property->ShadeOn();
//        property->SetAmbient(0.1);
//        property->SetDiffuse(0.9);
//        property->SetSpecular(0.2);
//        property->SetSpecularPower(10.0);
//        property->SetScalarOpacityUnitDistance(0.8919);
//        break;
//    default:
//        vtkGenericWarningMacro("Unknown blend type.");
//        break;
//    }

//    // Set the default window size
//    renWin->SetSize(600, 600);
//    renWin->SetWindowName("FixedPointVolumeRayCastMapperCT");
//    //renWin->Render();

//    // Add the volume to the scene
//    renderer2->AddVolume(volume);

//    renderer2->ResetCamera();
//    renderer2->SetBackground(colors->GetColor3d("0").GetData());

//    auto camera = renderer2->GetActiveCamera();
//    camera->SetPosition(56.8656, -297.084, 78.913);
//    //camera->SetFocalPoint(109.139, 120.604, 63.5486);
//    camera->SetViewUp(-0.00782421, -0.0357807, -0.999329);
//    //camera->SetDistance(421.227);
//    //camera->SetClippingRange(146.564, 767.987);




//    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
//    vtkNew<vtkInteractorStyleImage> style;
//    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_4 = (vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New());
//    vtkSmartPointer<vtkRenderer> mRenderer = (vtkSmartPointer<vtkRenderer>::New());
//    vtkSmartPointer<QVTKInteractor> mInteractor = (vtkSmartPointer<QVTKInteractor>::New());
//    vtkSmartPointer<vtkInteractorStyle> mInteractorStyle = (vtkSmartPointer<vtkInteractorStyle>::New());

//    ui->volumeView->setRenderWindow(mRenderWindow_4);
//    mInteractor->Initialize();
//    mRenderer->SetBackground(0, 0, 0);

//    renderWindowInteractor->SetInteractorStyle(style);

//    renderWindowInteractor->SetRenderWindow(ui->volumeView->renderWindow());

//    renderWindowInteractor->Initialize();

//    mRenderer->SetBackground(
//    colors->GetColor3d("LightSlateGray").GetData());
//    mRenderWindow_4->SetSize(600, 300);
//    mRenderWindow_4->AddRenderer(renderer2);
//    mRenderWindow_4->SetInteractor(mInteractor);

//    mRenderWindow_4->Render();

//    renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
//    mRenderer->ResetCamera();


//    renderWindowInteractor->Start();


//    ui->volumeView->setRenderWindow(renWin);




//}
//void MainWindow::volumeSliderCtrl()
//{

//    lightIntensity = (ui->volumeSlider->value())*-1;
//    MainWindow::volumeRender(0);

//}
