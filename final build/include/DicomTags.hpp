#ifndef DICOMTAGS_H
#define DICOMTAGS_H
#include <map>

#include <itkImageSeriesReader.h>
#include <itkGDCMImageIO.h>
#include <itkGDCMSeriesFileNames.h>


class DicomTags{
    public:
        std::map<std::string,std::string>dicomTags;
    public:
        DicomTags();
        ~DicomTags();
        void loadInfo(std::string);
        void Reset();
};

#endif
