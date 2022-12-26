#include "yolov3-ball-detector/header.h"
#include "yolov3-ball-detector/systems.h"
#include "yolov3-ball-detector/image.h"
#include "yolov3-ball-detector/yolov3.h"

void Start()
{
        yolov3.Init();
#ifdef ROS
        ImageManager Im;

        ros::Rate rate(30);

        while (ros::ok())
        {
                Im.process();

                ros::spinOnce();
                rate.sleep();
        }
#endif

#ifdef NO_ROS
        iM.Init();
        iM.setWindowName("Frame");
        while (1)
        {
                iM.Handler();
                yolov3.Handler(
                    iM.getImages());
        }

#endif
}

void Shutdown()
{
        sys.Reset();
}

int main(int argc, char **argv)
{
#ifdef ROS
        ros::init(argc, argv, Node_t);
#endif
        sys.Init(Start, Shutdown);

        return 0;
}