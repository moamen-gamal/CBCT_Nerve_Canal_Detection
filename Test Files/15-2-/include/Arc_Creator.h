#include "All_Librarries.h"
#include "scene.h"
#ifndef The_ARc_Goottter
#define The_ARc_Goottter

class TheArcCreator
{

public:
	Scenez *SceneAxial;
	Scenez *Scene_Coronal;
	Scenez *Scene_Sagitial;
	Scenez *Scene_Paronama_Arc;
	Scenez * Scene_Paronama_Image;
	Scenez * Scene_Curve_3Image;
	void SceneReturener(QGraphicsScene * Scene, int HorizonatSilderValue);

};
#endif // !
