#include "robot_info/agv_robot_info_class.h"

int main(int argc, char **argv) {

  // initialize and create node handle
  ros::init(argc, argv, "agv_robot_info");
  ros::NodeHandle nh;

  // creating robot info node
  AGVRobotInfo rm = AGVRobotInfo(&nh);

  // set robot info fields
  rm.set_robot_description("Cooper100");
  rm.set_serial_number("567A359");
  rm.set_ip_address("169.254.5.180");
  rm.set_firmware_version("3.5.8");
  rm.set_maximum_payload("100 Kg");
  rm.simulate_hydraulic_system_parameters("45C", "100%", "250 bar");

  // publish robot info
  rm.publish_data();
}