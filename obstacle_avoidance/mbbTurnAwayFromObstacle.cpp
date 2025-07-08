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
