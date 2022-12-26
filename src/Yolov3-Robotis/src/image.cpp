#include "yolov3-ball-detector/image.h"

#ifdef NO_ROS
iMage iM;
#endif

ImageManager::ImageManager()
#ifdef ROS
    : nh_(ros::this_node::getName()),
      it_(this->nh_),
      image_sub_(it_.subscribe("/usb_cam_node/image_raw", 1,
                               &ImageManager::imageCallBack, this)),
      cam_info_sub_(nh_.subscribe("/usb_cam/camera_info", 100,
                                  &ImageManager::cameraInfoCallback, this))
#endif
{
}

ImageManager::~ImageManager()
{
        cv::destroyAllWindows();
}

void ImageManager::process()
{
#ifdef ROS
        if (cv_ptr == nullptr)
                return;
        setInputImage() = cv_ptr->image;

        yolov3.Handler(in_img_);
#endif

#if defined(ROS) && defined(DEBUG)
        cv::String name = "frame";
        cv::imshow(name, in_img_);
#endif

        cv::waitKey(1);
}
#ifdef ROS
cv::Mat &ImageManager::setInputImage()
{
        return in_img_;
}

void ImageManager::imageCallBack(const sensor_msgs::ImageConstPtr &msg)
{
        try
        {
                cv_ptr = cv_bridge::toCvCopy(msg,
                                             sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception &e)
        {
                ROS_ERROR("cv_bridgexception: %s",
                          e.what());
                return;
        }
}

void ImageManager::cameraInfoCallback(const sensor_msgs::CameraInfo &_msg)
{
}
#endif
cv::Mat ImageManager::resizeImage(const cv::Mat &src, int width, int height)
{
        cv::Mat img_resized_;
        cv::resize(src, img_resized_, cv::Size(width, height),
                   0, 0, cv::INTER_AREA);
        return img_resized_;
}

#ifdef NO_ROS

void iMage::Init()
{
        (*this).cap = cv::VideoCapture(0);
        if (!cap.isOpened())
                return;
}

void iMage::Handler()
{

        bool _s = (*this).cap.read(
            (*this).in_img_);
        if (!_s)
                return;
        this->out_img_ = this->in_img_;
        // cv::imshow(this->name, this->in_img_);
        // cv::waitKey(1);
}

cv::Mat iMage::getImages()
{
        return this->out_img_;
}

void iMage::setWindowName(std::string __name)
{
        this->name = __name;
}

#endif