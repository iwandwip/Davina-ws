#include "yolov3-ball-detector/header.h"
#include "yolov3-ball-detector/yolov3.h"

Yolov3BallDetector yolov3;

void Yolov3BallDetector::Init()
{
#ifdef CV_4
        (*this).net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
        (*this).net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
#endif
}

void Yolov3BallDetector::Handler(const cv::Mat img)
{
#ifdef CV_4
        (*this).blob = cv::dnn::blobFromImage(img,
                                              (1 / 255.0),
                                              cv::Size(416, 416),
                                              cv::Scalar(0, 0, 0),
                                              true,
                                              false);
        std::vector<cv::String> names;
        std::vector<int> outLayers = (*this).net.getUnconnectedOutLayers();
        std::vector<cv::String> layersNames = (*this).net.getLayerNames();

        names.resize(outLayers.size());

        for (size_t i = 0; i < outLayers.size(); i++)
        {
                names[i] = layersNames[outLayers[i] - 1];
        }

        std::vector<cv::Mat> netOutput;
        (*this).net.setInput((*this).blob);
        (*this).net.forward(netOutput, names);

        float confThreshold = 0.40;
        std::vector<int> classIds;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;

        // for (size_t i = 0; i < netOutput.size(); ++i)
        // {

        //         float *data = (float *)netOutput[i].data;

        //         for (int j = 0; j < netOutput[i].rows; data += netOutput[i].cols)
        //         {
        //                 ROS_INFO("haii");

        //                 cv::Mat scores = netOutput[i].row(j).colRange(5, netOutput[i].cols);
        //                 cv::Point classId;
        //                 double confidence;

        //                 cv::minMaxLoc(scores, 0, &confidence, 0, &classId);

        //                 if (confidence > confThreshold)
        //                 {
        //                         cv::Rect box;
        //                         int cx, cy;
        //                         cx = (int)((data[0]) * img.cols);
        //                         cy = (int)((data[1]) * img.rows);

        //                         box.width = (int)((data[2]) * img.cols);
        //                         box.height = (int)((data[3]) * img.rows);

        //                         box.x = cx - box.width / 2;
        //                         box.y = cy - box.height / 2;

        //                         boxes.push_back(box);
        //                         classIds.push_back(classId.x);
        //                         confidences.push_back((float)confidence);
        //                 }
        //         }
        // }

        // float nmsThreshold = 0.2;
        // std::vector<int> indices;
        // cv::dnn::NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
        // std::vector<BoundingBox> bBoxes;

        // for (auto it = indices.begin(); it != indices.end(); ++it)
        // {
        //         BoundingBox bBox;
        //         bBox.roi = boxes[*it];
        //         bBox.classID = classIds[*it];
        //         bBox.boxID = (int)bBoxes.size();

        //         bBoxes.push_back(bBox);
        // }

        // cv::Mat visImg = img.clone();
        // for (auto it = bBoxes.begin(); it != bBoxes.end(); ++it)
        // {
        //         int top, left, width, height;
        //         top = (*it).roi.y;
        //         left = (*it).roi.x;
        //         width = (*it).roi.width;
        //         height = (*it).roi.height;

        //         cv::rectangle(visImg, cv::Point(left, top), cv::Point(left + width, top + height), cv::Scalar(0, 255, 0), 2);

        //         std::string label = cv::format("%.2f", (*it).confidence);
        //         label = classes[((*it).classID)] + ":" + label;

        //         int baseLine;
        //         cv::Size labelSize = getTextSize(label, cv::FONT_ITALIC, 0.5, 1, &baseLine);
        //         top = std::max(top, labelSize.height);

        //         cv::rectangle(visImg, cv::Point(left, top - round(1.5 * labelSize.height)),
        //                       cv::Point(left + round(1.5 * labelSize.width)),
        //                       cv::Scalar(255, 255, 0), 2);

        //         cv::putText(visImg, label, cv::Point(left, top), cv::FONT_ITALIC, 0.75, cv::Scalar(0, 0, 0), 1);
        // }

        // cv::namedWindow("name", 1);
        // cv::imshow("name", visImg);
        cv::imshow("name", img);
        cv::waitKey(1);
#endif
}

void Yolov3BallDetector::ReadPath()
{
        Classes = Classes_t;
        Models = Models_t;
        Config = Config_t;

        std::ifstream ifs(Classes.c_str());
        while (std::getline(ifs, Line))
                (*this).classes.push_back(Line);
}
