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







MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
    axialRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    coronalRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    sagittalRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    volumeRenderWiindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),

	mRenderer(vtkSmartPointer<vtkRenderer>::New()),
	mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
	mInteractorStyle(vtkSmartPointer<vtkInteractorStyle>::New())

	
	
{
	ui->setupUi(this);
    ui->axial_slider->setValue(0);
    ui->intensity_slider->setRange(-8192,0);
    ui->intensity_slider->setMaximum(0);
    ui->intensity_slider->setValue(-4096);
    ui->axial_view_widget->SetRenderWindow(axialRenderWindow);
    ui->coronal_view_widget->SetRenderWindow(coronalRenderWindow);
    ui->sagittal_view_widget->SetRenderWindow(sagittalRenderWindow);
    ui->volume_view_widget->SetRenderWindow(volumeRenderWiindow);
	mInteractor->Initialize();
	// Set the background color 
	mRenderer->SetBackground(0, 0, 0);
  connect(ui->actionopen, SIGNAL(triggered()), this, SLOT(open_view_dicom()));
  connect(ui->actionbone, SIGNAL(triggered()), this, SLOT(Bone_volume_render()));
  connect(ui->actionMIP, SIGNAL(triggered()), this, SLOT(mip_volume_render()));
  connect(ui->actionskeletal, SIGNAL(triggered()), this, SLOT(muscle_volume_render()));
  connect(ui->actiongaussin, SIGNAL(triggered()), this, SLOT(Gaussin_Filter()));
  connect(ui->actionMedien, SIGNAL(triggered()), this, SLOT(median_Filter()));




    QObject::connect(ui->axial_slider, &QSlider::valueChanged,
        this, &MainWindow::axial_slider_control);

    QObject::connect(ui->coronal_slider, &QSlider::valueChanged,
        this, &MainWindow::coronal_slider_control);

    QObject::connect(ui->sagittal_slider, &QSlider::valueChanged,
        this, &MainWindow::Sagittal_slider_control);

    QObject::connect(ui->intensity_slider, &QSlider::valueChanged,
        this, &MainWindow::intensity_control);





}

MainWindow::~MainWindow() {
	delete ui;
}

std::vector<std::string> DICOM_Names;

std::vector<std::string> Full_Path_Names;
 
int TheVolType=4;


void MainWindow::median_Filter() {
	
	vtkNew<vtkNamedColors> colors;

	
	vtkNew<vtkDICOMImageReader> reader;
    int y = ui->axial_slider->value();

	
	const char *converter = (Full_Path_Names[y]).c_str();
	QString z = QString::fromStdString(converter);
	
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


    axialRenderWindow->SetSize(600, 300);
    axialRenderWindow->AddRenderer(originalRenderer);
    axialRenderWindow->AddRenderer(gradientMagnitudeRenderer);
    axialRenderWindow->SetInteractor(mInteractor);

    axialRenderWindow->Render();

}

QString dir3;

void MainWindow::open_view_dicom()
{


	vtkNew<vtkNamedColors> colors;

	dir3= QFileDialog::getExistingDirectory(this, 
		tr("Open Directory"), 
		"G:\MedicalData",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  TheDirectory = dir3;
	QStringList DICOMS = TheDirectory.entryList(QStringList() << "*.dcm", QDir::Files);
	


	foreach (QString Dicom, DICOMS)
	{
		DICOM_Names.push_back(Dicom.toUtf8().constData());
		std::string the_path = dir3.toStdString() + "\\" + Dicom.toUtf8().constData();
		Full_Path_Names.push_back(the_path);
		
	}

	
    ui->axial_slider->setRange(0, DICOM_Names.size());
    ui->coronal_slider->setRange(0, DICOM_Names.size());
    ui->sagittal_slider->setRange(0, DICOM_Names.size());
    ui->volume_slider->setRange(0, DICOM_Names.size());

	// Read all the DICOM files in the specified directory.
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double * range = image->GetPointData()->GetScalars()->GetRange();
	vtkNew<vtkImageViewer2> imageViewer;
	vtkNew<vtkImageViewer2> imageViewer2;
	vtkNew<vtkImageViewer2> imageViewer3;
	imageViewer->SetSliceOrientationToXZ();
	imageViewer2->SetSliceOrientationToYZ();
	imageViewer3->SetSliceOrientationToXY();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	imageViewer2->SetInputConnection(reader->GetOutputPort());
	imageViewer3->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer2->SetupInteractor(mInteractor);
	imageViewer3->SetupInteractor(mInteractor);
    imageViewer->SetRenderWindow(ui->axial_view_widget->GetRenderWindow());
    imageViewer2->SetRenderWindow(ui->coronal_view_widget->GetRenderWindow());
    imageViewer3->SetRenderWindow(ui->sagittal_view_widget->GetRenderWindow());
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->Render();
	imageViewer2->Render();
	imageViewer3->Render();
	imageViewer->SetColorLevel(0.5*(range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	imageViewer2->SetColorLevel(0.5*(range[0] + range[1]));
	imageViewer2->SetColorWindow(range[1] - range[0]);
	imageViewer3->SetColorLevel(0.5*(range[0] + range[1]));
	imageViewer3->SetColorWindow(range[1] - range[0]);
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer2->GetRenderer()->ResetCamera();
	imageViewer3->GetRenderer()->ResetCamera();
	imageViewer->Render();
	imageViewer2->Render();
	imageViewer3->Render();
	renderWindowInteractor->Start();
}

void MainWindow::axial_slider_control()
{
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetSliceOrientationToXZ();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
    imageViewer->SetRenderWindow(ui->axial_view_widget->GetRenderWindow());
	imageViewer->Render();
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
    imageViewer->SetSlice(ui->axial_slider->value());
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	renderWindowInteractor->Start();
}


void MainWindow::coronal_slider_control()
{
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetSliceOrientationToYZ();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
    imageViewer->SetRenderWindow(ui->coronal_view_widget->GetRenderWindow());
	imageViewer->Render();
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);;
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
    imageViewer->SetSlice(ui->coronal_slider->value());
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	renderWindowInteractor->Start();
}

void MainWindow::Sagittal_slider_control()
{
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetSliceOrientationToXY();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
    imageViewer->SetRenderWindow(ui->sagittal_view_widget->GetRenderWindow());
	imageViewer->Render();
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
    imageViewer->SetSlice(ui->sagittal_slider->value());
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	renderWindowInteractor->Start();
}

void MainWindow::Gaussin_Filter()
{
	vtkNew<vtkDICOMImageReader> reader;
	vtkNew<vtkImageData> image;
	image->SetExtent(0, 9, 0, 9, 0, 0);
	image->AllocateScalars(VTK_INT, 1);
	int* pixel = static_cast<int*>(image->GetScalarPointer(0, 9, 0));
    int y = ui->axial_slider->value();
	const char *converter = (Full_Path_Names[y]).c_str();
	reader->SetFileName(converter);
	reader->Update();
	vtkNew<vtkImageCast> cast;
	cast->SetInputConnection(reader->GetOutputPort());
	cast->SetOutputScalarTypeToFloat();
	vtkNew<vtkImageGaussianSmooth> filter;
	filter->SetDimensionality(2);
	filter->SetInputConnection(cast->GetOutputPort());
	filter->SetStandardDeviations(4.0, 4.0);
	filter->SetRadiusFactors(2.0, 2.0);
	vtkNew<vtkNamedColors> colors;
	vtkNew<vtkImageActor> originalActor;
	originalActor->GetMapper()->SetBackground(2);
	originalActor->GetMapper()->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkImageActor> filteredActor;
	filteredActor->GetMapper()->SetInputConnection(filter->GetOutputPort());
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

	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	vtkNew<vtkInteractorStyleImage> style;
	renderWindowInteractor->SetInteractorStyle(style);
    renderWindowInteractor->SetRenderWindow(ui->axial_view_widget->GetRenderWindow());
	renderWindowInteractor->Initialize();
    axialRenderWindow->SetSize(600, 300);
    axialRenderWindow->AddRenderer(originalRenderer);
    axialRenderWindow->AddRenderer(filteredRenderer);
    axialRenderWindow->SetInteractor(mInteractor);
    axialRenderWindow->Render();
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	mRenderer->ResetCamera();
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
		camera->SetFocalPoint(109.139, 120.604, 63.5486);
		camera->SetViewUp(-0.00782421, -0.0357807, -0.999329);
		camera->SetDistance(421.227);
		camera->SetClippingRange(146.564, 767.987);

		vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
		vtkNew<vtkInteractorStyleImage> style;

		renderWindowInteractor->SetInteractorStyle(style);

        renderWindowInteractor->SetRenderWindow(ui->volume_view_widget->GetRenderWindow());

		renderWindowInteractor->Initialize();

		mRenderer->SetBackground(
			colors->GetColor3d("LightSlateGray").GetData());
        volumeRenderWiindow->SetSize(600, 300);
        volumeRenderWiindow->AddRenderer(renderer2);
        volumeRenderWiindow->SetInteractor(mInteractor);

        volumeRenderWiindow->Render();

		renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
		mRenderer->ResetCamera();
	

		renderWindowInteractor->Start();


        ui->volume_view_widget->SetRenderWindow(renWin);

}
void MainWindow::on_actionfile_triggered()
{
	QMessageBox r;
	r.setText("Try");
	r.exec();


}

void MainWindow::mip_volume_render()
{

	TheVolType = 0;
	zerrrrro = 1;
	SLICERER();


}
void MainWindow::muscle_volume_render()
{

	TheVolType = 5;
	zerrrrro = 1;
	SLICERER();


}

void MainWindow::Bone_volume_render()
{
	TheVolType = 3;
	zerrrrro = 1;
	SLICERER();


}

void MainWindow::intensity_control()
{
	
    TheLightIntensity = (ui->intensity_slider->value())*-1;
	SLICERER();

}
