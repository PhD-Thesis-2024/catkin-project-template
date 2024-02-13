#include <iostream>  // cout

#include <ros/ros.h>      // NodeHandle
#include <ros/package.h>  // ros::package::getPath


static constexpr auto kNodeName = "cpp_node";

int main(int argc, char **argv) {

  ros::init(argc, argv, kNodeName);

  ros::NodeHandle handle;

  if (handle.ok()) {
    ROS_INFO_STREAM("Node path " << ros::package::getPath("catkin_template"));
  }

  return 0;
}