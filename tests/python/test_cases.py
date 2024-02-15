#!/usr/bin/env python3
# encoding: utf-8

import os
import sys
import rospkg

# Append import paths to the tested modules and helpers.
sys.path.append(os.path.abspath(os.path.dirname(__file__)))
sys.path.append(os.path.join(rospkg.RosPack().get_path('catkin_template'), 'scripts'))

import unittest

from package.dummy import dummy_fun


class BasicTestCases(unittest.TestCase):

  def test_dummy_fun_should_return_one(self):
    self.assertEquals(dummy_fun(), 1, "dummy_fun() != 1")


if __name__ == '__main__':
  unittest.main()
