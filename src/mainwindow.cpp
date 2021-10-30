#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qpainter.h>
#include <string>
#include <vtkInteractorStyleImage.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkImageNoiseSource.h>
#include <vtkImageMapper3D.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkImageData.h>
#include <vtkImageActor.h>
#include <vtkImageCast.h>
#include <vtkImageViewer.h>
#include <vtkImageMapper3D.h>
#include <vtkImageMedian3D.h>
#include <vtkStructuredGridGeometryFilter.h>
#include <vtkMultiBlockDataSet.h>
#include <vtkMultiBlockPLOT3DReader.h>
#include <vtkSTLReader.h>


#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSTLReader.h>
#include <vtkCamera.h>

#include <vtkInteractorStyleTrackballActor.h>



#include "vtkCommand.h"
#include "vtkImageActor.h"
#include "vtkImageData.h"
#include "vtkImageMapToColors.h"
#include "vtkImageMapper3D.h"
#include "vtkImageReader2.h"
#include "vtkImageReslice.h"
#include "vtkInformation.h"
#include "vtkInteractorStyleImage.h"
#include "vtkLookupTable.h"
#include "vtkMatrix4x4.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkStreamingDemandDrivenPipeline.h"



#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>

#include <vtkStringArray.h>





#include <vtkCamera.h>
#include <vtkColorTransferFunction.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkMetaImageReader.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPiecewiseFunction.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>






#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
// headers needed for this example
#include <vtkActor2D.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>

// needed to easily convert int to std::string
#include <sstream>
#include <vtkImageResliceMapper.h>

#include <vtkBoxWidget.h>
#include <vtkCamera.h>
#include <vtkColorTransferFunction.h>
#include <vtkCommand.h>
#include <vtkDICOMImageReader.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkImageData.h>
#include <vtkImageResample.h>
#include <vtkMetaImageReader.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPiecewiseFunction.h>
#include <vtkPlanes.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkXMLImageDataReader.h>

#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkMetaImageReader.h>


#define VTI_FILETYPE 1
#define MHA_FILETYPE 2


#include "vtkCamera.h"
#include "vtkColorTransferFunction.h"
#include "vtkCommand.h"
#include "vtkDataArray.h"
#include "vtkEncodedGradientShader.h"
#include "vtkFiniteDifferenceGradientEstimator.h"
#include "vtkFixedPointRayCastImage.h"
#include "vtkFixedPointVolumeRayCastCompositeGOHelper.h"
#include "vtkFixedPointVolumeRayCastCompositeGOShadeHelper.h"
#include "vtkFixedPointVolumeRayCastCompositeHelper.h"
#include "vtkFixedPointVolumeRayCastCompositeShadeHelper.h"
#include "vtkFixedPointVolumeRayCastMIPHelper.h"
#include "vtkGraphicsFactory.h"
#include "vtkImageData.h"
#include "vtkLight.h"
#include "vtkMath.h"
#include "vtkMultiThreader.h"
#include "vtkObjectFactory.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPlaneCollection.h"
#include "vtkPointData.h"
#include "vtkRayCastImageDisplayHelper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkSphericalDirectionEncoder.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkTimerLog.h"
#include "vtkTransform.h"
#include "vtkVolumeProperty.h"
#include "vtkVolumeRayCastSpaceLeapingImageFilter.h"

#include <cmath>
#include <exception>
#include <vtkDataSetMapper.h>


#include <vtkCamera.h>
#include <vtkColorTransferFunction.h>
#include <vtkContourValues.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkMetaImageReader.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkOpenGLGPUVolumeRayCastMapper.h>
#include <vtkPiecewiseFunction.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>




#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkImageMapToColors.h>
#include <vtkImageMapper3D.h>
#include <vtkLookupTable.h>
#include <vtkMetaImageReader.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkStripper.h>
#include <vtkVersion.h>
#include <vtkVolume16Reader.h>

#include <vtkContourFilter.h>
#include <vtkPolyDataNormals.h>


// vtkFlyingEdges3D was introduced in VTK >= 8.2
#if VTK_MAJOR_VERSION >= 9 || (VTK_MAJOR_VERSION >= 8 && VTK_MINOR_VERSION >= 2)
#define USE_FLYING_EDGES
#else
#undef USE_FLYING_EDGES
#endif

#ifdef USE_FLYING_EDGES
#include <vtkFlyingEdges3D.h>
#else
#include <vtkMarchingCubes.h>
#endif





namespace {
	void PrintUsage()
	{
		cout << "Usage: " << endl;
		cout << endl;
		cout << "  FixedPointVolumeRayCastMapperCT <options>" << endl;
		cout << endl;
		cout << "where options may include: " << endl;
		cout << endl;
		cout << "  -DICOM <directory>" << endl;
		cout << "  -VTI <filename>" << endl;
		cout << "  -MHA <filename>" << endl;
		cout << "  -DependentComponents" << endl;
		cout << "  -Clip" << endl;
		cout << "  -MIP <window> <level>" << endl;
		cout << "  -CompositeRamp <window> <level>" << endl;
		cout << "  -CompositeShadeRamp <window> <level>" << endl;
		cout << "  -CT_Skin" << endl;
		cout << "  -CT_Bone" << endl;
		cout << "  -CT_Muscle" << endl;
		cout << "  -FrameRate <rate>" << endl;
		cout << "  -DataReduction <factor>" << endl;
		cout << endl;
		cout << "You must use either the -DICOM option to specify the directory where"
			<< endl;
		cout << "the data is located or the -VTI or -MHA option to specify the path "
			"of a .vti file."
			<< endl;
		cout << endl;
		cout << "By default, the program assumes that the file has independent "
			"components,"
			<< endl;
		cout << "use -DependentComponents to specify that the file has dependent "
			"components."
			<< endl;
		cout << endl;
		cout << "Use the -Clip option to display a cube widget for clipping the "
			"volume."
			<< endl;
		cout << "Use the -FrameRate option with a desired frame rate (in frames per "
			"second)"
			<< endl;
		cout << "which will control the interactive rendering rate." << endl;
		cout << "Use the -DataReduction option with a reduction factor (greater than "
			"zero and"
			<< endl;
		cout << "less than one) to reduce the data before rendering." << endl;
		cout << "Use one of the remaining options to specify the blend function"
			<< endl;
		cout << "and transfer functions. The -MIP option utilizes a maximum intensity"
			<< endl;
		cout << "projection method, while the others utilize compositing. The"
			<< endl;
		cout << "-CompositeRamp option is unshaded compositing, while the other"
			<< endl;
		cout << "compositing options employ shading." << endl;
		cout << endl;
		cout << "Note: MIP, CompositeRamp, CompositeShadeRamp, CT_Skin, CT_Bone,"
			<< endl;
		cout << "and CT_Muscle are appropriate for DICOM data. MIP, CompositeRamp,"
			<< endl;
		cout << "and RGB_Composite are appropriate for RGB data." << endl;
		cout << endl;
		cout
			<< "Example: FixedPointVolumeRayCastMapperCT -DICOM CTNeck -MIP 4096 1024"
			<< endl;
		cout << endl;
	}
} // namespace

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
	mRenderer(vtkSmartPointer<vtkRenderer>::New()),
	mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
	mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())
	
{
	ui->setupUi(this);
	ui->horizontalSlider->setValue(200);
	
	
	//mRenderWindow->AddRenderer(mRenderer);
	//mRenderWindow->SetInteractor(mInteractor);
	ui->openGLWidget->SetRenderWindow(mRenderWindow);
	//mInteractor->SetInteractorStyle(mInteractorStyle);
	mInteractor->Initialize();
	
	// Set the background color 
	mRenderer->SetBackground(0, 0, 0);
	



	


	
	// Set the UI connections
	QObject::connect(ui->pushButton, &QPushButton::clicked,
		this, &MainWindow::onDrawSphereClick);

	QObject::connect(ui->pushButton_2, &QPushButton::clicked,
		this, &MainWindow::onDrawSphere2Click);

	QObject::connect(ui->pushButton_3, &QPushButton::clicked,
		this, &MainWindow::Gaussin_Filter);

	QObject::connect(ui->pushButton_4, &QPushButton::clicked,

		this, &MainWindow::OpenSTLER);
	
	
	QObject::connect(ui->pushButton_5, &QPushButton::clicked,
		this, &MainWindow::SLICERER);


	QObject::connect(ui->horizontalSlider, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom);





}

MainWindow::~MainWindow() {
	delete ui;
}

std::vector<std::string> DICOM_Names;

std::vector<std::string> Full_Path_Names;

void MainWindow::onDrawSphereClick() {
	// Create sphere

	
	vtkNew<vtkNamedColors> colors;

	// Verify input arguments
	
	vtkNew<vtkDICOMImageReader> reader;
	int y = ui->horizontalSlider->value();

	//QMessageBox msgBox;
	const char *converter = (Full_Path_Names[y]).c_str();
	QString z = QString::fromStdString(converter);
	//msgBox.setText(z);
	//msgBox.exec();

	reader->SetFileName(converter);
	reader->Update();


	vtkNew <vtkImageMedian3D> meanfilter;
	meanfilter->SetInputConnection(reader->GetOutputPort());
	meanfilter->SetKernelSize(3,3,1);
	meanfilter->Update();

	vtkNew<vtkImageActor>OriginalActor;
	OriginalActor->GetMapper()->SetInputConnection(reader->GetOutputPort());

	vtkNew<vtkImageActor> Filtered;
	Filtered->GetMapper()->SetInputConnection(meanfilter->GetOutputPort());
	// Define viewport ranges
  // (xmin, ymin, xmax, ymax)
	double leftViewport[4] = { 0.0, 0.0, 0.5, 1.0 };
	double rightViewport[4] = { 0.5, 0.0, 1.0, 1.0 };

	vtkNew<vtkRenderer> originalRenderer;
	originalRenderer->SetViewport(leftViewport);
	originalRenderer->AddActor(OriginalActor);
	originalRenderer->ResetCamera();
	originalRenderer->SetBackground(
		colors->GetColor3d("0").GetData());

	vtkNew<vtkRenderer> gradientMagnitudeRenderer;
	gradientMagnitudeRenderer->SetViewport(rightViewport);
	gradientMagnitudeRenderer->AddActor(Filtered);
	gradientMagnitudeRenderer->ResetCamera();
	gradientMagnitudeRenderer->SetBackground(
		colors->GetColor3d("0").GetData());


	mRenderWindow->SetSize(600, 300);
	mRenderWindow->AddRenderer(originalRenderer);
	mRenderWindow->AddRenderer(gradientMagnitudeRenderer);
	mRenderWindow->SetInteractor(mInteractor);

	mRenderWindow->Render();


	/*
	// Visualize
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->Render();
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	
	renderWindowInteractor->Start();
	
	*/


}



void MainWindow::onDrawSphere2Click()
{


	vtkNew<vtkNamedColors> colors;

	// Verify input arguments
	
	
	/*
	//QString inputFilename = QFileDialog::getOpenFileName(this, "open a file", "G:\MedicalDATA");
	QString inputFolderName = QFileDialog::getOpenFileName(
		this,
		"Open a Folder",
		"G:\MedicalData",
		tr("Dicom Images (*.dcm)")	
	);
	*/
	QString dir = QFileDialog::getExistingDirectory(this, 
		tr("Open Directory"), 
		"G:\MedicalData",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  TheDirectory = dir;
	QStringList DICOMS = TheDirectory.entryList(QStringList() << "*.dcm", QDir::Files);
	

	/*
	QMessageBox messagerrr;
	messagerrr.setText(dir);
	messagerrr.exec();
	*/


	foreach (QString Dicom, DICOMS)
	{
		DICOM_Names.push_back(Dicom.toUtf8().constData());
		std::string the_path = dir.toStdString() + "\\" + Dicom.toUtf8().constData();
		Full_Path_Names.push_back(the_path);
		
	}

	/*
	for(int i= 0; i<= 100;i++ )
	{
		int SIZER = DICOM_Names.size();
		QString y = QString::fromStdString(std::to_string( SIZER));
		QMessageBox msgBox;
		msgBox.setText( y );
		msgBox.exec();

	}
	*/
	ui->horizontalSlider->setRange(0, DICOM_Names.size());

	
	/*
	// Read all the DICOM files in the specified directory.
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetFileName(inputFolderName.toUtf8().constData());
	reader->Update();
	 
	

	// Visualize
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->Render();
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();

	renderWindowInteractor->Start();
	*/

}

void MainWindow::TweakTheDicom()
{
	double zeer[6];
	vtkNew<vtkDICOMImageReader> reader;
	
	//double wow = 0;
	//double * rour = &wow ;
	//reader->SetDataDirection(rour);
	//reader->GetDataByteOrder();
	auto x = reader->GetImageOrientationPatient();
	*(x + 0) = 0;
	*(x + 1) = 1;
	*(x + 2) = 0;
	*(x + 3) = 0;
	*(x + 4) = 0;
	*(x + 5) = -1;
	
	for (int i = 0; i < 6;i++)
	{

		zeer[i] = *(x + i);
		//QString rw = QString::number(zeer[i]);
		//QMessageBox t;
		//t.setText(rw);
		//t.exec();
	}
	
	
	int y = ui->horizontalSlider->value();

	

	//QMessageBox msgBox;
	const char *converter = (Full_Path_Names[y]).c_str();
	QString z = QString::fromStdString(converter);
	//msgBox.setText(z);
	//msgBox.exec();
	
	reader->SetFileName(converter);
	reader->Update();

	
	// Visualize
	vtkNew<vtkImageViewer2> imageViewer;
	
	//vtkNew<vtkAlgorithmOutput> theOutput;
	//theOutput.Get( = *(reader->GetOutputPort();
	//QMessageBox t;
	//t.setText( );

	imageViewer->SetInputConnection(reader->GetOutputPort());
	
	//imageViewer->SetSliceOrientationToXZ();
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->Render();
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();

	renderWindowInteractor->Start();
	

}

void MainWindow::Gaussin_Filter()
{
	float x[10];
	vtkNew<vtkDICOMImageReader> reader;
	
	auto ror=reader->GetPixelSpacing();
	
	//int j = 0;
	float zeerX[1000];
	float zeerY[1000];
	float zeerZ[1000];
	float changeer;
	std::string ZeerString[100];
	ZeerString[0] = "";
	for (int i = 0; i <1000 ; i++)
	{
		
		zeerX[i] = *(ror + ((3*i)));
		zeerY[i] = *(ror + ((3 * i) + 1));
		zeerZ[i] = *(ror + ((3 * i) + 2));

		//changeer = zeerX[i];
		//*(ror + ((3 * i))) = zeerZ[i];
		//*(ror + ((3 * i) + 2)) = changeer;

	}
	
	for (int i = 0; i < 100; i++)
	{
		
		//if (i % 10 == 0) { j++; }
		//else
		//{
			//ZeerString[0] = ZeerString[0].append (std::to_string(zeerX[i])) + " ";

		//}
		
	}
	
	
	//QMessageBox t;
	//QString eow = QString::fromStdString(ZeerString[0]);
	//t.setText(eow);
	//t.exec();
	
	vtkNew<vtkImageData> image;
	image->SetExtent(0, 9, 0, 9, 0, 0);
	image->AllocateScalars(VTK_INT, 1);
	int* pixel = static_cast<int*>(image->GetScalarPointer(0, 9, 0));
	vtkNew<vtkImageReslice> reslice;
	reslice->SetOutputExtent(0, 9, 0, 100, 0, 0);
	reslice->SetInputData(image);
	reslice->Update();
	
	
	int y = ui->horizontalSlider->value();

	//QMessageBox msgBox;
	const char *converter = (Full_Path_Names[y]).c_str();
	QString z = QString::fromStdString(converter);
	//msgBox.setText(z);
	//msgBox.exec();

	reader->SetFileName(converter);
	reader->Update();

	// Process the
	vtkNew<vtkImageCast> cast;
	cast->SetInputConnection(reader->GetOutputPort());
	cast->SetOutputScalarTypeToFloat();

	vtkNew<vtkImageGaussianSmooth> filter;
	filter->SetDimensionality(2);
	filter->SetInputConnection(cast->GetOutputPort());
	filter->SetStandardDeviations(4.0, 4.0);
	filter->SetRadiusFactors(2.0, 2.0);

	// Create actors
	vtkNew<vtkNamedColors> colors;

	vtkNew<vtkImageActor> originalActor;
	originalActor->GetMapper()->SetInputConnection(reader->GetOutputPort());

	vtkNew<vtkImageActor> filteredActor;
	filteredActor->GetMapper()->SetInputConnection(filter->GetOutputPort());

	// Define viewport ranges
	// (xmin, ymin, xmax, ymax)
	double originalViewport[4] = { 0.0, 0.0, 0.5, 1.0 };
	double filteredViewport[4] = { 0.5, 0.0, 1.0, 1.0 };
	vtkNew<vtkImageResliceMapper> imageResliceMapper;
	imageResliceMapper->SetInputData(image);
	
	vtkNew<vtkImageSlice> imageSlice;
	imageSlice->SetMapper(imageResliceMapper);

	;
	// Setup renderers
	vtkNew<vtkRenderer> originalRenderer;
	originalRenderer->SetViewport(originalViewport);
	originalRenderer->AddViewProp(imageSlice);
	originalRenderer->AddActor(originalActor);
	originalRenderer->ResetCamera();
	originalRenderer->SetBackground(colors->GetColor3d("0").GetData());

	vtkNew<vtkRenderer> filteredRenderer;
	filteredRenderer->SetViewport(filteredViewport);
	filteredRenderer->AddActor(filteredActor);
	filteredRenderer->ResetCamera();
	filteredRenderer->SetBackground(
	colors->GetColor3d("0").GetData());





	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->SetSize(600, 300);
	renderWindow->SetWindowName("GaussianSmooth");
	renderWindow->AddRenderer(originalRenderer);
	renderWindow->AddRenderer(filteredRenderer);

	

	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	vtkNew<vtkInteractorStyleImage> style;

	renderWindowInteractor->SetInteractorStyle(style);

	renderWindowInteractor->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	//renderWindow->Render();
	renderWindowInteractor->Initialize();

	
	//filteredActor->RotateZ(90);
	//filteredActor->RotateX(90);

	mRenderer->AddActor(filteredActor);
	mRenderer->SetViewport(filteredViewport);
	mRenderer->SetBackground(
	colors->GetColor3d("LightSlateGray").GetData());
	mRenderWindow->SetSize(600, 300);
	mRenderWindow->AddRenderer(originalRenderer);
	mRenderWindow->AddRenderer(filteredRenderer);
	mRenderWindow->SetInteractor(mInteractor);
	
	mRenderWindow->Render();
	//ui->openGLWidget->SetRenderWindow(renderWindow);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	mRenderer->ResetCamera();
	//mRenderWindow->Render();

	renderWindowInteractor->Start();


	ui->openGLWidget->SetRenderWindow(renderWindow);
	


	/*
	vtkNew<vtkImageViewer2> imageViewer2;
	
	
	

	imageViewer2->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	
	imageViewer2->GetRenderer()->ResetCamera();
	imageViewer2->Render();
	
	renderWindowInteractor->Start();
	*/





}
void MainWindow::OpenSTLER()
{
	vtkNew<vtkNamedColors> colors;


	QString inputFolderName = QFileDialog::getOpenFileName(
		this,
		"Open a Folder",
		"G:\MedicalData",
		tr("Dicom Images (*.stl)")
	);
	

	vtkNew<vtkSTLReader> reader;
	reader->SetFileName(inputFolderName.toUtf8().constData());
	
	reader->Update();

	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(reader->GetOutputPort());

	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	actor->GetProperty()->SetDiffuse(0.8);
	actor->GetProperty()->SetDiffuseColor(
	colors->GetColor3d("LightSteelBlue").GetData());
	actor->GetProperty()->SetSpecular(0.3);
	actor->GetProperty()->SetSpecularPower(60.0);

	vtkNew<vtkRenderer> renderer;
	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->AddRenderer(renderer);
	
	//ui->openGLWidget->SetRenderWindow(renderWindow);
	
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	renderWindowInteractor->SetRenderWindow(renderWindow);
	//vtkNew<vtkInteractorStyleTrackballActor> style;

	//renderWindowInteractor->SetInteractorStyle(style);

	//mRenderWindow->AddRenderer(renderer);
	vtkNew<vtkCamera> camera;
	camera->SetPosition(0, 0, 100);
	camera->SetFocalPoint(0, 0, 0);

	renderer->AddActor(actor);
	
	mRenderer->SetActiveCamera(camera);
	mRenderWindow->AddRenderer(renderer);

	renderer->SetBackground(colors->GetColor3d("0").GetData());
	mRenderer->SetBackground(colors->GetColor3d("0").GetData());

	
	
	renderWindow->Render();

	//ui->openGLWidget->SetRenderWindow(renderWindow);
	//renderWindowInteractor->Initialize();
	mRenderer->AddActor(actor);
	mRenderWindow->Render();
	//mRenderWindow->SetInteractor(renderWindowInteractor);
	renderWindowInteractor->Start();
	

	

	
}

void MainWindow::SLICERER()
{
	int count = 1;
	char* dirname = NULL;
	double opacityWindow = 4096;
	double opacityLevel = 2048;
	int blendType = 0;
	int clip = 0;
	double reductionFactor = 1.0;
	double frameRate = 10.0;
	char* fileName = 0;
	int fileType = 0;

	bool independentComponents = true;

	
	
	QString dir = QFileDialog::getExistingDirectory(this,
		tr("Open Directory"),
		"G:\MedicalData",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  TheDirectory = dir;
		
	std::string welldoe = dir.toStdString();

	 
	 QMessageBox teer;
	 QString rooow = QString::fromStdString(welldoe);
	 
	 teer.setText(rooow);
	 teer.exec();
	
	 //snprintf(dirname, Full_Path_Names.size(), "%s", dirname);
	

	// Create the renderer, render window and interactor
	// Parse the parameters

	

	 std::string theadder = "-DICOM";
	 int argc = 3;
	 const char * argv[2];
	 argv[1] = theadder.c_str();
	 argv[2] = welldoe.c_str();

	 
		 if (!strcmp(argv[count], "?"))
		 {
			 PrintUsage();
			 exit(EXIT_SUCCESS);
		 }
		 else if (!strcmp(argv[count], "-DICOM"))
		 {
			 QMessageBox t;
			 t.setText("Okay");
			 t.exec();
			 size_t size = strlen(argv[count + 1]) + 1;
			 dirname = new char[size];
			 snprintf(dirname, size, "%s", argv[count + 1]);
			 

			 //dirname = dir.toUtf8().constData();
			 
		 }
		 else if (!strcmp(argv[count], "-VTI"))
		 {
			 size_t size = strlen(argv[count + 1]) + 1;
			 fileName = new char[size];
			 fileType = VTI_FILETYPE;
			 snprintf(fileName, size, "%s", argv[count + 1]);
			 count += 2;
		 }
		 else if (!strcmp(argv[count], "-MHA"))
		 {
			 size_t size = strlen(argv[count + 1]) + 1;
			 fileName = new char[size];
			 fileType = MHA_FILETYPE;
			 snprintf(fileName, size, "%s", argv[count + 1]);
			 count += 2;
		 }
		 else if (!strcmp(argv[count], "-Clip"))
		 {
			 clip = 1;
			 count++;
		 }
		 else if (!strcmp(argv[count], "-MIP"))
		 {
			 opacityWindow = atof(argv[count + 1]);
			 opacityLevel = atof(argv[count + 2]);
			 blendType = 0;
			 count += 3;
		 }
		 else if (!strcmp(argv[count], "-CompositeRamp"))
		 {
			 opacityWindow = atof(argv[count + 1]);
			 opacityLevel = atof(argv[count + 2]);
			 blendType = 1;
			 count += 3;
		 }
		 else if (!strcmp(argv[count], "-CompositeShadeRamp"))
		 {
			 opacityWindow = atof(argv[count + 1]);
			 opacityLevel = atof(argv[count + 2]);
			 blendType = 2;
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
		 else if (!strcmp(argv[count], "-RGB_Composite"))
		 {
			 blendType = 6;
			 count += 1;
		 }
		 else if (!strcmp(argv[count], "-FrameRate"))
		 {
			 frameRate = atof(argv[count + 1]);
			 if (frameRate < 0.01 || frameRate > 60.0)
			 {
				 cout << "Invalid frame rate - use a number between 0.01 and 60.0"
					 << endl;
				 cout << "Using default frame rate of 10 frames per second." << endl;
				 frameRate = 10.0;
			 }
			 count += 2;
		 }
		 else if (!strcmp(argv[count], "-ReductionFactor"))
		 {
			 reductionFactor = atof(argv[count + 1]);
			 if (reductionFactor <= 0.0 || reductionFactor >= 1.0)
			 {
				 cout << "Invalid reduction factor - use a number between 0 and 1 "
					 "(exclusive)"
					 << endl;
				 cout << "Using the default of no reduction." << endl;
				 reductionFactor = 1.0;
			 }
			 count += 2;
		 }
		 else if (!strcmp(argv[count], "-DependentComponents"))
		 {
			 independentComponents = false;
			 count += 1;
		 }
		 else
		 {
			 cout << "Unrecognized option: " << argv[count] << endl;
			 cout << endl;
			 PrintUsage();
			 exit(EXIT_FAILURE);
		 }
	 
		 
		 QMessageBox t21;
		 t21.setText("Okay21");
		 t21.exec();
	 
	 // Create the renderer, render window and interactor
	 vtkNew<vtkNamedColors> colors;
	 vtkNew<vtkRenderer> renderer2;
	 vtkNew<vtkRenderWindow> renWin;
	 renWin->AddRenderer(renderer2);
	 
	 // Connect it all. Note that funny arithematic on the
	 // SetDesiredUpdateRate - the vtkRenderWindow divides it
	 // allocated time across all renderers, and the renderer
	 // divides it time across all props. If clip is
	 // true then there are two props
	 QMessageBox t2;
	 t2.setText("Okay2");
	 t2.exec();
	 vtkNew<vtkRenderWindowInteractor> iren;
	 iren->SetRenderWindow(renWin);
	 iren->SetDesiredUpdateRate(frameRate / (1 + clip));

	 iren->GetInteractorStyle()->SetDefaultRenderer(renderer2);
	 
	 QMessageBox t5;
	 t5.setText("Okay5");
	 t5.exec();
	 // Read the data
	 vtkSmartPointer<vtkAlgorithm> reader;
	 vtkSmartPointer<vtkImageData> input;
	 
	 QMessageBox t4;
	 t4.setText("Okay4");
	 t4.exec();
	
	 
		 vtkNew<vtkDICOMImageReader> dicomReader;
		 dicomReader->SetDirectoryName(dir.toUtf8().constData());
		 dicomReader->Update();
		 input = dicomReader->GetOutput();
		 reader = dicomReader;

		 QMessageBox t43;
		 t43.setText("Okay43");
		 t43.exec();

	 
	 
	 // Verify that we actually have a volume
	 int dim[3];
	 input->GetDimensions(dim);
	 
	
	 
	 vtkNew<vtkImageResample> resample;
	
		 resample->SetInputConnection(reader->GetOutputPort());
		 resample->SetAxisMagnificationFactor(0, reductionFactor);
		 resample->SetAxisMagnificationFactor(1, reductionFactor);
		 resample->SetAxisMagnificationFactor(2, reductionFactor);
	 

	 // Create our volume and mapper
	 vtkNew<vtkVolume> volume;
	 QMessageBox t3;
	 t3.setText("Okay3");
	 t3.exec();
	 vtkNew<vtkFixedPointVolumeRayCastMapper> mapper;

	 QMessageBox t35656;
	 t35656.setText("Okay3-1351");
	 t35656.exec();
		 mapper->SetInputConnection(resample->GetOutputPort());
	 
	

	 // Set the sample distance on the ray to be 1/2 the average spacing
	 double spacing[3];
	 QMessageBox A1;
	 A1.setText("OkayA");
	 A1.exec();
	 if (reductionFactor < 1.0)
	 {
		 resample->GetOutput()->GetSpacing(spacing);
	 }
	 else
	 {
		 input->GetSpacing(spacing);
	 }

	 //  mapper->SetSampleDistance( (spacing[0]+spacing[1]+spacing[2])/6.0 );
	 //  mapper->SetMaximumImageSampleDistance(10.0);

	 // Create our transfer function
	 vtkNew<vtkColorTransferFunction> colorFun;
	 vtkNew<vtkPiecewiseFunction> opacityFun;
	 // Create the property and attach the transfer functions
	 vtkNew<vtkVolumeProperty> property;
	 property->SetIndependentComponents(independentComponents);
	 property->SetColor(colorFun);
	 property->SetScalarOpacity(opacityFun);
	 property->SetInterpolationTypeToLinear();
	 QMessageBox A2;
	 A2.setText("OkayA2");
	 A2.exec();
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
	 camera->SetFocalPoint(109.139, 120.604, 63.5486);
	 camera->SetViewUp(-0.00782421, -0.0357807, -0.999329);
	 camera->SetDistance(421.227);
	 camera->SetClippingRange(146.564, 767.987);





	 vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	 vtkNew<vtkInteractorStyleImage> style;

	 renderWindowInteractor->SetInteractorStyle(style);

	 renderWindowInteractor->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	 //renderWindow->Render();
	 renderWindowInteractor->Initialize();


	 //filteredActor->RotateZ(90);
	 //filteredActor->RotateX(90);

	 mRenderer->SetBackground(
		 colors->GetColor3d("LightSlateGray").GetData());
	 mRenderWindow->SetSize(600, 300);
	 mRenderWindow->AddRenderer(renderer2);
	 mRenderWindow->SetInteractor(mInteractor);

	 mRenderWindow->Render();
	 //ui->openGLWidget->SetRenderWindow(renderWindow);
	 renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	 mRenderer->ResetCamera();
	 //mRenderWindow->Render();

	 renderWindowInteractor->Start();


	 ui->openGLWidget->SetRenderWindow(renWin);




	 // interact with data
	 //renWin->Render();

	 //iren->Start();
	

	 /*

	 vtkNew <vtkVolume16Reader > v16;
	 v16->SetDataDimensions(64, 64);
	 v16->SetImageRange(1, 93);
	 v16->SetDataByteOrderToLittleEndian();
	 v16->SetFilePrefix("headsq/quarter");
	 v16->SetDataSpacing(3.2, 3.2, 1.5);

	 vtkNew <vtkContourFilter > skinExtractor;
	 skinExtractor->SetInputConnection(v16->GetOutputPort());
	 skinExtractor->SetValue(0, 500);
	 vtkNew < vtkPolyDataNormals > skinNormals;
	 skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
	 skinNormals->SetFeatureAngle(60.0);
	 vtkNew <vtkPolyDataMapper > skinMapper;
	 skinMapper->SetInputConnection(skinNormals->GetOutputPort());
	 skinMapper->ScalarVisibilityOff();
	 vtkNew <vtkActor > skin;
	 skin->SetMapper(skinMapper);
	 skin->GetProperty()->SetDiffuseColor(
		 colors->GetColor3d("SkinColor").GetData());
	 vtkNew <vtkOutlineFilter > outlineData;
	 outlineData->SetInputConnection(v16->GetOutputPort());
	 vtkNew <vtkPolyDataMapper > mapOutline;
	 mapOutline->SetInputConnection(outlineData->GetOutputPort());
	 vtkNew <vtkActor > outline;
	 outline->SetMapper(mapOutline);
	 outline->GetProperty()->SetColor(
	 colors->GetColor3d("Black").GetData());
	 vtkNew <vtkCamera > aCamera;
	 aCamera->SetViewUp(0, 0, -1);
	 aCamera->SetPosition(0, 1, 0);
	 aCamera->SetFocalPoint(0, 0, 0);
	 aCamera->ComputeViewPlaneNormal();

	 renderer2->AddActor(outline);
	 renderer2->AddActor(skin);
	 renderer2->SetActiveCamera(aCamera);
	 renderer2->ResetCamera();
	 renderer2->SetBackground(
		 colors->GetColor3d("BkgColor").GetData());
	 aCamera->Dolly(1.5);
	 renWin->SetSize(640, 480);
	 renderer2->ResetCameraClippingRange();
	 // Initialize the event loop and then start it.
	 iren->Initialize();
	 iren->Start();


	 */


















	


}
