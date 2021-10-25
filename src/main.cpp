#include <iostream>
#include <QtWidgets\qapplication.h>
#include <mainwindow.h>

int main(int argc ,char * argv[]) 
{
	QApplication app(argc, argv);
	MainWindow t;
	t.show();
	app.exec();




}