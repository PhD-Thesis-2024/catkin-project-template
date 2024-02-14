#include <cstdint> // uint32_t

#include <ros/ros.h> // NodeHandle, Duration, Subscriber

// custom message
#include <catkin_template/Message.h>

// constants
static constexpr auto kNodeName = "cpp_subscriber";

static constexpr auto kSubTopic = "message";
static constexpr auto kSubTimeoutSecs = double{5.0};
static constexpr auto kSubQueueSize = std::uint32_t{10};


void callback(const catkin_template::MessageConstPtr& msg) {
  ROS_INFO("Recieved data = '%s' from '%s'", msg->data.data(), ros::names::resolve(kSubTopic).data());
}

int main(int argc, char** argv) {

  // initialize ROS Node
  ros::init(argc, argv, kNodeName);

  auto handle = ros::NodeHandle();

  // wait for messages to arrive (3 seconds timeout)
  ROS_INFO("Waiting for messages on '%s'", ros::names::resolve(kSubTopic).data());

  if (!ros::topic::waitForMessage<catkin_template::Message>(kSubTopic, ros::Duration(kSubTimeoutSecs))) {
    ROS_ERROR("Could not subscribe to '%s'", ros::names::resolve(kSubTopic).data());
    return 0;
  }

  // subscribe to topic
  ros::Subscriber subscriber = handle.subscribe(kSubTopic, kSubQueueSize, callback);

  ros::spin();

  return 0;
}