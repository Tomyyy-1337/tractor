#include <cassert>
#include "projects/thesis_passberg/hardware_interface/mGPS_Sensor_Interface.h"

#include "libraries/unreal/converters/mUPose.h"

namespace finroc::thesis_passberg::hardware_interface
{
//----------------------------------------------------------------------
mGPS_Sensor_Interface::~mGPS_Sensor_Interface()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<mGPS_Sensor_Interface> cCREATE_ACTION_FOR_M_GPS_SENSOR_INTERFACE("GPS_Sensor_Interface");
#endif

mGPS_Sensor_Interface::mGPS_Sensor_Interface(core::tFrameworkElement *parent, const std::string &name) : 
  tSenseControlModule(parent, name, false)
{
  // auto vehicle_unreal_pose = new finroc::unreal::converters::mUPose(this, "Vehicle Unreal Pose");
  

  // vehicle_unreal_pose->in_upose.ConnectTo("tcp:/Unreal/Output/Pose Component Pose");
  // vehicle_unreal_pose->in_utwist.ConnectTo("tcp:/Unreal/Output/Pose Component Twist");
  // this->out_vehicle_unreal_pose.ConnectTo(vehicle_unreal_pose->out_pose);
  // this->out_vehicle_unreal_twist.ConnectTo(vehicle_unreal_pose->out_twist);
}



}
