#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<imageManager.h>
#include<SceneManger.h>
#include<opencv2/opencv.hpp>
#include<cvQTconvert.h>
#include<naturalSort.h>
#include<QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ImageManager imageManager;
    SceneManager sceneManager;
    std::vector<std::string> DICOM_Names;
    std::vector<std::string> Full_Path_Names;
    QString folderPath;
public slots:

    void axialSliderCtrl();
    void coronalSliderCtrl();
    void sagittalSliderCtrl();


    void axialViewCtrl(int id);
    void sagittalViewCtrl(int id);
    void coronalViewCtrl(int id);

    void setOrthogonalViews();
    void setSliders();

    void openFolder();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
