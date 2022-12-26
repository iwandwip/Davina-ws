#pragma once

// #define CV_DEPRECATED
#define NO_ROS
#define CV_4

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "numeric"
#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CameraInfo.h>

#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include <math.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/dnn/dnn.hpp>

#define BasePath "/home/robotis/RobotisSoccer/src/yolov3-ball-detector/assets"

#define Models_t "/home/bayimaung/cicii_ws/src/Yolov3-Robotis/assets/models/data.weights"
#define Config_t "/home/bayimaung/cicii_ws/src/Yolov3-Robotis/assets/config/config.cfg"
#define Classes_t "/home/bayimaung/cicii_ws/src/Yolov3-Robotis/assets/classes/class.names"

#ifndef HEAD_H
#define HEAD_H
#endif // HEAD_H
