#include "statistics.hpp"
statistics::statistics(){
    for(int i=0;i<256;i++){
            this->histogram.push_back(0);
        }
}
statistics::~statistics(){}
void statistics::calculateMean(){
    double sumFreq = 0;
    double sumNum=0;
    for(int i=0;i<256;i++){
        sumFreq +=i*histogram[i];
        sumNum +=histogram[i];
    }
    this->mean =sumFreq/sumNum;
}
void statistics::calculateStdDev(){
    double fx2 = 0;
    double num = 0;
    double numerator, denom;
    for (int i = 0; i < histogram.size(); i++) {
        fx2 += pow(i, 2) * histogram[i];
        num += histogram[i];
    }
    numerator =  fx2 - num *pow(this->mean,2);
    denom =  (num - 1);
    this->stdDev = sqrt(numerator / denom);
}
void statistics::addFreq(int& value){
    this->histogram[value]++;
}
void statistics::Reset(){
    if(this->histogram.size() !=0){
        this->histogram.clear();
        for(int i=0;i<256;i++){
            this->histogram.push_back(0);
        }
    }
    else{
        for(int i=0;i<256;i++){
            this->histogram.push_back(0);
        }
    }
    this->mean =0;
    this->stdDev =0;
}
