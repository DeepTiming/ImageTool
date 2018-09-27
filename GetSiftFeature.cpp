#include "opencv2/opencv.hpp"
#include <opencv2/xfeatures2d/nonfree.hpp>//SIFT
#include <vector>
#include<iostream>
using namespace std;
using namespace cv;
using namespace xfeatures2d;

void main()
{
	Mat srcImg1 = imread("E:\\Image\\0\\cell.bmp");
	 //Mat srcImg2 = imread("E:\\LeaperFiles\\MachineLearningData\\mlSample\\31\\1-627-5118615.png");
	//定义SIFT特征检测类对象
	SiftFeatureDetector siftDetector1;
	//SiftFeatureDetector siftDetector2;

	SiftFeatureDetector siftDetector;//SIFT=SiftFeatureDetector=SiftDescriptorExtractor    别名//定义KeyPoint变量
	vector<KeyPoint>keyPoints1;
	//vector<KeyPoint>keyPoints2;
	//特征点检测
	siftDetector.detect(srcImg1, keyPoints1);
	//siftDetector.detect(srcImg2, keyPoints2);
	//绘制特征点(关键点)
	Mat feature_pic1, feature_pic2;
	drawKeypoints(srcImg1, keyPoints1, feature_pic1, Scalar(0, 0, 255));
	//drawKeypoints(srcImg2, keyPoints2, feature_pic2, Scalar(0, 0, 255));
	//drawKeypoints(srcImg1, keyPoints1, feature_pic1, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);//颜色随机，带有方向
	//drawKeypoints(srcImg2, keyPoints2, feature_pic2, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	//显示原图
	imshow("src1", srcImg1);
	//imshow("src2", srcImg2);
	//显示结果
	imshow("feature1", feature_pic1);
	//imshow("feature2", feature_pic2);

	waitKey(0);
}