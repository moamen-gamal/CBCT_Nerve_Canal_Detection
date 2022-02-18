#include "All_Librarries.h"
#include "scene.h"
#ifndef views
#define views

class SceneManager
{

public:
    Scenez *sceneAxial;
    Scenez *sceneCoronal;
    Scenez *sceneSagittal;
    Scenez *sceneCurve;
    Scenez *scenePanorama;
    Scenez *sceneSerial;
	void SceneReturener(QGraphicsScene * Scene, int HorizonatSilderValue);

};
#endif // !
