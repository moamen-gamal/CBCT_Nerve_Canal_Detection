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


/*
class vtkImageInteractionCallback : public vtkCommand
{
public:
	static vtkImageInteractionCallback* New() { return new vtkImageInteractionCallback; }

	vtkImageInteractionCallback()
	{
		this->Slicing = 0;
		this->ImageReslice = nullptr;
		this->Interactor = nullptr;
	}

	void SetImageReslice(vtkImageReslice* reslice) { this->ImageReslice = reslice; }

	vtkImageReslice* GetImageReslice() { return this->ImageReslice; }

	void SetInteractor(vtkRenderWindowInteractor* interactor) { this->Interactor = interactor; }

	vtkRenderWindowInteractor* GetInteractor() { return this->Interactor; }

	void Execute(vtkObject*, unsigned long event, void*) override
	{
		vtkRenderWindowInteractor* interactor = this->GetInteractor();

		int lastPos[2];
		interactor->GetLastEventPosition(lastPos);
		int currPos[2];
		interactor->GetEventPosition(currPos);

		if (event == vtkCommand::LeftButtonPressEvent)
		{
			this->Slicing = 1;
		}
		else if (event == vtkCommand::LeftButtonReleaseEvent)
		{
			this->Slicing = 0;
		}
		else if (event == vtkCommand::MouseMoveEvent)
		{
			if (this->Slicing)
			{
				vtkImageReslice* reslice = this->ImageReslice;

				// Increment slice position by deltaY of mouse
				int deltaY = lastPos[1] - currPos[1];

				reslice->Update();
				double sliceSpacing = reslice->GetOutput()->GetSpacing()[2];
				vtkMatrix4x4* matrix = reslice->GetResliceAxes();
				// move the center point that we are slicing through
				double point[4];
				double center[4];
				point[0] = 0.0;
				point[1] = 0.0;
				point[2] = sliceSpacing * deltaY;
				point[3] = 1.0;
				matrix->MultiplyPoint(point, center);
				matrix->SetElement(0, 3, center[0]);
				matrix->SetElement(1, 3, center[1]);
				matrix->SetElement(2, 3, center[2]);
				interactor->Render();
			}
			else
			{
				vtkInteractorStyle* style =
					vtkInteractorStyle::SafeDownCast(interactor->GetInteractorStyle());
				if (style)
				{
					style->OnMouseMove();
				}
			}
		}
	}

private:
	// Actions (slicing only, for now)
	int Slicing;

	// Pointer to vtkImageReslice
	vtkImageReslice* ImageReslice;

	// Pointer to the interactor
	vtkRenderWindowInteractor* Interactor;
};

*/

namespace {

	// helper class to format slice status message
	class StatusMessage
	{
	public:
		static std::string Format(int slice, int maxSlice)
		{
			std::stringstream tmp;
			tmp << "Slice Number  " << slice + 1 << "/" << maxSlice + 1;
			return tmp.str();
		}
	};

	// Define own interaction style
	class myVtkInteractorStyleImage : public vtkInteractorStyleImage
	{
	public:
		static myVtkInteractorStyleImage* New();
		vtkTypeMacro(myVtkInteractorStyleImage, vtkInteractorStyleImage);

	protected:
		vtkImageViewer2* _ImageViewer;
		vtkTextMapper* _StatusMapper;
		int _Slice;
		int _MinSlice;
		int _MaxSlice;

	public:
		void SetImageViewer(vtkImageViewer2* imageViewer)
		{
			_ImageViewer = imageViewer;
			_MinSlice = imageViewer->GetSliceMin();
			_MaxSlice = imageViewer->GetSliceMax();
			_Slice = _MinSlice;
			cout << "Slicer: Min = " << _MinSlice << ", Max = " << _MaxSlice
				<< std::endl;
		}

		void SetStatusMapper(vtkTextMapper* statusMapper)
		{
			_StatusMapper = statusMapper;
		}

	protected:
		void MoveSliceForward()
		{
			if (_Slice < _MaxSlice)
			{
				_Slice += 1;
				cout << "MoveSliceForward::Slice = " << _Slice << std::endl;
				_ImageViewer->SetSlice(_Slice);
				std::string msg = StatusMessage::Format(_Slice, _MaxSlice);
				_StatusMapper->SetInput(msg.c_str());
				_ImageViewer->Render();
			}
		}

		void MoveSliceBackward()
		{
			if (_Slice > _MinSlice)
			{
				_Slice -= 1;
				cout << "MoveSliceBackward::Slice = " << _Slice << std::endl;
				_ImageViewer->SetSlice(_Slice);
				std::string msg = StatusMessage::Format(_Slice, _MaxSlice);
				_StatusMapper->SetInput(msg.c_str());
				_ImageViewer->Render();
			}
		}

		virtual void OnKeyDown()
		{
			std::string key = this->GetInteractor()->GetKeySym();
			if (key.compare("Up") == 0)
			{
				// cout << "Up arrow key was pressed." << endl;
				MoveSliceForward();
			}
			else if (key.compare("Down") == 0)
			{
				// cout << "Down arrow key was pressed." << endl;
				MoveSliceBackward();
			}
			// forward event
			vtkInteractorStyleImage::OnKeyDown();
		}

		virtual void OnMouseWheelForward()
		{
			// std::cout << "Scrolled mouse wheel forward." << std::endl;
			MoveSliceForward();
			// don't forward events, otherwise the image will be zoomed
			// in case another interactorstyle is used (e.g. trackballstyle, ...)
			// vtkInteractorStyleImage::OnMouseWheelForward();
		}

		virtual void OnMouseWheelBackward()
		{
			// std::cout << "Scrolled mouse wheel backward." << std::endl;
			if (_Slice > _MinSlice)
			{
				MoveSliceBackward();
			}
			// don't forward events, otherwise the image will be zoomed
			// in case another interactorstyle is used (e.g. trackballstyle, ...)
			// vtkInteractorStyleImage::OnMouseWheelBackward();
		}
	};

	vtkStandardNewMacro(myVtkInteractorStyleImage);

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
	
	vtkNew<vtkDICOMImageReader> reader;
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
	auto r= reader->GetImageOrientationPatient();
	for (int i = 0;i < 5;i++) {
		x[i] = *(r + i);
		
		//QMessageBox t;
		//QString K = QString::number(x[i]);

		//t.setText(K);
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

	// Setup renderers
	vtkNew<vtkRenderer> originalRenderer;
	originalRenderer->SetViewport(originalViewport);
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
	filteredActor->RotateX(90);

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


	QMessageBox r2;
	r2.setText("Okay");
	r2.exec();

	
	//QString inputFilename = QFileDialog::getOpenFileName(this, "open a file", "G:\MedicalDATA");
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
	/*

	foreach(QString Dicom, DICOMS)
	{
		DICOM_Names.push_back(Dicom.toUtf8().constData());
		std::string the_path = dir.toStdString() + "\\" + Dicom.toUtf8().constData();
		Full_Path_Names.push_back(the_path);

	}
	const char *W;
	std::string K = dir.toStdString();
	K.append("\0");
	W = K.c_str();

	QString QWE = W;
	QMessageBox r;
	r.setText(QWE);
	r.exec();

	
	vtkSmartPointer<vtkImageData> imageData = vtkSmartPointer<vtkImageData>::New();
	vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
	vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
	vtkSmartPointer<vtkPiecewiseFunction> gradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	vtkSmartPointer<vtkPiecewiseFunction> scalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
	vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();

	vtkSmartPointer<vtkDICOMImageReaderVector>readrerer= vtkSmartPointer<vtkDICOMImageReaderVector>::New();

	reader->SetDirectoryName(W);
	reader->Update();
	imageData->ShallowCopy(reader->GetOutput());

	renderer->SetBackground(0.1, 0.2, 0.3);

	renderWindow->AddRenderer(renderer);
	renderWindow->SetSize(500, 500);

	renderWindowInteractor->SetInteractorStyle(interactorStyle);
	renderWindowInteractor->SetRenderWindow(renderWindow);

	volumeMapper->SetBlendModeToComposite();
	volumeMapper->SetRequestedRenderModeToGPU();
	volumeMapper->SetInputData(imageData);

	volumeProperty->ShadeOn();
	volumeProperty->SetInterpolationTypeToLinear();

	volumeProperty->SetAmbient(0.1);
	volumeProperty->SetDiffuse(0.9);
	volumeProperty->SetSpecular(0.2);
	volumeProperty->SetSpecularPower(10.0);

	gradientOpacity->AddPoint(0.0, 0.0);
	gradientOpacity->AddPoint(2000.0, 1.0);
	volumeProperty->SetGradientOpacity(gradientOpacity);

	scalarOpacity->AddPoint(-800.0, 0.0);
	scalarOpacity->AddPoint(-750.0, 1.0);
	scalarOpacity->AddPoint(-350.0, 1.0);
	scalarOpacity->AddPoint(-300.0, 0.0);
	scalarOpacity->AddPoint(-200.0, 0.0);
	scalarOpacity->AddPoint(-100.0, 1.0);
	scalarOpacity->AddPoint(1000.0, 0.0);
	scalarOpacity->AddPoint(2750.0, 0.0);
	scalarOpacity->AddPoint(2976.0, 1.0);
	scalarOpacity->AddPoint(3000.0, 0.0);
	volumeProperty->SetScalarOpacity(scalarOpacity);

	color->AddRGBPoint(-750.0, 0.08, 0.05, 0.03);
	color->AddRGBPoint(-350.0, 0.39, 0.25, 0.16);
	color->AddRGBPoint(-200.0, 0.80, 0.80, 0.80);
	color->AddRGBPoint(2750.0, 0.70, 0.70, 0.70);
	color->AddRGBPoint(3000.0, 0.35, 0.35, 0.35);
	volumeProperty->SetColor(color);

	volume->SetMapper(volumeMapper);
	volume->SetProperty(volumeProperty);
	renderer->AddVolume(volume);
	renderer->ResetCamera();

	renderWindow->Render();
	renderWindowInteractor->Start();



	*/


/*
	
	
	vtkNew<vtkNamedColors> colors;

	std::array<unsigned char, 4> bkg{ {51, 77, 102, 255} };
	colors->SetColor("BkgColor", bkg.data());

	// Create the renderer, the render window, and the interactor. The renderer
	// draws into the render window, the interactor enables mouse- and
	// keyboard-based interaction with the scene.
	vtkNew<vtkRenderer> ren;
	vtkNew<vtkRenderWindow> renWin;
	renWin->AddRenderer(ren);
	vtkNew<vtkRenderWindowInteractor> iren;
	iren->SetRenderWindow(renWin);

	// The following reader is used to read a series of 2D slices (images)
	// that compose the volume. The slice dimensions are set, and the
	// pixel spacing. The data Endianness must also be specified. The reader
	// uses the FilePrefix in combination with the slice number to construct
	// filenames using the format FilePrefix.%d. (In this case the FilePrefix
	// is the root name of the file: quarter.)
	vtkNew<vtkStringArray>CK;
	for (int i = 0; i < DICOM_Names.size();i++) 
	{
		CK->InsertValue(i, Full_Path_Names[i]+"\0" );
		//QMessageBox Well;
		//QString H = CK->GetValue(i);
		//Well.setText(H);
		//Well.exec();

	}

	QMessageBox Weel;
	Weel.setText(dir.toUtf8().constData());
	Weel.exec();

	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir.toUtf8().constBegin());
	

	// The volume will be displayed by ray-cast alpha compositing.
	// A ray-cast mapper is needed to do the ray-casting.
	vtkNew<vtkFixedPointVolumeRayCastMapper> volumeMapper;
	volumeMapper->SetInputConnection(reader->GetOutputPort());
	QMessageBox Well2;
	QString H = CK->GetValue(DICOM_Names.size());
	Well2.setText(H);
	Well2.exec();
	// The color transfer function maps voxel intensities to colors.
	// It is modality-specific, and often anatomy-specific as well.
	// The goal is to one color for flesh (between 500 and 1000)
	// and another color for bone (1150 and over).
	vtkNew<vtkColorTransferFunction> volumeColor;
	volumeColor->AddRGBPoint(0, 0.0, 0.0, 0.0);
	volumeColor->AddRGBPoint(500, 240.0 / 255.0, 184.0 / 255.0, 160.0 / 255.0);
	volumeColor->AddRGBPoint(1000, 240.0 / 255.0, 184.0 / 255.0, 160.0 / 255.0);
	volumeColor->AddRGBPoint(1150, 1.0, 1.0, 240.0 / 255.0); // Ivory

	// The opacity transfer function is used to control the opacity
	// of different tissue types.
	vtkNew<vtkPiecewiseFunction> volumeScalarOpacity;
	volumeScalarOpacity->AddPoint(0, 0.00);
	volumeScalarOpacity->AddPoint(500, 0.15);
	volumeScalarOpacity->AddPoint(1000, 0.15);
	volumeScalarOpacity->AddPoint(1150, 0.85);

	// The gradient opacity function is used to decrease the opacity
	// in the "flat" regions of the volume while maintaining the opacity
	// at the boundaries between tissue types. The gradient is measured
	// as the amount by which the intensity changes over unit distance.
	// For most medical data, the unit distance is 1mm.
	vtkNew<vtkPiecewiseFunction> volumeGradientOpacity;
	volumeGradientOpacity->AddPoint(0, 0.0);
	volumeGradientOpacity->AddPoint(90, 0.5);
	volumeGradientOpacity->AddPoint(100, 1.0);

	// The VolumeProperty attaches the color and opacity functions to the
	// volume, and sets other volume properties. The interpolation should
	// be set to linear to do a high-quality rendering. The ShadeOn option
	// turns on directional lighting, which will usually enhance the
	// appearance of the volume and make it look more "3D". However,
	// the quality of the shading depends on how accurately the gradient
	// of the volume can be calculated, and for noisy data the gradient
	// estimation will be very poor. The impact of the shading can be
	// decreased by increasing the Ambient coefficient while decreasing
	// the Diffuse and Specular coefficient. To increase the impact
	// of shading, decrease the Ambient and increase the Diffuse and Specular.
	vtkNew<vtkVolumeProperty> volumeProperty;
	volumeProperty->SetColor(volumeColor);
	volumeProperty->SetScalarOpacity(volumeScalarOpacity);
	volumeProperty->SetGradientOpacity(volumeGradientOpacity);
	volumeProperty->SetInterpolationTypeToLinear();
	volumeProperty->ShadeOn();
	volumeProperty->SetAmbient(0.4);
	volumeProperty->SetDiffuse(0.6);
	volumeProperty->SetSpecular(0.2);

	// The vtkVolume is a vtkProp3D (like a vtkActor) and controls the position
	// and orientation of the volume in world coordinates.
	vtkNew<vtkVolume> volume;
	volume->SetMapper(volumeMapper);
	volume->SetProperty(volumeProperty);

	// Finally, add the volume to the renderer
	ren->AddViewProp(volume);

	// Set up an initial view of the volume. The focal point will be the
	// center of the volume, and the camera position will be 400mm to the
	// patient's left (which is our right).
	vtkCamera* camera = ren->GetActiveCamera();
	double* c = volume->GetCenter();
	camera->SetViewUp(0, 0, -1);
	camera->SetPosition(c[0], c[1] - 400, c[2]);
	camera->SetFocalPoint(c[0], c[1], c[2]);
	camera->Azimuth(30.0);
	camera->Elevation(30.0);

	// Set a background color for the renderer
	ren->SetBackground(colors->GetColor3d("BkgColor").GetData());

	// Increase the size of the render window
	renWin->SetSize(640, 480);
	renWin->SetWindowName("MedicalDemo4");

	// Interact with the data.
	renWin->Render();
	iren->Start();
	*/




vtkNew<vtkNamedColors> colors;

// Verify input arguments
	
	std::string folder = dir.toUtf8().constData();
// std::string folder = "C:\\VTK\\vtkdata-5.8.0\\Data\\DicomTestImages";

// Read all the DICOM files in the specified directory.
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(folder.c_str());
	reader->Update();
/*
// Visualize
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetInputConnection(reader->GetOutputPort());

// slice status message
	vtkNew<vtkTextProperty> sliceTextProp;
	sliceTextProp->SetFontFamilyToCourier();
sliceTextProp->SetFontSize(20);
sliceTextProp->SetVerticalJustificationToBottom();
sliceTextProp->SetJustificationToLeft();

vtkNew<vtkTextMapper> sliceTextMapper;
std::string msg = StatusMessage::Format(imageViewer->GetSliceMin(),
	imageViewer->GetSliceMax());
sliceTextMapper->SetInput(msg.c_str());
sliceTextMapper->SetTextProperty(sliceTextProp);

vtkNew<vtkActor2D> sliceTextActor;
sliceTextActor->SetMapper(sliceTextMapper);
sliceTextActor->SetPosition(15, 10);

// usage hint message
vtkNew<vtkTextProperty> usageTextProp;
usageTextProp->SetFontFamilyToCourier();
usageTextProp->SetFontSize(14);
usageTextProp->SetVerticalJustificationToTop();
usageTextProp->SetJustificationToLeft();

vtkNew<vtkTextMapper> usageTextMapper;
usageTextMapper->SetInput(
	"- Slice with mouse wheel\n  or Up/Down-Key\n- Zoom with pressed right\n "
	" mouse button while dragging");
usageTextMapper->SetTextProperty(usageTextProp);

vtkNew<vtkActor2D> usageTextActor;
usageTextActor->SetMapper(usageTextMapper);
usageTextActor->GetPositionCoordinate()
->SetCoordinateSystemToNormalizedDisplay();
usageTextActor->GetPositionCoordinate()->SetValue(0.05, 0.95);

// create an interactor with our own style (inherit from
// vtkInteractorStyleImage) in order to catch mousewheel and key events
vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;

vtkNew<myVtkInteractorStyleImage> myInteractorStyle;

// make imageviewer2 and sliceTextMapper visible to our interactorstyle
// to enable slice status message updates when scrolling through the slices
myInteractorStyle->SetImageViewer(imageViewer);
myInteractorStyle->SetStatusMapper(sliceTextMapper);

imageViewer->SetupInteractor(renderWindowInteractor);
// make the interactor use our own interactorstyle
// cause SetupInteractor() is defining it's own default interatorstyle
// this must be called after SetupInteractor()
renderWindowInteractor->SetInteractorStyle(myInteractorStyle);
// add slice status message and usage hint message to the renderer
imageViewer->GetRenderer()->AddActor2D(sliceTextActor);
imageViewer->GetRenderer()->AddActor2D(usageTextActor);

// initialize rendering and interaction
imageViewer->Render();
imageViewer->GetRenderer()->ResetCamera();
imageViewer->GetRenderer()->SetBackground(
colors->GetColor3d("SlateGray").GetData());
imageViewer->GetRenderWindow()->SetSize(800, 800);
imageViewer->GetRenderWindow()->SetWindowName("ReadDICOMSeries");
imageViewer->Render();
renderWindowInteractor->Start();


*/


vtkSmartPointer<vtkImageData> imageData = vtkSmartPointer<vtkImageData>::New();
vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
vtkSmartPointer<vtkInteractorStyleTrackballCamera> interactorStyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
vtkSmartPointer<vtkPiecewiseFunction> gradientOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
vtkSmartPointer<vtkPiecewiseFunction> scalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();


vtkNew<vtkImageViewer2> imageViewer;
imageViewer->SetInputConnection(reader->GetOutputPort());
imageViewer->SetInputData(reader->GetOutput());


renderer->SetBackground(0.1, 0.2, 0.3);

renderWindow->AddRenderer(renderer);
renderWindow->SetSize(500, 500);

renderWindowInteractor->SetInteractorStyle(interactorStyle);
renderWindowInteractor->SetRenderWindow(renderWindow);

volumeMapper->SetBlendModeToComposite();
volumeMapper->SetRequestedRenderModeToGPU();
volumeMapper->SetInputData(imageViewer->GetInput());

volumeProperty->ShadeOn();
volumeProperty->SetInterpolationTypeToLinear();

volumeProperty->SetAmbient(0.1);
volumeProperty->SetDiffuse(0.9);
volumeProperty->SetSpecular(0.2);
volumeProperty->SetSpecularPower(10.0);

gradientOpacity->AddPoint(0.0, 0.0);
gradientOpacity->AddPoint(2000.0, 1.0);
volumeProperty->SetGradientOpacity(gradientOpacity);

scalarOpacity->AddPoint(-800.0, 0.0);
scalarOpacity->AddPoint(-750.0, 1.0);
scalarOpacity->AddPoint(-350.0, 1.0);
scalarOpacity->AddPoint(-300.0, 0.0);
scalarOpacity->AddPoint(-200.0, 0.0);
scalarOpacity->AddPoint(-100.0, 1.0);
scalarOpacity->AddPoint(1000.0, 0.0);
scalarOpacity->AddPoint(2750.0, 0.0);
scalarOpacity->AddPoint(2976.0, 1.0);
scalarOpacity->AddPoint(3000.0, 0.0);
volumeProperty->SetScalarOpacity(scalarOpacity);

color->AddRGBPoint(-750.0, 0.08, 0.05, 0.03);
color->AddRGBPoint(-350.0, 0.39, 0.25, 0.16);
color->AddRGBPoint(-200.0, 0.80, 0.80, 0.80);
color->AddRGBPoint(2750.0, 0.70, 0.70, 0.70);
color->AddRGBPoint(3000.0, 0.35, 0.35, 0.35);
volumeProperty->SetColor(color);

volume->SetMapper(volumeMapper);
volume->SetProperty(volumeProperty);
renderer->AddVolume(volume);
renderer->ResetCamera();

renderWindow->Render();
renderWindowInteractor->Start();






}
