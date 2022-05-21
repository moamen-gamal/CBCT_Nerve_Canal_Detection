#ifndef STATISTICS_H
#define STATISTICS_H
#include<vector>

#include <opencv2/opencv.hpp>

class statistics{
    public:
        double mean=0;
        double stdDev=0;
        std::vector<int>histogram;
    public:
        statistics();
        ~statistics();
        void calculateMean();
        void calculateStdDev();
        void addFreq(int&);
        void Reset();
};
#endif