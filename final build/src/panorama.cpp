#include "panorama.h"

panorama::panorama(){}
panorama::~panorama(){}


int panorama::panoramaSliceSelect(){
    std::vector<int>whiteNum;
    int size = axialImages.size()-1;
    int selections[9] = {int(size*(4/(float)16)),int(size*(5/(float)16)),int(size*(6/(float)16)),int(size*(7/(float)16)),
                        int(size*(8/(float)16)),int(size*(9/(float)16)),int(size*(10/(float)16)),int(size*(9/(float)16)),
                                                                                               int(size*(12/(float)16))};


    double 	maxval = 255;
    double 	thresh= mean+ 3 * stddev;
    cv::Mat ThresImages[9];
    for(int i =0;i<9;i++){
        cv::threshold(*axialImages[selections[i]], ThresImages[i], thresh, maxval, 0);
    }
    for(int i=0;i<9;i++){
        whiteNum.push_back(0);
        whiteNum[i] =cv::countNonZero(ThresImages[i]);
    }
    int max =0;
    for(int i=1;i<9;i++){
        if(whiteNum[max]<whiteNum[i]){
            max =i;
        }
    }
    return selections[max];

}

cv::Mat panorama::SkeletonGenerate(int id){
        cv::Mat image = *axialImages[id];
        double 	maxval = 255;
        double 	thresh= mean +3*stddev;
        cv::Mat thresholdedImg;
        cv::threshold(image, thresholdedImg, thresh, maxval, 0);

        cv::Mat im_floodfill = thresholdedImg.clone();
        cv::floodFill(im_floodfill, cv::Point(0, 0), cv::Scalar(255));
        cv::Mat im_floodfill_inv;
        cv::bitwise_not(im_floodfill, im_floodfill_inv);
        cv::Mat holeFilled = (thresholdedImg | im_floodfill_inv);
        cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(30,30));
        cv::Mat closingImg;
        morphologyEx(holeFilled, closingImg,cv::MORPH_CLOSE, element,cv::Point(-1, -1), 2);

        cv::Mat labelImage(image.size(), CV_32S),dst(image.size(), CV_8UC3);
        int nLabels = connectedComponents(closingImg, labelImage, 8);
        std::vector<cv::Vec3b> colors(nLabels);
        colors[0] = cv::Vec3b(0, 0, 0);//background
        for(int label = 1; label < nLabels; ++label){
            colors[label] = cv::Vec3b(0, 0, 0);
            if(label ==1)
            colors[label] = cv::Vec3b(255, 255, 255);
        }
        for(int r = 0; r < dst.rows; ++r){
            for(int c = 0; c < dst.cols; ++c){
                int label = labelImage.at<int>(r, c);
                cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
                pixel = colors[label];
            }
        }
        cvtColor(dst, dst, cv::COLOR_RGB2GRAY);
        this->offset = Offset(dst);
        cv::Mat blur;
        cv::blur(dst,blur,cv::Size(9,9));
        cv::Mat SkeletonImg;
        cv::ximgproc::thinning (blur, SkeletonImg ,  0);
        return SkeletonImg;
}

int panorama::Offset(cv::Mat img) {
    std::vector<int>whiteNum;
    for (int y = 0; y < img.cols; y++) {
        int sum = 0;
        for (int x = 0; x < img.rows; x++)
        {
            if (img.at<uchar>(y, x) > 0)
            {
                sum++;
            }
        }
        whiteNum.push_back(sum);
    }
    int avg =0;
    for(int i =0;i<whiteNum.size();i++){
        avg += whiteNum[i];
    }
    avg /= whiteNum.size();
    return avg;
}

void panorama::ctrlPtsCalculate(cv::Mat skeleton){
    std::vector <int >ptsX;
    std::vector <int >ptsY;
    this->curveCtrlX.clear();
    this->curveCtrlY.clear();

    for (int i = 0; i < skeleton.cols; i++)//To loop through all the pixels
    {
        for (int j = 0; j < skeleton.rows; j++)
        {
            if (skeleton.at<uchar>(j, i) == 255)
            {
                ptsX.push_back(i);
                ptsY.push_back(j);
            }
        }
    }

    for (int i = 0; i <= 10; i++) {
        std::vector<int>::iterator csitX = (i* ((ptsX.end() - 1) - ptsX.begin()) / 10) + ptsX.begin();
        std::vector<int>::iterator csitY = (i* ((ptsY.end() - 1) - ptsY.begin()) / 10) + ptsY.begin();
        cv::Point cubicPoint = { *csitX ,  *csitY };
        this->curveCtrlX.push_back(*csitX);
        this->curveCtrlY.push_back(*csitY);
}
}

void panorama::shiftCurve(float shift) {

    tk::spline curve(this->curveCtrlX, this->curveCtrlY, tk::spline::cspline);
    std::vector<double>derivs;
    if(this->curveShiftX.size() != 0){
        this->curveShiftX.clear();
        this->curveShiftY.clear();
    }
    for (int i = 0;i < this->curveCtrlX.size();i++) {

        derivs.push_back(curve.deriv(1, this->curveCtrlX[i]));
        this->curveShiftX.push_back(0);
        this->curveShiftY.push_back(0);
    }
    if (shift - (this->offset / 2) > 0) {
        float shiftValue = (shift - this->offset/2 );
        for (int i = 0;i < this->curveCtrlX.size();i++) {
            this->curveShiftY[i] = this->curveCtrlY[i] - (shiftValue / sqrt(1 + pow(derivs[i], 2)));
            this->curveShiftX[i] = this->curveCtrlX[i] + ((derivs[i] * shiftValue) / sqrt(1 + pow(derivs[i], 2)));
        }
    }
    else if (shift - (this->offset / 2) < 0) {
        float shiftValue = (this->offset/2 - shift);
        for (int i = 0;i < this->curveCtrlX.size();i++) {
            this->curveShiftY[i] = this->curveCtrlY[i] + (shiftValue / sqrt(1 + pow(derivs[i], 2)));
            this->curveShiftX[i] = this->curveCtrlX[i] - ((derivs[i] * shiftValue) / sqrt(1 + pow(derivs[i], 2)));
        }
    }
    else {
        //control points stay the same if not required a shift
        double shiftValue = 0;
        for (int i = 0;i < this->curveCtrlX.size();i++) {
            this->curveShiftX[i] = this->curveCtrlX[i];
            this->curveShiftY[i] = this->curveCtrlY[i];
        }
    }

}


void panorama::panoramaProjection(float shiftValue){
    panorama::shiftCurve(shiftValue);
    tk::spline curve(this->curveShiftX,this->curveShiftY,tk::spline::cspline);
    int colNum =this->curveShiftX[this->curveShiftX.size()-1] - this->curveShiftX[0] +2;
    this->panoramaImage =cv::Mat(cv::Size(colNum,axialImages.size()),CV_8UC1);
    for(int i=0;i<axialImages.size();i++){
        int col=0;
        for(int j =this->curveShiftX[0];j<this->curveShiftX[this->curveShiftX.size()-1];j++){
            if(j < 0 || j> axialImages[i]->cols-1 || curve(j)<0 ||curve(j)>axialImages[i]->rows-1){
                this->panoramaImage.at<uchar>(i,col) = 0;
            }
            else{
                this->panoramaImage.at<uchar>(i,col) = axialImages[i]->at<uchar>(curve(j),j);
            }
            col++;

        }
    }
    
}
cv::Mat panorama::serialProjection(int id){
    tk::spline curve(this->curveCtrlX,this->curveCtrlY,tk::spline::cspline);
    cv::Mat serial(axialImages.size(),203*3,CV_8UC1);
    float slope = curve.deriv(1,id);
    int point_x =id, point_y = curve(id);
    int b = -1*slope*point_x+point_y;
    for(int i =0;i<axialImages.size();i++){
    int col=0;
    for(int x =id-100;x<id+100;x++){
       int y = slope*x+b;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;

    }
    }
    float slope_2 = curve.deriv(1,id+5);
    int point_x_2 =id+5, point_y_2 = curve(id+5);
    int b_2 = -1*slope_2*point_x_2+point_y_2;
    for(int i =0;i<axialImages.size();i++){
    int col=203;
    for(int x =id+5-100;x<id+5+100;x++){
       int y = slope_2*x+b_2;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;

    }
    }
    float slope_3 = curve.deriv(1,id+20);
    int point_x_3 =id+20, point_y_3 = curve(id+20);
    int b_3 = -1*slope_3*point_x_3+point_y_3;
    for(int i =0;i<axialImages.size();i++){
    int col=406;
    for(int x =id+20-100;x<id+20+100;x++){
       int y = slope_3*x+b_3;
       if(x < 0 || x> axialImages[i]->cols-1 || y<0 ||y>axialImages[i]->rows-1){
           serial.at<uchar>(i,col)=0;
       }
       else
            serial.at<uchar>(i,col) = axialImages[i]->at<uchar>(y,x);
       col++;
    }
    }
    return serial;
}

