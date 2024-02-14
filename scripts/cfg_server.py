#!/usr/bin/env python3
# encoding: utf-8

import sys
from typing import Final

import rospy
from dynamic_reconfigure.server import Server

# custom config
from catkin_template.cfg import ConfigConfig

# constants
NODE_NAME: Final[str] = 'py_cfg_server'


def callback(config: ConfigConfig, _) -> ConfigConfig:
  rospy.loginfo("Reconfigure: {int_param}, {double_param}, {str_param}, {bool_param}, {size}".format(**config))

  # config validation ... 

  return config


def main() -> None:

  # initialize ROS Node
  rospy.init_node(NODE_NAME, sys.argv)

  server = Server(ConfigConfig, callback)
  
  rospy.spin()


if __name__ == '__main__':
    main()
