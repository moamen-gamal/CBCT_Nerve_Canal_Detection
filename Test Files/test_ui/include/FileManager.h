#ifndef _FILE_MANAGER_H
#define _FILE_MANAGER_H

#include <QFileDialog>
#include<string>
#include<vector>
using namespace std;
class FileManager : public QFileDialog
{
public:
    FileManager(){};
    ~FileManager(){};
private:
    QDir Directory;
    QString DirectoryName;
    QStringList DICOM_FILES;
    vector<string>ImagesNames;
    vector<string>ImagesPath;


public:
    void OpenFolder();
    void ConvertSTR();
    
};

#endif
