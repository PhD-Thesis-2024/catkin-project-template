# Catkin project template

[![ROS Noetic Ninjemys](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml/badge.svg?branch=main)](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml)

## Overview

Template of catkin package for C++ and Python projects in ROS (Robot Operating System). 

This project includes basic examples of pub/sub, custom messages and services, and dynamic reconfigure. 

It provides standard ROS project structure and build/test pipeline using [GitHub workflows](.github/workflows). 

Start your journey by clicking [Use this template](https://github.com/new?template_name=catkin-project-template&template_owner=PhD-Thesis-2024).

## Requirements

- OS: Ubuntu 20.04 LTS
- ROS: Noetic Ninjemys
- Build: GCC 9+, CMake 3.15+
- _Optinal_: [catkin tools](https://catkin-tools.readthedocs.io/en/latest/index.html)

## Instructions

1. Prepare catkin workspace:
```shell
mkdir -p workspace/src && cd src
catkin config --init --extend /opt/ros/noetic
```

2. Optinally, configure your workspace (CMake args, parallel jobs, etc.):
```shell
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release -DCATKIN_ENABLE_TESTING=ON
catkin config --jobs $(nproc)
```

3. Build (forcing CMake to run, no cache):
```shell
catkin build --force-cmake
```

4. Source your workspace:
```shell
source devel/setup.bash
```

Now, you're ready to get going!

### Tests

Before continuing any further, make sure `CATKIN_ENABLE_TESTING` CMake variables is `ON` (it is by default).

You can run all catkin-integrated tests (unittest, GoogleTest) using this command: 
```shell
catkin test -t [run_tests]
```

### Catch2 (C++)

C++ tests can be written in two ways:
- [GoogleTest](https://github.com/google/googletest) library (integrated into ROS).
- [Catch2](https://github.com/catchorg/Catch2) framework (v3) (external dependency).

It's really tricky to setup Catch2 with catkin. That's why we need to run them manually:
```shell
cd build/catkin_template
ctest [-V]
```

This runs all the specified tests (unittest, nosetests, GoogleTest, Catch2).

### Usage

#### 1. Launch file

```shell
roslaunch catkin_template example.launch [ns:=<your-namespace>] [remap_to:=<your-remapping>]
```

#### 2. Publisher/subscriber

Run ROS publisher (publishes [`Message.msg`](msg/Message.msg) to `/message` by default):
```shell
rosrun catkin_template cpp_publisher [message:=<topic-remapping>]
```

Run ROS subscriber (subscribes to `/message` by default):
```shell
rosrun catkin_template cpp_subscriber [message:=<topic-remapping>]
```

#### 3. Service

Run ROS service server (uses [Service.srv](srv/Service.srv), endpoint = `/service`):
```shell
rosrun catkin_template cpp_service_server [service:=<endpoint-remapping>]
```

Call service `/service`:
```shell
rosservice call /service "request: '<data>'"
```

#### 4. Dynamic reconfigure

```shell
rosrun catkin_template cpp_cfg_server
```

Check reconfiguration server using RQT:
```shell
rosrun rqt_reconfigure rqt_reconfigure
```
