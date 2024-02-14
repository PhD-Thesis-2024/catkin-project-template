#!/usr/bin/env python3
# encoding: utf-8

import sys
from typing import Final

import rospy

# cystom message
from catkin_template.msg import Message

# constants
NODE_NAME: Final[str] = 'py_subscriber'

SUB_QUEUE_SIZE: Final[int] = 10
SUB_TOPIC: Final[str] = 'message'
SUB_TIMEOUT_SECS: Final[float] = 5.0


def callback(msg: Message) -> None:
  rospy.loginfo(f"Recieved data = '{msg.data}' from '{rospy.resolve_name(SUB_TOPIC)}'")


def main() -> None:

  # initilize ROS Node
  rospy.init_node(NODE_NAME, sys.argv)

  try:
    # wait for messages to arrive
    rospy.loginfo(f"Waiting for messages to arrive on '{rospy.resolve_name(SUB_TOPIC)}'")
    rospy.wait_for_message(SUB_TOPIC, Message, timeout=SUB_TIMEOUT_SECS)

  except rospy.ROSException:
    rospy.logerr(f"Could not subscribe to '{rospy.resolve_name(SUB_TOPIC)}'")
    return

  # subscribe to topic
  rospy.Subscriber(SUB_TOPIC, Message, callback, queue_size=SUB_QUEUE_SIZE)

  rospy.spin()


if __name__ == '__main__':
  main()