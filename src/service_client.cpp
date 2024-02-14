#include <string>

#include <ros/ros.h> // NodeHandle, ServiceProxy

// custom service
#include <catkin_template/Service.h>  // Service, ServiceRequest, ServiceResponse

// constants
static constexpr auto kNodeName = "cpp_service_client";

static constexpr auto kServiceName = "service";

static constexpr auto kTimeoutSecs = double{5.0};


int main(int argc, char **argv) {
  
  // initialize ROS Node
  ros::init(argc, argv, kNodeName);

  auto handle = ros::NodeHandle();

  // wait for service availability
  ros::service::waitForService(kServiceName, ros::Duration(kTimeoutSecs));

  // create proxy to call service
  ros::ServiceClient service = handle.serviceClient<catkin_template::Service>(kServiceName);

  // create service request and response instances
  auto req = catkin_template::ServiceRequest();
  req.request = "cpp::service::request";

  auto resp = catkin_template::ServiceResponse();

  if (!service.call(req, resp)) {
    ROS_ERROR("Failed to call service '%s'", ros::names::resolve(kServiceName).data());
    return 1;
  }

  ROS_INFO("Service call to '%s' returned response = '%s'", ros::names::resolve(kServiceName).data(), resp.response.data());

  return 0;
}
