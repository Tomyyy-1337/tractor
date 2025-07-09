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

#include <tuple>
#include "plugins/ib2c/tModule.h"
#include "rrlib/aspect_maps/tAspectMap.h"
#include "rrlib/si_units/si_units.h"
#include "rrlib/aspect_maps/tGridAspectMap.h"

namespace finroc::thesis_passberg::obstacle_avoidance
{
/** 
 * Turns away from obstacles in the path of the robot.
 */
class mbbTurnAwayFromObstacle : public ib2c::tModule
{
public:
  	mbbTurnAwayFromObstacle(core::tFrameworkElement *parent, const std::string &name = "TurnAwayFromObstacle",
                          ib2c::tStimulationMode stimulation_mode = ib2c::tStimulationMode::AUTO);

  	//----------------------------------------------------------------------
	// Input Ports
	//----------------------------------------------------------------------

	// Map of distances to obstacles in the robots coordinate system. (Supossed to take input from aspect_maps_application/obstacle_maps/distance_map)
	tInput<rrlib::aspect_maps::tAspectMap<float>> in_obstacle_distance_map;

	// Current curvature of the vehicle.
	tCertaintyInput<rrlib::si_units::tCurvature<float>, ib2c::tScalarSigma> in_current_curvature;


	//----------------------------------------------------------------------
	// Parameters
	//----------------------------------------------------------------------

	// Vehicle Width
	tParameter<rrlib::si_units::tLength<float>> par_vehicle_width;

	//----------------------------------------------------------------------
	// Output Ports
	//----------------------------------------------------------------------

	tOutput<rrlib::si_units::tCurvature<float>> out_curvature; 

protected:
	/** Destructor
	*
	* The destructor of modules is declared protected to avoid accidental deletion. Deleting
	* modules is already handled by the framework.
	*/
  	virtual ~mbbTurnAwayFromObstacle();


private:

	virtual void OnParameterChange() override;

	virtual bool ProcessTransferFunction() override;

	virtual ib2c::tTargetRating CalculateTargetRating() const override;

	static constexpr int NUMBER_OF_SAMPLING_POINTS = 100;
	static constexpr int NUMBER_OF_TENTACLES = 25; 

	// Length of the tentacles in meters
	const float TENTACLE_LENGTH = 10;
	
	// tentacles
	std::tuple<int,int> precomputed_tentacles[NUMBER_OF_TENTACLES][NUMBER_OF_SAMPLING_POINTS];

	void rotate(std::tuple<float, float>& point, float angle) const;

	float index_to_angle(int index) const;

	bool path_is_clear(const std::tuple<int, int> tentacle[]) const;
	
	void calculate_tentacle(std::tuple<int, int> tentacle_start[], float angle) const;
	
};
}
