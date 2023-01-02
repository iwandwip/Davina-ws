cmake_minimum_required(VERSION 3.5)
project(try-yolo)

set(ENV{OpenCV_DIR} "/usr/local/include/opencv4")
set(OpenCV_INCLUDE_DIRS /usr/local/include/opencv4 /usr/local/include/opencv4/opencv2/)

add_compile_options(-std=c++11 -mavx -mfma)


find_package(OpenCV 4 REQUIRED)
find_package(yaml-cpp REQUIRED)
#add_compile_options(-std=c++1z)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs cv_bridge sensor_msgs image_transport
#        kri_2021
)

#find_package(OpenCV 4 REQUIRED core highgui calib3d PATHS /usr/local NO_DEFAULT_PATH)

find_package(Boost REQUIRED COMPONENTS thread)

message(STATUS "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
message(STATUS "~~ [ Libraries ] Include Libraries :: OpenCV 4 ")
message(STATUS "~~ OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "~~ OpenCV_LIBS = ${OpenCV_LIBS}")
message(STATUS "~~ OpenCV_LIBRARIES = ${OpenCV_LIBRARIES}")
message(STATUS "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
#find_package(OpenCV 3 REQUIRED)

#find_package(OpenCV 4 REQUIRED COMPONENTS opencv_video opencv_objdetect opencv_imgproc opencv_photo opencv_calib3d opencv_videoio opencv_highgui opencv_flann opencv_gapi opencv_core opencv_imgcodecs opencv_ml opencv_features2d opencv_dnn opencv_stitching )



catkin_package(
INCLUDE_DIRS include
CATKIN_DEPENDS roscpp
rospy
roslib
std_msgs
sensor_msgs
cv_bridge
image_transport
DEPENDS Boost OpenCV
LIBRARIES yolov3-ball-detector
#        kri_2021
)

include_directories(
include
${catkin_INCLUDE_DIRS}
${Boost_INCLUDE_DIRS}
${OpenCV_INCLUDE_DIRS}
${YAML_CPP_INCLUDE_DIR}
#        ${OpenCV_LIBS}
#        ${OpenCV_LIBRARIES}
#        /usr/local/include/opencv4
)

#include_directories("/usr/local/include/opencv4")
#include_directories(include ${OpenCV_INCLUDE_DIRS})
#add_subdirectory(dnn)

add_executable(${PROJECT_NAME}_node src/systems.cpp src/yolov3.cpp src/image.cpp src/main.cpp)

target_include_directories(${PROJECT_NAME}_node
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}_node
${catkin_LIBRARIES}
${Boost_LIBRARIES}
#        ${OpenCV_LIBRARIES}
#        ${OpenCV_LIBS}
#                ${OpenCV_INCLUDE_DIRS}
${OpenCV_LIBS}
${OpenCV_LIBRARIES}
#        opencv_video opencv_objdetect opencv_imgproc opencv_photo opencv_calib3d opencv_videoio opencv_highgui opencv_flann opencv_gapi opencv_core opencv_imgcodecs opencv_ml opencv_features2d opencv_dnn opencv_stitching
)

