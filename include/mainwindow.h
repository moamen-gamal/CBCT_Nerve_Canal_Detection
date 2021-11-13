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

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> axialRenderWindow;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> coronalRenderWindow;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> sagittalRenderWindow;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> volumeRenderWiindow;

    vtkSmartPointer<vtkRenderer> mRenderer;
    vtkSmartPointer<QVTKInteractor> mInteractor;
    vtkSmartPointer<vtkInteractorStyle> mInteractorStyle;


    int mMinSliderX;

    int mMaxSliderX;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void axial_slider_control();
    void coronal_slider_control();
    void Sagittal_slider_control();
    void intensity_control();
    void median_Filter();
    void Gaussin_Filter();
    void SLICERER();
private slots:
    void on_actionfile_triggered();
    void open_view_dicom();
    void mip_volume_render();
    void muscle_volume_render();
    void Bone_volume_render();


};

#endif // MAINWINDOW_H
