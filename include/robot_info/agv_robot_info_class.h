#pragma once
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"

class AGVRobotInfo : public RobotInfo {

protected:
  std::string maximum_payload;
  HydraulicSystemMonitor hs_monitor;

public:
  AGVRobotInfo(ros::NodeHandle *node_handle);
  void publish_data();
  void set_maximum_payload(std::string max_payload);
  void simulate_hydraulic_system_parameters(std::string hs_oil_temp,
                                            std::string hs_oil_level,
                                            std::string hs_oil_pressure);
  std::string get_hs_oil_temperature();
  std::string get_hs_oil_tank_fill_level();
  std::string get_hs_oil_pressure();
};