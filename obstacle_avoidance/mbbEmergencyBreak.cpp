#include <cassert>
#include "projects/thesis_passberg/obstacle_avoidance/mbbEmergencyBreak.h"

namespace finroc::thesis_passberg::obstacle_avoidance
{
//----------------------------------------------------------------------
mbbEmergencyBreak::~mbbEmergencyBreak()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<mbbEmergencyBreak> cCREATE_ACTION_FOR_MBB_EMERGENCYBREAK("EmergencyBreak");
#endif

mbbEmergencyBreak::mbbEmergencyBreak(core::tFrameworkElement *parent, const std::string &name,
                                     ib2c::tStimulationMode stimulation_mode) : 
  tModule(parent, name, stimulation_mode, false)
{

}

void mbbEmergencyBreak::OnParameterChange()
{
  tModule::OnParameterChange();
}

bool mbbEmergencyBreak::ProcessTransferFunction()
{
	out_velocity.Publish(rrlib::si_units::tVelocity<double>(0.0));

	return true;
}

ib2c::tTargetRating mbbEmergencyBreak::CalculateTargetRating() const
{
	double distance_to_obstacle = in_distance_to_obstacle.Get().Value();
	double emergency_break_distance = par_emergency_break_distance.Get().Value();

	if (distance_to_obstacle < emergency_break_distance) 
	{
		return 1.0;
	} 

	return 0.0;
}


}
