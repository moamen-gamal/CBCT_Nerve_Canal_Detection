#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdialog.h>
#include <qgraphicsscene.h>
#include "Arc_Creator.h"










namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

	void MAX1();
	void MAX2();
	void MAX3();
	void MAX4();
	void Drawer();
	void Shift();
	void openFolder();
	void onButtonClicked();
	void onDrawSphere3Click();
	void onDrawSphere45Click();
	void onDrawSphere998Click();
	void MMO();
	void MIP();
	
	

private:
    Ui::MainWindow *ui;
	
	

	

	
	QGraphicsEllipseItem *Ellipse;
	//void onDrawSphere2Click();

private slots:
	void onDrawSphere2Click();

	void onDrawSphere77Click();
	void onDrawSphere88Click();
	void onDrawSphere99Click();
	void onDrawSphere100Click();
	void actionGroupClicked();
	void actionGroupClicked22();
	
	void bone();
	void skin();
	void muscle();
	void Volume(std::string x, int y);
	void ClustereedImagesSaver();
	void MisterShowHistoGram();
	void ChangeASLICERER();
	void ChangeSKESLICERER();
	void ChageABoneSLICERER();
	void TweakTheIntensity();
	void SLICERER();
};

#endif // MAINWINDOW_H
