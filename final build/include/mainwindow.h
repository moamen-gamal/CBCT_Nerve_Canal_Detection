#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<imageManager.h>
#include<SceneManger.h>
#include<opencv2/opencv.hpp>
#include<cvQTconvert.h>
#include<naturalSort.h>
#include<QFileDialog>
#include<panorama.h>
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
    panorama panorama;
    std::vector<std::string> DICOM_Names;
    std::vector<std::string> Full_Path_Names;
    QString folderPath;
    bool isFileopened = false;

public slots:
    void processImages();
    void processPanorama();

    void axialSliderCtrl();
    void coronalSliderCtrl();
    void sagittalSliderCtrl();
    void panoramaSliderCtrl();

    void axialViewCtrl(int id);
    void coronalViewCtrl(int id);
    void sagittalViewCtrl(int id);
    void panoramaViewCtrl(int id);

    void setViews();
    void setSliders();

    void openFolder();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
