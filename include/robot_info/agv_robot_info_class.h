#pragma once
#include "robot_info/robot_info_class.h"

class AGVRobotInfo : public RobotInfo {

protected:
  std::string maximum_payload;

public:
  AGVRobotInfo(ros::NodeHandle *node_handle);
  void publish_data();
  void set_maximum_payload(std::string max_payload);
};