#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QAction>
#include <QGraphicsView>
#include <QKeyEvent>

class Scenez : public QGraphicsScene
{
public:
    enum Mode {NoMode, SelectObject, DrawLine};
    Scenez(QObject* parent = 0);
    void setMode(Mode mode);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    Mode sceneMode;
    QPointF origPoint;
    QPointF secOrigPoint;
    QGraphicsLineItem* itemToDraw;
    QGraphicsLineItem* secItemToDraw;
    int secSeg;
    void makeItemsControllable(bool areControllable);
};

#endif // SCENE_H