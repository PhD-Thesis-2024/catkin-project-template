#include <cstdint> // uint32_t

#include <boost/bind.hpp>

#include <ros/ros.h> // NodeHandle, Publisher, Rate
#include <dynamic_reconfigure/server.h>

// custom config
#include <catkin_template/ConfigConfig.h>

// constants
static constexpr auto kNodeName = "cpp_cfg_server";


void callback(catkin_template::ConfigConfig& config, std::uint32_t level) {
  ROS_INFO("Reconfigure: %d, %.1f, %s, %s, %d, level = %d",
           config.int_param, config.double_param, config.str_param.data(),
           config.bool_param? "True":"False", config.size, level);

  // validation ...
}

int main(int argc, char **argv) {

  // initialize ROS Node
  ros::init(argc, argv, kNodeName);

  auto server = dynamic_reconfigure::Server<catkin_template::ConfigConfig>();
  auto callback_type = dynamic_reconfigure::Server<catkin_template::ConfigConfig>::CallbackType();

  server.setCallback(boost::bind(&callback, boost::placeholders::_1, boost::placeholders::_2));

  ros::spin();

  return 0;
}