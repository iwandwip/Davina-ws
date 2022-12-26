#include "yolov3-ball-detector/systems.h"

Systems sys;

void Systems::Init(void (*StartCallback)(void),
               void (*ShutdownCallback)(void)) {

        StartCallback();
        ShutdownCallback();
}

void Systems::Reset() {
}