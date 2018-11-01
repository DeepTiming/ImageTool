#include "opencv2/highgui/highgui.hpp";
#include "opencv2/imgproc/imgproc.hpp"
 
#include <iostream>
#include <stdio.h>
 
using namespace cv;
using namespace std;
 
#define DST_IMG_WIDTH 24        //需要调整图片后的尺寸宽度
#define SRC_IMG_HEIGH 24        //需要调整图片后的尺寸高度
 
int main(int argc, char* argv[])
{
	Mat src_img;
	int i, j;
	string src_img_name = "yale/", dst_img_name = "yale_small_size/";//源文件和目的文件的文件夹名字
	char chari[5], charj[5];//因为人脸数据不是很多，所以下标5足够用
	for (i = 1; i <= 15; i++)//15个人的人脸数据
	{
		for (j = 1; j <= 11; j++)//每个人的人脸有11种不同的表情
		{
			itoa(i, chari, 10);//将变量转换成字符型，此处的chari是字符数组首地址，但是如果定义为char *chari="";则会出现错误，why？
			itoa(j, charj, 10);
 
			src_img_name += chari;//原图命名格式为，比如第5个人的第6张图，5_s6.bmp
			src_img_name += "_s";
			src_img_name += charj;
			src_img_name += ".bmp";
 
		      src_img = imread(src_img_name, 1);
			Mat dst_img_rsize(DST_IMG_WIDTH, SRC_IMG_HEIGH, src_img.type());
			resize(src_img, dst_img_rsize, dst_img_rsize.size(), 0, 0, INTER_LINEAR);
 
		    dst_img_name += chari;//转换后图的命名格式为：例上，5_s6n.bmp
			dst_img_name += "_s";
			dst_img_name += charj;
			dst_img_name += "n.bmp";
 
		       imwrite(dst_img_name, dst_img_rsize);
			src_img_name = "yale/", dst_img_name = "yale_small_size/";//每次循环后要重新清0字符数组内的内容，目的文件夹一定要事先建立，否则无效果
 
			
		}
	}
	return 0;
}
