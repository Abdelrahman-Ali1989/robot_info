#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/init.h"
#include "ros/node_handle.h"

RobotInfo::RobotInfo(ros::NodeHandle *node_handle) { this->nh = node_handle; }

void RobotInfo::publish_data() {

  // create the publisher of the robotinfo_msg over the robot_info topic
  this->pub =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);

  // Filling message data
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + this->robot_description;
  msg.data_field_02 = "serial_number: " + this->serial_number;
  msg.data_field_03 = "ip_address: " + this->ip_address;
  msg.data_field_04 = "firmware_version: " + this->firmware_version;

  // the message rate is 10Hz
  ros::Rate rate(10);

  // publish periodically
  while (ros::ok()) {
    // Publish the message
    pub.publish(msg);
    ros::spinOnce();
    rate.sleep();
  }
}

void RobotInfo::set_robot_description(std::string description) {
  this->robot_description = description;
}

void RobotInfo::set_serial_number(std::string serial_number) {
  this->serial_number = serial_number;
}

void RobotInfo::set_ip_address(std::string ip_address) {
  this->ip_address = ip_address;
}

void RobotInfo::set_firmware_version(std::string firmware_version) {
  this->firmware_version = firmware_version;
}