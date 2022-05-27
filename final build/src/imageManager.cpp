#include "imageManager.h"

ImageManager::ImageManager(){}

ImageManager::~ImageManager(){}

void ImageManager::loadImages(std::vector<std::string>& path){
    DJDecoderRegistration::registerCodecs();
    for(int i =0;i<path.size();i++){
       this->DicomImages.push_back(new DicomImage(path[i].c_str(),0,0,0));
       this->axialImages.push_back(std::make_shared<cv::Mat>(cv::Mat(int(DicomImages[i]->getWidth())
                                                            ,int(DicomImages[i]->getHeight()),CV_16UC1,
                                                            (short*)DicomImages[i]->getOutputData(16))));
    }
}

void ImageManager::artifactReduction(int threshold, int slope,int intercept){
    for(int i =0;i<axialImages.size();i++){
       for(int j=0;j<axialImages[0]->rows;j++){
           for(int k=0;k<axialImages[0]->cols;k++){
               int HU = axialImages[i]->at<ushort>(j,k)*slope + intercept;
               if(HU >threshold){
                   axialImages[i]->at<ushort>(j,k) =threshold - intercept;
               }
           }
       }
   }
}

void ImageManager::grayTransform(){
    double max=axialImages[0]->at<ushort>(0,0),min=axialImages[0]->at<ushort>(0,1);
    for(int i =0;i<axialImages.size();i++){
        for(int j=0;j<axialImages[0]->rows;j++){
            for(int k=0;k<axialImages[0]->cols;k++){
                if(axialImages[i]->at<ushort>(j,k)<min)
                    min =axialImages[i]->at<ushort>(j,k);
                else if(axialImages[i]->at<ushort>(j,k)>max)
                    max =axialImages[i]->at<ushort>(j,k);
            }
        }
    }
    for(int i =0;i<axialImages.size();i++){
        for(int j=0;j<axialImages[0]->rows;j++){
            for(int k=0;k<axialImages[1]->cols;k++){
                int pixelValue = axialImages[i]->at<ushort>(j,k);
                int grayvalue = int(((pixelValue-min)/(max-min))*(pow(2,8)-1));
                axialImages[i]->at<ushort>(j,k) = grayvalue;
                this->statistics.addFreq(grayvalue);
            }
        }
        axialImages[i]->convertTo(*axialImages[i],CV_8UC1 );
    }
}

void ImageManager::MPR(){
    std::vector<std::shared_ptr<cv::Mat>>sagitialTempImages;
    for (int i = 0;i < axialImages[0]->rows; i++)
    {
        sagitialTempImages.push_back(std::make_shared<cv::Mat>(cv::Mat(axialImages[0]->rows, axialImages.size(),0)));
        coronalImages.push_back(std::make_shared<cv::Mat>(cv::Mat(axialImages.size(), axialImages[0]->rows,0)));
    }

    for (int K = axialImages.size() - 1;K >= 0;K--)
    {
        cv::Mat axialImage = *axialImages[K];

        for (int j = 0; j < axialImage.rows; j++)//To loop through all the pixels
        {
            for (int i = 0; i < axialImage.cols; i++)
            {
                coronalImages[j]->at<uchar>(K, i) = axialImage.at<uchar>(j, i);
                sagitialTempImages[j]->at<uchar>(i, K) = axialImage.at<uchar>(i,j);
            }
        }
    }
    for (int i = 0;i < coronalImages.size();i++)
    {
        //REMOVE IF NOT SAGITAL NO NEED TO ROTATE
        double angle = -90;
        // get rotation matrix for rotating the image around its center in pixel coordinates
        cv::Point2f center((sagitialTempImages[i]->cols - 1) / 2.0, (sagitialTempImages[i]->rows - 1) / 2.0);
        cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
        // determine bounding rectangle, center not relevant
        cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), sagitialTempImages[i]->size(), angle).boundingRect2f();
        // adjust transformation matrix
        rot.at<double>(0, 2) += bbox.width / 2.0 - sagitialTempImages[i]->cols / 2.0;
        rot.at<double>(1, 2) += bbox.height / 2.0 - sagitialTempImages[i]->rows / 2.0;

        sagittalImages.push_back(std::make_shared<cv::Mat>());
        cv::warpAffine(*sagitialTempImages[i], *sagittalImages[i], rot, bbox.size());
        cv::flip(*sagittalImages[i], *sagittalImages[i], 1);
    }
    sagitialTempImages.clear();
}

void ImageManager::Reset(){
    for(int i = DicomImages.size()-1; i>=0;i--){
        delete DicomImages[i];
        DicomImages.pop_back();
    }
    axialImages.clear();
    coronalImages.clear();
    sagittalImages.clear();
    this->statistics.Reset();
    this->header.Reset();
}
