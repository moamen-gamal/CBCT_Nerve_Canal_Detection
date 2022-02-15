#include "scene.h"
#include <QToolTip>
#include <QtMath>
#include "All_Librarries.h"

 QString dist;


Scenez::Scenez(QObject* parent): QGraphicsScene(parent)
{
    sceneMode = NoMode;
    itemToDraw = 0;
    secItemToDraw = 0;
    secSeg = 0;
}

void Scenez::setMode(Mode mode){
    sceneMode = mode;
    QGraphicsView::DragMode vMode =
            QGraphicsView::NoDrag;
    if(mode == DrawLine){
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }
    else if(mode == SelectObject){
        makeItemsControllable(true);
        vMode = QGraphicsView::RubberBandDrag;
    }
    QGraphicsView* mView = views().at(0);
    if(mView)
        mView->setDragMode(vMode);
}

void Scenez::makeItemsControllable(bool areControllable){
    foreach(QGraphicsItem* item, items()){
        item->setFlag(QGraphicsItem::ItemIsSelectable,
                      areControllable);
        item->setFlag(QGraphicsItem::ItemIsMovable,
                      areControllable);
    }
}

 // length measurements
void Scenez::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(sceneMode == DrawLine)
        origPoint = event->scenePos();
    QGraphicsScene::mousePressEvent(event);


}

void Scenez::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(sceneMode == DrawLine){
        if(!itemToDraw){
            itemToDraw = new QGraphicsLineItem;

            this->addItem(itemToDraw);
            itemToDraw->setPen(QPen(Qt::red, 3, Qt::SolidLine)); 
            itemToDraw->setPos(origPoint);
        }
        itemToDraw->setLine(0,0,
                            event->scenePos().x() - origPoint.x(),
                            event->scenePos().y() - origPoint.y());
        float distance = qSqrt(qPow(event->scenePos().x() - origPoint.x(),2)+ qPow(event->scenePos().y() - origPoint.y(),2));
        dist = QString::number(distance, 'f', 2);
        itemToDraw->setToolTip(dist);
        //itemToDraw->setToolTipDuration(500);

    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}

void Scenez::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
	
	
		QMessageBox kk;
		kk.setText("The Length is " + dist);
		kk.exec();
	
    itemToDraw = 0;
    QGraphicsScene::mouseReleaseEvent(event);
}

/*
//angle measurements
void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine)
        origPoint = event->scenePos();
    QGraphicsScene::mousePressEvent(event);


}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine) {
        if (!itemToDraw) {
            itemToDraw = new QGraphicsLineItem;

            this->addItem(itemToDraw);
            itemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            itemToDraw->setPos(origPoint);
        }
        itemToDraw->setLine(0, 0,
            event->scenePos().x() - origPoint.x(),
            event->scenePos().y() - origPoint.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    secOrigPoint = event->scenePos();
    itemToDraw = 0;
    secSeg = 1;
    QGraphicsScene::mouseReleaseEvent(event);
}

bool Scene::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::MouseMove)
    {
        if (sceneMode == DrawLine) {
            if (secSeg) {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));


                itemToDraw = new QGraphicsLineItem;

                this->addItem(itemToDraw);
                itemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
                itemToDraw->setPos(origPoint);
            }
            itemToDraw->setLine(0, 0,
                event->scenePos().x() - origPoint.x(),
                event->scenePos().y() - origPoint.y());
        }
    }
    else
        QGraphicsScene::mouseMoveEvent(event);

    
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine) {
        if (!secItemToDraw) {
            secItemToDraw = new QGraphicsLineItem;

            this->addItem(secItemToDraw);
            secItemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            secItemToDraw->setPos(secOrigPoint);
        }
        secItemToDraw->setLine(0, 0,
            event->scenePos().x() - secOrigPoint.x(),
            event->scenePos().y() - secOrigPoint.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}
*/
////////////////////////////////////////////////
void Scenez::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete)
        foreach(QGraphicsItem* item, selectedItems()){
            removeItem(item);
            delete item;
        }
    else
        QGraphicsScene::keyPressEvent(event);
}


