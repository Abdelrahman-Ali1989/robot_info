#pragma once
#include <string>

class HydraulicSystemMonitor {

protected:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;

public:
  HydraulicSystemMonitor(){};
  HydraulicSystemMonitor(std::string oil_temp, std::string oil_level,
                         std::string oil_pressure);
  void set_oil_temperature(std::string oil_temp);
  void set_oil_level(std::string oil_level);
  void set_oil_pressure(std::string oil_pressure);
  std::string get_hydraulic_oil_temperature();
  std::string get_hydraulic_oil_tank_fill_level();
  std::string get_hydraulic_oil_pressure();
};