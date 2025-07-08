#include <cassert>
#include "projects/thesis_passberg/mbbDriveToPoint.h"

namespace finroc::thesis_passberg
{
//----------------------------------------------------------------------
mbbDriveToPoint::~mbbDriveToPoint()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<mbbDriveToPoint> cCREATE_ACTION_FOR_MBB_DRIVETOPOINT("DriveToPoint");
#endif

mbbDriveToPoint::mbbDriveToPoint(core::tFrameworkElement *parent, const std::string &name,
                                 ib2c::tStimulationMode stimulation_mode) : 
  	tModule(parent, name, stimulation_mode, false)
{

}

void mbbDriveToPoint::OnParameterChange()
{
  	tModule::OnParameterChange();
}

bool mbbDriveToPoint::ProcessTransferFunction()
{
	
	
  	return true;
}

ib2c::tTargetRating mbbDriveToPoint::CalculateTargetRating() const
{
  	return std::min(1.0, in_target_pose.DataPort().GetPointer()->Position().Length().Value());
}


}
