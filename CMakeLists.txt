cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(catkin_template VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  message_runtime
  message_generation
  dynamic_reconfigure
)

catkin_python_setup()

## System dependencies can be found with CMake's conventions.
# find_package(Boost REQUIRED COMPONENTS system)

## Declare ROS messages, services and actions.
##
## To declare and build messages, services or actions from within this package, follow these steps:

## Generate messages in the 'msg' folder.
add_message_files(
  FILES
  Message.msg
)

## Generate services in the 'srv' folder.
add_service_files(
  FILES
  Service.srv
)

## Generate actions in the 'action' folder.
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here.
generate_messages(
  DEPENDENCIES
  std_msgs
)

## Declare ROS dynamic reconfigure parameters.
##
## To declare and build dynamic reconfigure parameters within this package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder.
generate_dynamic_reconfigure_options(
  cfg/Config.cfg
)

## catkin specific configuration.
##
## The catkin_package macro generates cmake config files for your package.
## Declare things to be passed to dependent projects:
##  INCLUDE_DIRS: header files directory
##  LIBRARIES: libraries you create in this project
##  CATKIN_DEPENDS: catkin packages
##  DEPENDS: system dependencies of this project
catkin_package(
  INCLUDE_DIRS include
  # LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime message_generation dynamic_reconfigure
)

## Declare a catkin interface target.
## Note: link against this target to include catkin libraries and link catkin directories.
add_library(catkin_deps INTERFACE)
target_link_libraries(catkin_deps INTERFACE ${catkin_LIBRARIES})
target_include_directories(catkin_deps INTERFACE ${catkin_INCLUDE_DIRS})

## Note: pre-build messages, services, actions.
add_dependencies(catkin_deps ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${PROJECT_NAME}_gencfg)

## Declare a C++ executables (targets).

## Publisher
add_executable(cpp_publisher src/publisher.cpp)
target_link_libraries(cpp_publisher PRIVATE catkin_deps)

## Subscriber
add_executable(cpp_subscriber src/subscriber.cpp)
target_link_libraries(cpp_subscriber PRIVATE catkin_deps)

## Service
add_executable(cpp_service_server src/service_server.cpp)
target_link_libraries(cpp_service_server PRIVATE catkin_deps)

add_executable(cpp_service_client src/service_client.cpp)
target_link_libraries(cpp_service_client PRIVATE catkin_deps)

## Cfg
add_executable(cpp_cfg_server src/cfg_server.cpp)
target_link_libraries(cpp_cfg_server PRIVATE catkin_deps)

## Testing.
## Coming soon ...
