//
// You received this file as part of Finroc
// A framework for intelligent robot control
//
// Copyright (C) AG Robotersysteme TU Kaiserslautern
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//----------------------------------------------------------------------
#pragma once

#include "plugins/ib2c/tGroup.h"
#include "rrlib/localization/tPose.h"
#include "rrlib/si_units/si_units.h"
#include "libraries/localization/behaviors/sigma_utilities.h"


namespace finroc::thesis_passberg::point_approach
{
/** 
 * Drive towards a point and reach an orientation at the end
 */
class gbbPointApproach : public ib2c::tGroup
{
public:

public:
  gbbPointApproach(core::tFrameworkElement *parent, const std::string &name = "PointApproach",
                   ib2c::tStimulationMode stimulation_mode = ib2c::tStimulationMode::AUTO,
                   const std::string &structure_config_file = __FILE__".xml");

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
  /** Destructor
   *
   * The destructor of modules is declared protected to avoid accidental deletion. Deleting
   * modules is already handled by the framework.
   */
  virtual ~gbbPointApproach();


private:


};
}
