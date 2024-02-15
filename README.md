# Catkin project template

[![ROS Noetic Ninjemys](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml/badge.svg?branch=main)](https://github.com/PhD-Thesis-2024/catkin-project-template/actions/workflows/catkin.yml)

## Overview

Template of catkin package for C++ and Python projects in ROS (Robot Operating System). 

Includes basic examples of pub/sub, custom messages and services, and dynamic reconfigure. Provides standard ROS project structure and build/test pipeline using [GitHub workflows](.github/workflows). 

Start your journey by clicking [Use this template](https://github.com/new?template_name=catkin-project-template&template_owner=PhD-Thesis-2024).

<p align="center">
  <img src="https://github.com/PhD-Thesis-2024/catkin-project-template/assets/11016580/b7e3c0bc-7cb9-47b5-bc20-747b4f001b86" width="75%"/>  
</p>

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

3. Build (forcing CMake to run, no cache):
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

2. Publisher/subscriber:

Run ROS publisher (publishes [`Message.msg`](msg/Message.msg) to `/message` by default):
```shell
rosrun catkin_template cpp_publisher [message:=<topic-remapping>]
```

Run ROS subscriber (subscribes to `/message` by default):
```shell
rosrun catkin_template cpp_subscriber [message:=<topic-remapping>]
```

3. Service

Start ROS service server (uses [Service.srv](srv/Service.srv), endpoint = `/service`):
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

### Tests

Coming soon ...
