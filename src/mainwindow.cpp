#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vtkImagePermute.h>
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



#include <vtkImageGradientMagnitude.h>

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
#include <vtkImageMagnitude.h>

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
#include <vtkImageProperty.h>
#include <vtkMedicalImageProperties.h>



#include "itkImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include "itkImageFileWriter.h"

#include <opencv2\opencv.hpp>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <gdcmImage.h>



#include <vtkAnnotatedCubeActor.h>
#include <vtkAxesActor.h>
#include <vtkCamera.h>
#include <vtkCaptionActor2D.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPlaneSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkPropAssembly.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTextProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkVectorText.h>
#include <vtkXMLPolyDataReader.h>

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>





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

	vtkSmartPointer<vtkAxesActor>
		MakeAxesActor(std::array<double, 3>& scale,
			std::array<std::string, 3>& xyzLabels);

	/**
	 * @param colors Used to set the colors of the cube faces.
	 * @return The annotated cube actor.
	 */
	vtkSmartPointer<vtkAnnotatedCubeActor>
		MakeAnnotatedCubeActor(vtkNamedColors* colors);

	/**
	 * @param scale Sets the scale and direction of the axes.
	 * @param xyzLabels Labels for the axes.
	 * @param colors Used to set the colors of the cube faces.
	 * @return The combined axes and annotated cube prop.
	 */
	vtkSmartPointer<vtkPropAssembly>
		MakeCubeActor(std::array<double, 3>& scale,
			std::array<std::string, 3>& xyzLabels, vtkNamedColors* colors);

	/**
	 * Make the traverse, coronal and saggital planes.
	 *
	 * @param colors Used to set the color of the planes.
	 * @return The planes actors.
	 */
	std::vector<vtkSmartPointer<vtkActor>> MakePlanesActors(vtkNamedColors* colors);

	/**
	 * Generate text to place on the planes.
	 * Careful placement is needed here.
	 * @return The text actors.
	 */
	std::vector<vtkSmartPointer<vtkActor>> AddTextToPlanes();


} // namespace

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
	mRenderWindow_2(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
	mRenderWindow_3(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
	mRenderWindow_4(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),

	mRenderer(vtkSmartPointer<vtkRenderer>::New()),
	mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
	mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())

	
	
{
	ui->setupUi(this);
	ui->horizontalSlider->setValue(0);
	ui->horizontalSlider_5->setRange(-8192,0);
	ui->horizontalSlider_5->setMaximum(0);
	ui->horizontalSlider_5->setValue(-4096);

	//mRenderWindow->AddRenderer(mRenderer);
	//mRenderWindow->SetInteractor(mInteractor);
	ui->openGLWidget->SetRenderWindow(mRenderWindow);
	ui->openGLWidget_2->SetRenderWindow(mRenderWindow_2);
	ui->openGLWidget_3->SetRenderWindow(mRenderWindow_3);
	ui->openGLWidget_4->SetRenderWindow(mRenderWindow_4);

	
	//mInteractor->SetInteractorStyle(mInteractorStyle);
	mInteractor->Initialize();
	
	// Set the background color 
	mRenderer->SetBackground(0, 0, 0);
	


	

  connect(ui->actionopen, SIGNAL(triggered()), this, SLOT(onDeleteThies()));
  connect(ui->actionbone, SIGNAL(triggered()), this, SLOT(ChageABoneSLICERER()));
  connect(ui->actionMIP, SIGNAL(triggered()), this, SLOT(ChangeASLICERER()));
  connect(ui->actionskeletal, SIGNAL(triggered()), this, SLOT(ChangeSKESLICERER()));

  connect(ui->actiongaussin, SIGNAL(triggered()), this, SLOT(Gaussin_Filter()));
  connect(ui->actionMedien, SIGNAL(triggered()), this, SLOT(onDrawSphereClick()));



	
	// Set the UI connections
	//QObject::connect(ui->actionopen, SIGNAL(QAction*), this, SLOT(onDrawSphere2Click()));


	QObject::connect(ui->horizontalSlider, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom);

	QObject::connect(ui->horizontalSlider_5, &QSlider::valueChanged,
		this, &MainWindow::TweakTheIntensity);





}

MainWindow::~MainWindow() {
	delete ui;
}

std::vector<std::string> DICOM_Names;

std::vector<std::string> Full_Path_Names;
 
int TheVolType=4;


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

	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	Filtered->GetProperty()->SetColorLevel(0.5 * (range[0] + range[1]));
	Filtered->GetProperty()->SetColorWindow(range[1] - range[0]);
	OriginalActor->GetProperty()->SetColorLevel(0.5 * (range[0] + range[1]));
	OriginalActor->GetProperty()->SetColorWindow(range[1] - range[0]);


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
	
	
	
	int y = ui->horizontalSlider->value();

	int n = Full_Path_Names[y].length();
	char  * converter= &Full_Path_Names[y][0];


	

	//QMessageBox msgBox;
	//char *converter = (Full_Path_Names[y]).c_str();
	QString z = QString::fromStdString(converter);
	//msgBox.setText(z);
	//msgBox.exec();
	
	reader->SetFileName(converter);
	reader->Update();
	
	

	





	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250

	
	
	vtkNew<vtkColorTransferFunction> colorFun;
	vtkNew<vtkPiecewiseFunction> opacityFun;
	// Create the property and attach the transfer functions
	//vtkNew<vtkImageProperty> property;
	//property->SetIndependentComponents(true);
	//property->SetColor(colorFun);
	//property->SetScalarOpacity(opacityFun);
	//property->SetInterpolationTypeToLinear();
	
	//vtkNew<vtkInteractorStyleImage>TheStyler;
	
	// Visualize
	vtkNew<vtkImageViewer2> imageViewer;
	
	//vtkNew<vtkAlgorithmOutput> theOutput;
	//theOutput.Get( = *(reader->GetOutputPort();
	//QMessageBox t;
	//t.setText( );



	imageViewer->SetInputConnection(reader->GetOutputPort());

	
	//imageViewer->SetSliceOrientationToXZ();
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	//imageViewer->SetColorLevel(0);
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	

	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	
	//TheStyler->SetPickColor(0);
	//renderWindowInteractor->SetInteractorStyle(TheStyler);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);

	//imageViewer->SetColorLevel(172);
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
	vtkNew<vtkColorTransferFunction> colorFun;
	vtkNew<vtkPiecewiseFunction> opacityFun;



	vtkNew<vtkIntArray> temperatue;
	int temp[4] = {	0,20,40,60};

	for each (int var in temp)
	{
		temperatue->InsertNextValue(var);

	}
	



	vtkNew<vtkImageActor> originalActor;
	originalActor->GetMapper()->SetBackground(2);
	




	originalActor->GetMapper()->SetInputConnection(reader->GetOutputPort());

	
	
	//cv::Mat image(int(DCM_image.getWidth()), int(DCM_image.getHeight()), CV_8U, (uchar*)DCM_image.getOutputData(8));


	vtkNew<vtkImageData>DATAER;
	
	
	//originalActor->GetProperty()->SetColorLevel(colorFun);
	//originalActor->GetProperty()->SetOpacity(opacityFun);

	vtkNew<vtkImageActor> filteredActor;
	filteredActor->GetMapper()->SetInputConnection(filter->GetOutputPort());
	
	//vtkNew<vtkProperty> property;
	//vtkNew<vtkImageProperty>Theproperity;
	
	//originalActor->SetProperty();
	//originalActor->GetProperty()->SetColorLevel(50);
	//originalActor->GetProperty()->SetColorLevel(50);

	//originalActor->SetProperty(Theproperity);
	
	
	// Define viewport ranges
	// (xmin, ymin, xmax, ymax)
	double originalViewport[4] = { 0.0, 0.0, 0.5, 1.0 };
	double filteredViewport[4] = { 0.5, 0.0, 1.0, 1.0 };
	vtkNew<vtkImageResliceMapper> imageResliceMapper;
	imageResliceMapper->SetInputData(image);
	
	vtkNew<vtkImageSlice> imageSlice;
	imageSlice->SetMapper(imageResliceMapper);

	auto image2 = reader->GetOutput();
	double *range = image2->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	filteredActor->GetProperty()->SetColorLevel(0.5 * (range[0] + range[1]));
	filteredActor->GetProperty()->SetColorWindow(range[1] - range[0]);
	originalActor->GetProperty()->SetColorLevel(0.5 * (range[0] + range[1]));
	originalActor->GetProperty()->SetColorWindow(range[1] - range[0]);

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
int PasserK = 0;
std::string welldoe;
QString dir;
int zerrrrro = 0;

double TheLightIntensity=4096;
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


			//QMessageBox teer;
			QString rooow = QString::fromStdString(welldoe);

			//teer.setText(rooow);
			//teer.exec();
			PasserK = 1;
		}
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
			// QMessageBox t;
			// t.setText("Okay");
			// t.exec();
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


		// QMessageBox t21;
		// t21.setText("Okay21");
		// t21.exec();

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
	   // QMessageBox t2;
	   // t2.setText("Okay2");
	   // t2.exec();
		vtkNew<vtkRenderWindowInteractor> iren;
		iren->SetRenderWindow(renWin);
		iren->SetDesiredUpdateRate(frameRate / (1 + clip));

		iren->GetInteractorStyle()->SetDefaultRenderer(renderer2);

		// QMessageBox t5;
		// t5.setText("Okay5");
		// t5.exec();
		 // Read the data
		vtkSmartPointer<vtkAlgorithm> reader;
		vtkSmartPointer<vtkImageData> input;

		//QMessageBox t4;
	   // t4.setText("Okay4");
		//t4.exec();


		vtkNew<vtkDICOMImageReader> dicomReader;
		dicomReader->SetDirectoryName(dir.toUtf8().constData());
		dicomReader->Update();
		input = dicomReader->GetOutput();
		reader = dicomReader;

		// QMessageBox t43;
		// t43.setText("Okay43");
		// t43.exec();



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
		// QMessageBox t3;
		// t3.setText("Okay3");
		// t3.exec();
		vtkNew<vtkFixedPointVolumeRayCastMapper> mapper;

		//QMessageBox t35656;
	   // t35656.setText("Okay3-1351");
	   // t35656.exec();
		mapper->SetInputConnection(resample->GetOutputPort());



		// Set the sample distance on the ray to be 1/2 the average spacing
		double spacing[3];
		//QMessageBox A1;
		//A1.setText("OkayA");
	   // A1.exec();
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
		// QMessageBox A2;
		 //A2.setText("OkayA2");
		// A2.exec();
		 // connect up the volume to the property and the mapper
		volume->SetProperty(property);
		volume->SetMapper(mapper);

		if (zerrrrro == 0) {
			QMessageBox trr;
			trr.setText(QString::number(0.5 * opacityWindow));
		}
		//trr.exec();
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
				TheLightIntensity, 1.0);



			mapper->SetBlendModeToMaximumIntensity();

			//property->SetUseClippedVoxelIntensity(2000);
			 //property->SetAmbient(100);
			 //property->SetDiffuse(100);
			 //property->SetShade(0.2);
			 //property->SetSpecular(100);
			 //property->SetSpecularPower(4000.0);
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

		renderWindowInteractor->SetRenderWindow(ui->openGLWidget_4->GetRenderWindow());
		//renderWindow->Render();
		renderWindowInteractor->Initialize();


		//filteredActor->RotateZ(90);
		//filteredActor->RotateX(90);

		mRenderer->SetBackground(
			colors->GetColor3d("LightSlateGray").GetData());
		mRenderWindow_4->SetSize(600, 300);
		mRenderWindow_4->AddRenderer(renderer2);
		mRenderWindow_4->SetInteractor(mInteractor);

		mRenderWindow_4->Render();
		//ui->openGLWidget->SetRenderWindow(renderWindow);
		renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
		mRenderer->ResetCamera();
		//mRenderWindow->Render();

		renderWindowInteractor->Start();


		ui->openGLWidget_4->SetRenderWindow(renWin);

	


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


vtkSmartPointer<vtkImageData> convertCVMatToVtkImageData(const cv::Mat &sourceCVImage, bool flipOverXAxis) {
	vtkSmartPointer<vtkImageData> outputVtkImage = vtkSmartPointer<vtkImageData>::New();
	double spacing[3] = { 1, 1, 1 };
	double origin[3] = { 0, 0, 0 };
	int extent[6] = { 0, sourceCVImage.cols - 1, 0, sourceCVImage.rows - 1, 0, 0 };
	auto numOfChannels = sourceCVImage.channels();
	outputVtkImage->SetSpacing(spacing);
	outputVtkImage->SetOrigin(origin);
	outputVtkImage->SetExtent(extent);
	outputVtkImage->SetDimensions(sourceCVImage.cols, sourceCVImage.rows, 1);
	outputVtkImage->AllocateScalars(VTK_UNSIGNED_CHAR, numOfChannels);

	cv::Mat tempCVImage;
	if (flipOverXAxis) { // Normaly you should flip the image!
		cv::flip(sourceCVImage, tempCVImage, 0);
	}
	else {
		tempCVImage = sourceCVImage;
	}
	for (int imgHeightPos = 0; imgHeightPos < sourceCVImage.rows; ++imgHeightPos) {
		for (int imgWidthPos = 0; imgWidthPos < sourceCVImage.cols; ++imgWidthPos) {
			switch (numOfChannels) {
			case 1: {
				auto pixel = tempCVImage.at<unsigned char>(imgHeightPos, imgWidthPos);
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 0, pixel); //red
				break;
			}
			case 3: {
				auto pixel2 = tempCVImage.at<cv::Vec3b>(imgHeightPos, imgWidthPos);
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 0, pixel2[2]); //red
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 1, pixel2[1]); //green
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 2, pixel2[0]); //blue
				break;
			}
			case 4: {
				auto pixel3 = tempCVImage.at<cv::Vec4b>(imgHeightPos, imgWidthPos);
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 0, pixel3[2]); //red
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 1, pixel3[1]); //green
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 2, pixel3[0]); //blue
				outputVtkImage->SetScalarComponentFromDouble(imgWidthPos, imgHeightPos, 0, 3, pixel3[3]); //alpha
				break;
			}
			default:
				std::cout << "unknown number of channels" << std::endl;
			}
		}
	}
	outputVtkImage->Modified();
	return outputVtkImage;
}

void MainWindow::on_actionfile_triggered()
{
	QMessageBox r;
	r.setText("Try");
	r.exec();


}

void MainWindow::ChangeASLICERER() 
{

	TheVolType = 0;
	zerrrrro = 1;
	SLICERER();


}
void MainWindow::ChangeSKESLICERER()
{

	TheVolType = 5;
	zerrrrro = 1;
	SLICERER();


}

void MainWindow::ChageABoneSLICERER() 
{
	TheVolType = 3;
	zerrrrro = 1;
	SLICERER();


}

void MainWindow::TweakTheIntensity()
{
	
	TheLightIntensity = (ui->horizontalSlider_5->value())*-1;
	SLICERER();

}

void MainWindow::onDeleteThies() 
{

	QString inputFolderName = QFileDialog::getOpenFileName(
		this,
		"Open a Folder",
		"G:\MedicalData",
		tr("Dicom Images (*.stl)")
	);


	
	std::string fileName(inputFolderName.toUtf8().constData());

	vtkNew<vtkNamedColors> colors;

	// Create the rendering window, renderer, and interactive renderer.
	vtkNew<vtkRenderer> ren;
	vtkNew<vtkRenderWindow> renWin;
	renWin->SetSize(780, 780);
	renWin->AddRenderer(ren);
	vtkNew<vtkRenderWindowInteractor> iren;
	iren->SetRenderWindow(renWin);

	// Make an annotated cube actor with axes and then add it into an orientation
	// marker widget.
	// Three of these need to be made.

	// Right Posterior Superior
	std::array<std::string, 3> xyzLabels{ {"X", "Y", "Z"} };
	std::array<double, 3> scale{ {10.5, -1.5, 1.5} };
	auto axes = MakeCubeActor(scale, xyzLabels, colors);
	vtkNew<vtkOrientationMarkerWidget> om;
	om->SetOrientationMarker(axes);
	// Position upper left in the viewport.
	om->SetViewport(5.0, 0.8, 0.2, 1.0);
	om->SetInteractor(iren);
	om->EnabledOn();
	om->InteractiveOn();

	// Right, Anterior, Superior.
	std::array<double, 3> scale1{ {1.5, 1.5, 1.5} };
	auto axes1 = MakeCubeActor(scale1, xyzLabels, colors);
	vtkNew<vtkOrientationMarkerWidget> om1;
	om1->SetOrientationMarker(axes1);
	// Position lower left in the viewport.
	om1->SetViewport(0, 0, 0.2, 0.2);
	om1->SetInteractor(iren);
	om1->EnabledOn();
	om1->InteractiveOn();

	// Left, Posterior, Superior.
	std::array<double, 3> scale2{ {-1.5, -1.5, 1.5} };
	auto axes2 = MakeCubeActor(scale2, xyzLabels, colors);
	vtkNew<vtkOrientationMarkerWidget> om2;
	om2->SetOrientationMarker(axes2);
	// Position lower right in the viewport.
	om2->SetViewport(0.8, 0, 1.0, 0.2);
	om2->SetInteractor(iren);
	om2->EnabledOn();
	om2->InteractiveOn();

	// Finally create an annotated cube actor adding it into an orientation marker
	// widget.
	auto axes3 = MakeAnnotatedCubeActor(colors);
	vtkNew<vtkOrientationMarkerWidget> om3;
	om3->SetOrientationMarker(axes3);
	// Position upper right in the viewport.
	om3->SetViewport(0.8, 0.8, 1.0, 1.0);
	om3->SetInteractor(iren);
	om3->EnabledOn();
	om3->InteractiveOn();

	// Read in the model.
	vtkNew<vtkXMLPolyDataReader> reader;
	reader->SetFileName(fileName.c_str());
	reader->Update();

	vtkNew<vtkPolyDataMapper> humanMapper;
	humanMapper->SetInputConnection(reader->GetOutputPort());
	humanMapper->SetScalarModeToUsePointFieldData();
	humanMapper->SelectColorArray("Color");
	humanMapper->SetColorModeToDirectScalars();

	vtkNew<vtkActor> humanActor;
	humanActor->SetMapper(humanMapper);
	std::vector<double> bounds(6, 0);
	humanActor->GetBounds(&bounds[0]);
	std::vector<double>::iterator maxElt =
		std::max_element(bounds.begin(), bounds.end());
	// Scale the actor
	humanActor->SetScale(1.0 / *maxElt);
	ren->AddActor(humanActor);

	// Make the planes.
	auto actors = MakePlanesActors(colors);
	for (auto actor : actors)
	{
		ren->AddViewProp(actor);
	}

	// Label them.
	auto textActors = AddTextToPlanes();
	for (auto actor : textActors)
	{
		ren->AddViewProp(actor);
	}

	// Interact
	ren->SetBackground2(colors->GetColor3d("OldLace").GetData());
	ren->SetBackground(colors->GetColor3d("MistyRose").GetData());
	ren->GradientBackgroundOn();
	ren->ResetCamera();
	ren->GetActiveCamera()->Zoom(1.6);
	ren->GetActiveCamera()->SetPosition(-2.3, 4.1, 4.2);
	ren->GetActiveCamera()->SetViewUp(0.0, 0.0, 1.0);
	ren->ResetCameraClippingRange();
	renWin->Render();
	//  Call SetWindowName after renWin.Render() is called.
	renWin->SetWindowName("AnatomicalOrientation");

	iren->Initialize();
	iren->Start();







}

namespace {

	vtkSmartPointer<vtkAxesActor>
		MakeAxesActor(std::array<double, 3>& scale,
			std::array<std::string, 3>& xyzLabels)
	{
		vtkNew<vtkAxesActor> axes;
		axes->SetScale(scale[0], scale[1], scale[2]);
		axes->SetShaftTypeToCylinder();
		axes->SetXAxisLabelText(xyzLabels[0].c_str());
		axes->SetYAxisLabelText(xyzLabels[1].c_str());
		axes->SetZAxisLabelText(xyzLabels[2].c_str());
		axes->SetCylinderRadius(0.5 * axes->GetCylinderRadius());
		axes->SetConeRadius(1.025 * axes->GetConeRadius());
		axes->SetSphereRadius(1.5 * axes->GetSphereRadius());
		vtkTextProperty* tprop =
			axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty();
		tprop->ItalicOn();
		tprop->ShadowOn();
		tprop->SetFontFamilyToTimes();
		// Use the same text properties on the other two axes.
		axes->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->ShallowCopy(tprop);
		axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->ShallowCopy(tprop);
		return axes;
	}

	vtkSmartPointer<vtkAnnotatedCubeActor>
		MakeAnnotatedCubeActor(vtkNamedColors* colors)
	{
		// A cube with labeled faces.
		vtkNew<vtkAnnotatedCubeActor> cube;
		cube->SetXPlusFaceText("R");  // Right
		cube->SetXMinusFaceText("L"); // Left
		cube->SetYPlusFaceText("A");  // Anterior
		cube->SetYMinusFaceText("P"); // Posterior
		cube->SetZPlusFaceText("S");  // Superior/Cranial
		cube->SetZMinusFaceText("I"); // Inferior/Caudal
		cube->SetFaceTextScale(0.5);
		cube->GetCubeProperty()->SetColor(colors->GetColor3d("Gainsboro").GetData());

		cube->GetTextEdgesProperty()->SetColor(
			colors->GetColor3d("LightSlateGray").GetData());

		// Change the vector text colors.
		cube->GetXPlusFaceProperty()->SetColor(
			colors->GetColor3d("Tomato").GetData());
		cube->GetXMinusFaceProperty()->SetColor(
			colors->GetColor3d("Tomato").GetData());
		cube->GetYPlusFaceProperty()->SetColor(
			colors->GetColor3d("DeepSkyBlue").GetData());
		cube->GetYMinusFaceProperty()->SetColor(
			colors->GetColor3d("DeepSkyBlue").GetData());
		cube->GetZPlusFaceProperty()->SetColor(
			colors->GetColor3d("SeaGreen").GetData());
		cube->GetZMinusFaceProperty()->SetColor(
			colors->GetColor3d("SeaGreen").GetData());
		return cube;
	}

	vtkSmartPointer<vtkPropAssembly>
		MakeCubeActor(std::array<double, 3>& scale,
			std::array<std::string, 3>& xyzLabels, vtkNamedColors* colors)
	{
		// We are combining a vtk.vtkAxesActor and a vtk.vtkAnnotatedCubeActor
		// into a vtk.vtkPropAssembly
		vtkSmartPointer<vtkAnnotatedCubeActor> cube = MakeAnnotatedCubeActor(colors);
		vtkSmartPointer<vtkAxesActor> axes = MakeAxesActor(scale, xyzLabels);

		// Combine orientation markers into one with an assembly.
		vtkNew<vtkPropAssembly> assembly;
		assembly->AddPart(axes);
		assembly->AddPart(cube);
		return assembly;
	}

	vtkSmartPointer<vtkTransformPolyDataFilter>
		MakePlane(std::array<int, 2>& resolution, std::array<double, 3>& origin,
			std::array<double, 3>& point1, std::array<double, 3>& point2,
			std::array<double, 4>& wxyz, std::array<double, 3>& translate)
	{
		vtkNew<vtkPlaneSource> plane;
		plane->SetResolution(resolution[0], resolution[1]);
		plane->SetOrigin(origin.data());
		plane->SetPoint1(point1.data());
		plane->SetPoint2(point2.data());
		vtkNew<vtkTransform> trnf;
		trnf->RotateWXYZ(wxyz[0], wxyz[1], wxyz[2], wxyz[3]);
		trnf->Translate(translate.data());
		vtkNew<vtkTransformPolyDataFilter> tpdPlane;
		tpdPlane->SetTransform(trnf);
		tpdPlane->SetInputConnection(plane->GetOutputPort());
		return tpdPlane;
	}

	std::vector<vtkSmartPointer<vtkActor>> MakePlanesActors(vtkNamedColors* colors)
	{
		std::vector<vtkSmartPointer<vtkTransformPolyDataFilter>> planes;
		std::vector<vtkSmartPointer<vtkPolyDataMapper>> mappers;
		std::vector<vtkSmartPointer<vtkActor>> actors;

		// Parameters for a plane lying in the x-y plane.
		std::array<int, 2> resolution{ {10, 10} };
		std::array<double, 3> origin{ {0.0, 0.0, 0.0} };
		std::array<double, 3> point1{ {1, 0, 0} };
		std::array<double, 3> point2{ {0, 1, 0} };

		std::array<double, 4> wxyz0{ {0, 0, 0, 0} };
		std::array<double, 3> translate{ {-0.5, -0.5, 0} };
		std::array<double, 4> wxyz1{ {-90, 1, 0, 0} };
		std::array<double, 4> wxyz2{ {-90, 0, 1, 0} };
		planes.push_back(MakePlane(resolution, origin, point1, point2, wxyz0,
			translate)); // x-y plane
		planes.push_back(MakePlane(resolution, origin, point1, point2, wxyz1,
			translate)); // x-z plane
		planes.push_back(MakePlane(resolution, origin, point1, point2, wxyz2,
			translate)); // y-z plane
		for (size_t i = 0; i < planes.size(); ++i)
		{
			mappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());
			mappers[i]->SetInputConnection(planes[i]->GetOutputPort());
			actors.push_back(vtkSmartPointer<vtkActor>::New());
			actors[i]->SetMapper(mappers[i]);
		}
		actors[0]->GetProperty()->SetColor(
			colors->GetColor3d("SeaGreen").GetData()); // Transverse plane
		actors[1]->GetProperty()->SetColor(
			colors->GetColor3d("DeepSkyBlue").GetData()); // Coronal plane
		actors[2]->GetProperty()->SetColor(
			colors->GetColor3d("Tomato").GetData()); // Saggital plane
		return actors;
	}

	std::vector<vtkSmartPointer<vtkActor>> AddTextToPlanes()
	{
		std::vector<vtkSmartPointer<vtkActor>> textActors;
		std::array<double, 3> scale{ {0.04, 0.04, 0.04} };

		vtkNew<vtkVectorText> text1;
		text1->SetText("Transverse\nPlane\n\nSuperior\nCranial");
		vtkNew<vtkTransform> trnf1;
		trnf1->RotateZ(-90);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane1;
		tpdPlane1->SetTransform(trnf1);
		tpdPlane1->SetInputConnection(text1->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper1;
		textMapper1->SetInputConnection(tpdPlane1->GetOutputPort());
		vtkNew<vtkActor> textActor1;
		textActor1->SetMapper(textMapper1);
		textActor1->SetScale(scale.data());
		textActor1->AddPosition(0.4, 0.49, 0.01);
		textActors.push_back(textActor1);

		vtkNew<vtkVectorText> text2;
		text2->SetText("Transverse\nPlane\n\nInferior\n(Caudal)");
		vtkNew<vtkTransform> trnf2;
		trnf2->RotateZ(270);
		trnf2->RotateWXYZ(180, 0, 1, 0);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane2;
		tpdPlane2->SetTransform(trnf2);
		tpdPlane2->SetInputConnection(text2->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper2;
		textMapper2->SetInputConnection(tpdPlane2->GetOutputPort());
		vtkNew<vtkActor> textActor2;
		textActor2->SetMapper(textMapper2);
		textActor2->SetScale(scale.data());
		textActor2->AddPosition(0.4, -0.49, -0.01);
		textActors.push_back(textActor2);

		vtkNew<vtkVectorText> text3;
		text3->SetText("Sagittal\nPlane\n\nLeft");
		vtkNew<vtkTransform> trnf3;
		trnf3->RotateX(90);
		trnf3->RotateWXYZ(-90, 0, 1, 0);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane3;
		tpdPlane3->SetTransform(trnf3);
		tpdPlane3->SetInputConnection(text3->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper3;
		textMapper3->SetInputConnection(tpdPlane3->GetOutputPort());
		vtkNew<vtkActor> textActor3;
		textActor3->SetMapper(textMapper3);
		textActor3->SetScale(scale.data());
		textActor3->AddPosition(-0.01, 0.49, 0.4);
		textActors.push_back(textActor3);

		vtkNew<vtkVectorText> text4;
		text4->SetText("Sagittal\nPlane\n\nRight");
		vtkNew<vtkTransform> trnf4;
		trnf4->RotateX(90);
		trnf4->RotateWXYZ(-270, 0, 1, 0);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane4;
		tpdPlane4->SetTransform(trnf4);
		tpdPlane4->SetInputConnection(text4->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper4;
		textMapper4->SetInputConnection(tpdPlane4->GetOutputPort());
		vtkNew<vtkActor> textActor4;
		textActor4->SetMapper(textMapper4);
		textActor4->SetScale(scale.data());
		textActor4->AddPosition(0.01, -0.49, 0.4);
		textActors.push_back(textActor4);

		vtkNew<vtkVectorText> text5;
		text5->SetText("Coronal\nPlane\n\nAnterior");
		vtkNew<vtkTransform> trnf5;
		trnf5->RotateY(-180);
		trnf5->RotateWXYZ(-90, 1, 0, 0);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane5;
		tpdPlane5->SetTransform(trnf5);
		tpdPlane5->SetInputConnection(text5->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper5;
		textMapper5->SetInputConnection(tpdPlane5->GetOutputPort());
		vtkNew<vtkActor> textActor5;
		textActor5->SetMapper(textMapper5);
		textActor5->SetScale(scale.data());
		textActor5->AddPosition(0.49, 0.01, 0.20);
		textActors.push_back(textActor5);

		vtkNew<vtkVectorText> text6;
		text6->SetText("Coronal\nPlane\n\nPosterior");
		vtkNew<vtkTransform> trnf6;
		trnf6->RotateWXYZ(90, 1, 0, 0);
		vtkNew<vtkTransformPolyDataFilter> tpdPlane6;
		tpdPlane6->SetTransform(trnf6);
		tpdPlane6->SetInputConnection(text6->GetOutputPort());
		vtkNew<vtkPolyDataMapper> textMapper6;
		textMapper6->SetInputConnection(tpdPlane6->GetOutputPort());
		vtkNew<vtkActor> textActor6;
		textActor6->SetMapper(textMapper6);
		textActor6->SetScale(scale.data());
		textActor6->AddPosition(-0.49, -0.01, 0.3);
		textActors.push_back(textActor6);

		return textActors;
	}
}