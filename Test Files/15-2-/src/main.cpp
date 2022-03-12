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
//QString myImgName = "myimg.png";
//static QImage *myImg;

//static const int imageRTTI = 984376;

//class ImageItem : public QGraphicsRectItem
//{
//public:
//	ImageItem(QImage img);
//	int rtti() const { return imageRTTI; }
//	void advance(int phase);
//protected:
//	void paint(QPainter *, const QStyleOptionGraphicsItem *option, QWidget *widget);
//private:
//	QImage image;
//	QPixmap pixmap;
//	int state;
//};


//void ImageItem::advance(int phase)
//{
//	if (state == 0)
//	{
//		moveBy(0, 30);
//		state = 1;
//	}
//	else
//	{
//		moveBy(0, -30);
//		state = 0;
//	}
//}


//ImageItem::ImageItem(QImage img)
//	: image(img)
//{
//	state = 0;
//	setRect(0, 0, image.width(), image.height());
//	setFlag(ItemIsMovable);
//	pixmap = pixmap.fromImage(image, Qt::OrderedAlphaDither);

//}

//void ImageItem::paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *)
//{
//	p->drawPixmap(option->exposedRect, pixmap, option->exposedRect);
//}

int main(int argc, char * argv[])
{
	QApplication app(argc, argv); 
    MainWindow winodw;
    winodw.show();
	app.exec();
}
