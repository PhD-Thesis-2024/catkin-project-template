#!/usr/bin/env python3
# encoding: utf-8

import sys
from typing import Final

import rospy

# custom message
from catkin_template.msg import Message

# constants
NODE_NAME: Final[str] = 'py_publisher'

PUB_QUEUE_SIZE: Final[int] = 10
PUB_RATE_HZ: Final[float] = 1.0
PUB_TOPIC: Final[str] = 'message'


def main() -> None:

  # initialize ROS Node
  rospy.init_node(NODE_NAME, sys.argv)

  # create publisher
  publisher = rospy.Publisher(PUB_TOPIC, Message, queue_size=PUB_QUEUE_SIZE)

  # create message
  msg = Message(data='py::publisher::message')

  # define publish rate
  pub_rate = rospy.Rate(PUB_RATE_HZ)

  while not rospy.is_shutdown():
    rospy.loginfo_once(f"Publishing to '{rospy.resolve_name(PUB_TOPIC)}' at {PUB_RATE_HZ} Hz")

    # publish message
    publisher.publish(msg)
    
    pub_rate.sleep()


if __name__ == '__main__':
    main()
