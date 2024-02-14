#!/usr/bin/env python3
# encoding: utf-8

import sys
from typing import Final

import rospy

# custom service
from catkin_template.srv import Service, ServiceResponse

# constants
NODE_NAME: Final[str] = 'py_service_client'

SERVICE_NAME: Final[str] = 'service'
SERVICE_TIMEOUT_SECS: Final[float] = 5.0


def main() -> None:

  # initialize ROS Node
  # Note: this step can be ommited, but name resolution will not work
  rospy.init_node(NODE_NAME, sys.argv)

  # wait for service to be available
  rospy.wait_for_service(SERVICE_NAME, rospy.Duration(SERVICE_TIMEOUT_SECS))

  # create proxy to call service 
  service = rospy.ServiceProxy(SERVICE_NAME, Service)

  try:
    # execute service call
    resp: ServiceResponse = service(request = 'py::service::request')
    rospy.loginfo(f"Service call to '{rospy.resolve_name(SERVICE_NAME)} returned response = '{resp.response}'")
  
  except rospy.ServiceException:
    rospy.logerr(f"Failed to call service '{rospy.resolve_name(SERVICE_NAME)}'")


if __name__ == '__main__':
  main()
