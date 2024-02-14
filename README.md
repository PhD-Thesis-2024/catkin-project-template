# Catkin project template

[![ROS Noetic Ninjemys](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml/badge.svg?branch=main)](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml)

## Overview

Template of catkin package for C++ and Python projects in ROS (Robot Operating System). 

Includes basic examples of pub/sub, custom messages and services, and dynamic reconfigure. 

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
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin config --jobs $(nproc)
```

3. Build (forcing CMake to run)
```shell
catkin build --force-cmake
```

4. Source your workspace:
```shell
source devel/setup.bash
```

Now, you're ready to get going!

### Usage

1. Launch file:
```shell
roslaunch catkin_template example.launch [ns:=<your-namespace>] [remap_to:=<your-remapping>]
```
In this example we demonstate:
- launch file arguments
- topic remapping
- namespace encapsulation

2. Publisher/subscriber:

Start ROS publisher (publish [`Message.msg`](msg/Message.msg) to `/message`):
```shell
rosrun catkin_template cpp_publisher [message:=<topic-remapping>]
```

Start ROS subscriber:
```shell
rosrun catkin_template cpp_subscriber [message:=<topic-remapping>]
```

3. Service

Start ROS service server (uses custom [Service.srv](srv/Service.srv), endpoint = `/service`):
```shell
rosrun catkin_template cpp_service_server [service:=<endpoint-remapping>]
```

Call service `/service`:
```shell
rosservice call /service "request: '<data>'"
```

4. Dynamic reconfigure:

```shell
rosrun catkin_template cpp_cfg_server
```

Check reconfiguration server using RQT:
```shell
rosrun rqt_reconfigure rqt_reconfigure
```
