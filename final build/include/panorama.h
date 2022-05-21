#ifndef PANORAMA_H
#define PANORAMA_H


#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/imgcodecs.hpp>
// include tk spline?
#include <vector>
#include<spline.h>

class panorama{
    private:
    
        int offset;

        std::vector<double> curveCtrlX;
        std::vector<double> curveCtrlY;
        std::vector<cv::Mat*> axialImages;

    public:    

        std::vector<double> curveShiftX;
        std::vector<double> curveShiftY;
        cv::Mat panoramaImage;  

    public:
        panorama();
        ~panorama();
        int panoramaSliceSelect();
        cv::Mat SkeletonGenerate(int id);
        int Offset(cv::Mat img);
        void ctrlPtsCalculate(cv::Mat skeleton);
        void shiftCurve(float shift);
        void panoramaProjection(float shiftValue);
        cv::Mat serialProjection(int id);
};
#endif
