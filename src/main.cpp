#include <QtWidgets\qapplication.h>
#include <MainWindow.h>

int main(int argc,char * argv[]) 
{
	QApplication app(argc, argv);
	MainWindow themainwindow;
	themainwindow.show();


	return app.exec();

}