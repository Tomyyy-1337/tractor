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
	// Precompute the gridmap entries we need to sample for each tentacle
	for (int i = 0; i < NUMBER_OF_TENTACLES; ++i)
	{
		std::tuple<float, float> sampling_point = std::make_tuple(0.0, 0.0);
		std::tuple<float, float> direction = std::make_tuple(0.0, 1.0);
		float rotation_angle = index_to_angle(i);

		for (int j = 0; j < NUMBER_OF_SAMPLING_POINTS; ++j)
		{
			this->rotate(direction, rotation_angle);
			sampling_point = std::make_tuple(
				static_cast<int>(std::get<0>(sampling_point) + std::get<0>(direction) * TENTACLE_LENGTH),
				static_cast<int>(std::get<1>(sampling_point) + std::get<1>(direction) * TENTACLE_LENGTH)
			);
			this->a[i][j] = sampling_point;
		}
	}
}

float mbbTurnAwayFromObstacle::index_to_angle(int index)
{
	float max_angle = M_PI / 16.0; // Maximum angle for the tentacles
	float stepsize = max_angle / static_cast<float>(NUMBER_OF_TENTACLES);
	return static_cast<float>(index) * stepsize - max_angle / 2.0f; 
}

void mbbTurnAwayFromObstacle::rotate(std::tuple<float, float> &point, float angle)
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

	return true;
}

ib2c::tTargetRating mbbTurnAwayFromObstacle::CalculateTargetRating() const
{
    return 1.0;;
}

}
