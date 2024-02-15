#include <cstdint> // uint32_t

#include <ros/ros.h> // NodeHandle, Publisher, Rate

// custom message
#include <catkin_template/Message.h>

// constants
static constexpr auto kNodeName = "cpp_publisher";

static constexpr auto kPubTopic = "message";
static constexpr auto kPubRateHz = double{1.0};
static constexpr auto kPubQueueSize = std::uint32_t{10};


int main(int argc, char **argv) {

  // initialize ROS Node
  ros::init(argc, argv, kNodeName);

  auto handle = ros::NodeHandle();

  // create publisher
  ros::Publisher publisher = handle.advertise<catkin_template::Message>(kPubTopic, kPubQueueSize);

  // create message
  auto msg = catkin_template::Message();
  msg.data = "cpp::publisher::message";

  // define publish rate
  auto pub_rate = ros::Rate(kPubRateHz);

  while (ros::ok()) {
    ROS_INFO_ONCE("Publishing to '%s' at %f Hz", ros::names::resolve(kPubTopic).data(), kPubRateHz);

    // publish message
    publisher.publish(msg);

    ros::spinOnce();
    pub_rate.sleep();
  }

  return 0;
}