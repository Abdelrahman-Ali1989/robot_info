#pragma once
#include "ros/node_handle.h"
#include <ros/ros.h>
#include <string>

class RobotInfo {

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;
  ros::NodeHandle *nh;
  ros::Publisher pub;

public:
  RobotInfo(){};
  RobotInfo(ros::NodeHandle *node_handle);
  virtual void publish_data();
  void set_robot_description(std::string description);
  void set_serial_number(std::string serial_number);
  void set_ip_address(std::string ip_address);
  void set_firmware_version(std::string firmware_version);
};