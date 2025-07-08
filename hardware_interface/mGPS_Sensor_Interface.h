#pragma once

#include "plugins/structure/tSenseControlModule.h"
#include "rrlib/localization/tPose.h"

namespace finroc::thesis_passberg::hardware_interface
{
/** 
 * Provides Ports to access GPS Data.
 */
class mGPS_Sensor_Interface : public structure::tSenseControlModule
{
public:

public:
  mGPS_Sensor_Interface(core::tFrameworkElement *parent, const std::string &name = "GPS_Sensor_Interface");

  tSensorOutput<rrlib::localization::tPose3D<double>> out_vehicle_unreal_pose;
  tSensorOutput<rrlib::localization::tTwist3D<double>> out_vehicle_unreal_twist;


protected:
  virtual ~mGPS_Sensor_Interface();


private:


};
}
