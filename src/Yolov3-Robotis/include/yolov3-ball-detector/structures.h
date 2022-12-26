#pragma once

#include "header.h"
#include "vector"

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct LidarPoint {
    double x, y, z, r;
};

struct BoundingBox {
    int boxID;
    int trackId;

    cv::Rect roi;
    int classID;
    double confidence;

    std::vector<LidarPoint> lidarPoints;
    std::vector<cv::KeyPoint> keypoints;
    std::vector<cv::DMatch> kptMatchers;
};

#endif //STRUCTURES_H
