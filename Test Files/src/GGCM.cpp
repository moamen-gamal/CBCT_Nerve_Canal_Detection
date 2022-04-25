#include "GGCM.h"


GGCM::GGCM() : m_grayLevel(16){}

GGCM::~GGCM(){}


void GGCM::initGGCM(VecGGCM& vecGGCM, int size){
    assert(size == m_grayLevel);
    vecGGCM.resize(size);
    for (int i = 0; i < size; ++i){
        vecGGCM[i].resize(size);
    }

    for (int i = 0; i < size; ++i){
        for (int j = 0 ; j < size; ++ j){ 
            vecGGCM[i][j] = 0 ; 
        } 
    } 
} 

void GGCM::calGGCM(cv::Mat &inputImg, VecGGCM& vecGGCM,VecGGCM &tempVec_Gray,VecGGCM & tempVec_Gradient){ 
    cv::Mat src; 
    src = inputImg.clone(); 

    int height = src.rows;
     int width = src.cols; 

    int maxGrayLevel = 0 ;
     // find the maximum pixel gray value 
    for ( int i = 0 ; i < height; ++ i ){
         for( int j = 0 ; j < width; ++ j){
             int grayVal = src.at<uchar> (i,j);
             if (grayVal > maxGrayLevel){ 
                maxGrayLevel = grayVal; 
            } 
        } 
    }
     ++ maxGrayLevel; 

    tempVec_Gray. resize(height); 
    for ( int i = 0 ; i < height; ++ i){ 
        tempVec_Gray[i].resize(width); 
    } 

    //   grayscale normalization 
    if (maxGrayLevel > m_grayLevel) // if grayscale If the number of levels is greater than 16, the gray level of the image will be reduced to 16 levels.
    {
         for ( int i = 0 ; i < height; ++ i){
             for ( int j = 0 ; j < width; ++ j){
                 int tmpVal = src.at<uchar> (i,j); 
                tempVec_Gray[ i][j] = int (tmpVal*m_grayLevel/ maxGrayLevel); 
            } 
        } 
    } 
    else {    // If the number of gray levels is less than 16, generate the corresponding gray matrix 
        for ( int i = 0 ; i < height; ++ i){
             for ( int j = 0; j < width; ++j){
                int tmpVal = src.at<uchar>(i,j);
                tempVec_Gray[i][j] = tmpVal;
            }
        }
    }

    tempVec_Gradient.resize(height);
    for (int i = 0; i < height; ++i){
        tempVec_Gradient[i].resize(width);
    }
    int maxGradientLevel = 0;
//Find the gradient of an image
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if(i==0||i==height-1||j==0||j==width-1){
                tempVec_Gradient[i][j]=0;
            }else{
                int g_x=src.at<uchar>(i+1,j-1)+2*src.at<uchar>(i+1,j)+src.at<uchar>(i+1,j+1)
                        -src.at<uchar>(i-1,j-1)-2*src.at<uchar>(i-1,j)-src.at<uchar>(i-1,j+1);
                int g_y=src.at<uchar>(i-1,j+1)+2*src.at<uchar>(i,j+1)+src.at<uchar>(i+1,j+1)
                        -src.at<uchar>(i-1,j+1)-2*src.at<uchar>(i,j-1)-src.at<uchar>(i+1,j-1);
                int g=sqrt(g_x*g_x+g_y*g_y);
                tempVec_Gradient[i][j]=g;
                if(g>maxGradientLevel){
                    maxGradientLevel=g;
                }
            }
        }
    }
    ++maxGradientLevel;
//Gradient normalization
    if(maxGradientLevel>m_grayLevel){
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                int tmpVal = tempVec_Gradient[i][j];
                tempVec_Gradient[i][j] = int(tmpVal*m_grayLevel/maxGradientLevel); 
            } 
        } 
    } 
    // Get the gradient-gray co-occurrence matrix 
    for ( int i = 0 ; i < height; ++ i){
         for ( int j = 0 ; j < width; ++ j){
             int row= tempVec_Gray[i][j];
             int col= tempVec_Gradient[i][j]; 
            vecGGCM[row][col] ++ ; 
        } 
    } 
} 

// 2D array sum 
template<typename T> float sumVVector(std::vector<std::vector <T>> v) 
{

    float ans = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            ans += v[i][j];
        }
    }
    return ans;
}

//2D array sum by row
template<typename T>float sumRowVVector(std::vector<std::vector<T>> v, int num)
{float ans = 0;
    for(int i = 

    0; i < v.size(); ++i)
    {
        ans += v[num][i];
    }
    return ans;
}

//2D array sum by column
template<typename T>float sumColVVector(std::vector<std::vector<T>> v, int num)
{float ans = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        ans += v[i][num];
    }return ans;
}void GGCM::getGGCMFeatures(VecGGCM& vecGGCM, GGCMFeatures&

    
    

 features){
    float total=sumVVector(vecGGCM);
    for (int i = 0; i < m_grayLevel; ++i){
        float sumRowGray = 0;
        sumRowGray = sumRowVVector(vecGGCM, i);
        float sumColGrad =0;
        sumColGrad=sumColVVector(vecGGCM, i);
        for (int j = 0; j < m_grayLevel; ++j){
            features.small_grads_dominance += vecGGCM[i][j] / pow(j+1, 2);
            features.big_grads_dominance+=vecGGCM[i][j] * pow(j+1 ,2);
        }
        features.gray_asymmetry += pow(sumRowGray, 2);
        features.grads_asymmetry += pow(sumColGrad, 2);
    }

    features.small_grads_dominance /= total;
    features.big_grads_dominance /= total;
    features.gray_asymmetry /= total;
    features.grads_asymmetry /= total;

    std::vector<std::vector<float>> vecPGGCM;
    vecPGGCM.resize(m_grayLevel);
    for (int i = 0; i < m_grayLevel; ++i){
        vecPGGCM[i].resize(m_grayLevel);
    }

    for(int i=0;i<vecGGCM.size();i++){
        for(int j=0;j<vecGGCM[i].size();j++){
            int tmp=vecGGCM[i][j];
            vecPGGCM[i][j]=tmp/total;
        }
    }

    for(int i=0;i<m_grayLevel;i++){
        float sumRowGray = 0;
        sumRowGray = sumRowVVector(vecPGGCM, i);
        float sumColGrad=0;
        sumColGrad = sumColVVector(vecPGGCM, i);
        for(int j=0;j<m_grayLevel;j++){
            features.energy += pow(vecPGGCM[i][j], 2);
            if(vecGGCM[i][j] != 0)
            {
                features.entropy -= vecPGGCM[i][j] * log(vecPGGCM[i][j]);
                features.inertia += pow((i-j), 2) * vecPGGCM[i][j];
            }
            features.differ_moment += vecPGGCM[i][j] / (1 + pow((i-j), 2));
        }
        features.gray_mean += (i+1) * sumRowGray;
        features.grads_mean += (i+1) * sumColGrad;
        if(sumRowGray != 0){
            features.gray_entropy -= sumRowGray * log(sumRowGray);
        }
        if(sumColGrad!=0){
            features.grads_entropy-=sumColGrad*log(sumColGrad);
        }
    }

    for(int i=0;i<m_grayLevel;i++){
        float sumRowGray = 0;
        sumRowGray = sumRowVVector(vecPGGCM, i);
        features.gray_variance+=pow(i+1-features.gray_mean,2)*sumRowGray;
        float sumColGrad=0;
        sumColGrad = sumColVVector(vecPGGCM, i);
        features.grads_variance+=pow(i+1-features.grads_mean,2)*sumColGrad;
    }
    features.gray_variance = pow(features.gray_variance, 0.5);
    features.grads_variance = pow(features.grads_variance, 0.5);

    for(int i = 0; i < m_grayLevel; ++i){
        for(int j = 0; j < m_grayLevel; ++j){
            features.corelation += (i+1-features.gray_mean) * (j+1-features.grads_mean) * vecPGGCM[i][j];
        }
    }
    features.corelation =features.corelation /(features.gray_variance*features.grads_variance);

}