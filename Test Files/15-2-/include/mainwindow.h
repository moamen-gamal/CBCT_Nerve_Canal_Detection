#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qdialog.h>
#include <qgraphicsscene.h>
#include<string>
#include<vector>
#include<qfiledialog.h>
#include<naturalSort.h>
#include<iterator>
#include<map>
#include "itkImageSeriesReader.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <sstream>
#include <opencv2/opencv.hpp>
#include"opencv2/imgproc.hpp"
#include"opencv2/ximgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include<dcmtk/dcmimage/dicoimg.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include<SceneManger.h>
#include<cvQTconvert.h>
#include<QVTKOpenGLWidget.h>
#include<QVTKOpenGLWindow.h>
#include<QVTKOpenGLStereoWidget.h>
#include<QVTKOpenGLNativeWidget.h>

#include <QtCharts\qsplineseries.h>
#include <QtCharts\qchart.h>
#include <QtCharts\qchartview.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::vector<std::string> DICOM_Names;
    std::vector<std::string> Full_Path_Names;
    QString folderPath;

    SceneManager sceneManager;

    std::vector<DicomImage*>DicomImages;
    std::vector<cv::Mat*> axialImages;
    std::vector<cv::Mat*> coronalImages;
    std::vector<cv::Mat*> sagittalImages;

    std::vector<int> histogram;
    float mean=34,stddev=10,variance;

    std::map<std::string,std::string>dicomTags;
    int offset;
    cv::Mat skeleton;
    std::vector<double> curveCtrlX;
    std::vector<double> curveCtrlY;
    std::vector<double> curveShiftX;
    std::vector<double> curveShiftY;

    double lightIntensity = 4096;

    int renderMode =0;

public:
    void grayTransform();
    void MPR();

public slots:
    void openFolder();
    void init();
    void initSliders();
    void initViews();

    void axialSliderCtrl();
    void coronalSliderCtrl();
    void sagittalSliderCtrl();
    void panoramaSliderCtrl();
    void serialSliderCtrl();

    void axialViewCtrl(int id);
    void sagittalViewCtrl(int id);
    void coronalViewCtrl(int id);
    void panoramaViewCtrl(int id);
    void serialViewCtrl(int id);
    //void volumeSliderCtrl();

    void maxScreenAxial();
    void minScreenAxial();

    void maxScreenCoronal();
    void minScreenCoronal();

    void maxScreenSagittal();
    void minScreenSagittal();

    void maxScreenPanorama();
    void minScreenPanorama();

    void maxScreenSerial();
    void minScreenSerial();

    void normalViews();
    void constructedViews();

    void statistics();
    void DicomTags(std::string Path);

    int panoramaSliceSelect();
    cv::Mat SkeletonGenerate(int id);
    int Offset(cv::Mat img);
    void ctrlPtsCalculate(cv::Mat skeleton);
    void shiftCurve(float shift);
    cv::Mat panoramaProjection(float shiftValue);
    cv::Mat serialProjection(int id);
    //void volumeRender(int Mode);

};

#endif // MAINWINDOW_H
