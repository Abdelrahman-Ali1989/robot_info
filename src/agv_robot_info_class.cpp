
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include <robot_info/agv_robot_info_class.h>
#include <string>

// Parameterized constructor definition
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle) {
  this->nh = node_handle;
}

// Definition of the Overriden function
void AGVRobotInfo::publish_data() {

  // create the publisher of the robotinfo_msg over the robot_info topic
  this->pub =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);

  // Filling message data
  robotinfo_msgs::RobotInfo10Fields msg;
  msg.data_field_01 = "robot_description: " + this->robot_description;
  msg.data_field_02 = "serial_number: " + this->serial_number;
  msg.data_field_03 = "ip_address: " + this->ip_address;
  msg.data_field_04 = "firmware_version: " + this->firmware_version;
  msg.data_field_05 = "maximum_payload: " + this->maximum_payload;

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

void AGVRobotInfo::set_maximum_payload(std::string max_payload) {
  this->maximum_payload = max_payload;
}