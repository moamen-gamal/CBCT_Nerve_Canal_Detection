#ifndef _IMAGE_PROCESS_H
#define _IMAGE_PROCESS_H
#include<itkImage.h>
#include<itkGDCMImageIO.h>
#include<itkCastImageFilter.h>
#include<itkRescaleIntensityImageFilter.h>
#include<itkOpenCVImageBridge.h>

class ImageProcess{
public:
    ImageProcess(){};
    ~ImageProcess(){};

public:
    static constexpr unsigned int Dim = 2;
    using RawPixelType = float;
    using OutputPixelType = unsigned char;
    using RawImageType = itk::Image<RawPixelType,Dim>;
    using OutputImageType = itk::Image<OutputPixelType,Dim>;
    using CastFilterType = itk::CastImageFilter<RawImageType, OutputImageType>;
    using RescaleFilterType = itk::RescaleIntensityImageFilter<RawImageType, OutputImageType>;
    

};

#endif
