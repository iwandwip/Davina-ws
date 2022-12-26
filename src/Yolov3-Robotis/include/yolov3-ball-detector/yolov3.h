#pragma once

#include "header.h"
#include "structures.h"

#ifndef YOLO_BALL_DETECTOR_H
#define YOLO_BALL_DETECTOR_H

struct Yolov3BallDetector
{
    void Init();
    void ReadPath();
    void Handler(const cv::Mat img);

private:
    std::string Classes,
        Models,
        Config,
        Line;

    std::vector<std::string> classes;
    std::string basePath = BasePath;

    cv::Mat blob;
#ifdef CV_4
    cv::dnn::Net net = cv::dnn::readNetFromDarknet(Config_t, Models_t);
#endif
    long long tmr;
};

extern Yolov3BallDetector yolov3;

#endif // YOLO_BALL_DETECTOR_H