#include<FileManager.h>

void FileManager::OpenFolder(){
    this->DirectoryName =QFileDialog::getExistingDirectory(this,tr("Open Directory"),"C:\\",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    this->Directory = this->DirectoryName;
    this->DICOM_FILES =Directory.entryList(QStringList() << "*.dcm", QDir::Files);
    return;
}

void FileManager::ConvertSTR(){
    foreach (QString Dicom, DICOM_FILES)
    {
        this->ImagesNames.push_back(Dicom.toUtf8().constData());
        std::string the_path = this->DirectoryName.toStdString() + "\\" + Dicom.toUtf8().constData();
        this->ImagesPath.push_back(the_path);
    }
    return;
}



