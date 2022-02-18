#include<mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpenFolder, SIGNAL(triggered()), this, SLOT(openFolder()));

    QObject::connect(ui->axialSlider, &QSlider::valueChanged,
            this, &MainWindow::axialSliderCtrl);
    QObject::connect(ui->coronalSlider, &QSlider::valueChanged,
            this, &MainWindow::coronalSliderCtrl);
    QObject::connect(ui->sagittalSlider, &QSlider::valueChanged,
            this, &MainWindow::sagittalSliderCtrl);
    QObject::connect(ui->panoramaSlider, &QSlider::valueChanged,
            this, &MainWindow::panoramaSliderCtrl);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFolder() {
    folderPath= QFileDialog::getExistingDirectory(this,
            tr("Open Folder"),
            "C:\\",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    QDir  Directory = folderPath;
    QStringList DICOMS = Directory.entryList(QStringList()<<"*.dcm", QDir::Files);
    foreach (QString Dicom, DICOMS)
        {
            DICOM_Names.push_back(Dicom.toUtf8().constData());
        }
    //need to do natural sort to sort the name of files correctly
    SI::natural::sort(DICOM_Names);
    for(int i =0;i<DICOM_Names.size();i++){
         Full_Path_Names.push_back(folderPath.toStdString() + "//" + DICOM_Names[i]);
    }
    DicomTags(folderPath.toStdString());
    grayTransform();
    MPR();
    maxSliceID = panoramaSliceSelect(axialImages);
    cv::Mat skeleton =skeletonGenerate(*axialImages[maxSliceID]);
    ctrlPtsCalculate(skeleton);
    setSliders();
    setViews();
}


void MainWindow::grayTransform() {
    for(int i =0;i<Full_Path_Names.size();i++){
       DicomImages.push_back(new DicomImage(Full_Path_Names[i].c_str()));
       cv::Mat* cvImg = new cv::Mat(int(DicomImages[i]->getWidth()), int(DicomImages[i]->getHeight()),
                                    CV_16U,(short*)DicomImages[i]->getOutputData(DicomImages[i]->getOutputDataSize()));
       axialImages.push_back(cvImg);

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


    for(int i =0;i<256;i++){
        Histogram[i]=0;
    }
    for(int i =0;i<axialImages.size();i++){
        for(int j=0;j<axialImages[0]->rows;j++){
            for(int k=0;k<axialImages[1]->cols;k++){
                int pixelValue = axialImages[i]->at<ushort>(j,k);
                int grayvalue = int(((pixelValue-min)/(max-min))*(pow(2,8)-1));
                axialImages[i]->at<ushort>(j,k) = grayvalue;

                Histogram[grayvalue]++;
            }
        }
        axialImages[i]->convertTo(*axialImages[i],CV_8U );
    }
};

void MainWindow::MPR(){
    std::vector<cv::Mat>temp;
    for (int i = 0;i < axialImages.size(); i++)
    {
        coronalImages.push_back(new cv::Mat(axialImages.size(),axialImages[i]->rows,0));

        temp.push_back(cv::Mat(axialImages[i]->cols,axialImages.size(),0));
    }
    for (int K = axialImages.size() - 1;K >= 0;K--)
    {

        cv::Mat axialImage = *axialImages[K];

        for (int j = 0; j < axialImage.rows; j++)//To loop through all the pixels
        {
            for (int i = 0; i < axialImage.cols; i++)
            {
                temp[599 - j].at<uchar>(K, i) = axialImage.at<uchar>(599 - j, i);
                coronalImages[599 - j]->at<uchar>(i, K) = axialImage.at<uchar>(i, 599 - j);
            }
        }
    }
    for (int i = 0;i < temp.size();i++)
    {
        //REMOVE IF NOT SAGITAL NO NEED TO ROTATE
        double angle = -90;
        // get rotation matrix for rotating the image around its center in pixel coordinates
        cv::Point2f center((coronalImages[i]->cols - 1) / 2.0, (coronalImages[i]->rows - 1) / 2.0);
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
        // determine bounding rectangle, center not relevant
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), coronalImages[i]->size(), angle).boundingRect2f();
        // adjust transformation matrix
        rot.at<double>(0, 2) += bbox.width / 2.0 - coronalImages[i]->cols / 2.0;
        rot.at<double>(1, 2) += bbox.height / 2.0 - coronalImages[i]->rows / 2.0;

        cv::Mat* dst = new cv::Mat();
        cv::warpAffine(*coronalImages[i], *dst, rot, bbox.size());
        cv::flip(*dst,*dst, 1);
        sagittalImages.push_back(dst);

}
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
        }
        ++itr;
    }
}

int  MainWindow::panoramaSliceSelect(std::vector<cv::Mat*>&Images)
{
    int size = Images.size()-1;
    int selections[9] ={int(size*(4/(float)16)),
                        int(size*(5/(float)16)),int(size*(6/(float)16)),int(size*(7/(float)16)),int(size*(8/(float)16)),
                        int(size*(9/(float)16)),int(size*(10/(float)16)),int(size*(9/(float)16)),int(size*(12/(float)16))};

    cv::Scalar meanSelection          [9];
    cv::Scalar stdSelection           [9];
    int whitePixelNumSelection [9];
    for(int i =0;i<9;i++){

        cv::meanStdDev(*Images[selections[i]],meanSelection[i],stdSelection[i]);

    }
    float mean1=0,std1=0;
    for(int i =0;i<9;i++){
    mean1+=meanSelection[i][0];
    std1+=stdSelection[i][0];
    }
    mean1/=9;
    std1/=9;
    cv::Mat ThresImages[9];
    for(int i =0;i<9;i++){
        double 	maxval = 255;
        double 	thresh= mean1+ 2 * std1;
        cv::threshold(*Images[selections[i]], ThresImages[i], thresh, maxval, 0);
    }
    for(int i=0;i<9;i++){
        whitePixelNumSelection[i] =cv::countNonZero(ThresImages[i]);
    }
    int max =0;
    for(int i=1;i<9;i++){
        if(whitePixelNumSelection[max]<whitePixelNumSelection[i]){
            max =i;
        }
    }
    return selections[max];
}

cv::Mat MainWindow::skeletonGenerate(cv::Mat image){
    cv::Scalar mean, stddev;
    cv::meanStdDev(image, mean, stddev);

    double 	maxval = 255;
    double 	thresh= mean[0]+ 2 * stddev[0];
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
    std::cout<< nLabels;
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

void MainWindow::fullScreen(int id)
{
    switch (id){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }}

void MainWindow::minScreen(int id){
}

void MainWindow::setSliders(){
    ui->axialSlider->setRange(0,axialImages.size()-1);
    ui->axialSlider->setValue(0);

    ui->coronalSlider->setRange(0,coronalImages.size()-1);
    ui->coronalSlider->setValue(0);

    ui->sagittalSlider->setRange(0,sagittalImages.size()-1);
    ui->sagittalSlider->setValue(0);

    ui->panoramaSlider->setRange(0,offset);
    ui->panoramaSlider->setValue(int(offset/2));

    ui->serialSlider->setRange(0,1);
    ui->serialSlider->setValue(0);
}

void MainWindow::setViews(){
    sceneManager.sceneAxial = new Scenez(this);
    sceneManager.sceneCoronal = new Scenez(this);
    sceneManager.sceneSagittal = new Scenez(this);
    sceneManager.sceneSerial = new Scenez(this);
    sceneManager.sceneCurve = new Scenez(this);
    sceneManager.scenePanorama = new Scenez(this);

    QPixmap axialPixmap= ASM::cvMatToQPixmap(*axialImages[0]);
    QPixmap coronalPixmap= ASM::cvMatToQPixmap(*coronalImages[0]);
    QPixmap sagittalPixmap= ASM::cvMatToQPixmap(*sagittalImages[0]);


    sceneManager.sceneAxial->addPixmap(axialPixmap);
    sceneManager.sceneCoronal->addPixmap(coronalPixmap);
    sceneManager.sceneSagittal->addPixmap(sagittalPixmap);

    ui->axialView->setScene(sceneManager.sceneAxial);
    ui->coronalView->setScene(sceneManager.sceneCoronal);
    ui->sagittalView->setScene(sceneManager.sceneSagittal);
    ui->serialView->setScene(sceneManager.sceneSerial);
    ui->panoramaView->setScene(sceneManager.scenePanorama);
    ui->curveView->setScene(sceneManager.sceneCurve);

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
    return *std::max_element(whiteNum.begin(),whiteNum.end());
}

void MainWindow::constructSerialView(int Slider_Value){
    tk::spline curve (curveCtrlX,curveCtrlY,tk::spline::cspline);
    std::vector<int>curvePtsX,curvePtsY;
    for (int x = curveCtrlX[0];x<= curveCtrlX[curveCtrlX.size()-1];x++)
    {
            curvePtsY.push_back(x);
            curvePtsX.push_back(curve(x));
    }
    cv::Mat SerialImage1(axialImages[0]->rows,axialImages[0]->cols,CV_8U),
            SerialImage2(axialImages[0]->rows,axialImages[0]->cols,CV_8U),
            SerialImage3(axialImages[0]->rows,axialImages[0]->cols,CV_8U);

        SerialImage1.setTo(cv::Scalar(0, 0, 0));
        SerialImage2.setTo(cv::Scalar(0, 0, 0));
        SerialImage3.setTo(cv::Scalar(0, 0, 0));

        int serial1CountLower=0,serial1CountUpper = 0;
        int serial2CountLower=0,serial2CountUpper= 0;
        int serial3CountLower=0,serial3CountUpper= 0;
        for (int y = 0;y < SerialImage1.rows - 16; y++)//To loop through all the pixels
        {
            for (int x = 0; x < SerialImage1.cols - 16; x++)
            {
                if ((y) <= (NegativeSlope(curvePtsX[Slider_Value], curvePtsX[Slider_Value + 1], curvePtsY[Slider_Value], curvePtsY[Slider_Value + 1])*x) + returnOfCuttedARC(curvePtsX[Slider_Value], curvePtsX[Slider_Value + 1], curvePtsY[Slider_Value], curvePtsY[Slider_Value + 1]))
                {
                    SerialImage1.at<uchar>(x, y) = 255;
                }
                if ((y) <= (NegativeSlope(curvePtsX[Slider_Value + 7], curvePtsX[Slider_Value + 8], curvePtsY[Slider_Value + 7], curvePtsY[Slider_Value + 8])*x) + returnOfCuttedARC(curvePtsX[Slider_Value + 7], curvePtsX[Slider_Value + 8], curvePtsY[Slider_Value + 7], curvePtsY[Slider_Value + 8]))
                {
                    SerialImage2.at<uchar>(x, y) = 255;
                }

                if ((y) <= (NegativeSlope(curvePtsX[Slider_Value + 15], curvePtsX[Slider_Value + 16], curvePtsY[Slider_Value + 15], curvePtsY[Slider_Value + 16])*x) + returnOfCuttedARC(curvePtsX[Slider_Value + 15], curvePtsX[Slider_Value + 16], curvePtsY[Slider_Value + 15], curvePtsY[Slider_Value + 16]))
                {
                    SerialImage3.at<uchar>(x, y) = 255;
                }
            }
        }
        cv::Canny(SerialImage1 ,SerialImage1 ,0, 0, 3);
        cv::Canny(SerialImage2 ,SerialImage2 ,0, 0, 3);
        cv::Canny(SerialImage3 ,SerialImage3 ,0, 0, 3);



        for (int y = curvePtsY[Slider_Value];y < SerialImage1.rows; y++)//To loop through all the pixels
        {
            for (int x = curvePtsX[Slider_Value]; x < SerialImage1.cols; x++)
            {

                if ((y >= curvePtsY[Slider_Value] || x >= curvePtsX[Slider_Value]) && SerialImage1.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial1CountUpper++;
                    SerialImage1.at<uchar>(x, y) = 255;
                }

                if (serial1CountUpper > 80)
                {
                    SerialImage1.at<uchar>(x, y) = 0;

                }


                if ((y >= curvePtsY[Slider_Value + 7] || x >= curvePtsX[Slider_Value + 7]) && SerialImage2.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial2CountUpper++;
                    SerialImage2.at<uchar>(x, y) = 255;
                }

                if (serial2CountUpper > 80)
                {
                    SerialImage2.at<uchar>(x, y) = 0;

                }



                if ((y >= curvePtsY[Slider_Value + 15] || x >= curvePtsX[Slider_Value + 15]) && SerialImage3.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial3CountUpper++;
                    SerialImage3.at<uchar>(x, y) = 255;
                }

                if (serial3CountUpper > 80)
                {
                    SerialImage3.at<uchar>(x, y) = 0;

                }
            }
        }
        for (int y = curvePtsY[Slider_Value];y > 0; y--)//To loop through all the pixels
        {
            for (int x = curvePtsX[Slider_Value]; x > 0; x--)
            {



                if ((y <= curvePtsY[Slider_Value] || x >= curvePtsX[Slider_Value]) && SerialImage1.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial1CountLower++;
                    SerialImage1.at<uchar>(x, y) = 255;
                }

                if (serial1CountLower > 80)
                {
                    SerialImage1.at<uchar>(x, y) = 0;

                }
                if ((y <= curvePtsY[Slider_Value + 7] || x >= curvePtsX[Slider_Value + 7]) && SerialImage2at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial2CountLower++;
                    SerialImage2.at<uchar>(x, y) = 255;
                }

                if (serial2CountLower > 80)
                {
                    SerialImage2.at<uchar>(x, y) = 0;

                }

                if ((y <= curvePtsY[Slider_Value + 15] || x >= curvePtsX[Slider_Value + 15]) && SerialImage3.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial3CountLower++;
                    SerialImage3.at<uchar>(x, y) = 255;
                }

                if (serial3CountLower > 80)
                {
                    SerialImage3.at<uchar>(x, y) = 0;

                }
            }
        }

        serial1CountLower = 0;
        serial2CountLower = 0;
        serial3CountLower = 0;
        serial1CountUpper = 0;
        serial2CountUpper = 0;
        serial3CountUpper = 0;
        for (int y = curvePtsY[Slider_Value];y < SerialImage1.rows; y++)//To loop through all the pixels
        {
            for (int x = curvePtsX[Slider_Value]; x > 0; x--)
            {



                if ((y >= curvePtsY[Slider_Value] || x <= curvePtsX[Slider_Value]) && SerialImage1.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial1CountLower++;
                    SerialImage1.at<uchar>(x, y) = 255;
                }

                if (serial1CountLower > 80)
                {
                    SerialImage1.at<uchar>(x, y) = 0;

                }


                if ((y >= curvePtsY[Slider_Value + 7] || x <= curvePtsX[Slider_Value + 7]) && SerialImage2at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial2CountLower++;
                    SerialImage2.at<uchar>(x, y) = 255;
                }

                if (serial2CountLower > 80)
                {
                    SerialImage2.at<uchar>(x, y) = 0;

                }

                if ((y >= curvePtsY[Slider_Value + 15] || x <= curvePtsX[Slider_Value + 15]) && SerialImage3.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial3CountLower++;
                    SerialImage3.at<uchar>(x, y) = 255;
                }

                if (serial3CountLower > 80)
                {
                    SerialImage3.at<uchar>(x, y) = 0;
                }
            }
        }
        for (int y = curvePtsY[Slider_Value];y > 0; y--)//To loop through all the pixels
        {
            for (int x = curvePtsX[Slider_Value]; x < SerialImage1.cols; x++)
            {

                if ((y <= curvePtsY[Slider_Value] || x >= curvePtsX[Slider_Value]) && SerialImage1.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial1CountUpper++;
                    SerialImage1.at<uchar>(x, y) = 255;
                }

                if (serial1CountUpper > 80)
                {
                    SerialImage1.at<uchar>(x, y) = 0;

                }
                if ((y <= curvePtsY[Slider_Value + 7] || x >= curvePtsX[Slider_Value + 7]) && SerialImage2at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial2CountUpper++;
                    SerialImage2.at<uchar>(x, y) = 255;
                }

                if (serial2CountUpper > 80)
                {
                    SerialImage2.at<uchar>(x, y) = 0;

                }
                if ((y <= curvePtsY[Slider_Value + 15] || x >= curvePtsX[Slider_Value + 15]) && SerialImage3.at<uchar>(x, y) == 255) {

                    //if (x <= Arc.cols / 2) {
                    serial3CountUpper++;
                    SerialImage3.at<uchar>(x, y) = 255;
                }

                if (serial3CountUpper > 80)
                {
                    SerialImage3.at<uchar>(x, y) = 0;
                }
            }
        }

        for (int y = 0;y < SerialImage3.rows; y++)//To loop through all the pixels
        {
            for (int x = 0; x < SerialImage3.cols; x++)
            {
                if (x > SerialImage3.cols - 40)
                {
                    SerialImage1.at<uchar>(x, y) = 0;
                    SerialImage2.at<uchar>(x, y) = 0;
                    SerialImage3.at<uchar>(x, y) = 0;
                }
            }
        }
        cv::Mat Accumilated;
        cv::addWeighted(SerialImage1, 1,*axialImages[maxSliceID], 1, 0.0, Accumilated);
        cv::addWeighted(Accumilated, 1,SerialImage2, 1, 0.0, Accumilated);
        cv::addWeighted(Accumilated, 1,SerialImage3, 1, 0.0, Accumilated);

        int N_operationsRED = 0;
        int N_operationsRED2 = 0;
        int N_operationsRED3 = 0;

        curvePtsX.clear();
        curvePtsYRED.clear();

        curvePtsXRED2.clear();
        curvePtsYRED2.clear();

        curvePtsXRED3.clear();
        curvePtsYRED3.clear();

        for (int y = 0;y < SerialImage1.rows; y++)//To loop through all the pixels
        {
            for (int x = 0; x < SerialImage1.cols; x++)
            {
                if (SerialImage1.at<uchar>(x, y) >= 200)
                {
                    curvePtsXRED.push_back(x);
                    curvePtsYRED.push_back(y);
                    N_operationsRED++;

                }


                if (SerialImage2.at<uchar>(x, y) >= 200)
                {
                    curvePtsXRED2.push_back(x);
                    curvePtsYRED2.push_back(y);
                    N_operationsRED2++;

                }


                if (SerialImage3.at<uchar>(x, y) >= 200)
                {
                    curvePtsXRED3.push_back(x);
                    curvePtsYRED3.push_back(y);
                    N_operationsRED3++;

                }
            }
        }

        TheTwo();

}

float MainWindow::NegativeSlope(int x1, int x2, int y1, int y2)
{
    float negativeSlope;
    float mk = float(y2 - y1);
    if (mk == 0)
    {        mk = 0.001;    }
    negativeSlope = ((float(x2 - x1) / mk)-1);
    slope= negativeSlope;
    return slope;
}

float MainWindow::NegativeSlopeArc(int x1,int x2,int y1,int y2)
{
    return (y1 - (slope*x1));
}

cv::Mat MainWindow::constructPanorama(int shiftValue){
    shiftCurve(shiftValue);
    tk::spline curve(curveShiftX,curveShiftY,tk::spline::cspline);
    int colNum =curveShiftX[curveShiftX.size()-1] - curveShiftX[0];
    cv::Mat Panorama(axialImages.size(),colNum,CV_8U);
    for(int i=0;i<axialImages.size();i++){
        for(int j =curveShiftX[0];j<curveShiftX[curveShiftX.size()-1];j++){
            Panorama.at<uchar>(i,j) = axialImages[i]->at<uchar>(curve(j),j);
        }
    }
    return Panorama;
}

void MainWindow::shiftCurve(int shift) {
    tk::spline curve(curveCtrlX, curveCtrlY, tk::spline::cspline);
    std::vector<double>derivs;
    for (int i = 0;i < curveCtrlX.size();i++) {
        derivs.push_back(curve.deriv(1, curveCtrlX[i]));
        curveShiftX[i] = 0;
        curveShiftY[i] = 0;

    }
    if (shift - (float(offset) / 2) > 0) {
        double shiftValue = 1 / (float(shift));
        for (int i = 0;i < curveCtrlX.size();i++) {
            curveShiftY[i] = curveCtrlY[i] - (shiftValue)*((offset / 2) / sqrt(1 + pow(derivs[i], 2)));
            curveShiftX[i] = curveCtrlX[i] + (shiftValue)*((derivs[i] * (offset / 2)) / sqrt(1 + pow(derivs[i], 2)));
        }
    }
    else if (shift - (offset / 2) < 0) {
        double shiftValue = 1 / (float(shift));
        for (int i = 0;i < curveCtrlX.size();i++) {
            curveShiftY[i] = curveCtrlY[i] + (shiftValue)*((offset / 2) / sqrt(1 + pow(derivs[i], 2)));
            curveShiftX[i] = curveCtrlX[i] - (shiftValue)*((derivs[i] * (offset / 2)) / sqrt(1 + pow(derivs[i], 2)));
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
void MainWindow::axialSliderCtrl(){
    int sliderValue = ui->axialSlider->value();
    QPixmap image = ASM::cvMatToQPixmap(*axialImages[sliderValue]);
    sceneManager.sceneAxial->clear();
    sceneManager.sceneAxial->addPixmap(image);
    ui->axialView->setScene(sceneManager.sceneAxial);
}
void MainWindow::coronalSliderCtrl(){
    int sliderValue = ui->coronalSlider->value();
    QPixmap image = ASM::cvMatToQPixmap(*coronalImages[sliderValue]);
    sceneManager.sceneCoronal->clear();
    sceneManager.sceneCoronal->addPixmap(image);
    ui->coronalView->setScene(sceneManager.sceneCoronal);
}
void MainWindow::sagittalSliderCtrl(){
    int sliderValue = ui->sagittalSlider->value();
    QPixmap image = ASM::cvMatToQPixmap(*sagittalImages[sliderValue]);
    sceneManager.sceneSagittal->clear();
    sceneManager.sceneSagittal->addPixmap(image);
    ui->sagittalView->setScene(sceneManager.sceneSagittal);
}
void MainWindow::panoramaSliderCtrl(){
    int sliderValue = ui->panoramaSlider->value();
    cv::Mat panoramaShiftImage =constructPanorama(sliderValue);
    QPixmap image = ASM::cvMatToQPixmap(panoramaShiftImage);
    sceneManager.scenePanorama->clear();
    sceneManager.scenePanorama->addPixmap(image);
    ui->panoramaView->setScene(sceneManager.scenePanorama);
}
void MainWindow::serialSliderCtrl(){}

