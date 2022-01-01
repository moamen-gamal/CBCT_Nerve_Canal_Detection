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
	ui->openGLWidget->SetRenderWindow(mRenderWindow);
	ui->openGLWidget_2->SetRenderWindow(mRenderWindow_2);
	ui->openGLWidget_3->SetRenderWindow(mRenderWindow_3);
	ui->openGLWidget_4->SetRenderWindow(mRenderWindow_4);
	mInteractor->Initialize();
	// Set the background color 
	mRenderer->SetBackground(0, 0, 0);
  connect(ui->actionopen, SIGNAL(triggered()), this, SLOT(DeleteThisFun()));
  connect(ui->actionbone, SIGNAL(triggered()), this, SLOT(ChageABoneSLICERER()));
  connect(ui->actionMIP, SIGNAL(triggered()), this, SLOT(ChangeASLICERER()));
  connect(ui->actionskeletal, SIGNAL(triggered()), this, SLOT(ChangeSKESLICERER()));
  connect(ui->actiongaussin, SIGNAL(triggered()), this, SLOT(Gaussin_Filter()));
  connect(ui->actionMedien, SIGNAL(triggered()), this, SLOT(onDrawSphereClick()));




	QObject::connect(ui->horizontalSlider, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom);

	QObject::connect(ui->horizontalSlider_2, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom2);

	QObject::connect(ui->horizontalSlider_3, &QSlider::valueChanged,
		this, &MainWindow::TweakTheDicom3);

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


	mRenderWindow->SetSize(600, 300);
	mRenderWindow->AddRenderer(originalRenderer);
	mRenderWindow->AddRenderer(gradientMagnitudeRenderer);
	mRenderWindow->SetInteractor(mInteractor);

	mRenderWindow->Render();

}

QString dir3;
QString dir45;

void MainWindow::onDrawSphere2Click()
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

	
	ui->horizontalSlider->setRange(0, DICOM_Names.size());
	ui->horizontalSlider_2->setRange(0, DICOM_Names.size());
	ui->horizontalSlider_3->setRange(0, DICOM_Names.size());
	ui->horizontalSlider_4->setRange(0, DICOM_Names.size());

	// Read all the DICOM files in the specified directory.
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double * range = image->GetPointData()->GetScalars()->GetRange();
	vtkNew<vtkImageViewer2> imageViewer;
	vtkNew<vtkImageViewer2> imageViewer2;
	vtkNew<vtkImageViewer2> imageViewer3;
	imageViewer3->SetSliceOrientationToXZ();
	imageViewer2->SetSliceOrientationToYZ();
	imageViewer->SetSliceOrientationToXY();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	imageViewer2->SetInputConnection(reader->GetOutputPort());
	imageViewer3->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer2->SetupInteractor(mInteractor);
	imageViewer3->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	imageViewer2->SetRenderWindow(ui->openGLWidget_2->GetRenderWindow());
	imageViewer3->SetRenderWindow(ui->openGLWidget_3->GetRenderWindow());
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

void MainWindow::TweakTheDicom()
{
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250


	vtkNew<vtkImageDilateErode3D> dilateErode;
	dilateErode->SetInputConnection(reader->GetOutputPort());
	dilateErode->SetDilateValue(300000);
	dilateErode->SetErodeValue(255);
	dilateErode->SetKernelSize(1, 1, 1);
	dilateErode->ReleaseDataFlagOff();

	


	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetSliceOrientationToXY();
	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	imageViewer->Render();

	

	
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->SetSlice(ui->horizontalSlider->value());
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	renderWindowInteractor->Start();
}


void MainWindow::TweakTheDicom2()
{
	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(dir3.toUtf8().constData());
	reader->Update();
	auto image = reader->GetOutput();
	double *range = image->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	vtkNew<vtkImageViewer2> imageViewer;
	imageViewer->SetSliceOrientationToYZ();
	//vtkSmartPointer<vtkProp3D> TheProp;
	//TheProp->SetUserMatrix(imageViewer->GetImageActor()->GetMatrix());


	imageViewer->SetInputConnection(reader->GetOutputPort());
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	imageViewer->SetupInteractor(mInteractor);
	imageViewer->SetRenderWindow(ui->openGLWidget_2->GetRenderWindow());
	imageViewer->Render();
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);;
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->SetSlice(ui->horizontalSlider_2->value());
	imageViewer->GetRenderer()->ResetCamera();
	imageViewer->Render();
	renderWindowInteractor->Start();
}

void MainWindow::TweakTheDicom3()
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
	imageViewer->SetRenderWindow(ui->openGLWidget_3->GetRenderWindow());
	imageViewer->Render();
	imageViewer->SetColorLevel(0.5 * (range[0] + range[1]));
	imageViewer->SetColorWindow(range[1] - range[0]);
	renderWindowInteractor->SetInteractorStyle(mInteractorStyle);
	imageViewer->SetSlice(ui->horizontalSlider_3->value());
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
	int y = ui->horizontalSlider->value();
	const char *converter = (Full_Path_Names[y]).c_str();
	reader->SetFileName(converter);
	reader->Update();
	vtkNew<vtkImageCast> cast;
	cast->SetInputConnection(reader->GetOutputPort());
	cast->SetOutputScalarTypeToFloat();

	// threshold the images
	vtkSmartPointer<vtkImageThreshold> imageThreshold =
		vtkSmartPointer<vtkImageThreshold>::New();
	imageThreshold->SetInputConnection(reader->GetOutputPort());
	// unsigned char lower = 127;
	unsigned int upper = 3497;

	imageThreshold->ThresholdByLower(upper);
	imageThreshold->ReplaceInOn();
	imageThreshold->SetInValue(0);
	imageThreshold->ReplaceOutOn();
	imageThreshold->SetOutValue(151);
	imageThreshold->Update();

	vtkNew<vtkImageDilateErode3D> dilate1;
	dilate1->SetInputConnection(imageThreshold->GetOutputPort());
	dilate1->SetDilateValue(0);
	dilate1->SetErodeValue(255);
	dilate1->SetKernelSize(31, 31, 1);

	vtkNew<vtkImageDilateErode3D> erode1;
	erode1->SetInputConnection(dilate1->GetOutputPort());
	erode1->SetDilateValue(255);
	erode1->SetErodeValue(0);
	erode1->SetKernelSize(31, 31, 1);

	vtkNew<vtkImageOpenClose3D> openClose;
	openClose->SetInputConnection(imageThreshold->GetOutputPort());
	openClose->SetOpenValue(0);
	openClose->SetCloseValue(255);
	//openClose->SetKernelSize(5, 5, 3);
	openClose->ReleaseDataFlagOff();
	openClose->GetOutput();
	openClose->GetCloseValue();
	openClose->GetOpenValue();


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
	filteredActor->GetMapper()->SetInputConnection(erode1->GetOutputPort());
	double originalViewport[4] = { 0.0, 0.0, 0.5, 1.0 };
	double filteredViewport[4] = { 0.5, 0.0, 1.0, 1.0 };
	vtkNew<vtkImageResliceMapper> imageResliceMapper;
	imageResliceMapper->SetInputData(image);
	vtkNew<vtkImageSlice> imageSlice;
	imageSlice->SetMapper(imageResliceMapper);
	auto image2 = reader->GetOutput();
	double *range = image2->GetPointData()->GetScalars()->GetRange();//0-500---0---250---250
	//filteredActor->GetProperty()->SetColorLevel(0.5 * (range[0] + range[1]));
	//filteredActor->GetProperty()->SetColorWindow(range[1] - range[0]);
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
	renderWindowInteractor->SetRenderWindow(ui->openGLWidget->GetRenderWindow());
	renderWindowInteractor->Initialize();
	mRenderWindow->SetSize(600, 300);
	mRenderWindow->AddRenderer(originalRenderer);
	mRenderWindow->AddRenderer(filteredRenderer);
	mRenderWindow->SetInteractor(mInteractor);
	mRenderWindow->Render();
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

		renderWindowInteractor->SetRenderWindow(ui->openGLWidget_4->GetRenderWindow());

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


		ui->openGLWidget_4->SetRenderWindow(renWin);

}
void MainWindow::DeleteThisFun()
{


	vtkNew<vtkNamedColors> colors;

	dir45 = QFileDialog::getExistingDirectory(this,
		tr("Open Directory"),
		"G:\MedicalData",
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir  TheDirectory = dir45;
	QStringList DICOMS = TheDirectory.entryList(QStringList() << "*.dcm", QDir::Files);



	foreach(QString Dicom, DICOMS)
	{
		DICOM_Names.push_back(Dicom.toUtf8().constData());
		std::string the_path = dir45.toStdString() + "\\" + Dicom.toUtf8().constData();
		for (int i = 0 ; i <=the_path.size() ; i++)
		{
			
			QString zee = the_path[i];
			QMessageBox r;
			r.setText( zee);
			//r.exec();

		}


		Full_Path_Names.push_back(the_path);

	}

	std::string ZORO = "G:\\MedicalDATA\\DICOM\\128602 - L  yz\\NEW21888.dcm";
	

	
	constexpr unsigned int Dimension = 2;
	std::string location = "C:\\Users\\EGYPT_LAPTOP\\Desktop\\Dicomtoimage\\build\\Release\\NewDCM12345.jpeg";
	for (int i = 0; i < Full_Path_Names.size();i++) {
		const char* inputImage = Full_Path_Names[i].c_str();
		const char* outputImage = location.c_str();

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
		//itk::NumericTraits<OutputPixelType>::max()
		using FilterType = itk::CastImageFilter<InputImageType, OutputImageType>;
		FilterType::Pointer filter = FilterType::New();
		filter->SetInput(rescale->GetOutput());


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



		cv::Mat image = cv::imread(outputImage);

		// Check for failure
		if (image.empty())
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get(); //wait for any key press

		}

		std::string windowName = "The Guitar"; //Name of the window

		//cv::namedWindow(windowName); // Create a window

		//imshow(windowName, image); // Show our image inside the created window.

		//cv::waitKey(0); // Wait for any keystroke in the window

		//cv::destroyWindow(windowName); //destroy the created window


		cv::Mat src = cv::imread(outputImage, cv::IMREAD_GRAYSCALE);

		cv::Mat dst;

		// Set threshold and maxValue
		double thresh = 200;
		double maxValue = 255;
		//cv::namedWindow("Oh MY", cv::CV_WINDOW_AUTOSIZE);
		// Binary Threshold
		cv::threshold(src, dst, thresh, maxValue, cv::THRESH_BINARY);
		//imshow("oh my", dst);
		int morph_size = 1;
		cv::Mat element = cv::getStructuringElement(
			cv::MORPH_RECT, cv::Size(2 * morph_size + 1,
				2 * morph_size + 1),
			cv::Point(morph_size, morph_size));
		cv::Mat  dill;
		cv::Mat  dull;
		dilate(dst, dill, element,
			cv::Point(-1, -1), 1);
		dilate(dill, dull, element,
			cv::Point(-1, -1), 1);

		imshow("dilate", dill);
		imshow("dilateNEWWWWWW", dull);
		//cv::waitKey();
		//cv::Mat img = itk::OpenCVImageBridge::ITKImageToCVMat<OutputImageType>(outputImage);
		//cv::imshow("One", img);


		for (int i = 0; i < dill.rows; i++)
		{
			for (int j = 0; j < dill.cols; j++)
			{
				if ((int)dill.at<cv::Vec3b>(i, j)[0] > 40) {
					the_counter_Most_dialated++;
					//std::string DATA = " R:  " + std::to_string((int)dill.at<cv::Vec3b>(i, j)[0]) + " G: " + std::to_string((int)dill.at<cv::Vec3b>(i, j)[1]) + " B: " + std::to_string((int)dill.at<cv::Vec3b>(i, j)[2]);
					//XYZEER.push_back(DATA);
				}
				if (dill.type() == CV_8UC1)
				{
					dill.at<uchar>(i, j) = 255;



				}
				else if (dill.type() == CV_8UC3)
				{
					std::cout << (int)dill.at<cv::Vec3b>(i, j)[0] << " " << (int)dill.at<cv::Vec3b>(i, j)[1] << " " << (int)dill.at<cv::Vec3b>(i, j)[2] << std::endl;
					dill.at<cv::Vec3b>(i, j)[0] = 255;
					dill.at<cv::Vec3b>(i, j)[1] = 255;
					dill.at<cv::Vec3b>(i, j)[2] = 255;

					cout << (int)dill.at<cv::Vec3b>(i, j)[0] << " " << (int)dill.at<cv::Vec3b>(i, j)[1] << " " << (int)dill.at<cv::Vec3b>(i, j)[2] << endl;
				}

				else
				{
					cout << "Anknown image format" << endl;

				}
			}
		}
		The_intensities.push_back(the_counter_Most_dialated);
		//QString str;
		//for (int i = 0; i < XYZEER.size(); ++i)
		//{
			//if (i > 0)
				//str += " ";
			//str += QString::fromStdString(XYZEER[i]);
		//}
		the_counter_Most_dialated = 0;



	}
	double max = *std::max_element(The_intensities.begin(), The_intensities.end());
	for (int i = 0; i < The_intensities.size();i++)
	{
	
		if (The_intensities[i] == max) 
		{
			needed_Slice = i;
		
		}
	}

	QMessageBox t11;

	t11.setText( QString::number(needed_Slice));
	t11.exec();
	QMessageBox t22;

	t22.setText(QString::number(The_intensities[needed_Slice]));
	t22.exec();











	const char* inputImage = Full_Path_Names[needed_Slice].c_str();
	const char* outputImage = location.c_str();

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
	//itk::NumericTraits<OutputPixelType>::max()
	using FilterType = itk::CastImageFilter<InputImageType, OutputImageType>;
	FilterType::Pointer filter = FilterType::New();
	filter->SetInput(rescale->GetOutput());


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
