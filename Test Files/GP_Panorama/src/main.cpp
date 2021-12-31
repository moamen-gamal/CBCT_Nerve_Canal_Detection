
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <sstream>
#include <opencv2/opencv.hpp>
#include"opencv2/imgproc.hpp"
#include"opencv2/ximgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include"opencv2/ximgproc.hpp"
#include <opencv2/imgproc.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

int main()
{
    /*Mat image = imread("picture.jpg", CV_LOAD_IMAGE_GRAYSCALE); */
    string image_path = "C:\\Users\\moamen\\Desktop\\GP_Panorama\\CT_IMAGES\\DCM340.jpeg";
    Mat image = imread(image_path, IMREAD_GRAYSCALE);


    // allcoate memory for no of pixels for each intensity value
    int histogram[256];

    // initialize all intensity values to 0
    for (int i = 0; i < 255; i++)
    {
        histogram[i] = 0;
    }

    // calculate the no of pixels for each intensity values
    for (int y = 0; y < image.rows; y++)
        for (int x = 0; x < image.cols; x++)
            histogram[(int)image.at<uchar>(y, x)]++;

    for (int i = 0; i < 256; i++)
        cout << histogram[i] << " ";

    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w / 256);

    Mat histImage( hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

    // find the maximum intensity element from histogram
    int max = histogram[0];
    for (int i = 1; i < 256; i++) {
        if (max < histogram[i]) {
            max = histogram[i];
        }
    }

    // normalize the histogram between 0 and histImage.rows

    for (int i = 0; i < 255; i++) {
        histogram[i] = ((double)histogram[i] / max) * histImage.rows;
    }


    // draw the intensity line for histogram
    for (int i = 0; i < 255; i++)
    {
        line(histImage, Point(bin_w * (i), hist_h),
            Point(bin_w * (i), hist_h - histogram[i]),
            Scalar(0, 0, 0), 1, 8, 0);
    }

    // display histogram
    //cv::imshow("Intensity Histogram", histImage);
    cv::imshow("image", image);
    // gauessian fitting and pick T thresholding value
   //double thresh = mean + w * sd
    // thresholding
    cv::Scalar mean, stddev;
    cv::meanStdDev(image, mean, stddev);

    double 	maxval = 255;
    double 	thresh= mean[0]+ 2 * stddev[0];
    cv::Mat thresholdedImg;
    cv::threshold(image, thresholdedImg, thresh, maxval, 0);

      cv::imshow("thresholded", thresholdedImg);

      //hole filling
       // Floodfill from point (0, 0)

          Mat im_floodfill = thresholdedImg.clone();

          cv::floodFill(im_floodfill, cv::Point(0, 0), Scalar(255));

          // Invert floodfilled image

          Mat im_floodfill_inv;

          cv::bitwise_not(im_floodfill, im_floodfill_inv);

          // Combine the two images to get the foreground.

          Mat holeFilled = (thresholdedImg | im_floodfill_inv);

         // cv::imshow("Floodfilled Image", im_floodfill);
          //cv::imshow("Inverted Floodfilled Image", im_floodfill_inv);
          cv::imshow("Foreground", holeFilled);
          //morphological closing with element
          //disk radius 15 pixels

          Mat element = getStructuringElement(MORPH_ELLIPSE,
              Size(20,20));

          /*closingImg = close(holeFilled, element) = erode(dilate(holeFilled, element));*/
          Mat closingImg;
          morphologyEx(holeFilled, closingImg,
              MORPH_CLOSE, element,
              Point(-1, -1), 2);
          cv::imshow("closingImg", closingImg);

              Mat labelImage(image.size(), CV_32S),dst(image.size(), CV_8UC3);
              int nLabels = connectedComponents(closingImg, labelImage, 8);
              std::cout<< nLabels;
              std::vector<Vec3b> colors(nLabels);
                  colors[0] = Vec3b(0, 0, 0);//background
                  for(int label = 1; label < nLabels; ++label){
                      colors[label] = Vec3b(0, 0, 0);
                      if(label ==1)
                      colors[label] = Vec3b(255, 255, 255);
                  }
                  for(int r = 0; r < dst.rows; ++r){
                      for(int c = 0; c < dst.cols; ++c){
                          int label = labelImage.at<int>(r, c);
                          Vec3b &pixel = dst.at<Vec3b>(r, c);
                          pixel = colors[label];
                       }
                   }

              imshow( "Connected Components", dst );
          cvtColor(dst, dst, COLOR_RGB2GRAY);
          //cv::imshow("stats",statistics);
          //cv::imshow("centroid",centroid);
          Mat blur;
          cv::blur(dst,blur,Size(9,9));
          //morphological thinning
          cv::imshow("blurred",blur);
          Mat thiningImg;

          cv::ximgproc::thinning (blur, thiningImg ,  0);
          cv::imshow("thinned", thiningImg);
          cv::imwrite("skeleton.jpeg",thiningImg);
          cv::waitKey();
          return 0;
}





