#!/usr/bin/env python3
# encoding: utf-8

import sys
from typing import Final

import rospy

# custom service
from catkin_template.srv import Service, ServiceRequest, ServiceResponse

# constants
NODE_NAME: Final[str] = 'py_service_server'

SERVICE_NAME: Final[str] = 'service'


def handler(req: ServiceRequest) -> ServiceResponse:
  rospy.loginfo(f"Service called on '{rospy.resolve_name(SERVICE_NAME)}' request = '{req.request}'")
  return ServiceResponse(response='py::service::response')


def main() -> None:

  # initialize ROS Node
  rospy.init_node(NODE_NAME, sys.argv)

  # create service server
  rospy.Service(SERVICE_NAME, Service, handler)

  rospy.loginfo(f"Service is ready on endpoint '{rospy.resolve_name(SERVICE_NAME)}'")

  rospy.spin()


if __name__ == '__main__':
  main()
