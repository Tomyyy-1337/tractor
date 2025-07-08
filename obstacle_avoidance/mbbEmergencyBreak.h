#pragma once

#include "plugins/ib2c/tModule.h"
#include "rrlib/si_units/si_units.h"

namespace finroc::thesis_passberg::obstacle_avoidance
{
/** 
 * Breaks if obstacle is to close to be avoided without stopping.
 */
class mbbEmergencyBreak : public ib2c::tModule
{
public:

public:
  mbbEmergencyBreak(core::tFrameworkElement *parent, const std::string &name = "EmergencyBreak",
                    ib2c::tStimulationMode stimulation_mode = ib2c::tStimulationMode::AUTO);

	//----------------------------------------------------------------------
	// Input Ports
	//----------------------------------------------------------------------

	// Distance to the obstacle in the direction the vehicle is heading.
	tCertaintyInput<rrlib::si_units::tLength<double>, ib2c::tScalarSigma> in_distance_to_obstacle; 



	//----------------------------------------------------------------------
	// Parameters
	//----------------------------------------------------------------------

	// Distance to the obstacle at which the vehicle should start breaking.
	tParameter<rrlib::si_units::tLength<double>> par_emergency_break_distance; 


	//----------------------------------------------------------------------
	// Output Ports
	//----------------------------------------------------------------------
	
	// Velocity to be used for breaking (allways 0).
	tOutput<rrlib::si_units::tVelocity<double>> out_velocity; 


protected:
  /** Destructor
   *
   * The destructor of modules is declared protected to avoid accidental deletion. Deleting
   * modules is already handled by the framework.
   */
  virtual ~mbbEmergencyBreak();


private:

  virtual void OnParameterChange() override;

  virtual bool ProcessTransferFunction() override;

  virtual ib2c::tTargetRating CalculateTargetRating() const override;


};
}
