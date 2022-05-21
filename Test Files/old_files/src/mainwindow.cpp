#include "Arc_Creator.h"


void TheDrawer();
cv::Mat src_gray;
int thresh = 100;
cv::RNG rng(12345);
void thresh_callback(int, void*);
const int alpha_slider_max = 100;
cv::Mat EmptyOne2;
int ZEE = 0;
cv::Mat inichializerofSize;
int Widx = 0;
int Widy = 0;

int alpha_slider;
double alpha;
MainWindow * MM ;
int OHMY=1;
double beta;
cv::Mat Filtered;
int Slider_Value = 0;
cv::Mat image;
cv::Mat EmptyOne;
bool SaveImages = false;
std::vector<cv::Mat>StoreerOfShiftedParonama;
std::vector<double>Xstorers;
std::vector<double>Ystorers;
std::vector<double>XstorersRED;
std::vector<double>YstorersRED;
std::vector<double>XstorersRED2;
std::vector<double>YstorersRED2;
std::vector<double>XstorersRED3;
std::vector<double>YstorersRED3;
int N_operations = 0;
int N_operationsRED2 = 0;
int N_operationsRED3 = 0;
int N_operationsRED = 0;
int KDestructor = 0;
void TheOne(std::vector<double>TheElevenPointsX, std::vector<double>TheElevenPointsY);
void TheTwo();
cv::Mat curveSplitter;
cv::Mat curveSplitter2;
cv::Mat curveSplitter3;
cv::Mat Paronama;
int ZDefiner = 0;
std::vector<std::string>fileNames;
float negativeSlope;
void THEONETWO(std::vector<double>TheElevenPointsX, std::vector<double>TheElevenPointsY);
cv::Mat  imageRED;
cv::Mat  imageRED2;
cv::Mat  imageRED3;
cv::Mat Modifiedimage;
//cv::Mat arc;
QString dir3;
QString dir45;
int Shift_happened=0;
int ShiftHover1 = 1;
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
bool Shift_accepted;
std::vector <double>elevenx;
int Num_define = 0;
std::vector <double>eleveny;
std::vector< QGraphicsScene *> Sceneeezer;
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
int Slider6_Value;
QPen blackpin(Qt::red);
int stateless = 0;




//C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheSupremeCureveSplitter.jpeg
std::string Supreme_Curve_Splitter = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheSupremeCureveSplitter.jpeg";
std::string Dicom_Fro_Size = "G:\\MedicalDATA\\DICOM\\128602 - L  yz\\Sample Images\\DCM0.jpeg";
std::string Final_Arc_Image = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheFinalArc001.jpg";
std::string The_Image_Red = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED.jpg";
std::string The_Image_Red2 = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED2.jpg";
std::string The_Image_Red3 = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\imageRED3.jpg";
std::string The_Skeletoner = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\skeleton.jpg";
std::string The_Miss_Paronam="C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheParonamaWhale.jpeg";
std::string TheCuttedSavedArc = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg";

std::vector <int>SummerV;





float average_offset(cv::Mat img) {

	SummerV.clear();
	for (int y = 0; y < img.cols; y++) {
		int sum = 0;
		for (int x = 0; x < img.rows; x++)
		{


			if (img.at<uchar>(y, x) > 0)
			{
				sum++;
			}

		}

		SummerV.push_back(sum);
	}

	/*
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
	*/


	return *std::max_element(SummerV.begin(), SummerV.end());
}

std::vector<double>ctrlShiftY(17, 0);
std::vector<double>ctrlShiftX(17, 0);
void shiftCurve(const std::vector<double>ctrlOriginX, const std::vector<double>ctrlOriginY,
	std::vector<double>&ctrlShiftX, std::vector<double>&ctrlShiftY,
	int shift, double offset) {
	//ctrlShiftX.clear();
	//ctrlShiftY.clear();

	////QmessageBox mm;
	//mm.setText(QString::number(ctrlShiftX[0]));
	//mm.exec();

	//mm.setText(QString::number(ctrlShiftX[1]));
	//mm.exec();
	//mm.setText(QString::number(ctrlShiftX[2]));
	//mm.exec();


	tk::spline curve(ctrlOriginX, ctrlOriginY, tk::spline::cspline);
	std::vector<double>derivs;
	for (int i = 0;i < ctrlOriginX.size();i++) {
		derivs.push_back(curve.deriv(1, ctrlOriginX[i]));
		ctrlShiftX[i] = 0;
		ctrlShiftY[i] = 0;

	}
	//mm.setText("The Shift is"+QString::number(shift));
	//mm.exec();

	//mm.setText("The offset/2 is"+QString::number((float(offset) / 2)));
	//mm.exec();

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
			//mm.setText("The Size of CtrlShiftX" + QString::number(ctrlShiftX.size()));
			//mm.exec();

			//mm.setText("The Size of CtrlShiftY" + QString::number(ctrlShiftY.size()));
			//mm.exec();
			ctrlShiftX[i] = ctrlOriginX[i];
			ctrlShiftY[i] = ctrlOriginY[i];
		}
	}



	//mm.setText(QString::number(elevenx[0]));
	//mm.exec();

	//mm.setText(QString::number(elevenx[1]));
	//mm.exec();
	//mm.setText(QString::number(elevenx[2]));
	//mm.exec();



}








cv::Mat skeletonGenerate(cv::Mat image) {
	////QmessageBox mm;
	//mm.setText("2");
	//mm.exec();
	cv::Scalar mean, stddev;
	cv::meanStdDev(image, mean, stddev);

	double 	maxval = 255;
	double 	thresh = mean[0] + 2 * stddev[0];
	cv::Mat thresholdedImg;
	cv::threshold(image, thresholdedImg, thresh, maxval, 0);
	//mm.setText("21");
	//mm.exec();
	cv::Mat im_floodfill = thresholdedImg.clone();
	cv::floodFill(im_floodfill, cv::Point(0, 0), cv::Scalar(255));
	cv::Mat im_floodfill_inv;
	//mm.setText("22");
	//mm.exec();
	cv::bitwise_not(im_floodfill, im_floodfill_inv);
	cv::Mat holeFilled = (thresholdedImg | im_floodfill_inv);
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(30, 30));
	cv::Mat closingImg;
	cv::morphologyEx(holeFilled, closingImg, cv::MORPH_CLOSE, element, cv::Point(-1, -1), 2);
	//mm.setText("3");
	//mm.exec();
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
	//mm.setText("4");
	//mm.exec();
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
int The_Offset = 20;
std::vector <cv::Mat>Images;
int ReturnOfMaxI()
{
	////QmessageBox mm;
	//mm.setText("5");
	//mm.exec();

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
	//mm.setText("6");
	//mm.exec();
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
	//mm.setText("7");
	//mm.exec();
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


	//mm.setText("8");
	//mm.exec();
	return max;



}




void MainWindow::Shift()
{


	QMessageBox mm;
	mm.setText(QString::number(The_Offset));
	//mm.exec();	
	//mm.exec();
	//mm.setText("SliderValue"+ QString::number(ui->verticalSlider_6->value()));
	//mm.exec();



	shiftCurve(elevenx, eleveny, ctrlShiftX, ctrlShiftY, ui->verticalSlider_3->value(), The_Offset);
	if (Shift_happened != 2)
	{
		Shift_happened = 1;

	}
	//mm.setText("ExitShift");
	//mm.exec();

	//Shift_Define = 1;
	//elevenx = std::copy(ctrlShiftX);
	
	if (ShiftHover1 == 0) 
	{
	
		TheDrawer();
		ShiftHover1 = 1;
	}
	else 
	{
		stateless = 1;
		TheOne(ctrlShiftX, ctrlShiftY);
		stateless = 0;

	}
	
	
}

class Point : public QGraphicsEllipseItem {
public:
	Point(QGraphicsItem *parent = nullptr) : QGraphicsEllipseItem(parent) {
		setRect(QRectF(-5, -5, 10, 10));
		QPen pen;
		pen.setCosmetic(true);
		pen.setWidth(7);
		pen.setColor(QColor(Qt::green));
		setPen(pen);
		QBrush brush ;
		brush.setStyle(Qt::SolidPattern);
		setBrush(brush);
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
		for (int i = 0; i <= 16; i++)
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
		//Shift_Define = 0;


		The_Offset = average_offset(skeletonGenerate(Images[ReturnOfMaxI()]));
		Shift_happened = 2;

		ShiftHover1 = 0;
		MainWindow().Shift();

		//TheDrawer();
		////QmessageBox r;
		//r.setText(QString::number(Point::y()));
		//r.exec();




		//myPath.quadTo(c1, endPoint);



	}
};







void MainWindow::ClustereedImagesSaver() 
{
	
	QMessageBox mr;
	//mr.exec();

	for (int i = 1;i < The_Offset;i++) 
	{
	
		Num_define = i;
		SaveImages = true;
		shiftCurve(elevenx, eleveny, ctrlShiftX, ctrlShiftY, i, The_Offset);
		if (Shift_happened != 2)
		{
			Shift_happened = 1;

		}
		//mm.setText("ExitShift");
		//mm.exec();

		//Shift_Define = 1;
		//elevenx = std::copy(ctrlShiftX);
		TheDrawer();
	
	
	
	






	}
}





void MainWindow::Volume(std::string x, int y) {
	//QmessageBox rr;
	//rr.setText(QString::fromStdString( x));
	//rr.exec();


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

	ui->graphicsView_5->setScene(Sceneeezer[ZEE]);
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
	//MisterArcClass.Scene_Paronama_Arc->setMode(Scenez::Mode(Scenez::DrawLine));
	MisterArcClass.Scene_Paronama_Image->setMode(Scenez::Mode(Scenez::PointsSelected));
	MisterArcClass.Scene_Sagitial->setMode(Scenez::Mode(Scenez::DrawLine));

	

}
void MainWindow::actionGroupClicked22() {
	
	MisterArcClass.SceneAxial->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Coronal->setMode(Scenez::Mode(Scenez::SelectObject));
	MisterArcClass.Scene_Curve_3Image->setMode(Scenez::Mode(Scenez::SelectObject));
	//MisterArcClass.Scene_Paronama_Arc->setMode(Scenez::Mode(Scenez::SelectObject));
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
	else if (event->key() == Qt::Key_L)
	{
		MisterArcClass.SceneAxial->clear();
		MisterArcClass.Scene_Coronal->clear();
		MisterArcClass.Scene_Sagitial->clear();
		MainWindow().onDrawSphere998Click();
		MainWindow().onDrawSphere3Click();
		MainWindow().onDrawSphere45Click();

	}

}





void MainWindow::onDrawSphere100Click() 
{

	

	Slider_Value = ui->verticalSlider_5->value();
	
	TheOne(elevenx,eleveny);
	cv::imwrite(picOFParonamaAccumiltaed, Accumilated);
	
	QPixmap Pic10001 = QPixmap(picOFParonamaAccumiltaed.c_str());
	//Pic10001.fill(Qt::black);

	Pic10001.scaled(ui->graphicsView_5->width(),ui->graphicsView_5->height(),Qt::KeepAspectRatio);
	
	//ui->graphicsView_5->setBackgroundBrush(Pic10001);


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

void MainWindow::MMO()
{

	QGraphicsScene * SceneMister = new QGraphicsScene(this);
	

	QPixmap TheAccumilatedFinal = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg");

	SceneMister->addPixmap(TheAccumilatedFinal);


	ui->graphicsView_5->setScene(SceneMister);



	
}


void TheOne(std::vector<double>TheElevenPointsX, std::vector<double>TheElevenPointsY)
{

	QMessageBox mss;
	mss.setText("1");
	//mss.exec();
	int pixel_value1 = 0, pixel_value2 = 0;
	image = cv::imread(Dicom_Fro_Size, CV_8UC1);
	image.setTo(cv::Scalar(0, 0, 0));


	tk::spline FunctionOfDraw(TheElevenPointsX, TheElevenPointsY);

	
	////QmessageBox bk;
	//bk.setText("");
	//bk.exec();
	

	//arc = cv::imread(Final_Arc_Image, 0);
	//arc.setTo(cv::Scalar(0, 0, 0));

	cv::Mat Sizer=cv::imread(Full_Path_Names[200], 0);

	N_operations = 0;
	Xstorers.clear();
	Ystorers.clear();
	for (int x = *std::min_element(TheElevenPointsX.begin(), TheElevenPointsX.end());x < *std::max_element(TheElevenPointsX.begin(), TheElevenPointsX.end()); x++)//To loop through all the pixels
	{
		

			Ystorers.push_back(x);
			Xstorers.push_back(FunctionOfDraw(x));
			N_operations++;
		
	}

	//QmessageBox kl;
	//kl.setText(QString::number(N_operations));
	//kl.exec();
	/*
	for (int y = 0;y < arc.rows; y++)//To loop through all the pixels
	{
		for (int x = 0; x < arc.cols; x++)
		{

			for (int i = 0;i < N_operations;i++) {
				if (x == Xstorers[i] && y == Ystorers[i]) 
				{
					arc.at<uchar>(y, x) = 255;
				}
			}

		}
	}

	*/

	mss.setText("2");
	//mss.exec();

	//cv::imshow("ARCER", arc);
	//cv::waitKey();

	if (stateless == 1) 
	{
		TheTwo();
	
	}
	else
	{
		THEONETWO(TheElevenPointsX, TheElevenPointsY);

	}
	
	mss.setText("CC");
	//mss.exec();

}

void THEONETWO(std::vector<double>TheElevenPointsX, std::vector<double>TheElevenPointsY)
{

	imageRED = cv::imread(Dicom_Fro_Size, CV_8UC1);
	imageRED2 = cv::imread(Dicom_Fro_Size, CV_8UC1);
	imageRED3 = cv::imread(Dicom_Fro_Size, CV_8UC1);

	imageRED.setTo(cv::Scalar(0, 0, 0));
	imageRED2.setTo(cv::Scalar(0, 0, 0));
	imageRED3.setTo(cv::Scalar(0, 0, 0));

	////QmessageBox bk;
	//bk.setText("1");
	//bk.exec();


	tk::spline FunctionOfDraw(TheElevenPointsX, TheElevenPointsY,tk::spline::cspline);


	

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
			if ((y) <= (-1 / FunctionOfDraw.deriv(1, Xstorers[Slider_Value]))*x + 1* (1/FunctionOfDraw.deriv(1, Xstorers[Slider_Value]))*Xstorers[Slider_Value]+ Ystorers[Slider_Value])
				//if(y==  x +100)
			{
				imageRED.at<uchar>(x, y) = 255;
			}
			if ((y) <= (-1 / FunctionOfDraw.deriv(1, Xstorers[Slider_Value+3]))*x + 1 * (1 / FunctionOfDraw.deriv(1, Xstorers[Slider_Value+3]))*Xstorers[Slider_Value+3] + Ystorers[Slider_Value+3])
				//if(y==  x +100)
			{
				imageRED2.at<uchar>(x, y) = 255;
			}

			if ((y) <= (-1 / FunctionOfDraw.deriv(1, Xstorers[Slider_Value+5]))*x + 1 * (1 / FunctionOfDraw.deriv(1, Xstorers[Slider_Value+5]))*Xstorers[Slider_Value+5] + Ystorers[Slider_Value+5])
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


			if ((y >= Ystorers[Slider_Value + 3] || x >= Xstorers[Slider_Value + 3]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}



			if ((y >= Ystorers[Slider_Value + 5] || x >= Xstorers[Slider_Value + 5]) && imageRED3.at<uchar>(x, y) == 255) {

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
			if ((y <= Ystorers[Slider_Value + 3] || x >= Xstorers[Slider_Value + 3]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}

			if ((y <= Ystorers[Slider_Value + 5] || x >= Xstorers[Slider_Value + 5]) && imageRED3.at<uchar>(x, y) == 255) {

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


			if ((y >= Ystorers[Slider_Value + 3] || x <= Xstorers[Slider_Value + 3]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfLess2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfLess2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}

			if ((y >= Ystorers[Slider_Value + 5] || x <= Xstorers[Slider_Value + 5]) && imageRED3.at<uchar>(x, y) == 255) {

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


			if ((y <= Ystorers[Slider_Value + 3] || x >= Xstorers[Slider_Value + 3]) && imageRED2.at<uchar>(x, y) == 255) {

				//if (x <= Arc.cols / 2) {
				DefinerOfYOfMORE2++;
				imageRED2.at<uchar>(x, y) = 255;
			}

			if (DefinerOfYOfMORE2 > 80)
			{
				imageRED2.at<uchar>(x, y) = 0;

			}



			if ((y <= Ystorers[Slider_Value + 5] || x >= Xstorers[Slider_Value + 5]) && imageRED3.at<uchar>(x, y) == 255) {

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
	Accumilated.setTo(cv::Scalar(0, 0, 0));
	cv::addWeighted(imageRED, 1,cv::imread(Full_Path_Names_Axial[302],0), 1, 0.0, Accumilated);
	cv::addWeighted(Accumilated, 1,imageRED2, 1, 0.0, Accumilated);
	cv::addWeighted(Accumilated, 1,imageRED3, 1, 0.0, Accumilated);
	cvtColor(Accumilated, Accumilated, CV_GRAY2RGB);

	if (ZEE != 0) 
	{
	
		cv::Mat big = inichializerofSize;
		cv::Mat Small = cv::imread(Final_Arc_Image);

		std::vector<int> XstorerSegma;
		std::vector<int> YstorerSegma;


		for (int y = 0;y < big.rows; y++)//To loop through all the pixels
		{
			for (int x = 0; x < big.cols; x++)
			{
				if (big.at<uchar>(x, y) >= 200)
				{

					XstorerSegma.push_back(x);
					YstorerSegma.push_back(y);

				}
			}
		}




		int changeinXbig = *std::max_element(XstorerSegma.begin(), XstorerSegma.end()) - *std::min_element(XstorerSegma.begin(), XstorerSegma.end());
		int changeinYbig = *std::max_element(YstorerSegma.begin(), YstorerSegma.end()) - *std::min_element(YstorerSegma.begin(), YstorerSegma.end());
		int minXbig = *std::min_element(XstorerSegma.begin(), XstorerSegma.end());
		int maxXbig = *std::max_element(XstorerSegma.begin(), XstorerSegma.end());
		int minYbig = *std::min_element(YstorerSegma.begin(), YstorerSegma.end());
		int maxYbig = *std::max_element(YstorerSegma.begin(), YstorerSegma.end());


		///////////////////////////////////////////
		XstorerSegma.clear();
		YstorerSegma.clear();

		for (int y = 0;y < big.rows; y++)//To loop through all the pixels
		{
			for (int x = 0; x < big.cols; x++)
			{
				if (Small.at<uchar>(x, y) >= 200)
				{

					XstorerSegma.push_back(x);
					YstorerSegma.push_back(y);

				}
			}
		}




		int changeinXsmall = *std::max_element(XstorerSegma.begin(), XstorerSegma.end()) - *std::min_element(XstorerSegma.begin(), XstorerSegma.end());
		int changeinYsmall = *std::max_element(YstorerSegma.begin(), YstorerSegma.end()) - *std::min_element(YstorerSegma.begin(), YstorerSegma.end());


		float ChangeX = (float)changeinXbig / (float)changeinXsmall;
		float ChangeY = (float)changeinYbig / (float)changeinYsmall;






		XstorerSegma.clear();
		YstorerSegma.clear();

		cv::Mat newimage;
		cv::resize(Small, newimage, cv::Size((int)round(600 * (ChangeY+0.1)), (int)round(600 * (ChangeX+0.1))), 1);

		for (int y = 0;y < big.rows; y++)//To loop through all the pixels
		{
			for (int x = 0; x < big.cols; x++)
			{
				if (newimage.at<uchar>(x, y) >= 200)
				{

					XstorerSegma.push_back(x);
					YstorerSegma.push_back(y);

				}
			}
		}




		int XMaxnewImage = *std::max_element(XstorerSegma.begin(), XstorerSegma.end());
		int YMaxnewImage = *std::max_element(YstorerSegma.begin(), YstorerSegma.end());

		int XMinnewImage = *std::min_element(XstorerSegma.begin(), XstorerSegma.end());
		int YMinnewImage = *std::min_element(YstorerSegma.begin(), YstorerSegma.end());


	



		cv::Mat cropped_image = newimage(cv::Range(YMinnewImage - minYbig + 45, YMinnewImage - minYbig + 645), cv::Range(XMinnewImage - minXbig-15, XMinnewImage - minXbig + 585));

		EmptyOne2 = cropped_image;
	
	}

	else
	{
	EmptyOne2 = cv::imread(Final_Arc_Image);

	}
	
	//cv::imshow("MMM", EmptyOne2);
	//cv::waitKey();
	cv::addWeighted(Accumilated, 1, EmptyOne2, 1, 0.0, Accumilated);

	Sceneeezer[ZEE]->clear();
	
	
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg", Accumilated);
	
	QPixmap TheAccumilatedFinal = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg");
	//QMessageBox mk;
	//mk.setText(QString::number(TheAccumilatedFinal.width()));
	//mk.exec();

	Sceneeezer[ZEE]->addPixmap(TheAccumilatedFinal);
	

	
	
	//add the 11 elipses 
	for (int i = 0; i <= 16;i++) {
		Point *Ellipse = new Point();

		
		Sceneeezer[ZEE]->addItem(Ellipse);
		Ellipse->setPos(elevenx[i], eleveny[i]);
		Ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);


	}

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

	//bk.setText("2");
	//bk.exec();
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
	//bk.setText("3");
	//bk.exec();
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

	//QmessageBox bk;
	//bk.setText("4");
	//bk.exec();


	for (int The_Blue_Definer = 0;The_Blue_Definer < 449;The_Blue_Definer++) {
		std::vector<int>gray_scale_storer;
		std::vector<int>gray_scale_storer_Paronama;


		cv::Mat The_Dicomear = cv::imread(fileNames[The_Blue_Definer], CV_8UC1);
		std::cout << std::to_string(The_Blue_Definer) << std::endl;

		cv::addWeighted(imageRED, 1, The_Dicomear, 1, 0.0, addedTogether);
		//cv::addWeighted(addedTogether, 1, arc, 1, 0.0, addedTogeth221);


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
	//bk.setText("5");
	//bk.exec();
	cv::imwrite(The_Miss_Paronam, Paronama);

	if (SaveImages) 
	{

		std::string MKSave = "G:\\MedicalDATA\\DICOM\\128602 - L  yz\\Paronama_ShiftImages\\ParonamaNum" + std::to_string(Num_define) + ".jpeg";
		cv::imwrite(MKSave, Paronama);
		SaveImages = false;
	
	
	
	
	}



	//bk.setText("5.1.0");
	//bk.exec();
	cv::imwrite(Supreme_Curve_Splitter, curveSplitter);
	//bk.setText("5.1.1");

	//bk.exec();
	
	picOFParonamaAccumiltaed = ("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Accumilated.jpeg");

	//bk.setText("5.1.2");
	//bk.exec();


	std::string ok1 = The_Miss_Paronam;
	QPixmap pic = QPixmap(ok1.c_str());
	MisterArcClass.Scene_Paronama_Image->clear();
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic);
	//bk.setText("5.2");
	//bk.exec();







	cv::Mat Filtered_paronama;
	alpha_slider = 0;
	cv::GaussianBlur(curveSplitter, Filtered, cv::Size(7, 7), 0);
	cv::GaussianBlur(Paronama, Filtered_paronama, cv::Size(7, 7), 0);
	ZDefiner++;
	KDestructor = 1;
	//bk.setText("6");
	//bk.exec();
}

//MainWindow TheMainWindowProblem;

int One_Time = 0;



int Mister_Min_in_Histogram = 0;
int Mister_Max_in_Histogram = 255;
int Mister_Contrast = 255;


std::vector< int> WherehistoPointX;
std::vector< int> WherehistoPointY;
int ThehoveredIndex_ofHis = 0;
float GraphToHistoX255(float TwoHundreadFivityFiveHisto, float zeroGraph, float MaxGraph, float ValueNeededX)
{

	return  ((ValueNeededX - zeroGraph)*(TwoHundreadFivityFiveHisto / (MaxGraph - zeroGraph)));


}

float FromZerotwofifty_ToX595(float TwoHundreadFivityFiveHisto, float zeroGraph, float MaxGraph,float ValueNeededX)
{

	float mkm = ((float)501.0 / 255);
	float mkm2 = mkm * ValueNeededX;
	return (mkm2 + (float)94.0);


}



class MisterPoint : public QGraphicsEllipseItem {
public:
	MisterPoint(QGraphicsItem *parent = nullptr) : QGraphicsEllipseItem(parent) {
		setRect(QRectF(-5, -5, 10, 10));

		QPen pen;
		pen.setColor(Qt::red);
		pen.setWidth(1);
		setPen(pen);
		setAcceptHoverEvents(true);
		ItemIsMovable*(true);


	}
protected:
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
		QPen pen;
		pen.setColor(Qt::green);
		pen.setWidth(2);
		setPen(pen);
		QGraphicsEllipseItem::hoverEnterEvent(event);
		PastXID = (MisterPoint::x());
		PastYID = (MisterPoint::y());
		for (int i = 0; i <= 10; i++)
		{
			if (PastXID == WherehistoPointX[i] && PastYID == WherehistoPointY[i])
			{
				ThehoveredIndex_ofHis = i;
			}


		}




	}
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {

		PastXID = (MisterPoint::x());
		PastYID = (MisterPoint::y());
		WherehistoPointX[ThehoveredIndex_ofHis] = PastXID;
		WherehistoPointY[ThehoveredIndex_ofHis] = PastYID;
		QMessageBox wk;
		wk.setText("X is" + QString::number(PastXID));
		//wk.exec();

		wk.setText("Y is" + QString::number(PastYID));
		//wk.exec();
		MainWindow().onDrawSphere998Click();
		MainWindow().onDrawSphere3Click();
		MainWindow().onDrawSphere45Click();

	
		//TheDrawer();
		////QmessageBox r;
		//r.setText(QString::number(Point::y()));
		//r.exec();




		//myPath.quadTo(c1, endPoint);



	}
};





















MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	//scene33{ new QGraphicsScene(this) },
	//view{ new ClickableMap(scene) },
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	std::vector<int>X1(11,0);
	std::vector<int>Y1(11,0);
	std::vector<int>X2(11,5);
	std::vector<int>Y2(11,5);

	QGraphicsView *zz = new QGraphicsView();
	zz->setBaseSize(QSize(500, 500));
	QGraphicsScene *mm = new QGraphicsScene();
	QPen pener;
	pener.setColor(Qt::black);
	pener.setWidth(10);
	QGraphicsItem* edgeDrawing = mm->addLine(1, 1,200, 200,pener);
	
	

	edgeDrawing->setZValue(1);
	mm->addItem(edgeDrawing);
	zz->setScene(mm);
	//zz->show();
	
	ui->verticalSlider_3->setRange(0, The_Offset);
	ui->verticalSlider_3->setValue((int)The_Offset / 2);
	if (One_Time == 0) {
		

		ui->verticalSlider->setRange(0, 450);
		ui->verticalSlider_2->setRange(0, 600);
		//ui->verticalSlider_3->setRange(0, 600);
		
		ui->verticalSlider_4->setRange(-8192, 0);
		ui->verticalSlider_6->setRange(0, 600);
		ui->verticalSlider_4->setMaximum(0);
		ui->verticalSlider_4->setValue(-4096);

		////QmessageBox rr;
		//rr.setText(QString::number());



		
		One_Time = 1;


		Slider6_Value = ui->verticalSlider_3->value();
		////QmessageBox kkk;

		//kkk.setText(QString::number(Slider6_Value));
		//kkk.exec();

		//TheDrawer();

		QObject::connect(ui->Ma2, &QPushButton::clicked, this, &MainWindow::MAX2);
		QObject::connect(ui->Ma3, &QPushButton::clicked, this, &MainWindow::MAX1);
		QObject::connect(ui->Ma4, &QPushButton::clicked, this, &MainWindow::MAX3);
		QObject::connect(ui->Ma1, &QPushButton::clicked, this, &MainWindow::MAX4);

		//ui->verticalSlider_6->setRange(0, (average_offset(skeletonGenerate(Images[ReturnOfMaxI()]))));
		//ui->verticalSlider_6->setValue((average_offset(skeletonGenerate(Images[ReturnOfMaxI()]))) / 2);

		connect(ui->actionNew_Project, SIGNAL(triggered()), this, SLOT(onDrawSphere2Click()));
		connect(ui->actionopen_project, SIGNAL(triggered()), this, SLOT(ClustereedImagesSaver()));
		connect(ui->actionCross_Sections_View, SIGNAL(triggered()), this, SLOT(onDrawSphere77Click()));
		connect(ui->actionParonama_View, SIGNAL(triggered()), this, SLOT(onDrawSphere88Click()));
		connect(ui->action3D_view, SIGNAL(triggered()), this, SLOT(onDrawSphere99Click()));
		connect(ui->actionDraw_Curve, SIGNAL(triggered()), this, SLOT(actionGroupClicked()));
		connect(ui->actionClose_Project, SIGNAL(triggered()), this, SLOT(actionGroupClicked22()));
		connect(ui->actionSave_Image, SIGNAL(triggered()), this, SLOT(SLICERER()));
		connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(MisterShowHistoGram()));


		//connect(ui->actionGrid, SIGNAL(triggered()), this, SLOT(Volume(dir3.toStdString(),0)));

		//connect(ui->actionAxial_Projection, SIGNAL(triggered()), this, SLOT(MIP()));
		//connect(ui->actionSagitial_Projection, SIGNAL(triggered()), this, SLOT(bone()));
		//connect(ui->actionCoronal_Projection, SIGNAL(triggered()), this, SLOT(muscle()));





		//connect(ui->actionShow_Help, SIGNAL(triggered()), this, SLOT(SLICERER()));


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
			this, &MainWindow::Shift);



		QObject::connect(ui->verticalSlider_5, &QSlider::valueChanged,
			this, &MainWindow::onDrawSphere100Click);

		QObject::connect(ui->verticalSlider_6, &QSlider::valueChanged,
			this, &MainWindow::onDrawSphere998Click);

		QObject::connect(ui->verticalSlider_4, &QSlider::valueChanged,
			this, &MainWindow::TweakTheIntensity);
		



		std::string sk_path = cv::samples::findFile(The_Skeletoner);
		cv::Mat skeleton = cv::imread(sk_path, cv::IMREAD_GRAYSCALE);

		std::vector <int >noXI;
		std::vector <int >noYI;
		//store white pixles
		for (int i = 0; i < skeleton.cols; i++)//To loop through all the pixels
		{
			for (int j = 0; j < skeleton.rows; j++)
			{
				if (skeleton.at<uchar>(j, i) >= 200)
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


		for (int i = 0; i <= 16; i++) {
			std::vector<int>::iterator csitX = (i* ((noXI.end() - 1) - noXI.begin()) / 16) + noXI.begin();
			std::vector<int>::iterator csitY = (i* ((noYI.end() - 1) - noYI.begin()) / 16) + noYI.begin();
			cv::Point cubicPoint = { *csitX ,  *csitY };
			elevenx.push_back(*csitX);
			eleveny.push_back(*csitY);
			//MyFilledCircle(grayBGR, cubicPoint);

		}















	}
}



void TheDrawer()
{
	Sceneeezer[ZEE]->clear();

	ZEE++;
	for (int i = 0; i < ctrlShiftX.size();i++) 
	{
	
		elevenx[i] = ctrlShiftX[i];
		eleveny[i] = ctrlShiftY[i];

	
	}


	MainWindow().Drawer();
	if (Shift_happened == 1) {
		TheOne(ctrlShiftX, ctrlShiftY);
		Shift_happened = 0;

	}
	else if (Shift_happened == 2)
	{
		TheOne(elevenx, eleveny);
		Shift_happened = 0;


	}



	



	/*
	OHMY = 0;
	
	MisterArcClass.Scene_Paronama_Arc = new Scenez();
	MainWindow().MIP();
	//MisterArcClass.Scene_Paronama_Image = new Scenez(MM);
	//MisterArcClass.Scene_Curve_3Image = new Scenez(MM);
	//MisterArcClass.SceneAxial = new Scenez(MM);


	// Then we put the pic best Image we got which was number 302 

	// set Pic99 to be The paronama image
	QPixmap pic99 = QPixmap(The_Miss_Paronam.c_str());

	//Set the pic of each scene according to its function

	//ui->graphicsView_5->setScene(MisterArcClass.Scene_Paronama_Arc);
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic99);
	//ui->graphicsView_7->setScene(MisterArcClass.Scene_Paronama_Image);
	//ui->graphicsView->setScene(MisterArcClass.SceneAxial);




	QBrush redBrush(Qt::red);
	QPen blackpin(Qt::red);
	blackpin.setWidth(2000);

	int Index_X = 0;
	int Index_Y = 0;
	

	QPainterPath myPath;
	//QMessageBox k;
	
	//k.setText("A");
	//k.exec();

	QMessageBox mmr;
	mmr.setText("The Bigest ctrlshiftx is "+QString::number((*max_element(ctrlShiftX.begin(), ctrlShiftX.end()))));
	///mmr.exec();

	mmr.setText("The Bigest ctrlshiftY is " + QString::number((*max_element(ctrlShiftY.begin(), ctrlShiftY.end()))));
	//mmr.exec();

	mmr.setText("The Bigest EleventhX is " + QString::number((*max_element(elevenx.begin(), elevenx.end()))));
	/////mmr.exec();

	





	for (int i = 0; i <= 8;i = i + 2) {

		myPath.moveTo(ctrlShiftX[i], ctrlShiftY[i]);

		myPath.cubicTo(QPoint(ctrlShiftX[i], ctrlShiftY[i]), QPoint(ctrlShiftX[i + 1], ctrlShiftY[i + 1]), QPoint(ctrlShiftX[i + 2], ctrlShiftY[i + 2]));

		//myPath.quadTo(c2, endPoint);
		MisterArcClass.Scene_Paronama_Arc->addPath(myPath);
	}


	mmr.setText("The Bigest EleventhY is " + QString::number((*max_element(eleveny.begin(), eleveny.end()))));
	//mmr.exec();

	//k.setText("B");
	//k.exec();



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
	QImage image(QSize(((*max_element(ctrlShiftX.begin(), ctrlShiftX.end())) - (*min_element(ctrlShiftX.begin(), ctrlShiftX.end()))), ((*max_element(ctrlShiftY.begin(), ctrlShiftY.end())) - (*min_element(ctrlShiftY.begin(), ctrlShiftY.end())))), QImage::Format_Grayscale8);  // Create the image with the exact size of the shrunk scene
	image.fill(Qt::transparent);                                              // Start all pixels transparent
	QPainter painter2(&image);

	painter2.setPen(blackpin);

	//k.setText("B1");
	//k.exec();


	myPath.moveTo(ctrlShiftX[0], ctrlShiftY[0]);
	myPath.cubicTo(QPoint(ctrlShiftX[0], ctrlShiftY[0]), QPoint(ctrlShiftX[0 + 1], ctrlShiftY[0 + 1]), QPoint(ctrlShiftX[0 + 2], ctrlShiftY[0 + 2]));


	painter2.drawPath(myPath);


	MisterArcClass.Scene_Paronama_Arc->render(&painter2);

	image.save("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg");


	//k.setText("B2");
	//k.exec();









	/*

	for (int i = 0; i <= 10;i++) {
		Point *Ellipse = new Point();
		MisterArcClass.Scene_Paronama_Arc->addItem(Ellipse);
		Ellipse->setPos(ctrlShiftX[i], ctrlShiftY[i]);
		Ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);


	}
	*/
	//k.setText("B3");
	//k.exec();
/*
	cv::Mat EmptyOne = cv::imread(The_Skeletoner, 0);
	EmptyOne.setTo(cv::Scalar(0, 0, 0));
	//cv::imshow("Hi", EmptyOne);
	cv::Mat cutted = cv::imread("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg", 0);
	cv::Mat dster;
	bitwise_not(cutted, dster);

	
	//k.setText(QString::number(ctrlShiftX[0]));
	//k.exec();
	//k.setText(QString::number(ctrlShiftX[1]));
	//k.exec();
	//k.setText(QString::number(ctrlShiftX[2]));
	//k.exec();
	//k.setText(QString::number(ctrlShiftX[3]));
	//k.exec();
	//k.setText(QString::number(ctrlShiftX[4]));
	//k.exec();

	//cv::imshow("Hi22", dster);
	for (int i = 0; i < dster.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < dster.rows; j++)
		{
			if (dster.at<uchar>(j, i) >= 200)
			{
				EmptyOne.at<uchar>(j + (*min_element(ctrlShiftY.begin(), ctrlShiftY.end())), i + (*min_element(ctrlShiftX.begin(), ctrlShiftX.end()))) = 255;
			}
		}
	}
	
	//cv::imshow("EmptyOne", EmptyOne);
	

	//cv::imshow("dster", EmptyOne);
	//cv::waitKey();
	//k.setText("B5");
	//k.exec();
	//cv::imshow("WellComeBack", EmptyOne);
	cv::cvtColor(EmptyOne, EmptyOne, CV_GRAY2RGB);
	cv::Mat element = cv::getStructuringElement(0,
		cv::Size(2 * 1 + 1, 2 * 1 + 1),
		cv::Point(1, 1));
	cv::dilate(EmptyOne, EmptyOne, element);
	cv::Mat mask;
	cv::inRange(EmptyOne, cv::Scalar(255, 255, 255), cv::Scalar(255, 255, 255), mask);
	EmptyOne.setTo(cv::Scalar(255, 0, 0), mask);
	
	cv::imwrite(Final_Arc_Image, EmptyOne);

	
	//k.setText("C");
	//k.exec();

	if (Shift_happened ==1) {
		TheOne(ctrlShiftX, ctrlShiftY);
		Shift_happened = 0;

	}
	else if(Shift_happened==2)
	{
		TheOne(elevenx, eleveny);
		Shift_happened = 0;


	}


	//k.setText("D");
	//k.exec();





	//MisterArcClass.Scene_Paronama_Arc->clear();

	MainWindow().MMO();







	



	*/




}

int maxer(int arr[], int n)
{
	int max = 0;
	for (int i = 0; i < n;i++)
	{

		if (arr[i] >= max)
		{
			max = arr[i];
		}




	}

	return max;

}

int miner(int arr[], int n)
{
	int min = 5000;
	for (int i = 0; i <= n;i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;

}





void MainWindow::Drawer()
{
	

	// First we initialize the scene of all Graphics scene 
	if (ZEE == 0) 
	{
		
		//MisterArcClass.Scene_Paronama_Arc = new Scenez(this);
		//Scenez *ArcScenee= new Scenez();
		MisterArcClass.Scene_Paronama_Arc = new QGraphicsScene();
		


		
		MisterArcClass.Scene_Paronama_Image = new Scenez(this);
		MisterArcClass.Scene_Curve_3Image = new Scenez(this);
		MisterArcClass.SceneAxial = new Scenez(this);
		
		//ui->graphicsView_5->setScene(MisterArcClass.Scene_Paronama_Arc);
		//Widx = MisterArcClass.Scene_Paronama_Arc->width();
		//Widy = MisterArcClass.Scene_Paronama_Arc->height();
		ui->graphicsView_7->setScene(MisterArcClass.Scene_Paronama_Image);
		ui->graphicsView->setScene(MisterArcClass.SceneAxial);



	}
	
	if (ZEE == 1) 
	{
	
		inichializerofSize = EmptyOne;

	}

	Sceneeezer.push_back(MisterArcClass.Scene_Paronama_Arc);

	ui->graphicsView_5->setScene(Sceneeezer[ZEE]);

	//MisterArcClass.Scene_Paronama_Arc->setSceneRect(QRectF(0, 0, Widx, Widy));
	
	


	// Then we put the pic best Image we got which was number 302 
	
	// set Pic99 to be The paronama image
	QPixmap pic99 = QPixmap(The_Miss_Paronam.c_str());

	//Set the pic of each scene according to its function
	
	MisterArcClass.Scene_Paronama_Image->addPixmap(pic99);
	


	QBrush redBrush(Qt::red);
	QPen blackpin(Qt::red);
	blackpin.setWidth(900);


	QPainterPath myPath;
	QPainterPath myPath77[9];
	//Set the path we need along the arc by cubic spline to each point +2 to make as 3 to be ablr to get 11

	for (int i = 0; i <= 14;i = i + 2) {

		myPath.moveTo(elevenx[i], eleveny[i]);
		myPath.cubicTo(QPoint(elevenx[i], eleveny[i]), QPoint(elevenx[i + 1], eleveny[i + 1]), QPoint(elevenx[i + 2], eleveny[i + 2]));
		Sceneeezer[ZEE]->addPath(myPath);



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

	Sceneeezer[ZEE]->clearSelection();                                                  // Selections would also render to the file
	//Scene->setSceneRect(Scene->sceneRect());                          // Re-shrink the scene to it's bounding contents
	QImage image(QSize(((*max_element(elevenx.begin(), elevenx.end())) - (*min_element(elevenx.begin(), elevenx.end()))), ((*max_element(eleveny.begin(), eleveny.end())) - (*min_element(eleveny.begin(), eleveny.end())))), QImage::Format_Grayscale8);  // Create the image with the exact size of the shrunk scene
	image.fill(Qt::transparent);                                              // Start all pixels transparent
	QPainter painter2(&image);

	painter2.setPen(blackpin);

	myPath.moveTo(elevenx[0], eleveny[0]);
	myPath.cubicTo(QPoint(elevenx[0], eleveny[0]), QPoint(elevenx[0 + 1], eleveny[0 + 1]), QPoint(elevenx[0 + 2], eleveny[0 + 2]));


	painter2.drawPath(myPath);


	Sceneeezer[ZEE]->render(&painter2);
	// Save the image needed for the Arc and which we will get next its data as the arc 
	image.save("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\Hi22.jpg");







	
	EmptyOne = cv::imread(The_Skeletoner, 0);
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



	cv::cvtColor(EmptyOne, EmptyOne, CV_GRAY2RGB);
	//cv::imshow("EmptyOne", EmptyOne);
	cv::Mat element = cv::getStructuringElement(0,
		cv::Size(2 * 1 + 1, 2 * 1 + 1),
		cv::Point(1, 1));
	cv::dilate(EmptyOne, EmptyOne, element);
	cv::Mat mask;
	cv::inRange(EmptyOne, cv::Scalar(255, 255, 255), cv::Scalar(255, 255, 255), mask);
	EmptyOne.setTo(cv::Scalar(255, 0, 0), mask);

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

	QMessageBox mr;
	//mr.exec();


	//Then we pass the function to arc generator
	if (ZEE == 0) 
	{
		TheOne(elevenx, eleveny);
	}
	//mr.exec();
	QPixmap Pic10001 = QPixmap(picOFParonamaAccumiltaed.c_str());
	//ui->graphicsView_5->setBackgroundBrush(Pic10001);
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
	ui->verticalSlider_5->setValue(96);


}

void MainWindow::MAX2() 
{
	if (ZO == 0) {
		ui->graphicsView_2->hide();
		ui->graphicsView_3->hide();
		ui->openGLWidget->hide();
		ui->verticalSlider_2->hide();
		ui->verticalSlider_6->hide();
		ui->verticalSlider_4->hide();
		ui->verticalSlider_3->hide();

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
		ui->verticalSlider_6->show();
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
		ui->verticalSlider_3->hide();


		//ui->verticalSlider_2->hide();
		ui->verticalSlider->hide();
		ui->verticalSlider_6->hide();
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


void MainWindow::onDrawSphere99Click()
{
	ui->pushButton->show();
	ui->pushButton_2->show();
	ui->pushButton_3->show();
	ui->pushButton_4->show();
	ui->pushButton_5->show();
	ui->pushButton_6->show();
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












}



/*
std::vector<std::string> DICOM_Names;
//std::vector<std::string> Full_Path_Names;
QString folderPath;
void MainWindow::openFolder() {
	folderPath = QFileDialog::getExistingDirectory(this,
		tr("Open Folder"),
		"C:\\",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  Directory = folderPath;
	QStringList DICOMS = Directory.entryList(QStringList() << "*.dcm", QDir::Files);
	foreach(QString Dicom, DICOMS)
	{
		DICOM_Names.push_back(Dicom.toUtf8().constData());
	}
	//need to do natural sort to sort the name of files correctly
	SI::natural::sort(DICOM_Names);
	for (int i = 0;i < DICOM_Names.size();i++) {
		Full_Path_Names.push_back(dir3.toStdString() + "//" + DICOM_Names[i]);
	}
}

*/









void MainWindow::onDrawSphere2Click()
{
	////QmessageBox kkk;
	//kkk.setText(QString::number(Slider6_Value));
	//kkk.exec();
	
	vtkNew<vtkNamedColors> colors;
	
	dir3 = QFileDialog::getExistingDirectory(this,
		tr("Open Directory"),
		"G:\MedicalData",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  TheDirectory = dir3;
	QStringList DICOMS = TheDirectory.entryList(QStringList() << "*.dcm", QDir::Files);

	//while (Slice_Definer != 450) {
	foreach(QString Dicom, DICOMS)
	{


		std::string the_path = dir3.toStdString() + "\\" + Dicom.toUtf8().constData();
		
		Full_Path_Names.push_back(the_path);
	



	}

	
















	std::string NewFolder = dir3.toStdString();
	int n = NewFolder.length();
	char *Beta=new char [n + 1];
	std::strcpy(Beta, NewFolder.c_str());
	int TheIndex = 0;

	////QmessageBox t;
	for (int i = NewFolder.size();i > 0;i--) 
	{
		
		
		if (Beta[i] == '/')
		{

			TheIndex = i;
			break;
		}
	}

	std::string TheFolderSpecified;
	
	TheFolderSpecified.append(NewFolder,0, TheIndex);

	
	TheCT_Sagitial = TheFolderSpecified + "\\" + "CT_Sagitial_Images";

	if (CreateDirectory(TheCT_Sagitial.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
	
	}
	


	TheCT_Coronal = TheFolderSpecified + "\\" + "CT_Coronal_Images";

	if (CreateDirectory(TheCT_Coronal.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
	
	}
	

	TheCT_Axial = TheFolderSpecified + "\\" + "CT_Axial_Images";

	if (CreateDirectory(TheCT_Axial.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{

	}

	constexpr unsigned int Dimension = 2;
	std::vector<std::string>Image_Names;
	/////////////////////////////////////////////
	/*
	std::vector<cv::Mat*> axialImages;
	std::vector<DicomImage*>DicomImages;
	for (int i = 0;i < Full_Path_Names.size();i++) {
		DicomImages.push_back(new DicomImage(Full_Path_Names[i].c_str()));
		cv::Mat* cvImg = new cv::Mat(int(DicomImages[i]->getWidth()), int(DicomImages[i]->getHeight()),
			CV_16U, (short*)DicomImages[i]->getOutputData(DicomImages[i]->getOutputDataSize()));
		axialImages.push_back(cvImg);

	}

	double max = axialImages[0]->at<ushort>(0, 0), min = axialImages[0]->at<ushort>(0, 1);
	for (int i = 0;i < axialImages.size();i++) {
		for (int j = 0;j < axialImages[0]->rows;j++) {
			for (int k = 0;k < axialImages[0]->cols;k++) {


				if (axialImages[i]->at<ushort>(j, k) < min)
					min = axialImages[i]->at<ushort>(j, k);
				else if (axialImages[i]->at<ushort>(j, k) > max)
					max = axialImages[i]->at<ushort>(j, k);
			}
		}
	}

	int Histogram[256];
	for (int i = 0;i < 256;i++) {
		Histogram[i] = 0;
	}
	for (int i = 0;i < axialImages.size();i++) {
		for (int j = 0;j < axialImages[0]->rows;j++) {
			for (int k = 0;k < axialImages[1]->cols;k++) {
				int pixelValue = axialImages[i]->at<ushort>(j, k);
				int grayvalue = int(((pixelValue - min) / (max - min))*(pow(2, 8) - 1));
				axialImages[i]->at<ushort>(j, k) = grayvalue;

				Histogram[grayvalue]++;
			}
		}
		axialImages[i]->convertTo(*axialImages[i], CV_8U);
		cv::imshow("dcm", *axialImages[i]);
		cv::waitKey(0);
	}
	*/

















	std::vector<DicomImage*>DicomImages;
	std::vector<cv::Mat*> axialImages;

	///////////////////////////////////////

	/*
	for (int i = 0;i < Full_Path_Names.size();i++) {
		DicomImages.push_back(new DicomImage(Full_Path_Names[i].c_str()));
		//cv::Mat* cvImg = 
		axialImages.push_back(new cv::Mat(int(DicomImages[i]->getWidth()), int(DicomImages[i]->getHeight()),
			CV_8U, (short*)DicomImages[i]->getOutputData(DicomImages[i]->getOutputDataSize())));

	}
	for (int i = 0; i < Full_Path_Names.size(); i++)
	{
		Image_Names.push_back("DCM" + std::to_string(i) + ".jpeg");
	}
	for (int i = 0;i < axialImages.size();i++) 
	{
		std::string location = TheCT_Axial + "\\" + Image_Names[i];
		const char* outputImage = location.c_str();
	
		cv::imwrite(outputImage, *axialImages[i]);

	}
	*/
	TheCT_Axial = "G:\\MedicalDATA\\DICOM\\128602 - L  yz\\Sample Images";

	
	for (int i = 0; i < Full_Path_Names.size(); i++)
	{
		Image_Names.push_back("DCM" + std::to_string(i) + ".jpeg");
	}
	/*
	for (int i = 0; i < Full_Path_Names.size();i++) {
		std::string location = TheCT_Axial +"\\"+ Image_Names[i];
		const char* outputImage = location.c_str();
	



		const char* inputImage = Full_Path_Names[i].c_str();


		using InputPixelType = float;
		using OutputPixelType = unsigned char;
		using InputImageType = itk::Image<InputPixelType, Dimension>;
		using OutputImageType = itk::Image<OutputPixelType, Dimension>;

		using ReaderType = itk::ImageFileReader<InputImageType>;
		ReaderType::Pointer reader = ReaderType::New();
		reader->SetFileName(inputImage);

		using RescaleType = itk::RescaleIntensityImageFilter<InputImageType, InputImageType>;
		RescaleType::Pointer rescale = RescaleType::New();
		rescale->SetInput(reader->GetOutput());
		rescale->SetOutputMinimum(0);
		rescale->SetOutputMaximum(itk::NumericTraits<OutputPixelType>::max());
		//rescale->Update();
		//itk::NumericTraits<OutputPixelType>::max()
		using FilterType = itk::CastImageFilter<InputImageType, OutputImageType>;
		FilterType::Pointer filter = FilterType::New();
		filter->SetInput(rescale->GetOutput());
		//filter->Update();

		using WriterType = itk::ImageFileWriter<OutputImageType>;
		WriterType::Pointer writer = WriterType::New();
		writer->SetFileName(outputImage);
		writer->SetInput(filter->GetOutput());

		try
		{
			writer->Update();
		}
		catch (itk::ExceptionObject& e)
		{
			std::cerr << "Error: " << e << std::endl;

		}
	}
	


	*/

	std::vector<cv::Mat>theImagerNumberOneMODCoronal;
	std::vector<cv::Mat>theImagerNumberOneMODSagitial;

	for (int i = 0;i < 600; i++)
	{

		cv::Mat theImagerNumberOneSagitial(450, 600, 0);
		cv::Mat theImagerNumberOneCoronal(600, 450, 0);


		theImagerNumberOneMODCoronal.push_back(theImagerNumberOneCoronal);
		theImagerNumberOneMODSagitial.push_back(theImagerNumberOneSagitial);


	}

	cv::Mat theFirstRower;
	
	QDir Directory_Axial = QString::fromStdString( TheCT_Axial);
	QStringList DICOMS_Axial = Directory_Axial.entryList(QStringList() << "*.jpeg", QDir::Files);



	int Slice_Definer_2 = 0;
	int Passed_Successful_Slice_2 = 0;
	while (Slice_Definer_2 < Full_Path_Names.size()) {
		foreach(QString Dicom_Axial, DICOMS_Axial)
		{


			//DICOM_Names_2.push_back(Dicom.toUtf8().constData());
			std::string the_path = TheCT_Axial + "\\" + Dicom_Axial.toUtf8().constData();
			std::string the_path_Sagitial = TheCT_Sagitial + "\\" + Dicom_Axial.toUtf8().constData();
			std::string the_path_Coronal = TheCT_Coronal + "\\" + Dicom_Axial.toUtf8().constData();

			if (Dicom_Axial.toUtf8().constData() == "DCM" + std::to_string(Slice_Definer_2) + ".jpeg")
			{
				Full_Path_Names_Axial.push_back(the_path);
				Full_Path_Names_Sagitial.push_back(the_path_Sagitial);
				Full_Path_Names_Coronal.push_back(the_path_Coronal);

				Passed_Successful_Slice_2++;
				Slice_Definer_2++;

			}

		}
	}








	for (int K = Full_Path_Names_Axial.size() - 1;K >= 0;K--)
	{

		theFirstRower = cv::imread(Full_Path_Names_Axial[K], 0);
		//cv::imshow("One",theFirstRower);
		//cv::waitKey();

		for (int j = 0; j <= 599; j++)//To loop through all the pixels
		{
			for (int i = 0; i < theFirstRower.cols; i++)
			{
				//if (j == R_DEFINER)
				//{
				//if (K >= j)
				//{
				theImagerNumberOneMODSagitial[599 - j].at<uchar>(K, i) = theFirstRower.at<uchar>(599 - j, i);
				theImagerNumberOneMODCoronal[599 - j].at<uchar>(i, K) = theFirstRower.at<uchar>(i, 599 - j);
				//}

				//}


			}
		}


	}





	for (int Z = 0;Z < theImagerNumberOneMODSagitial.size();Z++)
	{

		//REMOVE IF NOT SAGITAL NO NEED TO ROTATE
		double angle = -90;

		// get rotation matrix for rotating the image around its center in pixel coordinates
		cv::Point2f center((theImagerNumberOneMODCoronal[Z].cols - 1) / 2.0, (theImagerNumberOneMODCoronal[Z].rows - 1) / 2.0);
		cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
		// determine bounding rectangle, center not relevant
		cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), theImagerNumberOneMODCoronal[Z].size(), angle).boundingRect2f();
		// adjust transformation matrix
		rot.at<double>(0, 2) += bbox.width / 2.0 - theImagerNumberOneMODCoronal[Z].cols / 2.0;
		rot.at<double>(1, 2) += bbox.height / 2.0 - theImagerNumberOneMODCoronal[Z].rows / 2.0;

		cv::Mat dst;
		cv::warpAffine(theImagerNumberOneMODCoronal[Z], dst, rot, bbox.size());
		//cv::imwrite("rotated_im.png", dst);
		cv::flip(dst, dst, 1);

		cv::imwrite( TheCT_Coronal + "\\"+"DCM"+ std::to_string(Z) + ".jpeg", dst);
		cv::imwrite(TheCT_Sagitial + "\\" + "DCM" + std::to_string(Z) + ".jpeg", theImagerNumberOneMODSagitial[Z]);

	}
	
	The_Offset = average_offset(skeletonGenerate(Images[ReturnOfMaxI()]));

	WherehistoPointX.push_back(FromZerotwofifty_ToX595(255, 94, 595, 0));
	WherehistoPointY.push_back(430);

	//Max
	WherehistoPointX.push_back(FromZerotwofifty_ToX595(255, 94, 595, 255));
	WherehistoPointY.push_back(430);

	//Contrast
	WherehistoPointX.push_back(FromZerotwofifty_ToX595(255, 94, 595, 100));
	WherehistoPointY.push_back(100);


	QMessageBox mk;
	//mk.exec();


	Drawer();
	//mk.exec();


}
void MainWindow::onDrawSphere3Click()
{

	
	std::string ok1 = Full_Path_Names_Axial[ui->verticalSlider->value()];

	cv::Mat rrt1 = cv::imread(Full_Path_Names_Axial[ui->verticalSlider->value()], 0);
	rrt1.convertTo(rrt1, -1, (float)WherehistoPointX[2] * (float)2.2 / 595, 0);

	for (int i = 0; i < rrt1.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < rrt1.rows; j++)
		{
			if (rrt1.at<uchar>(j, i) >= (int)GraphToHistoX255(255.0, 94, 595, WherehistoPointX[1]))
			{
				rrt1.at<uchar>(j, i) = 0;
			}
		}
	}

	QMessageBox mkk;
	mkk.setText("min is "+QString::number(WherehistoPointX[0]));
	//mkk.exec();

	mkk.setText("max is " + QString::number(WherehistoPointX[1]));
	//mkk.exec();


	cv::threshold(rrt1, rrt1, GraphToHistoX255(255.0,94,595,WherehistoPointX[0]),255 ,3);
	cv::Mat zzr1;
	cv::Size zz1 (ui->graphicsView->width(),ui->graphicsView->height());
	cv::resize(rrt1,zzr1 ,zz1, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New.jpeg",zzr1);

	QPixmap pic1 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New.jpeg");
	pic1.scaled(MisterArcClass.SceneAxial->width(), MisterArcClass.SceneAxial->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	
	////QmessageBox r;
	QString Z = QString::fromStdString(ok1);
	//r.setText(Z);
	//r.exec();

	//ui->graphicsView->setBackgroundBrush(pic);
	//ui->graphicsView->setAutoFillBackground(true);
	MisterArcClass.SceneAxial->clear();
	MisterArcClass.SceneAxial->addPixmap(pic1);
	ui->graphicsView->setScene(MisterArcClass.SceneAxial);

	QRectF rc(QPoint(0, 0), pic1.size());
	ui->graphicsView->fitInView(rc, Qt::KeepAspectRatio);

}


void MainWindow::onDrawSphere45Click() {
	

	MisterArcClass.Scene_Sagitial = new Scenez(this);
	std::string ok1 = Full_Path_Names_Sagitial[ui->verticalSlider_2->value()];

	cv::Mat rrt2 = cv::imread(Full_Path_Names_Sagitial[ui->verticalSlider_2->value()], 0);
	rrt2.convertTo(rrt2, -1, (float)WherehistoPointX[2] * (float)2.2 / 595, 0);



	for (int i = 0; i < rrt2.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < rrt2.rows; j++)
		{
			if (rrt2.at<uchar>(j, i) >= (int)GraphToHistoX255(255.0, 94, 595, WherehistoPointX[1]))
			{
				rrt2.at<uchar>(j, i) = 0;
			}
		}
	}






	cv::threshold(rrt2, rrt2, GraphToHistoX255(255.0, 94, 595, WherehistoPointX[0]), 255, 3);
	cv::Mat zzr2;
	cv::Size zz2(ui->graphicsView_2->width(), ui->graphicsView_2->height());
	cv::resize(rrt2, zzr2, zz2, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New2.jpeg", zzr2);
	QPixmap pic2 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New2.jpeg");
	MisterArcClass.Scene_Sagitial->addPixmap(pic2);
	ui->graphicsView_2->setScene(MisterArcClass.Scene_Sagitial);
	
	QRectF rc(QPoint(0,0),pic2.size());
	ui->graphicsView_2->fitInView( rc , Qt::KeepAspectRatio);

	
}

void MainWindow::onDrawSphere998Click() {
	MisterArcClass.Scene_Coronal = new Scenez(this);
	std::string ok1 = Full_Path_Names_Coronal[ui->verticalSlider_6->value()];
	cv::Mat rrt3 = cv::imread(Full_Path_Names_Coronal[ui->verticalSlider_6->value()], 0);
	rrt3.convertTo(rrt3, -1, (float)WherehistoPointX[2]* (float)2.2/595, 0);
	for (int i = 0; i < rrt3.cols; i++)//To loop through all the pixels
	{
		for (int j = 0; j < rrt3.rows; j++)
		{
			if (rrt3.at<uchar>(j, i) >= (int)GraphToHistoX255(255.0, 94, 595, WherehistoPointX[1]))
			{
				rrt3.at<uchar>(j, i) = 0;
			}
		}
	}


	cv::threshold(rrt3, rrt3, GraphToHistoX255(255.0, 94, 595, WherehistoPointX[0]), 255, 3);
	cv::Mat zzr3;
	cv::Size zz3(ui->graphicsView_3->width(), ui->graphicsView_3->height());
	cv::resize(rrt3, zzr3, zz3, 0, 0, cv::INTER_CUBIC);
	cv::imwrite("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New3.jpeg", zzr3);

	

	QPixmap pic3 = QPixmap("C:\\Users\\EGYPT_LAPTOP\\Desktop\\OffscreesnRun\\New3.jpeg");


	//ui->graphicsView->setBackgroundBrush(pic);
	//ui->graphicsView->setAutoFillBackground(true);
	MisterArcClass.Scene_Coronal->addPixmap(pic3);
	ui->graphicsView_3->setScene(MisterArcClass.Scene_Coronal);
	QRectF rc(QPoint(0, 0), pic3.size());
	ui->graphicsView_3->fitInView(rc, Qt::KeepAspectRatio);

}




void MisterShowHistoGram_Alpha() 
{

	





	/*
	int Histogram[256];
	std::vector<DicomImage*>DicomImages;
	std::vector<cv::Mat*> axialImages;


	for (int i = 0;i < Full_Path_Names.size();i++) {
		DicomImages.push_back(new DicomImage(Full_Path_Names[i].c_str()));
		//cv::Mat* cvImg = 
		axialImages.push_back(new cv::Mat(int(DicomImages[i]->getWidth()), int(DicomImages[i]->getHeight()),
			CV_16U, (short*)DicomImages[i]->getOutputData(16)));


	}
	//cv::imshow("Jiii2", axialImages[1]);
	//cv::imshow("Jiii3", axialImages[2]);
	//::imshow("Jiii4", axialImages[3]);

	

	double max = axialImages[1]->at<ushort>(0, 0), min = axialImages[1]->at<ushort>(0, 1);
	for (int i = 1;i < axialImages.size();i++) {
		for (int j = 0;j < axialImages[1]->rows;j++) {
			for (int k = 0;k < axialImages[1]->cols;k++) {
				if (axialImages[i]->at<ushort>(j, k) < min)
					min = axialImages[i]->at<ushort>(j, k);
				else if (axialImages[i]->at<ushort>(j, k) > max)
					max = axialImages[i]->at<ushort>(j, k);
			}

		}
	}

	//mkr.exec();

	for (int i = 0;i < 256;i++) {
		Histogram[i] = 0;
	}
	for (int i = 0;i < axialImages.size();i++) {
		for (int j = 0;j < axialImages[1]->rows;j++) {
			for (int k = 0;k < axialImages[1]->cols;k++) {
				int pixelValue = axialImages[i]->at<uchar>(j, k);
				int grayvalue = int(((pixelValue - min) / (max - min))*(pow(2, 8) - 1));
				axialImages[i]->at<uchar>(j, k) = grayvalue;
				Histogram[grayvalue]++;
			}
		}
	}
	*/
	
	//cv::imshow("Jiii", axialImages[15]);
	//QMessageBox Mkr;
	//Mkr.setText(QString::number(Histogram[255]));
	//Mkr.exec();

	std::vector<int>Histogram;
	std::vector<cv::Mat>AxialImages;
	for (int i = 0; i < 256;i++) 
	{
	
		Histogram.push_back(0);
	}

	for (int i = 0; i < Full_Path_Names_Axial.size();i++) 
	{

		AxialImages.push_back(cv::imread(Full_Path_Names_Axial[i], 0));
	
	}

	
	for (int z = 0; z < AxialImages.size();z++) {
		for (int y = 0; y < AxialImages[z].rows; y++)//To loop through all the pixels
		{
			for (int x = 0; x < AxialImages[z].cols; x++)
			{
				Histogram[AxialImages[z].at<uchar>(x, y)]++;
			}
		}
	}


	QtCharts::QSplineSeries *series = new QtCharts::QSplineSeries();
	series->setName("spline");
	

	for (int i = 1; i < Histogram.size();i++) {


		series->append(i, Histogram[i]);
		
	}


	//*series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
	QtCharts::QChart *chart = new QtCharts::QChart();
	chart->legend()->hide();
	chart->addSeries(series);
	chart->setTitle("Simple spline chart example");
	chart->createDefaultAxes();

	

	//chart->axes(Qt::Vertical).first()->setRange(0, maxeeer);
	//chart->axes(Qt::Horizontal).first()->setRange(0, 255 );

	QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	//QWidget *wdg = new QWidget;
	//wdg->show();
	//chartView->show();
	QGraphicsScene * OhMyHisto= new QGraphicsScene();
	QGraphicsView *Scenevieweeer = new QGraphicsView();
	QMainWindow *window779= new QMainWindow;
	QRectF rc(QPoint(0, 0), window779->size());
	
	chart->resize(Scenevieweeer->size());
	OhMyHisto->addItem(chart);
	OhMyHisto->setSceneRect(rc);
	
	Scenevieweeer->setScene(OhMyHisto);
	Scenevieweeer->fitInView(rc, Qt::KeepAspectRatio);

	
	window779->resize(400, 300);


	//QHBoxLayout *m_layout = new QHBoxLayout();
	//window779->centralWidget()->setLayout(m_layout);

	//QPushButton * button = new QPushButton("Apply");
	
	//button->setFixedSize(20, 20);
	//QObject::connect(button, SIGNAL(triggered()), window779, SLOT(onButtonClicked()));
	//Min

	
	QMessageBox rr;
	//rr.exec();

	
	for (int i = 0; i <= 2;i++) {
		MisterPoint *Ellipse = new MisterPoint();
		OhMyHisto->addItem(Ellipse);
		Ellipse->setPos(WherehistoPointX[i], WherehistoPointY[i]);
		Ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
		Ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);


	}
	
	window779->setCentralWidget(Scenevieweeer);
	//rr.exec();
	//m_layout->addWidget(button);
	//int argc2 ;
	//char * argv2[5];
	

	//QApplication app2(argc2,argv2);
	window779->show();
	//app2.exec();











}
void MainWindow::MisterShowHistoGram()
{
	
	MisterShowHistoGram_Alpha();
}

void onButtonClicked() 
{
	QMessageBox rr;
	//rr.exec();


}


int TheVolType = 0;



std::string welldoe;
double TheLightIntensity = 4096;
int PasserK = 0;
//std::string welldoe;
QString dir;
int zerrrrro = 0;


void MainWindow::SLICERER()
{
	int count = 1;
	char* dirname = NULL;
	double opacityWindow = 4096;
	double opacityLevel = 2048;
	int blendType = TheVolType;
	int clip = 0;
	double reductionFactor = 1.0;
	double frameRate = 60.0;
	char* fileName = 0;
	int fileType = 0;

	bool independentComponents = true;

	if (PasserK == 0) {
		dir = QFileDialog::getExistingDirectory(this,
			tr("Open Directory"),
			"G:\MedicalData",
			QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

		QDir  TheDirectory = dir;
		welldoe = dir.toStdString();
		PasserK = 1;
	}
	std::string theadder = "-DICOM";
	int argc = 3;
	const char * argv[2];
	argv[1] = theadder.c_str();
	argv[2] = welldoe.c_str();


	if (!strcmp(argv[count], "?"))
	{


	}
	else if (!strcmp(argv[count], "-DICOM"))
	{
		size_t size = strlen(argv[count + 1]) + 1;
		dirname = new char[size];
		snprintf(dirname, size, "%s", argv[count + 1]);
	}
	else if (!strcmp(argv[count], "-MIP"))
	{
		opacityWindow = atof(argv[count + 1]);
		opacityLevel = atof(argv[count + 2]);
		blendType = 0;
		count += 3;
	}

	else if (!strcmp(argv[count], "-CT_Skin"))
	{
		blendType = 3;
		count += 1;
	}
	else if (!strcmp(argv[count], "-CT_Bone"))
	{
		blendType = 4;
		count += 1;
	}
	else if (!strcmp(argv[count], "-CT_Muscle"))
	{
		blendType = 5;
		count += 1;
	}

	else
	{
		cout << "Unrecognized option: " << argv[count] << endl;
		cout << endl;
		//PrintUsage();
		exit(EXIT_FAILURE);
	}

	vtkNew<vtkNamedColors> colors;
	vtkNew<vtkRenderer> renderer2;
	vtkNew<vtkRenderWindow> renWin;
	renWin->AddRenderer(renderer2);
	vtkNew<vtkRenderWindowInteractor> iren;
	iren->SetRenderWindow(renWin);
	iren->SetDesiredUpdateRate(frameRate / (1 + clip));

	iren->GetInteractorStyle()->SetDefaultRenderer(renderer2);
	vtkSmartPointer<vtkAlgorithm> reader;
	vtkSmartPointer<vtkImageData> input;

	vtkNew<vtkDICOMImageReader> dicomReader;
	dicomReader->SetDirectoryName(dir.toUtf8().constData());
	dicomReader->Update();
	input = dicomReader->GetOutput();
	reader = dicomReader;

	int dim[3];
	input->GetDimensions(dim);
	vtkNew<vtkImageResample> resample;

	resample->SetInputConnection(reader->GetOutputPort());
	resample->SetAxisMagnificationFactor(0, reductionFactor);
	resample->SetAxisMagnificationFactor(1, reductionFactor);
	resample->SetAxisMagnificationFactor(2, reductionFactor);


	vtkNew<vtkVolume> volume;

	vtkNew<vtkFixedPointVolumeRayCastMapper> mapper;


	mapper->SetInputConnection(resample->GetOutputPort());


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

	if (zerrrrro == 0) {
		QMessageBox trr;
		trr.setText(QString::number(0.5 * opacityWindow));
	}

	switch (blendType)
	{
		// MIP
		// Create an opacity ramp from the window and level values.
		// Color is white. Blending is MIP.
	case 0:
		colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0);


		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			TheLightIntensity, 1.0);



		mapper->SetBlendModeToMaximumIntensity();

		break;

	case 1:
		colorFun->AddRGBSegment(opacityLevel - 0.5 * opacityWindow, 0.0, 0.0, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0, 1.0, 1.0);
		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0);
		mapper->SetBlendModeToComposite();
		property->ShadeOff();
		break;

	case 2:
		colorFun->AddRGBSegment(0.0, 1.0, 1.0, 1.0, 255.0, 1.0, 1.0, 1.0);
		opacityFun->AddSegment(opacityLevel - 0.5 * opacityWindow, 0.0,
			opacityLevel + 0.5 * opacityWindow, 1.0);
		mapper->SetBlendModeToComposite();
		property->ShadeOn();
		break;

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

	// Set the default window size
	renWin->SetSize(600, 600);
	renWin->SetWindowName("FixedPointVolumeRayCastMapperCT");
	//renWin->Render();

	// Add the volume to the scene
	renderer2->AddVolume(volume);

	renderer2->ResetCamera();
	renderer2->SetBackground(colors->GetColor3d("0").GetData());

	auto camera = renderer2->GetActiveCamera();
	camera->SetPosition(56.8656, -297.084, 78.913);
	//camera->SetFocalPoint(109.139, 120.604, 63.5486);
	camera->SetViewUp(-0.00782421, -0.0357807, -0.999329);
	//camera->SetDistance(421.227);
	//camera->SetClippingRange(146.564, 767.987);




	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	vtkNew<vtkInteractorStyleImage> style;


	QMessageBox r;
	r.setText("0");
	//r.exec();
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_4= (vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New());

	vtkSmartPointer<vtkRenderer> mRenderer= (vtkSmartPointer<vtkRenderer>::New());
	vtkSmartPointer<QVTKInteractor> mInteractor= (vtkSmartPointer<QVTKInteractor>::New());
	vtkSmartPointer<vtkInteractorStyle> mInteractorStyle= (vtkSmartPointer<vtkInteractorStyle>::New());
	r.setText("1");
	//r.exec();
	//mRenderWindow_4(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New());

	//mRenderer(vtkSmartPointer<vtkRenderer>::New()),
	//mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
	//mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())

	ui->openGLWidget->SetRenderWindow(mRenderWindow_4);
	mInteractor->Initialize();
	// Set the background color 
	mRenderer->SetBackground(0, 0, 0);

	renderWindowInteractor->SetInteractorStyle(style);

	renderWindowInteractor->SetRenderWindow(ui->openGLWidget->GetRenderWindow());

	renderWindowInteractor->Initialize();

	mRenderer->SetBackground(
		colors->GetColor3d("LightSlateGray").GetData());
	mRenderWindow_4->SetSize(600, 300);
	mRenderWindow_4->AddRenderer(renderer2);
	mRenderWindow_4->SetInteractor(mInteractor);

	mRenderWindow_4->Render();

	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	mRenderer->ResetCamera();


	renderWindowInteractor->Start();


	ui->openGLWidget->SetRenderWindow(renWin);

}


void MainWindow::ChangeASLICERER()
{

	TheVolType = 0;

	SLICERER();


}
void MainWindow::ChangeSKESLICERER()
{

	TheVolType = 5;

	SLICERER();


}

void MainWindow::ChageABoneSLICERER()
{
	TheVolType = 3;

	SLICERER();


}

void MainWindow::TweakTheIntensity()
{

	TheLightIntensity = (ui->verticalSlider_4->value())*-1;
	SLICERER();

}


















MainWindow::~MainWindow()
{
    delete ui;
}

