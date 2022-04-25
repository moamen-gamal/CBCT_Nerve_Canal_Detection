#include "scene.h"
#include <QToolTip>
#include <QtMath>
#include "All_Librarries.h"
#include <QGraphicsSceneHoverEvent>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

#include <math.h>

#include "GGCM.h"

#define PI 3.14159265
int AccumilatedNum = 0;
std::vector<std::vector<int>>IndexOfIndexesImages1;
std::vector<std::vector<int>>IndexOfIndexesImages2;
std::vector<std::vector<int>>IndexOfIndexesImages3;
std::vector<std::vector<int>>IndexOfIndexesImages4;
std::vector<cv::Mat>ParonamaSeriesFinal;

std::vector<cv::Mat>TheAllIndex;
std::vector<std::vector<cv::Mat>> NEEWROIS;
std::vector<std::vector<cv::Mat>>MAXROI;
std::vector<cv::Mat>BIGROIS;
int ZDefine;

std::vector<int>IntReserver;
void ImagesAccumilator(std::vector<int>IndexOfimages1)
{

	ZDefine++;
	std::sort(IndexOfimages1.begin(), IndexOfimages1.end());
	//IndexOfimages1.erase(std::unique(IndexOfimages1.begin(), IndexOfimages1.end()), IndexOfimages1.end());


	for (int i = 0; i < IndexOfimages1.size();i++)
	{

		IntReserver.push_back(IndexOfimages1[i]);
	}
	if (ZDefine == 3)
	{
		std::sort(IntReserver.begin(), IntReserver.end());
		//IntReserver.erase(std::unique(IntReserver.begin(), IntReserver.end()), IntReserver.end());

		for (int i = 0; i < IntReserver.size();i++)
		{
			TheAllIndex.push_back(BIGROIS[IntReserver[i]]);

		}
		QMessageBox mrc;
		mrc.setText(QString::number(IntReserver.size()));
		//mrc.exec();
	}

	
	

	//int Range = (Max - Min) - 1;
	
	std::string FolderOfImages = "G:\\MedicalDATA\\DICOM\\128602 - L  yz\\Paronama_Imagess";

	std::vector<cv::Mat>ParonamaSeries;

	

	std::vector<int>MX;
	for (int i = 0; i < IndexOfimages1.size(); i++)
	{

		int index = floor(IndexOfimages1[i] / 8);
		MX.push_back(index);

		
	}

	std::sort(MX.begin(), MX.end());
	//MX.erase(std::unique(MX.begin(), MX.end()), MX.end());

	for (int i = 0; i < MX.size(); i++)
	{


		//QMessageBox mkr;
		//mkr.setText(QString::number(MX[i]));
		//mkr.exec();



		std::string ImagesPath = FolderOfImages + "\\" + std::to_string(MX[i]) + ".jpeg";

		ParonamaSeries.push_back(cv::imread(ImagesPath, 0));

		
		//cv::imshow("Slide" , cv::imread(ImagesPath, 0));
		//cv::waitKey();

	}



	


	cv::Mat Accumilated = ParonamaSeries[ParonamaSeries.size()-1];
	Accumilated.setTo(cv::Scalar(0, 0, 0));


	for (int z = 0; z < ParonamaSeries.size();z++)
	{

		cv::resize(ParonamaSeries[z], ParonamaSeries[z], cv::Size(ParonamaSeries[ParonamaSeries.size() - 1].cols, ParonamaSeries[ParonamaSeries.size() - 1].rows));


	}

	int accumilated;
	std::vector<int>PixelValues;
	std::vector<std::vector<int>>PixelValuesVector;

	std::vector<double>AccumilatedInts(ParonamaSeries[ParonamaSeries.size() - 1].rows*ParonamaSeries[ParonamaSeries.size() - 1].cols, 0);
	for (int z = 0; z < ParonamaSeries.size();z++)
	{
		PixelValues.clear();
		for (int y = 0; y < ParonamaSeries[z].cols; y++) {
			for (int x = 0; x < ParonamaSeries[z].rows; x++)
			{

				PixelValues.push_back(ParonamaSeries[z].at<uchar>(x, y));


			}
		}

		PixelValuesVector.push_back(PixelValues);
	}

	for (int z = 0; z < PixelValuesVector.size();z++)
	{
		for (int m = 0; m < PixelValuesVector[0].size();m++)
		{
			AccumilatedInts[m] = AccumilatedInts[m] + exp((float)PixelValuesVector[z][m] / 10.0);
		}

	}

	int Delta = 0;
	for (int y = 0; y < Accumilated.cols; y++) {
		for (int x = 0; x < Accumilated.rows; x++)
		{

			Accumilated.at<uchar>(x, y) = (int)(10 * log(AccumilatedInts[Delta]));;
			Delta++;



		}
	}

	std::string MIU = "Accumilated" + std::to_string(AccumilatedNum);
	
	
	Mat gauessianEdit, panoramaFinal;
	cv::GaussianBlur(Accumilated, gauessianEdit, Size(3, 3), 0.8, 0.8);
	// cv::imshow("gauessianEdit", gauessianEdit);
	Mat enhancedPanorama = Mat::zeros(Accumilated.size(), CV_64FC1);
	enhancedPanorama = 0.9 * Accumilated + 0.1 * (Accumilated - gauessianEdit);
	enhancedPanorama.convertTo(panoramaFinal, CV_8UC1);

	//cv::Sobel(panoramaFinal, panoramaFinal,CV_64F,1,1);
	cv::imshow(MIU, panoramaFinal);





	ParonamaSeriesFinal.push_back(panoramaFinal);
	

	

}













void sectorSelection(double theta, uchar pixel, cv::Mat& kernel) {
	cv::Mat_<uchar> Kernel1(3, 3);

	Kernel1 << 1, 0, 0,
		1, pixel, 0,
		1, 0, 0;

	cv::Mat_<uchar> Kernel2(3, 3);
	Kernel2 << 0, 0, 0,
		1, pixel, 0,
		1, 1, 0;

	cv::Mat_<uchar> Kernel3(3, 3);

	Kernel3 << 0, 0, 0,
		0, pixel, 0,

		1, 1, 1;
	cv::Mat_<uchar> Kernel4(3, 3);
	Kernel4 << 0, 0, 0,
		0, pixel, 1,
		0, 1, 1;

	cv::Mat_<uchar> Kernel5(3, 3);

	Kernel5 << 0, 0, 1,
		0, pixel, 1,
		0, 0, 1;
	cv::Mat_<uchar> Kernel6(3, 3);
	Kernel6 << 0, 1, 1,
		0, pixel, 1,
		0, 0, 0;


	cv::Mat_<uchar> Kernel78(3, 3);

	Kernel78 << 1, 1, 1,
		0, pixel, 0,
		0, 0, 0;


	if (theta > -22.5 && theta <= 22.5) { kernel = Kernel1; }
	else if (theta > 22.5 && theta <= 67.5) { kernel = Kernel2; }
	else if (theta > 67.5 && theta <= 112.5) { kernel = Kernel3; }
	else if (theta > 112.5 && theta <= 157.5) { kernel = Kernel4; }
	else if (theta > 157.5 && theta <= -157.5) { kernel = Kernel5; }
	else if (theta > -157.5 && theta <= -112.5) { kernel = Kernel6; }
	else if (theta > -112.5 && theta <= -22.5) { kernel = Kernel78; }

}



void gradTheta(cv::Mat src, cv::Mat& gradient, cv::Mat& theta) {
	//return gtotal and theta
	cv::Mat gx = cv::Mat::zeros(src.size(), CV_64FC1);
	cv::Mat gy = cv::Mat::zeros(src.size(), CV_64FC1);
	cv::Mat gTotal = cv::Mat::zeros(src.size(), CV_64FC1);
	theta = cv::Mat::zeros(src.size(), CV_64FC1);



	for (int i = 1; i < src.rows - 1; ++i) {
		for (int j = 1; j < src.cols - 1; ++j) {
			gx.at<double>(i, j) = src.at<uchar>(i + 1, j - 1) + 2 * src.at<uchar>(i + 1, j) + src.at<uchar>(i + 1, j + 1)
				- src.at<uchar>(i - 1, j - 1) - 2 * src.at<uchar>(i - 1, j) - src.at<uchar>(i - 1, j + 1);


			gy.at<double>(i, j) = src.at<uchar>(i - 1, j + 1) + 2 * src.at<uchar>(i, j + 1) + src.at<uchar>(i + 1, j + 1)
				- src.at<uchar>(i - 1, j + 1) - 2 * src.at<uchar>(i, j - 1) - src.at<uchar>(i + 1, j - 1);


			if (gy.at<double>(i, j) == 0) {
				theta.at<double>(i, j) = 90;

			}
			else {


				theta.at<double>(i, j) = atan(-gx.at<double>(i, j) / gy.at<double>(i, j)) * 180 /PI;
			}
			gTotal.at<double>(i, j) = sqrt(pow(gx.at<double>(i, j), 2) + pow(gy.at<double>(i, j), 2));





			//result.at<uchar>(i - 1, j - 1) = filter(src, kernel, i, j);

		}
	}
	gTotal.convertTo(gradient, CV_8UC1);
	// imshow("gtotal", gradient);

}





void gradEnhancement(cv::Mat src, cv::Mat& result) {


	result = cv::Mat::zeros(src.size(), CV_8UC1);
	cv::Mat resultedit = cv::Mat::zeros(src.size(), CV_8UC1);
	cv::Mat kernel, gradient, theta;
	double maxPixel;
	double intermediate, sumkernel;
	int maxX, maxY;
	gradTheta(src, gradient, theta);

	for (int i = 1; i < src.rows - 1; i++) {
		for (int j = 1; j < src.cols - 1; j++) {
			sectorSelection(theta.at<double>(i, j), gradient.at<uchar>(i, j), kernel);
			maxPixel = 0;
			intermediate = kernel.at<uchar>(0, 0) * gradient.at<uchar>(i - 1, j - 1);
			maxX = i - 1;
			maxY = j - 1;
			// sumkernel = 0;
			for (int indexX = -1; indexX <= 1; indexX++) {
				for (int indexY = -1; indexY <= 1; indexY++) {
					intermediate = kernel.at<uchar>(1 + indexX, 1 + indexY) * gradient.at<uchar>(i + indexX, j + indexY);
					if (intermediate > maxPixel) {
						maxPixel = intermediate;
						maxX = i + indexX;
						maxY = j + indexY;
					}
					// sumkernel += kernel.at<uchar>(1 + indexX, 1 + indexY) * gradient.at<uchar>(i + indexX, j + indexY);
				}
			}
			// resultedit.at<uchar>(i, j) = sumkernel;
			// resultedit.at<uchar>(i, j) = maxPixel;
			result.at<uchar>(i, j) = gradient.at<uchar>(maxX, maxY);

		}
	}
	// imshow("resultedit", resultedit);
}


void GGCMetKmeans(std::vector<std::vector<cv::Mat>>& ROIS,std::vector<cv::Mat>& images) {
	
	


	
	int zeerer;
	int Zelda = 0;
	while(Zelda < 3) {

		
	Zelda == 0 ? zeerer = 4 : Zelda == 1 ? zeerer = 6 : zeerer = 5;
	if (ROIS.size() < 2)
	{
		Zelda = 5;
		zeerer = 15;
		ZDefine = 100;
	}

	
	cv::Mat p = cv::Mat::zeros(ROIS[0].size()*ROIS.size(), zeerer, CV_32F);
	//cv::imshow("p", p);
	cv::Mat bestLabels, centers, clustered;
	//std::vector<cv::Mat> bgr;
	//cv::split(src, bgr);

	VecGGCM vecGGCM;
	VecGGCM tempVec_Gray;
	VecGGCM tempVec_Gradient;
	GGCMFeatures features;
	int size = 16;
	GGCM Alpha;
	// Initialize gray-gradient co-occurrence matrix 
	Alpha.initGGCM(vecGGCM, size);
	// Calculate gray-gradient co-occurrence matrix 
	
	int ROWNum = 0;

	
		for (int z = 0; z < ROIS.size();z++) {
			for (int i = 0; i < ROIS[z].size(); i++) {

				//p.at<float>(i, 0) = (i / src.cols) / src.rows;
				//p.at<float>(i, 1) = (i%src.cols) / src.cols;
				cv::Mat newImage = ROIS[z][i];
				if (Zelda < 5) 
				{
					BIGROIS.push_back(newImage);
				}
				Alpha.calGGCM(newImage, vecGGCM, tempVec_Gray, tempVec_Gradient);
				// Calculate feature value 
				Alpha.getGGCMFeatures(vecGGCM, features);


				if (Zelda == 0)
				{
					p.at<float>(ROWNum, 0) = features.gray_asymmetry;
					p.at<float>(ROWNum, 1) = features.gray_entropy;
					p.at<float>(ROWNum, 2) = features.gray_mean;
					p.at<float>(ROWNum, 3) = features.gray_variance;


				}
				if (Zelda == 1)
				{

					p.at<float>(ROWNum, 0) = features.big_grads_dominance;
					p.at<float>(ROWNum, 1) = features.grads_asymmetry;
					p.at<float>(ROWNum, 2) = features.grads_entropy;
					p.at<float>(ROWNum, 3) = features.grads_mean;
					p.at<float>(ROWNum, 4) = features.grads_variance;
					p.at<float>(ROWNum, 5) = features.small_grads_dominance;


				}
				if (Zelda == 2)
				{

					p.at<float>(ROWNum, 0) = features.corelation;
					p.at<float>(ROWNum, 1) = features.differ_moment;
					p.at<float>(ROWNum, 2) = features.energy;
					p.at<float>(ROWNum, 3) = features.entropy;
					p.at<float>(ROWNum, 4) = features.inertia;


				}
				if (Zelda == 5) 
				{
					p.at<float>(ROWNum, 0) = features.gray_asymmetry;
					p.at<float>(ROWNum, 1) = features.gray_entropy;
					p.at<float>(ROWNum, 2) = features.gray_mean;
					p.at<float>(ROWNum, 3) = features.gray_variance;
					p.at<float>(ROWNum, 4) = features.big_grads_dominance;
					p.at<float>(ROWNum, 5) = features.grads_asymmetry;
					p.at<float>(ROWNum, 6) = features.grads_entropy;
					p.at<float>(ROWNum, 7) = features.grads_mean;
					p.at<float>(ROWNum, 8) = features.grads_variance;
					p.at<float>(ROWNum, 9) = features.small_grads_dominance;
					p.at<float>(ROWNum, 10) = features.corelation;
					p.at<float>(ROWNum, 11) = features.differ_moment;
					p.at<float>(ROWNum, 12) = features.energy;
					p.at<float>(ROWNum, 13) = features.entropy;
					p.at<float>(ROWNum, 14) = features.inertia;
				
				
				}


				//QMessageBox mss2;
				//mss2.setText(QString::number(ROWNum));
				//mss2.exec();
				ROWNum++;
			}
		}
		//cv::imshow("p2", p);
		int K = 4;
		cv::kmeans(p, K, bestLabels,
			cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 10, 1.0),
			100, cv::KMEANS_PP_CENTERS, centers);




		
		std::vector<int>IndexOfimages1;
		std::vector<int>IndexOfimages2;
		std::vector<int>IndexOfimages3;
		std::vector<int>IndexOfimages4;


		QMessageBox mss;
		//mss.setText(QString::number(bestLabels.rows));
		//mss.exec();
		// store every cluster in a vector
		for (int e = 0; e < bestLabels.rows; e++)
		{



			if (bestLabels.at<int>(0, e) == 0)
			{



				IndexOfimages1.push_back(e);

			}

			if (bestLabels.at<int>(0, e) == 1)
			{
				IndexOfimages2.push_back(e);



			}
			if (bestLabels.at<int>(0, e) == 2)
			{
				IndexOfimages3.push_back(e);


			}
			if (bestLabels.at<int>(0, e) == 3)
			{
				IndexOfimages4.push_back(e);


			}

		}


		IndexOfIndexesImages1.push_back(IndexOfimages1);
		IndexOfIndexesImages2.push_back(IndexOfimages2);
		IndexOfIndexesImages3.push_back(IndexOfimages3);
		IndexOfIndexesImages4.push_back(IndexOfimages4);
		Zelda++;

	}



		//collect the MPR images corresponding to ROI or enhanced and store it in curvedKmean
	/*
	std::vector<cv::Mat>curvedKmean;

		int indexImage;
		cv::Mat panorama;
		std::sort(IndexOfimages4.begin(), IndexOfimages4.end());
		IndexOfimages4.erase(unique(IndexOfimages4.begin(), IndexOfimages4.end()), IndexOfimages4.end());
		for (int i = 0; i < IndexOfimages1.size(); i++) {
			indexImage = floor(IndexOfimages1[i] / 2);
			curvedKmean.push_back(images[indexImage]);
			//cv::imshow("imagek" + i, images[indexImage]);
		}
		*/
		
	
	if (ZDefine < 3) {
		ImagesAccumilator(IndexOfIndexesImages1[1]);
		AccumilatedNum++;


		ImagesAccumilator(IndexOfIndexesImages2[0]);
		//AccumilatedNum++;
		//ImagesAccumilator(IndexOfIndexesImages3[2]);
		AccumilatedNum++;
		ImagesAccumilator(IndexOfIndexesImages4[2]);

		AccumilatedNum++;
		std::vector<int>PixelValues;
		std::vector<std::vector<int>>PixelValuesVector;

		cv::Mat Accumilated = ParonamaSeriesFinal[ParonamaSeriesFinal.size() - 1];
		Accumilated.setTo(cv::Scalar(0, 0, 0));

		std::vector<double>AccumilatedInts(ParonamaSeriesFinal[ParonamaSeriesFinal.size() - 1].rows*ParonamaSeriesFinal[ParonamaSeriesFinal.size() - 1].cols, 0);
		for (int z = 0; z < ParonamaSeriesFinal.size();z++)
		{
			PixelValues.clear();
			for (int y = 0; y < ParonamaSeriesFinal[z].cols; y++) {
				for (int x = 0; x < ParonamaSeriesFinal[z].rows; x++)
				{

					PixelValues.push_back(ParonamaSeriesFinal[z].at<uchar>(x, y));


				}
			}

			PixelValuesVector.push_back(PixelValues);
		}

		for (int z = 0; z < PixelValuesVector.size();z++)
		{
			for (int m = 0; m < PixelValuesVector[0].size();m++)
			{
				AccumilatedInts[m] = AccumilatedInts[m] + exp((float)PixelValuesVector[z][m] / 10.0);
			}

		}

		int Delta = 0;
		for (int y = 0; y < Accumilated.cols; y++) {
			for (int x = 0; x < Accumilated.rows; x++)
			{

				Accumilated.at<uchar>(x, y) = (int)(10 * log(AccumilatedInts[Delta]));;
				Delta++;



			}
		}

		std::string MIU = "Accumilated" + std::to_string(AccumilatedNum);
		cv::imshow(MIU, Accumilated);
		cv::waitKey();
	
	
	
	
	}
		if (ZDefine == 3)
		{

			MAXROI.push_back(TheAllIndex);
			
			GGCMetKmeans(MAXROI, TheAllIndex);
			ImagesAccumilator(IndexOfIndexesImages1[3]);
			AccumilatedNum++;
			ImagesAccumilator(IndexOfIndexesImages2[3]);
			AccumilatedNum++;
			ImagesAccumilator(IndexOfIndexesImages3[3]);
			AccumilatedNum++;
			ImagesAccumilator(IndexOfIndexesImages4[3]);
			AccumilatedNum++;


		}




		

		// generate panorame from the sets
		/*
		cv::Mat synthesised = cv::Mat::zeros(curvedKmean[0].size(), CV_64FC1);
		double sumePixels = 0;
		for (int i = 0; i < curvedKmean[0].rows; ++i) {
			for (int j = 0; j < curvedKmean[0].cols; ++j) {

				for (int m = 0; m < curvedKmean.size(); m++) {
					sumePixels += exp(curvedKmean[m].at<uchar>(i, j) / 10);

				}
				synthesised.at<double>(i, j) = 10 * log(sumePixels);
				sumePixels = 0;
			}

		}

		synthesised.convertTo(panorama, CV_8UC1);


		// cv::imshow("panorama" , panorama);

		 // enhance panorama

		cv::Mat gauessianEdit, panoramaFinal;
		cv::GaussianBlur(panorama, gauessianEdit, cv::Size(3, 3), 0.8, 0.8);
		// cv::imshow("gauessianEdit", gauessianEdit);
		cv::Mat enhancedPanorama = cv::Mat::zeros(curvedKmean[0].size(), CV_64FC1);
		enhancedPanorama = 0.9 * panorama + 0.1*(panorama - gauessianEdit);
		enhancedPanorama.convertTo(panoramaFinal, CV_8UC1);
		*/
		//cv::imshow("panoramaFinal", panoramaFinal);
	
}















 QString dist;
 std::vector<QGraphicsSceneMouseEvent*>PointsSelectedVector;
 int K_Definer = 0;
 int PointsPressed = 1;

 class Pointor : public QGraphicsEllipseItem {
 public:
	 Pointor(QGraphicsItem *parent = nullptr) : QGraphicsEllipseItem(parent) {
		 setRect(QRectF(-5, -5, 10, 10));
		 QPen pen;
		 pen.setCosmetic(true);
		 pen.setWidth(7);
		 pen.setColor(QColor(Qt::green));
		 setPen(pen);
		 QBrush brush;
		 brush.setStyle(Qt::SolidPattern);
		 setBrush(brush);
		 setAcceptHoverEvents(true);
		 ItemIsMovable*(true);


	 }
 protected:
	 void hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
		 QPen pen;
		 pen.setColor(Qt::blue);
		 pen.setWidth(2);
		 setPen(pen);
		 QGraphicsEllipseItem::hoverEnterEvent(event);

	 }
	 void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
	 }
 };


 /*
 void QGraphicsScene::mouseMoveEvent (QGraphicsSceneMouseEvent * event)
 {		
		QPointF origPoint;
		QPointF secOrigPoint;
		QGraphicsLineItem* itemToDraw;
		QGraphicsLineItem* secItemToDraw;
	 
		itemToDraw = new QGraphicsLineItem;

		this->addItem(itemToDraw);
		itemToDraw->setPen(QPen(Qt::red, 3, Qt::SolidLine));
		itemToDraw->setPos(origPoint);
		 
		 itemToDraw->setLine(0, 0,
			 event->scenePos().x() - origPoint.x(),
			 event->scenePos().y() - origPoint.y());
		 float distance = qSqrt(qPow(event->scenePos().x() - origPoint.x(), 2) + qPow(event->scenePos().y() - origPoint.y(), 2));
		 dist = QString::number(distance, 'f', 2);
		 itemToDraw->setToolTip(dist);
		 //itemToDraw->setToolTipDuration(500);

	 


 }

 */

Scenez::Scenez(QObject* parent): QGraphicsScene(parent)
{
    sceneMode = NoMode;
    itemToDraw = 0;
    secItemToDraw = 0;
    secSeg = 0;
}

void Scenez::setMode(Mode mode){
    sceneMode = mode;
    QGraphicsView::DragMode vMode =
            QGraphicsView::NoDrag;
    if(mode == DrawLine){
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }
    else if(mode == SelectObject){
        makeItemsControllable(true);
        vMode = QGraphicsView::RubberBandDrag;
    }
    QGraphicsView* mView = views().at(0);
    if(mView)
        mView->setDragMode(vMode);
}

void Scenez::makeItemsControllable(bool areControllable){
    foreach(QGraphicsItem* item, items()){
        item->setFlag(QGraphicsItem::ItemIsSelectable,
                      areControllable);
        item->setFlag(QGraphicsItem::ItemIsMovable,
                      areControllable);
    }
}







// length measurements



std::vector<std::vector<cv::Mat>>ROIS;



double XStorererPos[] = { 12.3,26.6,44.5,62.464 };
double YStorererPos[] = {265.7,299.5,328.19,346.112};


int PosDefine = 0;
void Scenez::mousePressEvent(QGraphicsSceneMouseEvent *event){



	
	if (sceneMode == PointsSelected && PointsPressed <=4) 
	{
		PointsPressed++;
		Pointor* EllipserPoint  = new Pointor();
		PointsSelectedVector.push_back(event);
		QPen pen;
		pen.setColor(Qt::red);
		pen.setWidth(1);
		EllipserPoint->setPen(pen);
		
		this->addItem(EllipserPoint);
		EllipserPoint->setPos(event->scenePos().x(), event->scenePos().y());

		std::vector<cv::Mat> images;
		int Count = 84;
		for (int a = 0; a < Count; a++)
		{
			//read all images in curved MPR and resize 
			std::string name = cv::format("G:\\MedicalDATA\\PaonamaImagesss\\%d.jpeg", a);
			cv::Mat img = cv::imread(name);

			int up_width = 455;
			int up_height = 450;
			cv::Mat resized_up;
			//resize up
			resize(img, resized_up, cv::Size(up_width, up_height), cv::INTER_LINEAR);

			//cv::imshow("resized_Up", resized_up);
			//cv::waitKey();
			images.push_back(resized_up);

		}

		// create ROI and enhanced into vectors
		cv::Mat cropped, enhancedSmall;


		// make vector of ROIS(4 - ROI)
		// 



		
		std::vector<int>ROIStorerX;
		std::vector<int>ROIStorerY;



		std::vector<cv::Mat> ROI;
		//vector<Mat> Gset;
		for (int b = 0; b < Count; b++) {
			// ROI includes both roi in even and enhanced in odd size is double input
			images[b](cv::Rect(XStorererPos[PosDefine], YStorererPos[PosDefine], 63, 63)).copyTo(cropped);
			ROI.push_back(cropped);
			gradEnhancement(cropped, enhancedSmall);
			ROI.push_back(enhancedSmall);
		}


		ROIS.push_back(ROI);
		PosDefine++;
		if (ROIS.size() == 4) 
		{
			GGCMetKmeans(ROIS, images);
		}



		cv::waitKey();





















		QMessageBox mr;
		mr.setText("The X is "+QString::number(event->scenePos().x())+ "The Y is "+ QString::number(event->scenePos().y()));
		mr.exec();
	}
	else if (sceneMode == DrawLine)
	{
		origPoint = event->scenePos();
	}
	else
	{
		QMessageBox MMRC;
		MMRC.setText("Max 4 is pressed");
		MMRC.exec();

	}
    
    QGraphicsScene::mousePressEvent(event);


}


void DraweOfCurve() 
{


}


void Scenez::mouseMoveEvent(QGraphicsSceneMouseEvent *event){


    if(sceneMode == DrawLine){
        if(!itemToDraw){
            itemToDraw = new QGraphicsLineItem;

            this->addItem(itemToDraw);
            itemToDraw->setPen(QPen(Qt::red, 3, Qt::SolidLine)); 
            itemToDraw->setPos(origPoint);
        }
        itemToDraw->setLine(0,0,
                            event->scenePos().x() - origPoint.x(),
                            event->scenePos().y() - origPoint.y());
        float distance = qSqrt(qPow(event->scenePos().x() - origPoint.x(),2)+ qPow(event->scenePos().y() - origPoint.y(),2));
        dist = QString::number(distance, 'f', 2);
        itemToDraw->setToolTip(dist);
        //itemToDraw->setToolTipDuration(500);

    }
    else
        QGraphicsScene::mouseMoveEvent(event);

}




void Scenez::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
	
	
		//Scenez::mouseMoveEvent(event);
		K_Definer = 1;

		if (sceneMode == DrawLine) {
			QMessageBox kk;
			QString rc = QString::number((dist.toFloat() *0.2));
			kk.setText("The Length is " + rc + "mm");
			kk.exec();

		}
	
    itemToDraw = 0;
    //QGraphicsScene::mouseMoveEvent(event);
}

/*
//angle measurements
void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine)
        origPoint = event->scenePos();
    QGraphicsScene::mousePressEvent(event);


}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine) {
        if (!itemToDraw) {
            itemToDraw = new QGraphicsLineItem;

            this->addItem(itemToDraw);
            itemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            itemToDraw->setPos(origPoint);
        }
        itemToDraw->setLine(0, 0,
            event->scenePos().x() - origPoint.x(),
            event->scenePos().y() - origPoint.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    secOrigPoint = event->scenePos();
    itemToDraw = 0;
    secSeg = 1;
    QGraphicsScene::mouseReleaseEvent(event);
}

bool Scene::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::MouseMove)
    {
        if (sceneMode == DrawLine) {
            if (secSeg) {
                QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
                statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));


                itemToDraw = new QGraphicsLineItem;

                this->addItem(itemToDraw);
                itemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
                itemToDraw->setPos(origPoint);
            }
            itemToDraw->setLine(0, 0,
                event->scenePos().x() - origPoint.x(),
                event->scenePos().y() - origPoint.y());
        }
    }
    else
        QGraphicsScene::mouseMoveEvent(event);

    
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (sceneMode == DrawLine) {
        if (!secItemToDraw) {
            secItemToDraw = new QGraphicsLineItem;

            this->addItem(secItemToDraw);
            secItemToDraw->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            secItemToDraw->setPos(secOrigPoint);
        }
        secItemToDraw->setLine(0, 0,
            event->scenePos().x() - secOrigPoint.x(),
            event->scenePos().y() - secOrigPoint.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}
*/
////////////////////////////////////////////////
void Scenez::keyPressEvent(QKeyEvent *event){
	QMessageBox wwwm;
	wwwm.exec();
	if (event->key() == Qt::Key_L || event->key() == Qt::Key_R)
       foreach(QGraphicsItem* item, selectedItems()){

			QMessageBox wwwm;
			wwwm.exec();
			removeItem(item);
            delete item;
        }
    else
        Scenez::keyPressEvent(event);
}


void QGraphicsScene::keyPressEvent(QKeyEvent *event)
{

	if (event->key() == Qt::Key_L)
	{

		QMessageBox wwwm;
		wwwm.exec();

	}		

}

