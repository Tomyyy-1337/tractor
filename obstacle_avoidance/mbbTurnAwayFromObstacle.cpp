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

#include <cassert>
#include <tuple>
#include "projects/thesis_passberg/obstacle_avoidance/mbbTurnAwayFromObstacle.h"
#include "plugins/ib2c/tBehavior.h"
#include "rrlib/si_units/si_units.h"

namespace finroc::thesis_passberg::obstacle_avoidance
{
//----------------------------------------------------------------------
mbbTurnAwayFromObstacle::~mbbTurnAwayFromObstacle()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<mbbTurnAwayFromObstacle> cCREATE_ACTION_FOR_MBB_TURNAWAYFROMOBSTACLE("TurnAwayFromObstacle");
#endif

mbbTurnAwayFromObstacle::mbbTurnAwayFromObstacle(core::tFrameworkElement *parent, const std::string &name,
                                                 ib2c::tStimulationMode stimulation_mode) : 
  tModule(parent, name, stimulation_mode, false)
{
	// Precompute the gridmap entries we need to sample for e ach tentacle
	for (int i = 0; i < NUMBER_OF_TENTACLES; ++i)
	{
		float rotation_angle = index_to_angle(i);
		this->calculate_tentacle(this->precomputed_tentacles[i], rotation_angle);
	}
}

void mbbTurnAwayFromObstacle::calculate_tentacle(std::tuple<int, int> tentacle[], float angle) const
{
	std::tuple<float, float> sampling_point = std::make_tuple(0.0f, 0.0f);
	std::tuple<float, float> direction = std::make_tuple(0.0f, 1.0f);

	for (int i = 0; i < NUMBER_OF_SAMPLING_POINTS; ++i)
	{
		this->rotate(direction, angle);
		sampling_point = std::make_tuple(
			static_cast<int>(std::get<0>(sampling_point) + std::get<0>(direction) * TENTACLE_LENGTH),
			static_cast<int>(std::get<1>(sampling_point) + std::get<1>(direction) * TENTACLE_LENGTH)
		);
		tentacle[i] = sampling_point;
	}
}

float mbbTurnAwayFromObstacle::index_to_angle(int index) const
{
	float max_angle = M_PI / 16.0; // Maximum angle for the tentacles
	float stepsize = max_angle / static_cast<float>(NUMBER_OF_TENTACLES);
	return static_cast<float>(index) * stepsize - max_angle / 2.0f; 
}

bool mbbTurnAwayFromObstacle::path_is_clear(const std::tuple<int, int> tentacle[]) const
{
	for (int i = 0; i < NUMBER_OF_SAMPLING_POINTS; ++i)
	{
		// TODO: HOW to acces the obstacle map?
	}
	return true; // Path is clear
}

void mbbTurnAwayFromObstacle::rotate(std::tuple<float, float> &point, float angle) const
{
	float x = std::get<0>(point);
	float y = std::get<1>(point);
	std::get<0>(point) = x * cos(angle) - y * sin(angle);
	std::get<1>(point) = x * sin(angle) + y * cos(angle);
}

void mbbTurnAwayFromObstacle::OnParameterChange()
{

  tModule::OnParameterChange();
}

bool mbbTurnAwayFromObstacle::ProcessTransferFunction()
{	
	float best_curvature = this->in_current_curvature.Get().Value() + M_PI;
	float current_curvature = this->in_current_curvature.Get().Value();

	for (int i = 0; i < NUMBER_OF_TENTACLES; ++i)
	{
		bool path_is_clear = this->path_is_clear(this->precomputed_tentacles[i]);
		
		if (path_is_clear)
		{
			float tentacle_angle = index_to_angle(i);
			bool closer_to_current_curvature = std::abs(tentacle_angle - current_curvature) < std::abs(best_curvature - current_curvature);
			if (closer_to_current_curvature)
			{
				best_curvature = tentacle_angle;
			}
		}
	}

	out_curvature.Publish(rrlib::si_units::tCurvature<float>(best_curvature));

	return true;
}

ib2c::tTargetRating mbbTurnAwayFromObstacle::CalculateTargetRating() const
{
	std::tuple<int,int> dynamic_tentacle[NUMBER_OF_SAMPLING_POINTS];
	this->calculate_tentacle(dynamic_tentacle, this->in_current_curvature.Get().Value());

	bool path_is_clear = this->path_is_clear(dynamic_tentacle);

	if (path_is_clear) { return 1.0f; } else { return 0.0f; }
}

}
