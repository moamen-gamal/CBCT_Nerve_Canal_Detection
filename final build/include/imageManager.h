#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include "statistics.hpp"
#include "DicomTags.hpp"
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

#include <dcmtk/dcmimage/dicoimg.h>
#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmimage/diregist.h>
#include <dcmtk/dcmjpeg/djencode.h>
#include <dcmtk/dcmjpeg/djdecode.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

class ImageManager{
    public:
        std::vector<DicomImage*>DicomImages;
        std::vector<std::unique_ptr<cv::Mat>> axialImages;
        std::vector<std::unique_ptr<cv::Mat>> coronalImages;
        std::vector<std::unique_ptr<cv::Mat>> sagittalImages;
        statistics statistics;
        DicomTags  header;
    public:
        ImageManager();
        ~ImageManager();
        void loadImages(std::vector<std::string>&);
        void artifactReduction(int,int,int);
        void grayTransform();
        void MPR();
        void Reset();
};
#endif
