#include <iostream>
#include <mainwindow.h>
#include <QApplication>
#include <QtWidgets\qapplication.h>
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <qgraphicseffect.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qdatetime.h>
#include <qmainwindow.h>
#include <qstatusbar.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpainter.h>

#include <qlabel.h>
#include <qimage.h>
#include <qpixmap.h>
#include <QMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <qdebug.h>
#include <stdlib.h>
#include<qdebug.h>
#include<QtGlobal>
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}
int main(int argc, char * argv[])
{
    qInstallMessageHandler(myMessageOutput); // Install the handler
	QApplication app(argc, argv); 
    MainWindow winodw;
    winodw.show();
	app.exec();
}
