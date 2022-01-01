#ifndef _IMAGE_CONTAINER_H
#define _IMAGE_CONTAINER_H

#include<itkImage.h>
#include<itkImageFileReader.h>
#include<string>
template <typename PixelType,unsigned int Dimension>
class DicomImage{

public:
    DicomImage(){};
    ~DicomImage(){};
public:
    static constexpr unsigned int Dim = Dimension;
    using ImageType = itk::Image<PixelType, Dim>;
    using ReaderType = itk::ImageFileReader<ImageType>;
    itk::Image<PixelType,Dim> ItkImage;
public:
    void Read(std::string Path);
};


#endif
