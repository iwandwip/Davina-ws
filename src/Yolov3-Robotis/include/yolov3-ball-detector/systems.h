#pragma once

#include "image.h"

#define Node_t "yolov3_ball_detector_node"

#ifndef SYSTEM_H
#define SYSTEM_H

struct Systems {
    void Init(void (*Start)(void), void (*Shutdown)(void));
    void Reset();

private:
    long long tmr;
};

extern Systems sys;

#endif //SYSTEM_H
