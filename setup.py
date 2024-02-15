#!/usr/bin/env python3
# encoding: utf-8

from setuptools import setup
from catkin_pkg.python_setup import generate_distutils_setup


d = generate_distutils_setup()
d['packages'] = ['catkin_template']
d['package_dir'] = {'': 'scripts'}

setup(**d)
