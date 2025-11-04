#include <robot_info/hydraulic_system_monitor.h>

HydraulicSystemMonitor::HydraulicSystemMonitor(std::string oil_temp,
                                               std::string oil_level,
                                               std::string oil_pressure) {

  this->hydraulic_oil_temperature = oil_temp;
  this->hydraulic_oil_tank_fill_level = oil_level;
  this->hydraulic_oil_pressure = oil_pressure;
}

// setter for hydraulic_oil_temperature
void HydraulicSystemMonitor::set_oil_temperature(std::string oil_temp) {

  this->hydraulic_oil_temperature = oil_temp;
}

// setter for hydraulic_oil_tank_fill_level
void HydraulicSystemMonitor::set_oil_level(std::string oil_level) {

  this->hydraulic_oil_tank_fill_level = oil_level;
}

// setter for hydraulic_oil_pressure
void HydraulicSystemMonitor::set_oil_pressure(std::string oil_pressure) {

  this->hydraulic_oil_pressure = oil_pressure;
}

// getter for hydraulic_oil_temperature
std::string HydraulicSystemMonitor::get_hydraulic_oil_temperature() {
  return this->hydraulic_oil_temperature;
}

// getter for hydraulic_oil_tank_fill_level
std::string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() {

  return this->hydraulic_oil_tank_fill_level;
}

// getter for hydraulic_oil_pressure
std::string HydraulicSystemMonitor::get_hydraulic_oil_pressure() {
  return this->hydraulic_oil_pressure;
}