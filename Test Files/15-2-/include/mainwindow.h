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
	QGraphicsEllipseItem *Ellipse;

    std::vector<std::string> DICOM_Names;
    std::vector<std::string> Full_Path_Names;
    QString folderPath;

    std::vector<DicomImage*>DicomImages;
    std::vector<cv::Mat*> axialImages;
    std::vector<cv::Mat*>coronalImages;
    std::vector<cv::Mat*>sagittalImages;

    int Histogram[256];
    double mean,stddev,variance;
    std::map<std::string,std::string>dicomTags;

public:
    std::vector<double>curveCtrlX;
    std::vector<double> curveCtrlY;
    std::vector<double> curveShiftX;
    std::vector<double> curveShiftY;
    int offset;
    SceneManager sceneManager;
    float slope;
    int maxSliceID;
public slots:
    void openFolder();
    void grayTransform();
    void MPR();
    void DicomTags(std::string FolderPath);
    int panoramaSliceSelect(std::vector<cv::Mat*>&Images);
    cv::Mat skeletonGenerate(cv::Mat image);
    void ctrlPtsCalculate(cv::Mat skeleton);
    int Offset(cv::Mat img);
    cv::Mat constructPanorama(int shiftValue);
    void shiftCurve(int shift);
    void constructSerialView(int Slider_Value);
    float NegativeSlope(int x1,int x2,int y1,int y2);
    float NegativeSlopeArc(int x1,int x2,int y1,int y2);

public slots:
    void fullScreen(int id);
    void minScreen(int id);
    void setSliders();
    void setViews();
    void axialSliderCtrl();
    void coronalSliderCtrl();
    void sagittalSliderCtrl();
    void panoramaSliderCtrl();
    void serialSliderCtrl();

};

#endif // MAINWINDOW_H
