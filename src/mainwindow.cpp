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
	
	
	mRenderWindow->AddRenderer(mRenderer);
	mRenderWindow->SetInteractor(mInteractor);
	ui->openGLWidget->SetRenderWindow(mRenderWindow);
	mInteractor->SetInteractorStyle(mInteractorStyle);
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

	vtkNew<vtkDICOMImageReader> reader;
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
