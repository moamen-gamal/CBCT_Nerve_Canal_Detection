
#ifndef DETECT_SOCKS_GGCM_H
#define DETECT_SOCKS_GGCM_H

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

typedef std::vector<std::vector<int>> VecGGCM;
typedef struct _GGCMFeatures
{
    _GGCMFeatures()
            : small_grads_dominance(0.0)

  

            , big_grads_dominance(0.0)
            , gray_asymmetry(0.0)
            , grads_asymmetry(0.0)
            , energy(0.0)
            , gray_mean(0.0)
            , grads_mean(0.0)
            , gray_variance(0.0)
            , grads_variance(0.0)
            , corelation(0.0)
            , gray_entropy(0.0)
            , grads_entropy(0.0)
            , entropy(0.0)
            , inertia( 0.0 ) 
            , differ_moment( 0.0 ) 


    {} 
    float small_grads_dominance;   // Small gradient advantage 
    float big_grads_dominance;   // Large gradient advantage 
    float gray_asymmetry;   // Gray distribution unevenness 
    float grads_asymmetry;   // Gradient distribution unevenness 
    float energy;   // energy 
    float gray_mean ;   // gray mean 
    float grads_mean ;   // gradient mean 
    float gray_variance ;   // gray mean square error 
    float grads_variance ;   // gradient mean square error 
    float corelation;   // correlation 
    float gray_entropy ;   // gray entropy 
    float grads_entropy ;   // gradient entropy 
    float entropy ;    // mixed entropy 
    float inertia ;   // inertia 
    float differ_moment ;    // inverse disparity 
} GGCMFeatures; 

class GGCM { 

public : 
    GGCM();
     ~ GGCM(); 

private :
     int m_grayLevel;   // Divide the gray level co-occurrence matrix into grayLevel levels 

public:
     // Initialize gray-gradient co-occurrence matrix 
    void initGGCM(VecGGCM& vecGGCM, int size = 16 );
     // Calculate gray-gradient co-occurrence matrix 
    void calGGCM(cv::Mat &inputImg,VecGGCM &vecGGCM,VecGGCM &tempVec_Gray,VecGGCM & tempVec_Gradient);
     // Calculate feature value 
    void getGGCMFeatures(VecGGCM& vecGGCM, GGCMFeatures& features); 
}; 


#endif  // DETECT_SOCKS_GGCM_H