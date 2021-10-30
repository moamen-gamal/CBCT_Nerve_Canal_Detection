#include <iostream>
#include <QtWidgets\qapplication.h>
#include <mainwindow.h>

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
#define VTI_FILETYPE 1
#define MHA_FILETYPE 2

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

int main(int argc ,char * argv[]) 
{

	

	QApplication app(argc, argv);
	MainWindow t;
	t.show();
	app.exec();


	

}