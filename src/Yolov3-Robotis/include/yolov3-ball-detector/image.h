#pragma once

#include "header.h"
#include "yolov3.h"

#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#define DEBUG

class ImageManager
{
private:
#ifdef ROS
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    image_transport::Publisher image_pub_;

    cv_bridge::CvImagePtr cv_ptr;
    cv_bridge::CvImage cv_img_pubs_;

    cv::Mat in_img_;
    cv::Mat out_img_;

    ros::Subscriber cam_info_sub_;
    sensor_msgs::CameraInfo cam_info_msg_;

    void imageCallBack(const sensor_msgs::ImageConstPtr &msg);
    void cameraInfoCallback(const sensor_msgs::CameraInfo &_msg);

    cv::Mat &setInputImage();
#else
    cv::Mat resizeImage(const cv::Mat &src, int width, int height);

#endif
public:
    ImageManager();
    ~ImageManager();
    void process();
};

#ifdef NO_ROS
struct iMage
{
    void Init();
    void Handler();
    void setWindowName(std::string __name);
    cv::Mat getImages();

private:
    cv::VideoCapture cap;

    cv::Mat in_img_;
    cv::Mat out_img_;

    double width;
    double height;
    cv::String name = "frame";
};

extern iMage iM;
#endif

#endif // IMAGE_MANAGER_H
