#pragma once

#include "plugins/ib2c/tModule.h"
#include "rrlib/localization/tPose.h"
#include "rrlib/si_units/si_units.h"
#include "libraries/localization/behaviors/sigma_utilities.h"

namespace finroc::thesis_passberg
{
/** 
 * Drive to a Point and reach a orientation at this point.
 */
class mbbDriveToPoint : public ib2c::tModule
{
public:

public:
	mbbDriveToPoint(core::tFrameworkElement *parent, const std::string &name = "DriveToPoint",
					ib2c::tStimulationMode stimulation_mode = ib2c::tStimulationMode::AUTO);
	
	//----------------------------------------------------------------------
	// Input Ports
	//----------------------------------------------------------------------
	
	// Difference between target pose and vehicle pose in global coordinates. 
	tCertaintyInput<rrlib::localization::tPose2D<double>, localization::sigma::tPose2DSigma> in_target_pose;
	
	// Current velocity of the vehicle.
	tCertaintyInput<rrlib::si_units::tVelocity<double>, ib2c::tScalarSigma> in_current_velocity;
	
	//----------------------------------------------------------------------
	// Output Ports
	//----------------------------------------------------------------------
	tCertaintyOutput<rrlib::si_units::tCurvature<double>, ib2c::tScalarSigma> out_curvature;
	tCertaintyOutput<rrlib::si_units::tVelocity<double>, ib2c::tScalarSigma> out_velocity;

	
protected:
  	virtual ~mbbDriveToPoint();


private:

	virtual void OnParameterChange() override;

	virtual bool ProcessTransferFunction() override;

	virtual ib2c::tTargetRating CalculateTargetRating() const override;

};
}
