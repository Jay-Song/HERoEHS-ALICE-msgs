################################################################################
# CMake
################################################################################
cmake_minimum_required(VERSION 2.8.3)
project(alice_msgs)

add_compile_options(-std=c++11)
################################################################################
# Packages
################################################################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  message_generation
)
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

################################################################################
# Declare ROS messages, services and actions
################################################################################
add_message_files(
  FILES
  ForceTorque.msg
  BalanceParam.msg
  MoveCommand.msg
  RobotInfo.msg
  TeamInfo.msg
  RoboCupGameControlData.msg
  RoboCupGameControlReturnData.msg
  FoundObject.msg
  FoundObjectArray.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  sensor_msgs
  geometry_msgs
)

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Catkin specific configuration
################################################################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES alice_msgs
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs geometry_msgs
)

add_library(${PROJECT_NAME} src/robocup_struct.cpp)
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

################################################################################
# Build
################################################################################

################################################################################
# Install
################################################################################

################################################################################
# Test
################################################################################
