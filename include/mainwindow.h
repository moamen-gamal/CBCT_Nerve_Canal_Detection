#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_2;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_3;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow_4;

	vtkSmartPointer<vtkRenderer> mRenderer;
	vtkSmartPointer<QVTKInteractor> mInteractor;
	vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;

	
	int mMinSliderX;

	int mMaxSliderX;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void onDrawSphereClick();
	void TweakTheDicom();
	void TweakTheDicom2();
	void TweakTheDicom3();
	void Gaussin_Filter();
	void OpenSTLER();
	void SLICERER();
	void TweakTheIntensity();
private slots:
	void on_actionfile_triggered();
	void onDrawSphere2Click();
	void ChangeASLICERER();
	void ChangeSKESLICERER();
	void ChageABoneSLICERER();
	void onDeleteThies();
	
};

#endif // MAINWINDOW_H