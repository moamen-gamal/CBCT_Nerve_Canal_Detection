#include <iostream>
#include <QtWidgets\qapplication.h>
#include <mainwindow.h>
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <qgraphicseffect.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qdatetime.h>
#include <qmainwindow.h>
#include <qstatusbar.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpainter.h>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <qlabel.h>
#include <qimage.h>
#include <qpixmap.h>
#include <QMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <qdebug.h>
#include <stdlib.h>
#include "All_Librarries.h"
#include "GGCM.h"
#include <opencv2\ximgproc.hpp>
using namespace QtCharts;
QString myImgName = "myimg.png";
static QImage *myImg;
#include <qmessagebox.h>
static const int imageRTTI = 984376;

class ImageItem : public QGraphicsRectItem
{
public:
	ImageItem(QImage img);
	int rtti() const { return imageRTTI; }
	void advance(int phase);
protected:
	void paint(QPainter *, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
	QImage image;
	QPixmap pixmap;
	int state;
};


void ImageItem::advance(int phase)
{
	if (state == 0)
	{
		moveBy(0, 30);
		state = 1;
	}
	else
	{
		moveBy(0, -30);
		state = 0;
	}
}


ImageItem::ImageItem(QImage img)
	: image(img)
{
	state = 0;
	setRect(0, 0, image.width(), image.height());
	setFlag(ItemIsMovable);
	pixmap = pixmap.fromImage(image, Qt::OrderedAlphaDither);

}

void ImageItem::paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *)
{
	p->drawPixmap(option->exposedRect, pixmap, option->exposedRect);
}

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	MainWindow t;
	t.show();
	/*
	QtCharts::QSplineSeries *series = new QtCharts::QSplineSeries();
	series->setName("spline");
	series->append(0, 6);
	series->append(2, 4);
	series->append(3, 8);
	series->append(7, 4);
	series->append(10, 5);
	//*series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
	QtCharts::QChart *chart = new QtCharts::QChart();
	chart->legend()->hide();
	chart->addSeries(series);
	chart->setTitle("Simple spline chart example");
	chart->createDefaultAxes();
	chart->axes(Qt::Vertical).first()->setRange(0, 10);
	QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	QMainWindow window77;
	window77.setCentralWidget(chartView);
	window77.resize(400, 300);
	window77.show(); 
	*/

	app.exec();
	//QApplication app();
	std::vector<cv::Mat> ParonamaShifted;
	for (int i = 1;i < 67;i++)
	{
		ParonamaShifted.push_back(cv::imread("G:\\MedicalDATA\\DICOM\\128602 - L  yz\\Paronama_ShiftImages\\ParonamaNum" + std::to_string(i) + ".jpeg"));
		//cv::imshow("ParonamaShiftedzz", ParonamaShifted[0]);
		//cv::Mat Hello;
		
	}

	//cv::Mat hello=cv::imread("C:\\Users\\EGYPT_LAPTOP\\Desktop\\Skeltonization\\TheParonamaWhale.jpeg",0);
	//cv::imshow("ParonamaShiftedzz", hello);
	///cv::ximgproc::thinning(hello, hello);
	//cv::imshow("ParonamaShiftedzz2", hello);
	//cv::waitKey();

	//src = imread("fruits.jpg");
	//imshow("original", src);

	//blur(src, src, cv::Size(15, 15));
	//imshow("blurred", src);

	cv::Mat p = cv::Mat::zeros(ParonamaShifted.size(), 15, CV_32F);
	cv::imshow("p", p);
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




	for (int i = 0; i < ParonamaShifted.size(); i++) {
		//p.at<float>(i, 0) = (i / src.cols) / src.rows;
		//p.at<float>(i, 1) = (i%src.cols) / src.cols;
		Alpha.calGGCM(ParonamaShifted[i], vecGGCM, tempVec_Gray, tempVec_Gradient);
		// Calculate feature value 
		Alpha.getGGCMFeatures(vecGGCM, features);

		//p.at<float>(i, 2) = bgr[0].data[i] / 255.0;
		//p.at<float>(i, 3) = bgr[1].data[i] / 255.0;
		//p.at<float>(i, 4) = bgr[2].data[i] / 255.0;
		p.at<float>(i, 0) = features.big_grads_dominance;
		p.at<float>(i, 1) = features.corelation;
		p.at<float>(i, 2) = features.differ_moment;
		p.at<float>(i, 3) = features.energy;
		p.at<float>(i, 4) = features.entropy;
		p.at<float>(i, 5) = features.grads_asymmetry;
		p.at<float>(i, 6) = features.grads_entropy;
		p.at<float>(i, 7) = features.grads_mean;
		p.at<float>(i, 8) = features.grads_variance;
		p.at<float>(i, 9) = features.gray_asymmetry;
		p.at<float>(i, 10) = features.gray_entropy;
		p.at<float>(i, 11) = features.gray_mean;
		p.at<float>(i, 12) = features.gray_variance;
		p.at<float>(i, 13) = features.inertia;
		p.at<float>(i, 14) = features.small_grads_dominance;






		if (i < 20) {
			//cv::imshow("p2" + std::to_string(i), p);
		}
	}

	//cv::imshow("p2", p);
	int K = 4;
	cv::kmeans(p, K, bestLabels,
		cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 10, 1.0),
		100, cv::KMEANS_PP_CENTERS, centers);




	QMessageBox mmk;
	

	std::vector<int>IndexOfimages1;
	std::vector<int>IndexOfimages2;
	std::vector<int>IndexOfimages3;
	std::vector<int>IndexOfimages4;


	for (int i = 0;i < bestLabels.rows;i++) 
	{
		if (bestLabels.at<int>(0, i) == 0) 
		{
			IndexOfimages1.push_back(i);
		
		}
		if (bestLabels.at<int>(0, i) == 1)
		{
			IndexOfimages2.push_back(i);



		}
		if (bestLabels.at<int>(0, i) == 2)
		{
			IndexOfimages3.push_back(i);


		}
		if (bestLabels.at<int>(0, i) == 3)
		{
			IndexOfimages4.push_back(i);


		}


	
	
	
	
	
	}

	mmk.setText("The number of IAC images "+QString::number(IndexOfimages1.size()));
	mmk.exec();

	mmk.setText("The number of mandibular edge images at certain angle "+QString::number(IndexOfimages2.size()));
	mmk.exec();

	mmk.setText("The number of mandibular images with uniform low gray level "+QString::number(IndexOfimages3.size()));
	mmk.exec();

	mmk.setText("The number of mandibular images with uniform high gray level "+QString::number(IndexOfimages4.size()));
	mmk.exec();














	//QMessageBox mk;
	//mk.setText("MM");
	//mk.exec();
	/*
	const int MAX_CLUSTERS = 5;
	cv::Scalar colorTab[] =
	{
		cv::Scalar(0, 0, 255),
		cv::Scalar(0,255,0),
		cv::Scalar(255,100,100),
		cv::Scalar(255,0,255),
		cv::Scalar(0,255,255)
	};
	cv::Mat img(500, 500, CV_8UC3);
	cv::RNG rng(12345);
	
	double compactness=0;
	//QMessageBox mk;
	//mk.setText(QString::number(compactness));
	//mk.exec();
	for (;;)
	{
		int k, clusterCount = rng.uniform(2, MAX_CLUSTERS + 1);
		int i, sampleCount = rng.uniform(1, 1001);
		cv::Mat points(sampleCount, 1, CV_32FC2), labels;
		clusterCount = MIN(clusterCount, sampleCount);
		std::vector<cv::Point2f> centers;
		/* generate random sample from multigaussian distribution */
	/*
		for (k = 0; k < clusterCount; k++)
		{
 			cv::Point center;
			center.x = rng.uniform(0, img.cols);
			center.y = rng.uniform(0, img.rows);
			cv::Mat pointChunk = points.rowRange(k*sampleCount / clusterCount,
				k == clusterCount - 1 ? sampleCount :
				(k + 1)*sampleCount / clusterCount);
			rng.fill(pointChunk, cv::RNG::NORMAL, cv::Scalar(center.x, center.y), cv::Scalar(img.cols*0.05, img.rows*0.05));
			//cv::imshow("pointchunk",points);
		}
		randShuffle(points, 1, &rng);
		compactness = kmeans(points, clusterCount, labels,
			cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0),
			3, cv::KMEANS_PP_CENTERS, centers);
		img = cv::Scalar::all(0);
		for (i = 0; i < sampleCount; i++)
		{
			int clusterIdx = labels.at<int>(i);
			cv::Point ipt = points.at<cv::Point2f>(i);
			circle(img, ipt, 2, colorTab[clusterIdx], cv::FILLED, cv::LINE_AA);
		}
		for (i = 0; i < (int)centers.size(); ++i)
		{
			cv::Point2f c = centers[i];
			circle(img, c, 40, colorTab[i], 1, cv::LINE_AA);
		}
		//cout << "Compactness: " << compactness << endl;
		QMessageBox mk;
		mk.setText(QString::number(compactness));
		mk.exec();
		imshow("clusters", img);
		char key = (char)cv::waitKey();
		if (key == 27 || key == 'q' || key == 'Q') // 'ESC'
			break;
	}
	return 0;

	*/





}