
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
  msg.data_field_06 =
      "hydraulic_oil_temperature: " + this->get_hs_oil_temperature();
  msg.data_field_07 =
      "hydraulic_oil_tank_fill_level: " + this->get_hs_oil_tank_fill_level();
  msg.data_field_08 = "hydraulic_oil_pressure: " + this->get_hs_oil_pressure();

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

// setter for the maximum payload
void AGVRobotInfo::set_maximum_payload(std::string max_payload) {
  this->maximum_payload = max_payload;
}

// function to simulate the values of hydraulic system parameters (they should
// be measured through sensors in reality)
void AGVRobotInfo::simulate_hydraulic_system_parameters(
    std::string hs_oil_temp, std::string hs_oil_level,
    std::string hs_oil_pressure) {
  this->hs_monitor.set_oil_temperature(hs_oil_temp);
  this->hs_monitor.set_oil_level(hs_oil_level);
  this->hs_monitor.set_oil_pressure(hs_oil_pressure);
}

// A getter for the hs monitor oil temperature
std::string AGVRobotInfo::get_hs_oil_temperature() {
  return this->hs_monitor.get_hydraulic_oil_temperature();
}

// A getter for the hs monitor oil tank fill level
std::string AGVRobotInfo::get_hs_oil_tank_fill_level() {
  return this->hs_monitor.get_hydraulic_oil_tank_fill_level();
}

// A getter for the hs monitor oil pressure
std::string AGVRobotInfo::get_hs_oil_pressure() {
  return this->hs_monitor.get_hydraulic_oil_pressure();
}