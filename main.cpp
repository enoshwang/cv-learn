#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <random>

#include "ImageSimilarity.hpp"

// 添加椒盐噪声
void saltAndPepperNoise(cv::Mat image, int saltAndPepperPercentage);
// 减色
void colorReduce(cv::Mat image, int div);

int main(int argc, char** argv)
{
    // 创建一个空图像
    //cv::Mat image(400,600,CV_8UC3,cv::Scalar(0,0,255));

    cv::Mat image = cv::imread("C:/Users/enosh/Pictures/test.jpg", cv::IMREAD_COLOR);

    colorReduce(image, 16);

    // 显示图像
    cv::imshow("Display window", image);
    cv::waitKey(0);

    cv::imwrite("C:/Users/enosh/Pictures/test_color_reduce2.jpg", image);

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

void saltAndPepperNoise(cv::Mat image, int saltAndPepperPercentage)
{
    if (saltAndPepperPercentage < 0 || saltAndPepperPercentage > 100)
    {
        return;
    }

    auto saltAndPepperCount = static_cast<int>(image.rows * image.cols * saltAndPepperPercentage / 100.0f);

    auto height = image.rows;
    auto width = image.cols;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rowDist(0, height - 1);
    std::uniform_int_distribution<> colDist(0, width - 1);

    for (int i = 0; i < saltAndPepperCount; i++)
    {
        auto row = rowDist(gen);
        auto col = colDist(gen);
        image.at<cv::Vec3b>(row, col)[0] = 0;
        image.at<cv::Vec3b>(row, col)[1] = 0;
        image.at<cv::Vec3b>(row, col)[2] = 0;
    }
}

void colorReduce(cv::Mat image, int div)
{
    if (div <= 1 || div > 255)
    {
        return;
    }

    auto rows = image.rows;
    auto elementsOfRow = image.cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < elementsOfRow; j++)
        {
            image.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0] / div * div + div / 2;
            image.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1] / div * div + div / 2;
            image.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2] / div * div + div / 2;
        }
    }
}
