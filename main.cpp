#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "ImageSimilarity.hpp"

int main(int argc, char** argv)
{
    // 创建一个空图像
    cv::Mat image(200,200,CV_8UC3,cv::Scalar(0,0,255));

    // 显示图像
    cv::imshow("Display window", image);
    cv::waitKey(0);



    return 0;

    // 读取图像
    image = cv::imread("C:/Users/enosh/Desktop/stream_media.png", cv::IMREAD_COLOR);
    if(image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
    }
    else
    {
        std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;

        // 显示图像
        cv::imshow("Display window", image);
        cv::waitKey(0);
    }

    cv::Mat result;
    // 翻转图像
    cv::flip(image, result, 1);

    // 显示图像
    cv::imshow("Display window", result);
    cv::waitKey(0);

    // 保存图像
    cv::imwrite("C:/Users/enosh/Desktop/stream_media_flip.png", result);

    return 0;
}