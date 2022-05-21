#include "Arc_Creator.h"

void TheDrawer();
cv::Mat src_gray;
int thresh = 100;
cv::RNG rng(12345);
void thresh_callback(int, void*);
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;
cv::Mat Filtered;
int Slider_Value = 0;
cv::Mat image;
std::vector<int>Xstorers;
std::vector<int>Ystorers;
std::vector<int>XstorersRED;
std::vector<int>YstorersRED;
std::vector<int>XstorersRED2;
std::vector<int>YstorersRED2;
std::vector<int>XstorersRED3;
std::vector<int>YstorersRED3;
int N_operations = 0;
int N_operationsRED2 = 0;
int N_operationsRED3 = 0;
int N_operationsRED = 0;
int KDestructor = 0;
void TheOne();
void TheTwo();
cv::Mat curveSplitter;
cv::Mat curveSplitter2;
cv::Mat curveSplitter3;
cv::Mat Paronama;
int ZDefiner = 0;
std::vector<std::string>fileNames;
float negativeSlope;
void THEONETWO();
cv::Mat  imageRED;
cv::Mat  imageRED2;
cv::Mat  imageRED3;
cv::Mat Modifiedimage;
cv::Mat arc;
QString dir3;
QString dir45;
std::vector<std::string> DICOM_Names;
std::vector<std::string> DICOM_Names_2;
std::vector<std::string> DICOM_Names_3;
std::vector<std::string> Full_Path_Names;
std::vector<std::string> Full_Path_Names_Sagitial;
std::vector<std::string> Full_Path_Names_Coronal;
std::vector <cv::String>Full_Path_Names_Axial;
std::string TheCT_Sagitial;
std::string TheCT_Coronal;
std::string TheCT_Axial;
int Size_Definer = 1;
TheArcCreator MisterArcClass;
cv::Mat Accumilated;

std::vector <double>elevenx;
std::vector <double>eleveny;
double PastXID = 0;
double PastYID = 0;
double FutureXID = 0;
double FutureYID = 0;
int ThehoveredIndex = 0;
double TheSizer = 10;
int x_First;
int y_First;
QPointF origPoint;
void TheDrawer();
QGraphicsLineItem* itemToDraw=0;
int ZO = 0;
std::string  picOFParonamaAccumiltaed;
int R_Definer = 0;
int K_Clicked = 0;
int K_Define = 0;
QBrush redBrush(Qt::red);
QPen blackpin(Qt::red);
//C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheSupremeCureveSplitter.jpeg
std::string Supreme_Curve_Splitter = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheSupremeCureveSplitter.jpeg";
std::string Dicom_Fro_Size = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Dicomtoimage\\build\\Release\\NewDCM12345.jpeg";
std::string Final_Arc_Image = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheFinalArc001.jpg";
std::string The_Image_Red = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED.jpg";
std::string The_Image_Red2 = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED2.jpg";
std::string The_Image_Red3 = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED3.jpg";
std::string The_Skeletoner = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\skeleton.jpg";
std::string The_Miss_Paronam="C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheParonamaWhale.jpeg";
std::string TheCuttedSavedArc = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg";


float average_offset(cv::Mat img) {
	int sum = 0;
	int num = 0;
	int oldSum = 0;
	// calculate the no of white pixels 
	for (int y = 0; y < img.rows; y++) {
		oldSum = sum;
		for (int x = 0; x < img.cols; x++)
			img.at<uchar>(y, x) > 0 ? sum++ : NULL;
		sum > oldSum ? num++ : NULL;

	}

	float avrg;
	avrg = (sum*1.0) / num;

	return avrg;
}

std::vector<double>ctrlShiftY(11,0);
std::vector<double>ctrlShiftX(11,0);
void shiftCurve(const std::vector<double>ctrlOriginX, const std::vector<double>ctrlOriginY,
	std::vector<double>&ctrlShiftX, std::vector<double>&ctrlShiftY,
	int shift, double offset) {
	//ctrlShiftX.clear();
	//ctrlShiftY.clear();
	tk::spline curve(ctrlOriginX, ctrlOriginY, tk::spline::cspline);
	std::vector<double>derivs;
	for (int i = 0;i < ctrlOriginX.size();i++) {
		derivs.push_back(curve.deriv(1, ctrlOriginX[i]));
		ctrlShiftX[i] = 0;
		ctrlShiftY[i] = 0;

	}
	if (shift - (float(offset) / 2) > 0) {
		double shiftValue = 1 / (float(shift));
		for (int i = 0;i < ctrlOriginX.size();i++) {
			ctrlShiftY[i] = ctrlOriginY[i] - (shiftValue)*((offset / 2) / sqrt(1 + pow(derivs[i], 2)));
			ctrlShiftX[i] = ctrlOriginX[i] + (shiftValue)*((derivs[i] * (offset / 2)) / sqrt(1 + pow(derivs[i], 2)));
		}
	}
	else if (shift - (offset / 2) < 0) {
		double shiftValue = 1 / (float(shift));
		for (int i = 0;i < ctrlOriginX.size();i++) {
			ctrlShiftY[i] = ctrlOriginY[i] + (shiftValue)*((offset / 2) / sqrt(1 + pow(derivs[i], 2)));
			ctrlShiftX[i] = ctrlOriginX[i] - (shiftValue)*((derivs[i] * (offset / 2)) / sqrt(1 + pow(derivs[i], 2)));
		}
	}
	else {
		//control points stay the same if not required a shift
		double shiftValue = 0;
		for (int i = 0;i < ctrlOriginX.size();i++) {
			ctrlShiftX[i] = ctrlOriginX[i];
			ctrlShiftY[i] = ctrlOriginY[i];
		}
	}
}








cv::Mat skeletonGenerate(cv::Mat image) {
	cv::Scalar mean, stddev;
	cv::meanStdDev(image, mean, stddev);

	double 	maxval = 255;
	double 	thresh = mean[0] + 2 * stddev[0];
	cv::Mat thresholdedImg;
	cv::threshold(image, thresholdedImg, thresh, maxval, 0);

	cv::Mat im_floodfill = thresholdedImg.clone();
	cv::floodFill(im_floodfill, cv::Point(0, 0), cv::Scalar(255));
	cv::Mat im_floodfill_inv;
	cv::bitwise_not(im_floodfill, im_floodfill_inv);
	cv::Mat holeFilled = (thresholdedImg | im_floodfill_inv);
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(30, 30));
	cv::Mat closingImg;
	cv::morphologyEx(holeFilled, closingImg, cv::MORPH_CLOSE, element, cv::Point(-1, -1), 2);

	cv::Mat labelImage(image.size(), CV_32S), dst(image.size(), CV_8UC3);
	int nLabels = connectedComponents(closingImg, labelImage, 8);
	std::cout << nLabels;
	std::vector<cv::Vec3b> colors(nLabels);
	colors[0] = cv::Vec3b(0, 0, 0);//background
	for (int label = 1; label < nLabels; ++label) {
		colors[label] = cv::Vec3b(0, 0, 0);
		if (label == 1)
			colors[label] = cv::Vec3b(255, 255, 255);
	}
	for (int r = 0; r < dst.rows; ++r) {
		for (int c = 0; c < dst.cols; ++c) {
			int label = labelImage.at<int>(r, c);
			cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
			pixel = colors[label];
		}
	}
	cvtColor(dst, dst, cv::COLOR_RGB2GRAY);
	cv::Mat blur;
	cv::blur(dst, blur, cv::Size(9, 9));
//	cv::Mat SkeletonImg;
	//cv::ximgproc::thinning(blur, SkeletonImg, 0);
	return dst;
}
int Shift_Define = 0;



void MainWindow::Shift() 
{

	
	std::vector <cv::Mat>Images;
	for (int i = 0; i < Full_Path_Names_Axial.size();i++)
	{
		Images.push_back(cv::imread(Full_Path_Names_Axial[i], 0));

	}

	// allcoate memory for no of pixels for each intensity value
	int histogram[256];

	// initialize all intensity values to 0
	for (int i = 0; i < 255; i++)
	{
		histogram[i] = 0;
	}

	// calculate the no of pixels for each intensity values
	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			histogram[(int)image.at<uchar>(y, x)]++;

	for (int i = 0; i < 256; i++)
		cout << histogram[i] << " ";
	int size = Images.size() - 1;
	int selections[9] = { int(size*(4 / (float)16)),
						int(size*(5 / (float)16)),int(size*(6 / (float)16)),int(size*(7 / (float)16)),int(size*(8 / (float)16)),
						int(size*(9 / (float)16)),int(size*(10 / (float)16)),int(size*(9 / (float)16)),int(size*(12 / (float)16)) };

	cv::Scalar meanSelection[9];
	cv::Scalar stdSelection[9];
	int whitePixelNumSelection[9];
	for (int i = 0;i < 9;i++) {

		cv::meanStdDev(Images[selections[i]], meanSelection[i], stdSelection[i]);

	}
	float mean1 = 0, std1 = 0;
	for (int i = 0;i < 9;i++) {
		mean1 += meanSelection[i][0];
		std1 += stdSelection[i][0];
	}
	mean1 /= 9;
	std1 /= 9;
	cv::Mat ThresImages[9];
	for (int i = 0;i < 9;i++) {
		double     maxval = 255;
		double     thresh = mean1 + 2 * std1;
		cv::threshold(Images[selections[i]], ThresImages[i], thresh, maxval, 0);
	}
	for (int i = 0;i < 9;i++) {
		whitePixelNumSelection[i] = cv::countNonZero(ThresImages[i]);
	}
	int max = 0;
	for (int i = 1;i < 9;i++) {
		if (whitePixelNumSelection[max] < whitePixelNumSelection[i]) {
			max = i;
		}
	}

	shiftCurve(elevenx, eleveny, ctrlShiftX, ctrlShiftY, ui->verticalSlider_6->value(), average_offset(skeletonGenerate(Images[max])));
	Shift_Define = 1;
	//elevenx = std::copy(ctrlShiftX);
	TheDrawer();

}






void MainWindow::Volume(std::string x, int y) {
	QMessageBox rr;
	rr.setText(QString::fromStdString( x));
	rr.exec();


	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_5;
	vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;

	int count = 1;
	double opacityWindow = 4096;
	double opacityLevel = 2048;
	int blendType = y;
	int clip = 0;
	double reductionFactor = 1.0;
	double frameRate = 10.0;

	bool independentComponents = true;
	// Create the renderer, render window and interactor
	vtkNew<vtkNamedColors> colors;
	vtkNew<vtkRenderer> renderer;

	vtkNew<vtkRenderWindow> renWin;
	renWin->AddRenderer(renderer);


	vtkNew<vtkRenderWindowInteractor> iren;
	iren->SetRenderWindow(renWin);
	iren->SetDesiredUpdateRate(frameRate / (1 + clip));

	iren->GetInteractorStyle()->SetDefaultRenderer(renderer);

	// Read the data
	vtkSmartPointer<vtkAlgorithm> reader;
	vtkSmartPointer<vtkImageData> input;

	vtkNew<vtkDICOMImageReader> dicomReader;
	dicomReader->SetDirectoryName(x.c_str());
	dicomReader->Update();
	input = dicomReader->GetOutput();
	reader = dicomReader;


	// Verify that we actually have a volume
	int dim[3];
	input->GetDimensions(dim);
	vtkNew<vtkImageResample> resample;
	if (reductionFactor < 1.0)
	{
		resample->SetInputConnection(reader->GetOutputPort());
		resample->SetAxisMagnificationFactor(0, reductionFactor);
		resample->SetAxisMagnificationFactor(1, reductionFactor);
		resample->SetAxisMagnificationFactor(2, reductionFactor);
	}

	// Create our volume and mapper
	vtkNew<vtkVolume> volume;
	vtkNew<vtkFixedPointVolumeRayCastMapper> mapper;

	if (reductionFactor < 1.0)
	{
		mapper->SetInputConnection(resample->GetOutputPort());
	}
	else
	{
		mapper->SetInputConnection(reader->GetOutputPort());
	}

	// Set the sample distance on the ray to be 1/2 the average spacing
	double spacing[3];
	if (reductionFactor < 1.0)
	{
		resample->GetOutput()->GetSpacing(spacing);
	}
	else
	{
		input->GetSpacing(spacing);
	}

	// Create our transfer function
	vtkNew<vtkColorTransferFunction> colorFun;
	vtkNew<vtkPiecewiseFunction> opacityFun;
	// Create the property and attach the transfer functions
	vtkNew<vtkVolumeProperty> property;
	property->SetIndependentComponents(independentComponents);
	property->SetColor(colorFun);
	property->SetScalarOpacity(opacityFun);
	property->SetInterpolationTypeToLinear();

	// connect up the volume to the property and the mapper
	volume->SetProperty(property);
	volume->SetMapper(mapper);
	
	// Depending on the blend type selected as a command line option,
	// adjust the transfer function
	switch (blendType)
	{
		// MIP
		// Create an opacity ramp from the window and level values.
		// Color is white. Blending is MIP.
	case 0:
		colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0);
		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0);
		mapper->SetBlendModeToMaximumIntensity();
		break;
		// CompositeRamp
	// Create a ramp from the window and level values. Use compositing
	// without shading. Color is a ramp from black to white.
	case 1:
		colorFun->AddRGBSegment(opacityLevel - 0.5 * opacityWindow, 0.0, 0.0, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0, 1.0, 1.0);
		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0);
		mapper->SetBlendModeToComposite();
		property->ShadeOff();
		break;

		// CompositeShadeRamp
		// Create a ramp from the window and level values. Use compositing
		// with shading. Color is white.
	case 2:
		colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0);
		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0);
		mapper->SetBlendModeToComposite();
		property->ShadeOn();
		break;

		// CT_Skin
		// Use compositing and functions set to highlight skin in CT data
		// Not for use on RGB data
	case 3:
		colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0);
		colorFun->AddRGBPoint(-1000, .62, .36, .18, 0.5, 0.0);
		colorFun->AddRGBPoint(-500, .88, .60, .29, 0.33, 0.45);
		colorFun->AddRGBPoint(3071, .83, .66, 1, 0.5, 0.0);

		opacityFun->AddPoint(-3024, 0, 0.5, 0.0);
		opacityFun->AddPoint(-1000, 0, 0.5, 0.0);
		opacityFun->AddPoint(-500, 1.0, 0.33, 0.45);
		opacityFun->AddPoint(3071, 1.0, 0.5, 0.0);

		mapper->SetBlendModeToComposite();
		property->ShadeOn();
		property->SetAmbient(0.1);
		property->SetDiffuse(0.9);
		property->SetSpecular(0.2);
		property->SetSpecularPower(10.0);
		property->SetScalarOpacityUnitDistance(0.8919);
		break;

		// CT_Bone
		// Use compositing and functions set to highlight bone in CT data
		// Not for use on RGB data
	case 4:
		colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0);
		colorFun->AddRGBPoint(-16, 0.73, 0.25, 0.30, 0.49, .61);
		colorFun->AddRGBPoint(641, .90, .82, .56, .5, 0.0);
		colorFun->AddRGBPoint(3071, 1, 1, 1, .5, 0.0);

		opacityFun->AddPoint(-3024, 0, 0.5, 0.0);
		opacityFun->AddPoint(-16, 0, .49, .61);
		opacityFun->AddPoint(641, .72, .5, 0.0);
		opacityFun->AddPoint(3071, .71, 0.5, 0.0);

		mapper->SetBlendModeToComposite();
		property->ShadeOn();
		property->SetAmbient(0.1);
		property->SetDiffuse(0.9);
		property->SetSpecular(0.2);
		property->SetSpecularPower(10.0);
		property->SetScalarOpacityUnitDistance(0.8919);
		break;

		// CT_Muscle
		// Use compositing and functions set to highlight muscle in CT data
		// Not for use on RGB data
	case 5:
		colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0);
		colorFun->AddRGBPoint(-155, .55, .25, .15, 0.5, .92);
		colorFun->AddRGBPoint(217, .88, .60, .29, 0.33, 0.45);
		colorFun->AddRGBPoint(420, 1, .94, .95, 0.5, 0.0);
		colorFun->AddRGBPoint(3071, .83, .66, 1, 0.5, 0.0);

		opacityFun->AddPoint(-3024, 0, 0.5, 0.0);
		opacityFun->AddPoint(-155, 0, 0.5, 0.92);
		opacityFun->AddPoint(217, .68, 0.33, 0.45);
		opacityFun->AddPoint(420, .83, 0.5, 0.0);
		opacityFun->AddPoint(3071, .80, 0.5, 0.0);

		mapper->SetBlendModeToComposite();
		property->ShadeOn();
		property->SetAmbient(0.1);
		property->SetDiffuse(0.9);
		property->SetSpecular(0.2);
		property->SetSpecularPower(10.0);
		property->SetScalarOpacityUnitDistance(0.8919);
		break;

		// RGB_Composite
		// Use compositing and functions set to highlight red/green/blue regions
		// in RGB data. Not for use on single component data
	case 6:
		opacityFun->AddPoint(0, 0.0);
		opacityFun->AddPoint(5.0, 0.0);
		opacityFun->AddPoint(30.0, 0.05);
		opacityFun->AddPoint(31.0, 0.0);
		opacityFun->AddPoint(90.0, 0.0);
		opacityFun->AddPoint(100.0, 0.3);
		opacityFun->AddPoint(110.0, 0.0);
		opacityFun->AddPoint(190.0, 0.0);
		opacityFun->AddPoint(200.0, 0.4);
		opacityFun->AddPoint(210.0, 0.0);
		opacityFun->AddPoint(245.0, 0.0);
		opacityFun->AddPoint(255.0, 0.5);

		mapper->SetBlendModeToComposite();
		property->ShadeOff();
		property->SetScalarOpacityUnitDistance(1.0);
		break;
	default:
		vtkGenericWarningMacro("Unknown blend type.");
		break;
	}

	// Add the volume to the scene

	renderer->AddVolume(volume);
	renderer->ResetCamera();
	auto camera = renderer->GetActiveCamera();
	camera->SetPosition(56.8656, -297.084, 78.913);
	//camera->SetFocalPoint(109.139, 120.604, 63.5486);
	camera->SetViewUp(-0.00782421, -0.0357807, -0.999329);
	//camera->SetDistance(421.227);
	//camera->SetClippingRange(146.564, 767.987);
	mRenderWindow_5->AddRenderer(renderer);
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	mRenderWindow_5->SetInteractor(renderWindowInteractor);
	vtkNew<vtkInteractorStyleImage> myInteractorStyle;
	renderWindowInteractor->SetInteractorStyle(myInteractorStyle);

	//mRenderWindow_5->SetInteractor(mInteractor);
	mRenderWindow_5->Render();
	ui->openGLWidget->SetRenderWindow(mRenderWindow_5);
	
	// interact with data
	renWin->Render();
	iren->Start();
}


void MainWindow::MIP() {

	Volume(dir3.toStdString(), 0);
}

void MainWindow::bone() {

	Volume(dir3.toStdString(), 4);
}

void MainWindow::skin() {

	Volume(dir3.toStdString(), 3);
}

void MainWindow::muscle() {

	Volume(dir3.toStdString(), 5);
}














void MainWindow::actionGroupClicked() {
	
	
	MisterArcClass.SceneAxial->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Coronal->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Curve_3Image->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Paronama_Arc->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Paronama_Image->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Sagitial->setMode(Scenez::Mode(Scenez::DrawLine));

	

}
void MainWindow::actionGroupClicked22() {
	
	MisterArcClass.SceneAxial->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Coronal->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Curve_3Image->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Paronama_Arc->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Paronama_Image->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Sagitial->setMode(Scenez::Mode(Scenez::SelectObject));



}



void QGraphicsView::wheelEvent(QWheelEvent *event)
{
	if (event->delta() > 0) {
		scale(1.25, 1.25);
	}
	else
	{
		scale(0.8, 0.8);
	}
}



void QGraphicsView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_A)
		rotate(1);
	else if (event->key() == Qt::Key_D)
		rotate(-1);
}





void MainWindow::onDrawSphere100Click() 
{
	Slider_Value = ui->verticalSlider_5->value();
	
	TheOne();
	cv::imwrite(picOFParonamaAccumiltaed, Accumilated);
	
	QPixmap Pic10001 = QPixmap(picOFParonamaAccumiltaed.c_str());
	//Pic10001.fill(Qt::black);

	Pic10001.scaled(ui->graphicsView_5->width(),ui->graphicsView_5->height(),Qt::KeepAspectRatio);
	
	ui->graphicsView_5->setBackgroundBrush(Pic10001);


	MisterArcClass.Scene_Curve_3Image->clear();
	QPixmap pic101 = QPixmap(Supreme_Curve_Splitter.c_str());
	MisterArcClass.Scene_Curve_3Image->addPixmap(pic101);
	ui->graphicsView_6->setScene(MisterArcClass.Scene_Curve_3Image);


}


float returnOfNegativeSloper(int x1, int x2, int y1, int y2)
{
	float mk = float(y2 - y1);
	if (mk == 0)
	{

		mk = 0.001;
	}


	negativeSlope = ((float(x2 - x1) / mk)*-1);
	return negativeSlope;

}
float returnOfCuttedARC(int x1, int x2, int y1, int y2)
{
	
	return (y1 - (negativeSlope*x1));

}
float returnofP(int h, int k, int x2, int y2)
{
	float Thedown = (4 * (y2 - k));
	if (Thedown <= 0.1  && Thedown > -0.1)
	{
		Thedown = 0.001;

	}
	float Hi = (((x2*x2) - (2 * x2*h) + (h*h)) / Thedown);
	return Hi;


}

void TheOne()
{
	int pixel_value1 = 0, pixel_value2 = 0;
	image = cv::imread(Dicom_Fro_Size, CV_8UC1);
	image.setTo(cv::Scalar(0, 0, 0));

	arc = cv::imread(Final_Arc_Image, 0);


	N_operations = 0;
	Xstorers.clear();
	Ystorers.clear();
	for (int y = 0;y < arc.rows; y++)//To loop through all the pixels
	{
		for (int x = 0; x < arc.cols; x++)
		{
			if (arc.at<uchar>(x, y) >= 200)
			{
				Xstorers.push_back(x);
				Ystorers.push_back(y);
				N_operations++;

			}

		}
	}


	THEONETWO();

}

void THEONETWO()
{

	imageRED = cv::imread(Dicom_Fro_Size, CV_8UC1);
	imageRED2 = cv::imread(Dicom_Fro_Size, CV_8UC1);
	imageRED3 = cv::imread(Dicom_Fro_Size, CV_8UC1);

	imageRED.setTo(cv::Scalar(0, 0, 0));
	imageRED2.setTo(cv::Scalar(0, 0, 0));
	imageRED3.setTo(cv::Scalar(0, 0, 0));



	int DefinerOfYOfLess = 0;
	int DefinerOfYOfMORE = 0;
	int DefinerOfYOfLess2 = 0;
	int DefinerOfYOfMORE2 = 0;
	int DefinerOfYOfLess3 = 0;
	int DefinerOfYOfMORE3 = 0;
	for (int y = 0;y < imageRED.rows - 16; y++)//To loop through all the pixels
	{
		for (int x = 0; x < imageRED.cols - 16; x++)
		{
			if ((y) <= (returnOfNegativeSloper(Xstorers[Slider_Value], Xstorers[Slider_Value + 1], Ystorers[Slider_Value], Ystorers[Slider_Value + 1])*x) + returnOfCuttedARC(Xstorers[Slider_Value], Xstorers[Slider_Value + 1], Ystorers[Slider_Value], Ystorers[Slider_Value + 1]))
				//if(y==  x +100)
			{
				imageRED.at<uchar>(x, y) = 255;
			}
			if ((y) <= (returnOfNegativeSloper(Xstorers[Slider_Value + 7], Xstorers[Slider_Value + 8], Ystorers[Slider_Value + 7], Ystorers[Slider_Value + 8])*x) + returnOfCuttedARC(Xstorers[Slider_Value + 7], Xstorers[Slider_Value + 8], Ystorers[Slider_Value + 7], Ystorers[Slider_Value + 8]))
				//if(y==  x +100)
			{
				imageRED2.at<uchar>(x, y) = 255;
			}

			if ((y) <= (returnOfNegativeSloper(Xstorers[Slider_Value + 15], Xstorers[Slider_Value + 16], Ystorers[Slider_Value + 15], Ystorers[Slider_Value + 16])*x) + returnOfCuttedARC(Xstorers[Slider_Value + 15], Xstorers[Slider_Value + 16], Ystorers[Slider_Value + 15], Ystorers[Slider_Value + 16]))
				//if(y==  x +100)
			{
				imageRED3.at<uchar>(x, y) = 255;
			}
		}
	}
	cv::Canny(imageRED, imageRED, 0, 0, 3);
	cv::Canny(imageRED2, imageRED2, 0, 0, 3);
	cv::Canny(imageRED3, imageRED3, 0, 0, 3);



	for (int y = Ystorers[Slider_Value];y < imageRED.rows; y++)//To loop through all the pixels
	{
		for (int x = Xstorers[Slider_Value]; x < imageRED.cols; x++)
		{














			if ((y >= Ystorers[Slider_Value] || x >= Xstorers[Slider_Value]) && imageRED.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE++;
				imageRED.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE > 80)
			{
				imageRED.at<uchar>(x, y) = 0;

			}


			if ((y >= Ystorers[Slider_Value + 7] || x >= Xstorers[Slider_Value + 7]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}



			if ((y >= Ystorers[Slider_Value + 15] || x >= Xstorers[Slider_Value + 15]) && imageRED3.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE3++;
				imageRED3.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE3 > 80)
			{
				imageRED3.at<uchar>(x, y) = 0;

			}
		}
	}
	for (int y = Ystorers[Slider_Value];y > 0; y--)//To loop through all the pixels
	{
		for (int x = Xstorers[Slider_Value]; x > 0; x--)
		{



			if ((y <= Ystorers[Slider_Value] || x >= Xstorers[Slider_Value]) && imageRED.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess++;
				imageRED.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess > 80)
			{
				imageRED.at<uchar>(x, y) = 0;

			}
			if ((y <= Ystorers[Slider_Value + 7] || x >= Xstorers[Slider_Value + 7]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}

			if ((y <= Ystorers[Slider_Value + 15] || x >= Xstorers[Slider_Value + 15]) && imageRED3.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess3++;
				imageRED3.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess3 > 80)
			{
				imageRED3.at<uchar>(x, y) = 0;

			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////

	DefinerOfYOfLess = 0;
	DefinerOfYOfLess2 = 0;
	DefinerOfYOfLess3 = 0;
	DefinerOfYOfMORE = 0;
	DefinerOfYOfMORE2 = 0;
	DefinerOfYOfMORE3 = 0;


	for (int y = Ystorers[Slider_Value];y < imageRED.rows; y++)//To loop through all the pixels
	{
		for (int x = Xstorers[Slider_Value]; x > 0; x--)
		{



			if ((y >= Ystorers[Slider_Value] || x <= Xstorers[Slider_Value]) && imageRED.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess++;
				imageRED.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess > 80)
			{
				imageRED.at<uchar>(x, y) = 0;

			}


			if ((y >= Ystorers[Slider_Value + 7] || x <= Xstorers[Slider_Value + 7]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}

			if ((y >= Ystorers[Slider_Value + 15] || x <= Xstorers[Slider_Value + 15]) && imageRED3.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess3++;
				imageRED3.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess3 > 80)
			{
				imageRED3.at<uchar>(x, y) = 0;

			}


















		}
	}


	//////////////////////////////////////////////


	for (int y = Ystorers[Slider_Value];y > 0; y--)//To loop through all the pixels
	{
		for (int x = Xstorers[Slider_Value]; x < imageRED.cols; x++)
		{














			if ((y <= Ystorers[Slider_Value] || x >= Xstorers[Slider_Value]) && imageRED.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE++;
				imageRED.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE > 80)
			{
				imageRED.at<uchar>(x, y) = 0;

			}


			if ((y <= Ystorers[Slider_Value + 7] || x >= Xstorers[Slider_Value + 7]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}



			if ((y <= Ystorers[Slider_Value + 15] || x >= Xstorers[Slider_Value + 15]) && imageRED3.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE3++;
				imageRED3.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE3 > 80)
			{
				imageRED3.at<uchar>(x, y) = 0;

			}







		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////zzzzzzzzzz///////////////


	for (int y = 0;y < imageRED3.rows; y++)//To loop through all the pixels
	{
		for (int x = 0; x < imageRED3.cols; x++)
		{
			if (x > imageRED3.cols - 40)
			{
				imageRED.at<uchar>(x, y) = 0;
				imageRED2.at<uchar>(x, y) = 0;
				imageRED3.at<uchar>(x, y) = 0;



			}


		}
	}

	cv::imwrite(The_Image_Red, imageRED);
	cv::imwrite(The_Image_Red2, imageRED2);
	cv::imwrite(The_Image_Red3, imageRED3);
	
	cv::addWeighted(imageRED, 1,cv::imread(Full_Path_Names_Axial[302],0), 1, 0.0, Accumilated);
	cv::addWeighted(Accumilated, 1,imageRED2, 1, 0.0, Accumilated);
	cv::addWeighted(Accumilated, 1,imageRED3, 1, 0.0, Accumilated);
	

	cv::Mat imageTHEREADRED = cv::imread(The_Image_Red);

	N_operationsRED = 0;
	N_operationsRED2 = 0;
	N_operationsRED3 = 0;

	XstorersRED.clear();
	YstorersRED.clear();

	XstorersRED2.clear();
	YstorersRED2.clear();
	XstorersRED3.clear();
	YstorersRED3.clear();


	for (int y = 0;y < imageRED.rows; y++)//To loop through all the pixels
	{
		for (int x = 0; x < imageRED.cols; x++)
		{
			if (imageRED.at<uchar>(x, y) >= 200)
			{
				XstorersRED.push_back(x);
				YstorersRED.push_back(y);
				N_operationsRED++;

			}


			if (imageRED2.at<uchar>(x, y) >= 200)
			{
				XstorersRED2.push_back(x);
				YstorersRED2.push_back(y);
				N_operationsRED2++;

			}


			if (imageRED3.at<uchar>(x, y) >= 200)
			{
				XstorersRED3.push_back(x);
				YstorersRED3.push_back(y);
				N_operationsRED3++;

			}
		}
	}

	TheTwo();

}


void TheTwo()
{

	cv::Mat Arc = cv::imread(Dicom_Fro_Size, 0);
	Arc.setTo(cv::Scalar(0, 0, 0));

	curveSplitter = cv::Mat(fileNames.size(), N_operationsRED + N_operationsRED2 + N_operationsRED3, CV_8UC1, cv::Scalar(0, 0, 0));
	Paronama = cv::Mat(fileNames.size(), N_operations, CV_8UC1, cv::Scalar(0, 0, 0));
	cv::Mat addedTogether;
	cv::Mat addedTogeth221;




	for (int The_Blue_Definer = 0;The_Blue_Definer < 449;The_Blue_Definer++) {
		std::vector<int>gray_scale_storer;
		std::vector<int>gray_scale_storer_Paronama;


		cv::Mat The_Dicomear = cv::imread(fileNames[The_Blue_Definer], CV_8UC1);
		std::cout << std::to_string(The_Blue_Definer) << std::endl;

		cv::addWeighted(imageRED, 1, The_Dicomear, 1, 0.0, addedTogether);
		cv::addWeighted(addedTogether, 1, arc, 1, 0.0, addedTogeth221);


		for (int i = 0; i < N_operationsRED; i++)
		{
			gray_scale_storer.push_back(The_Dicomear.at<uchar>(XstorersRED[i], YstorersRED[i]));

		}

		for (int i = 0; i < N_operationsRED2; i++)
		{
			gray_scale_storer.push_back(The_Dicomear.at<uchar>(XstorersRED2[i], YstorersRED2[i]));

		}

		for (int i = 0; i < N_operationsRED3; i++)
		{
			gray_scale_storer.push_back(The_Dicomear.at<uchar>(XstorersRED3[i], YstorersRED3[i]));

		}
		for (int i = 0; i < N_operations; i++)
		{
			gray_scale_storer_Paronama.push_back(The_Dicomear.at<uchar>(Xstorers[i], Ystorers[i]));

		}
		for (int i = 0; i < N_operationsRED + N_operationsRED2 + N_operationsRED3;i++)
		{
			curveSplitter.at<uchar>(The_Blue_Definer, i) = gray_scale_storer[i];
		}

		for (int i = 0; i < N_operations;i++)
		{
			Paronama.at<uchar>(The_Blue_Definer, i) = gray_scale_storer_Paronama[i];
		}



	}

	cv::imwrite(The_Miss_Paronam, Paronama);
	cv::imwrite(Supreme_Curve_Splitter, curveSplitter);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg", Accumilated);
	picOFParonamaAccumiltaed = ("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg");




	std::string ok1 = The_Miss_Paronam;
	QPixmap pic = QPixmap(ok1.c_str());
	MisterArcClass.Scene_Paronama_Image->clear();
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic);
	







	cv::Mat Filtered_paronama;
	alpha_slider = 0;
	cv::GaussianBlur(curveSplitter, Filtered, cv::Size(7, 7), 0);
	cv::GaussianBlur(Paronama, Filtered_paronama, cv::Size(7, 7), 0);
	ZDefiner++;
	KDestructor = 1;

}

class Point : public QGraphicsEllipseItem {
public:
	Point(QGraphicsItem *parent = nullptr) : QGraphicsEllipseItem(parent) {
		setRect(QRectF(-5, -5, 10, 10));

		QPen pen;
		pen.setColor(Qt::darkBlue);
		pen.setWidth(1);
		setPen(pen);
		setAcceptHoverEvents(true);
		ItemIsMovable*(true);


	}
protected:
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
		QPen pen;
		pen.setColor(Qt::blue);
		pen.setWidth(2);
		setPen(pen);
		QGraphicsEllipseItem::hoverEnterEvent(event);
		PastXID = (Point::x());
		PastYID = (Point::y());
		for (int i = 0; i <= 10; i++)
		{
			if (PastXID == elevenx[i] && PastYID == eleveny[i])
			{
				ThehoveredIndex = i;
			}


		}




	}
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
		QPen pen;
		pen.setColor(Qt::green);
		pen.setWidth(1);
		setPen(pen);
		QGraphicsEllipseItem::hoverLeaveEvent(event);
		QLinearGradient myGradient;
		QPen myPen;
		QPoint c1(0, 0);
		QPoint c2(50, 50);
		elevenx[ThehoveredIndex] = (Point::x());
		eleveny[ThehoveredIndex] = (Point::y());
		Shift_Define = 0;





		TheDrawer();
		//QMessageBox r;
		//r.setText(QString::number(Point::y()));
		//r.exec();




		//myPath.quadTo(c1, endPoint);



	}
};





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
	

	ui->setupUi(this);

	ui->verticalSlider->setRange(0, 450);
	ui->verticalSlider_2->setRange(0, 600);
	ui->verticalSlider_3->setRange(0, 600);



	//TheDrawer();

	QObject::connect(ui->Ma2, &QPushButton::clicked, this, &MainWindow::MAX2);
	QObject::connect(ui->Ma3, &QPushButton::clicked, this, &MainWindow::MAX1);
	QObject::connect(ui->Ma4, &QPushButton::clicked, this, &MainWindow::MAX3);
	QObject::connect(ui->Ma1, &QPushButton::clicked, this, &MainWindow::MAX4);
	



	connect(ui->actionNew_Project, SIGNAL(triggered()), this, SLOT(onDrawSphere2Click()));
	connect(ui->actionopen_project, SIGNAL(triggered()), this, SLOT(onDrawSphere2Click()));
	connect(ui->actionCross_Sections_View, SIGNAL(triggered()), this, SLOT(onDrawSphere77Click()));
	connect(ui->actionParonama_View, SIGNAL(triggered()), this, SLOT(onDrawSphere88Click()));
	connect(ui->action3D_view, SIGNAL(triggered()), this, SLOT(onDrawSphere99Click()));
	connect(ui->actionDraw_Curve, SIGNAL(triggered()), this, SLOT(actionGroupClicked()));
	connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(actionGroupClicked22()));
	connect(ui->actionGrid, SIGNAL(triggered()), this, SLOT(Volume(dir3.toStdString(),0)));
	
	connect(ui->actionAxial_Projection, SIGNAL(triggered()), this, SLOT(MIP()));
	connect(ui->actionSagitial_Projection, SIGNAL(triggered()), this, SLOT(bone()));
	connect(ui->actionCoronal_Projection, SIGNAL(triggered()), this, SLOT(muscle()));





	//connect(ui->actionLearn, SIGNAL(triggered()), this, SLOT(ParonamaDraw()));
	
	
	ui->actionDefault->setData(int(Scenez::DrawLine));
	ui->actionlength->setData(int(Scenez::SelectObject));
	ui->actionDefault->setCheckable(true);
	ui->actionlength->setCheckable(true);

	//connect(ui->actionDefault, SIGNAL(triggered()), this, SLOT(actionGroupClicked()));
	
	//connect(ui->actionlength, SIGNAL(triggered()), this, SLOT(actionGroupClicked22()));




	QObject::connect(ui->verticalSlider, &QSlider::valueChanged,
		this, &MainWindow::onDrawSphere3Click);

	QObject::connect(ui->verticalSlider_2, &QSlider::valueChanged,
		this, &MainWindow::onDrawSphere45Click);


	QObject::connect(ui->verticalSlider_3, &QSlider::valueChanged,
		this, &MainWindow::onDrawSphere998Click);



	QObject::connect(ui->verticalSlider_5, &QSlider::valueChanged,
		this, &MainWindow::onDrawSphere100Click);

	QObject::connect(ui->verticalSlider_6, &QSlider::valueChanged,
		this, &MainWindow::Shift);


	


	std::string sk_path = cv::samples::findFile(The_Skeletoner);
	cv::Mat skeleton = cv::imread(sk_path, cv::IMREAD_GRAYSCALE);

	std::vector <int >noXI;
	std::vector <int >noYI;
	//store white pixles
	for (int i = 0; i < skeleton.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < skeleton.rows; j++)
		{
			if (skeleton.at<uchar>(j, i) == 255)
			{
				noXI.push_back(i);
				noYI.push_back(j);


			}
		}
	}


	//DicomImage* DCM_image = new DicomImage(Full_Path_Names[200].c_str());
	//cv::Mat imgdcm(int(DCM_image->getWidth()), int(DCM_image->getHeight()), CV_8U, (uchar*)DCM_image->getOutputData(8));
	//cv::imshow("DCMTKIMAGE", imgdcm);
	// Convert gray image to BGRb
	cv::Mat3b grayBGR;
	cv::cvtColor(skeleton, grayBGR, cv::COLOR_GRAY2BGR);


	for (int i = 0; i <= 10; i++) {
		std::vector<int>::iterator csitX = (i* ((noXI.end() - 1) - noXI.begin()) / 10) + noXI.begin();
		std::vector<int>::iterator csitY = (i* ((noYI.end() - 1) - noYI.begin()) / 10) + noYI.begin();
		cv::Point cubicPoint = { *csitX ,  *csitY };
		elevenx.push_back(*csitX);
		eleveny.push_back(*csitY);
		//MyFilledCircle(grayBGR, cubicPoint);

	}
	
	














}



void TheDrawer()
{
	MisterArcClass.Scene_Paronama_Arc->clear();

	QBrush redBrush(Qt::red);
	QPen blackpin(Qt::red);
	blackpin.setWidth(2000);

	int Index_X = 0;
	int Index_Y = 0;
	int min = 9000;
	bool Fun = true;
	std::vector<int>EleventhXSortedIndex;
	while (EleventhXSortedIndex.size() < elevenx.size()) {
		min = 9000;
		for (int i = 0; i < elevenx.size();i++)
		{

			for (int z = 0;z < EleventhXSortedIndex.size();z++)
			{
			
				if (i == EleventhXSortedIndex[z]) { Fun = false; }
			}
			if (min > elevenx[i]&&Fun)
			{
				min = elevenx[i];
				Index_X = i;

			}

			Fun = true;
		}
		
		EleventhXSortedIndex.push_back(Index_X);
	}

	std::vector<double>TheElevethXsorted;
	std::vector<double>TheElevethYsorted;

	for (int i = 0;i < EleventhXSortedIndex.size();i++) 
	{
		TheElevethXsorted.push_back((float)elevenx[EleventhXSortedIndex[i]]);
		TheElevethYsorted.push_back((float)eleveny[EleventhXSortedIndex[i]]);

	}

	QPainterPath myPath;

	if (Shift_Define == 0) {
		for (int i = 0; i <= 8;i = i + 2) {

			myPath.moveTo(elevenx[i], eleveny[i]);

			myPath.cubicTo(QPoint(elevenx[i], eleveny[i]), QPoint(elevenx[i + 1], eleveny[i + 1]), QPoint(elevenx[i + 2], eleveny[i + 2]));

			//myPath.quadTo(c2, endPoint);
			MisterArcClass.Scene_Paronama_Arc->addPath(myPath);
		}
	}
	if (Shift_Define == 1) 
	{
		for (int i = 0; i <= 8;i = i + 2) {

			myPath.moveTo(ctrlShiftX[i], ctrlShiftY[i]);

			myPath.cubicTo(QPoint(ctrlShiftX[i], ctrlShiftY[i]), QPoint(ctrlShiftX[i + 1], ctrlShiftY[i + 1]), QPoint(ctrlShiftX[i + 2], ctrlShiftY[i + 2]));

			//myPath.quadTo(c2, endPoint);
			MisterArcClass.Scene_Paronama_Arc->addPath(myPath);
		}
	
	
	
	
	}




	cv::Mat Oh = cv::imread("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\skeleton.jpg", 0);
	double width, height;
	cv::Size(width, height) = Oh.size();
	//double width = Oh.cols;
	//double height = Oh.rows;

	QRectF rect;
	rect.setHeight(height);
	rect.setWidth(width);

	MisterArcClass.Scene_Paronama_Arc->clearSelection();                                                  // Selections would also render to the file
	//Scene->setSceneRect(Scene->sceneRect());                          // Re-shrink the scene to it's bounding contents
	QImage image(QSize(((*max_element(elevenx.begin(), elevenx.end())) - (*min_element(elevenx.begin(), elevenx.end()))), ((*max_element(eleveny.begin(), eleveny.end())) - (*min_element(eleveny.begin(), eleveny.end())))), QImage::Format_Grayscale8);  // Create the image with the exact size of the shrunk scene
	image.fill(Qt::transparent);                                              // Start all pixels transparent
	QPainter painter2(&image);

	painter2.setPen(blackpin);




	myPath.moveTo(elevenx[0], eleveny[0]);
	myPath.cubicTo(QPoint(elevenx[0], eleveny[0]), QPoint(elevenx[0 + 1], eleveny[0 + 1]), QPoint(elevenx[0 + 2], eleveny[0 + 2]));


	painter2.drawPath(myPath);


	MisterArcClass.Scene_Paronama_Arc->render(&painter2);

	image.save("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi77.jpg");














	for (int i = 0; i <= 10;i++) {
		Point *Ellipse = new Point();
		MisterArcClass.Scene_Paronama_Arc->addItem(Ellipse);
		Ellipse->setPos(elevenx[i], eleveny[i]);
		Ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);


	}

	cv::Mat EmptyOne = cv::imread(The_Skeletoner, 0);
	EmptyOne.setTo(cv::Scalar(0, 0, 0));
	//cv::imshow("Hi", EmptyOne);
	cv::Mat cutted = cv::imread("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi77.jpg", 0);
	cv::Mat dster;
	bitwise_not(cutted, dster);
	//cv::imshow("Hi22", dster);
	for (int i = 0; i < dster.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < dster.rows; j++)
		{
			if (dster.at<uchar>(j, i) >= 200)
			{
				EmptyOne.at<uchar>(j + (*min_element(eleveny.begin(), eleveny.end())), i + (*min_element(elevenx.begin(), elevenx.end()))) = 255;
			}
		}
	}

	//cv::imshow("WellComeBack", EmptyOne);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheFinalArc001.jpg", EmptyOne);

	TheOne();


}


void MainWindow::Drawer()
{
	

	// First we initialize the scene of all Graphics scene 
	MisterArcClass.Scene_Paronama_Arc = new Scenez(this);
	MisterArcClass.Scene_Paronama_Image = new Scenez(this);
	MisterArcClass.Scene_Curve_3Image = new Scenez(this);
	MisterArcClass.SceneAxial = new Scenez(this);


	// Then we put the pic best Image we got which was number 302 
	
	// set Pic99 to be The paronama image
	QPixmap pic99 = QPixmap(The_Miss_Paronam.c_str());

	//Set the pic of each scene according to its function

	ui->graphicsView_5->setScene(MisterArcClass.Scene_Paronama_Arc);
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic99);
	ui->graphicsView_7->setScene(MisterArcClass.Scene_Paronama_Image);
	ui->graphicsView->setScene(MisterArcClass.SceneAxial);


	QBrush redBrush(Qt::red);
	QPen blackpin(Qt::red);
	blackpin.setWidth(900);


	QPainterPath myPath;
	QPainterPath myPath77[9];
	//Set the path we need along the arc by cubic spline to each point +2 to make as 3 to be ablr to get 11

	for (int i = 0; i <= 8;i = i + 2) {

		myPath.moveTo(elevenx[i], eleveny[i]);
		myPath.cubicTo(QPoint(elevenx[i], eleveny[i]), QPoint(elevenx[i + 1], eleveny[i + 1]), QPoint(elevenx[i + 2], eleveny[i + 2]));
		MisterArcClass.Scene_Paronama_Arc->addPath(myPath);



	}

	// then we crop the size needed which we will apply by the screenshot in
	cv::Mat Oh = cv::imread(The_Skeletoner, 0);
	double width, height;
	cv::Size(width, height) = Oh.size();
	//double width = Oh.cols;
	//double height = Oh.rows;


	QRectF rect;
	rect.setHeight(height);
	rect.setWidth(width);

	MisterArcClass.Scene_Paronama_Arc->clearSelection();                                                  // Selections would also render to the file
	//Scene->setSceneRect(Scene->sceneRect());                          // Re-shrink the scene to it's bounding contents
	QImage image(QSize(((*max_element(elevenx.begin(), elevenx.end())) - (*min_element(elevenx.begin(), elevenx.end()))), ((*max_element(eleveny.begin(), eleveny.end())) - (*min_element(eleveny.begin(), eleveny.end())))), QImage::Format_Grayscale8);  // Create the image with the exact size of the shrunk scene
	image.fill(Qt::transparent);                                              // Start all pixels transparent
	QPainter painter2(&image);

	painter2.setPen(blackpin);

	myPath.moveTo(elevenx[0], eleveny[0]);
	myPath.cubicTo(QPoint(elevenx[0], eleveny[0]), QPoint(elevenx[0 + 1], eleveny[0 + 1]), QPoint(elevenx[0 + 2], eleveny[0 + 2]));


	painter2.drawPath(myPath);


	MisterArcClass.Scene_Paronama_Arc->render(&painter2);
	// Save the image needed for the Arc and which we will get next its data as the arc 
	image.save("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg");






	//add the 11 elipses 
	for (int i = 0; i <= 10;i++) {
		Point *Ellipse = new Point();
		MisterArcClass.Scene_Paronama_Arc->addItem(Ellipse);
		Ellipse->setPos(elevenx[i], eleveny[i]);
		Ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);


	}
	
	cv::Mat EmptyOne = cv::imread(The_Skeletoner, 0);
	EmptyOne.setTo(cv::Scalar(0, 0, 0));

	cv::Mat cutted = cv::imread(TheCuttedSavedArc, 0);
	cv::Mat dster;
	bitwise_not(cutted, dster);

	//Then we need to invert the image to be able to make the arc white with blacjk background
	for (int i = 0; i < dster.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < dster.rows; j++)
		{
			if (dster.at<uchar>(j, i) >= 200)
			{
				EmptyOne.at<uchar>(j + (*min_element(eleveny.begin(), eleveny.end())), i + (*min_element(elevenx.begin(), elevenx.end()))) = 255;
			}
		}
	}

	cv::imwrite(Final_Arc_Image, EmptyOne);

	std::string folder(TheCT_Axial);
	QDir  TheDirectory = QString::fromStdString(folder);
	QStringList DICOMS = TheDirectory.entryList(QStringList() << "*.jpeg", QDir::Files);
	//cv::glob(folder, fileNames, false);
	int Slice_Definer = 0;
	int Passed_Successful_Slice = 0;
	while (Slice_Definer != 450) {
		foreach(QString Dicom, DICOMS)
		{



			std::string the_path = folder + "\\" + Dicom.toUtf8().constData();
			if (Dicom.toUtf8().constData() == "DCM" + std::to_string(Slice_Definer) + ".jpeg")
			{
				fileNames.push_back(the_path);
				Passed_Successful_Slice++;
				Slice_Definer++;

			}
		}
	}
	//Then we pass the function to arc generator
	TheOne();
	QPixmap Pic10001 = QPixmap(picOFParonamaAccumiltaed.c_str());
	ui->graphicsView_5->setBackgroundBrush(Pic10001);
	MisterArcClass.Scene_Curve_3Image->clear();
	//and set the curve of threeimages to this arc
	QPixmap pic100 = QPixmap(Supreme_Curve_Splitter.c_str());
	MisterArcClass.Scene_Curve_3Image->addPixmap(pic100);
	ui->graphicsView_6->setScene(MisterArcClass.Scene_Curve_3Image);
	//The same with paronama and paronama arc image
	MisterArcClass.Scene_Paronama_Image->clear();
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic99);
	ui->graphicsView_7->setScene(MisterArcClass.Scene_Paronama_Image);
	ui->verticalSlider_5->setRange(0, N_operations);
}

void MainWindow::MAX2() 
{
	if (ZO == 0) {
		ui->graphicsView_2->hide();
		ui->graphicsView_3->hide();
		ui->openGLWidget->hide();
		ui->verticalSlider_2->hide();
		ui->verticalSlider_3->hide();
		ui->verticalSlider_4->hide();
		ui->verticalSlider_6->hide();

		ui->graphicsView_5->hide();
		ui->graphicsView_6->hide();
		ui->graphicsView_7->hide();
		ui->verticalSlider_5->hide();

		ui->pushButton->hide();
		ui->pushButton_2->hide();
		ui->pushButton_3->hide();
		ui->pushButton_4->hide();
		ui->pushButton_5->hide();
		ui->pushButton_6->hide();
		


		ui->Ma1->hide();
		//ui->Ma2->hide();
		ui->Ma3->hide();
		ui->Ma4->hide();
		ui->Mi1->hide();
		//ui->Mi2->hide();
		ui->Mi3->hide();
		ui->Mi4->hide();
		ZO = 1;
	}
	else 
	{
		ui->graphicsView->show();
		ui->graphicsView_2->show();
		ui->graphicsView_3->show();
		ui->openGLWidget->show();


		ui->verticalSlider->show();
		ui->verticalSlider_2->show();
		ui->verticalSlider_3->show();
		ui->verticalSlider_4->show();

		ui->Ma1->show();
		ui->Ma2->show();
		ui->Ma3->show();
		ui->Ma4->show();
		ui->Mi1->show();
		ui->Mi2->show();
		ui->Mi3->show();
		ui->Mi4->show();

		ui->graphicsView_5->show();
		ui->graphicsView_6->show();
		ui->graphicsView_7->show();
		ui->verticalSlider_5->show();

		ui->pushButton->show();
		ui->pushButton_2->show();
		ui->pushButton_3->show();
		ui->pushButton_4->show();
		ui->pushButton_5->show();
		ui->pushButton_6->show();

		ZO = 0;
	
	
	}


}
void MainWindow::MAX3()
{
	
	if (ZO == 0) {

		ui->graphicsView_2->hide();
		ui->graphicsView->hide();
		//ui->graphicsView_3->hide();
		ui->openGLWidget->hide();
		ui->verticalSlider_6->hide();

			
		ui->verticalSlider_2->hide();
		ui->verticalSlider->hide();
		//ui->verticalSlider_3->hide();
		ui->verticalSlider_4->hide();

		ui->Ma1->hide();
		ui->Ma2->hide();
		//ui->Ma3->hide();
		ui->Ma4->hide();
		ui->Mi1->hide();
		ui->Mi2->hide();
		//ui->Mi3->hide();
		ui->Mi4->hide();

	
		//ui->verticalSpacer_2->widget()->hide();
		//ui->verticalSpacer_3->widget()->hide();
		//ui->verticalSpacer_4->widget()->hide();
		//ui->graphicsView->setFixedSize(15* ui->graphicsView_2->sizeHint());

		//ui->gridLayout->setEnabled(false);


		//ui->horizontalLayout->setEnabled(false);
		//ui->horizontalLayout_2->setEnabled(false);

		ui->graphicsView_5->hide();
		ui->graphicsView_6->hide();
		ui->graphicsView_7->hide();
		ui->verticalSlider_5->hide();

		ui->pushButton->hide();
		ui->pushButton_2->hide();
		ui->pushButton_3->hide();
		ui->pushButton_4->hide();
		ui->pushButton_5->hide();
		ui->pushButton_6->hide();

		//ui->verticalSpacer_2->changeSize(0, 0);

		//ui->verticalSpacer_3->changeSize(0, 0);
		//ui->verticalSpacer_4->changeSize(0, 0);
		ZO = 1;
	}
	else
	{

		//ui->graphicsView->setFixedSize(ui->graphicsView_2->sizeHint());
		ui->graphicsView->show();
		ui->graphicsView_2->show();
		ui->graphicsView_3->show();
		ui->openGLWidget->show();


		ui->verticalSlider->show();
		ui->verticalSlider_2->show();
		ui->verticalSlider_3->show();
		ui->verticalSlider_4->show();

		ui->Ma1->show();
		ui->Ma2->show();
		ui->Ma3->show();
		ui->Ma4->show();
		ui->Mi1->show();
		ui->Mi2->show();
		ui->Mi3->show();
		ui->Mi4->show();

		ui->graphicsView_5->show();
		ui->graphicsView_6->show();
		ui->graphicsView_7->show();
		ui->verticalSlider_5->show();

		ui->pushButton->show();
		ui->pushButton_2->show();
		ui->pushButton_3->show();
		ui->pushButton_4->show();
		ui->pushButton_5->show();
		ui->pushButton_6->show();

		
		//ui->verticalSpacer->changeSize(40, 20);
		//ui->verticalSpacer_2->changeSize(40, 20);

		//ui->verticalSpacer_3->changeSize(40, 20);
		//ui->verticalSpacer_4->changeSize(40, 20);
		ZO = 0;


	}


	

}
void MainWindow::MAX4()
{
	
	if (ZO == 0) {

		ui->graphicsView->hide();
		//ui->graphicsView_2->hide();
		ui->graphicsView_3->hide();
		ui->openGLWidget->hide();
		ui->verticalSlider_6->hide();


		//ui->verticalSlider_2->hide();
		ui->verticalSlider->hide();
		ui->verticalSlider_3->hide();
		ui->verticalSlider_4->hide();

		//ui->Ma1->hide();
		ui->Ma2->hide();
		ui->Ma3->hide();
		ui->Ma4->hide();
		//ui->Mi1->hide();
		ui->Mi2->hide();
		ui->Mi3->hide();
		ui->Mi4->hide();

		ui->graphicsView_5->hide();
		ui->graphicsView_6->hide();
		ui->graphicsView_7->hide();
		ui->verticalSlider_5->hide();

		ui->pushButton->hide();
		ui->pushButton_2->hide();
		ui->pushButton_3->hide();
		ui->pushButton_4->hide();
		ui->pushButton_5->hide();
		ui->pushButton_6->hide();

		//ui->verticalSpacer_2->widget()->hide();
		//ui->verticalSpacer_3->widget()->hide();
		//ui->verticalSpacer_4->widget()->hide();
		//ui->graphicsView->setFixedSize(15* ui->graphicsView_2->sizeHint());

		//ui->gridLayout->setEnabled(false);


		//ui->horizontalLayout->setEnabled(false);
		//ui->horizontalLayout_2->setEnabled(false);


		//ui->verticalSpacer_2->changeSize(0, 0);

		//ui->verticalSpacer_3->changeSize(0, 0);
		//ui->verticalSpacer_4->changeSize(0, 0);
		ZO = 1;
	}
	else
	{

		//ui->graphicsView->setFixedSize(ui->graphicsView_2->sizeHint());
		ui->graphicsView->show();
		ui->graphicsView_2->show();
		ui->graphicsView_3->show();
		ui->openGLWidget->show();


		ui->verticalSlider->show();
		ui->verticalSlider_2->show();
		ui->verticalSlider_3->show();
		ui->verticalSlider_4->show();

		ui->Ma1->show();
		ui->Ma2->show();
		ui->Ma3->show();
		ui->Ma4->show();
		ui->Mi1->show();
		ui->Mi2->show();
		ui->Mi3->show();
		ui->Mi4->show();

		ui->graphicsView_5->show();
		ui->graphicsView_6->show();
		ui->graphicsView_7->show();
		ui->verticalSlider_5->show();

		ui->pushButton->show();
		ui->pushButton_2->show();
		ui->pushButton_3->show();
		ui->pushButton_4->show();
		ui->pushButton_5->show();
		ui->pushButton_6->show();

	
		//ui->verticalSpacer->changeSize(40, 20);
		//ui->verticalSpacer_2->changeSize(40, 20);

		//ui->verticalSpacer_3->changeSize(40, 20);
		//ui->verticalSpacer_4->changeSize(40, 20);
		ZO = 0;


	}

	


}
void MainWindow::MAX1()
{
	
	if (ZO == 0) {

		ui->graphicsView_2->hide();
		ui->graphicsView_3->hide();
		ui->openGLWidget->hide();
		ui->verticalSlider_6->hide();


		ui->verticalSlider_2->hide();
		ui->verticalSlider_3->hide();
		ui->verticalSlider_4->hide();

		ui->Ma1->hide();
		//ui->Ma2->hide();
		ui->Ma3->hide();
		ui->Ma4->hide();
		ui->Mi1->hide();
		//ui->Mi2->hide();
		ui->Mi3->hide();
		ui->Mi4->hide();

		

		//ui->verticalSpacer_2->widget()->hide();
		//ui->verticalSpacer_3->widget()->hide();
		//ui->verticalSpacer_4->widget()->hide();
		//ui->graphicsView->setFixedSize(15* ui->graphicsView_2->sizeHint());

		//ui->gridLayout->setEnabled(false);


		//ui->horizontalLayout->setEnabled(false);
		//ui->horizontalLayout_2->setEnabled(false);


		//ui->verticalSpacer_2->changeSize(0, 0);

		//ui->verticalSpacer_3->changeSize(0, 0);
		//ui->verticalSpacer_4->changeSize(0, 0);
		ZO = 1;
	}
	else
	{

		//ui->graphicsView->setFixedSize(ui->graphicsView_2->sizeHint());
		ui->graphicsView->show();
		ui->graphicsView_2->show();
		ui->graphicsView_3->show();
		ui->openGLWidget->show();


		ui->verticalSlider->show();
		ui->verticalSlider_2->show();
		ui->verticalSlider_3->show();
		ui->verticalSlider_4->show();

		ui->Ma1->show();
		ui->Ma2->show();
		ui->Ma3->show();
		ui->Ma4->show();
		ui->Mi1->show();
		ui->Mi2->show();
		ui->Mi3->show();
		ui->Mi4->show();


		
		//ui->verticalSpacer->changeSize(40, 20);
		//ui->verticalSpacer_2->changeSize(40, 20);

		//ui->verticalSpacer_3->changeSize(40, 20);
		//ui->verticalSpacer_4->changeSize(40, 20);
		ZO = 0;


	}

	


}

void MainWindow::onDrawSphere77Click() 
{
	ui->pushButton->hide();
	ui->pushButton_2->hide();
	ui->pushButton_3->hide();
	ui->pushButton_4->hide();
	ui->pushButton_5->hide();
	ui->pushButton_6->hide();
	ui->graphicsView->show();
	ui->graphicsView_2->show();
	ui->graphicsView_3->show();
	ui->openGLWidget->show();


	ui->verticalSlider->show();
	ui->verticalSlider_2->show();
	ui->verticalSlider_3->show();
	ui->verticalSlider_4->show();

	ui->Ma1->show();
	ui->Ma2->show();
	ui->Ma3->show();
	ui->Ma4->show();
	ui->Mi1->show();
	ui->Mi2->show();
	ui->Mi3->show();
	ui->Mi4->show();
	ui->graphicsView_5->hide();
	ui->graphicsView_6->hide();
	ui->graphicsView_7->hide();
	ui->verticalSlider_5->hide();


	









}


void MainWindow::onDrawSphere88Click()
{
	ui->pushButton->show();
	ui->pushButton_2->show();
	ui->pushButton_3->show();
	ui->pushButton_4->show();
	ui->pushButton_5->show();
	ui->pushButton_6->show();
	ui->graphicsView->hide();
	ui->graphicsView_2->hide();
	ui->graphicsView_3->hide();
	ui->openGLWidget->hide();


	ui->verticalSlider->hide();
	ui->verticalSlider_2->hide();
	ui->verticalSlider_3->hide();
	ui->verticalSlider_4->hide();

	ui->Ma1->hide();
	ui->Ma2->hide();
	ui->Ma3->hide();
	ui->Ma4->hide();
	ui->Mi1->hide();
	ui->Mi2->hide();
	ui->Mi3->hide();
	ui->Mi4->hide();
	ui->graphicsView_5->show();
	ui->graphicsView_6->show();
	ui->graphicsView_7->show();
	ui->verticalSlider_5->show();
	
	










}
	Drawer();



}
void MainWindow::onDrawSphere3Click()
{

	
	std::string ok1 = Full_Path_Names_Axial[ui->verticalSlider->value()];

	cv::Mat rrt1 = cv::imread(Full_Path_Names_Axial[ui->verticalSlider->value()], 0);
	cv::Mat zzr1;
	cv::Size zz1 (ui->graphicsView->width(),ui->graphicsView->height());
	cv::resize(rrt1,zzr1 ,zz1, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New.jpeg",zzr1);

	QPixmap pic1 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New.jpeg");
	pic1.scaled(MisterArcClass.SceneAxial->width(), MisterArcClass.SceneAxial->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	
	QMessageBox r;
	QString Z = QString::fromStdString(ok1);
	r.setText(Z);
	//r.exec();

	//ui->graphicsView->setBackgroundBrush(pic);
	//ui->graphicsView->setAutoFillBackground(true);
	MisterArcClass.SceneAxial->clear();
	MisterArcClass.SceneAxial->addPixmap(pic1);
	ui->graphicsView->setScene(MisterArcClass.SceneAxial);

}


void MainWindow::onDrawSphere45Click() {
	

	MisterArcClass.Scene_Sagitial = new Scenez(this);
	std::string ok1 = Full_Path_Names_Sagitial[ui->verticalSlider_2->value()];

	cv::Mat rrt2 = cv::imread(Full_Path_Names_Sagitial[ui->verticalSlider_2->value()], 0);
	cv::Mat zzr2;
	cv::Size zz2(ui->graphicsView_2->width(), ui->graphicsView_2->height());
	cv::resize(rrt2, zzr2, zz2, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New2.jpeg", zzr2);
	QPixmap pic2 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New2.jpeg");
	MisterArcClass.Scene_Sagitial->addPixmap(pic2);
	ui->graphicsView_2->setScene(MisterArcClass.Scene_Sagitial);
	
}

void MainWindow::onDrawSphere998Click() {
	MisterArcClass.Scene_Coronal = new Scenez(this);
	std::string ok1 = Full_Path_Names_Coronal[ui->verticalSlider_3->value()];

	cv::Mat rrt3 = cv::imread(Full_Path_Names_Coronal[ui->verticalSlider_3->value()], 0);
	cv::Mat zzr3;
	cv::Size zz3(ui->graphicsView_3->width(), ui->graphicsView_3->height());
	cv::resize(rrt3, zzr3, zz3, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New3.jpeg", zzr3);

	

	QPixmap pic3 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New3.jpeg");


	//ui->graphicsView->setBackgroundBrush(pic);
	//ui->graphicsView->setAutoFillBackground(true);
	MisterArcClass.Scene_Coronal->addPixmap(pic3);
	ui->graphicsView_3->setScene(MisterArcClass.Scene_Coronal);

}


MainWindow::~MainWindow()
{
    delete ui;
}
