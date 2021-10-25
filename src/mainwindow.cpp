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


	QObject::connect(ui->horizontalSlider, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom);


}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::onDrawSphereClick() {
	// Create sphere

	
	vtkNew<vtkNamedColors> colors;

	// Verify input arguments
	
	QString inputFilename = QFileDialog::getOpenFileName(this, "open a file", "G:\MedicalDATA", tr("Dicom Images (*.dcm)"));
	


	// Read all the DICOM files in the specified directory.
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetFileName(inputFilename.toUtf8().constData());
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

std::vector<std::string> DICOM_Names;

std::vector<std::string> Full_Path_Names;


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