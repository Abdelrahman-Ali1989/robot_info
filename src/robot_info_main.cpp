#include "robot_info/robot_info_class.h"

int main(int argc, char **argv) {

  // initialize and create node handle
  ros::init(argc, argv, "robot_info");
  ros::NodeHandle nh;

  // creating robot info node
  RobotInfo rm = RobotInfo(&nh);

  // set robot info fields
  rm.set_robot_description("Cooper100");
  rm.set_serial_number("567A359");
  rm.set_ip_address("169.254.5.180");
  rm.set_firmware_version("3.5.8");

  // publish robot info
  rm.publish_data();
}