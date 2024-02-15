#include <string>

#include <ros/ros.h> // NodeHandle, ServiceServer

// custom service
#include <catkin_template/Service.h> // Service, ServiceRequest, ServiceResponse

// constants
static constexpr auto kNodeName = "cpp_service_server";

static constexpr auto kServiceName = "service";


bool handler(catkin_template::ServiceRequest& req, catkin_template::ServiceResponse& resp) {
  ROS_INFO("Service called on '%s' request = '%s'", ros::names::resolve(kServiceName).data(), req.request.data());
  resp.response = "cpp::service::response";
  return true;
}

int main(int argc, char **argv) {

  // initialize ROS Node
  ros::init(argc, argv, kNodeName);

  auto handle = ros::NodeHandle();

  // create and start service server
  ros::ServiceServer service = handle.advertiseService(kServiceName, handler);

  ROS_INFO("Service is ready on endpoint '%s'", ros::names::resolve(kServiceName).data());

  ros::spin();

  return 0;
}
