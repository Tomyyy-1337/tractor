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
#include "plugins/ib2c/tMetaSignal.h"
#include "projects/thesis_passberg/point_approach/mbbAbsoluteToRelativeTargetPose.h"

namespace finroc::thesis_passberg::point_approach
{
//----------------------------------------------------------------------
mbbAbsoluteToRelativeTargetPose::~mbbAbsoluteToRelativeTargetPose()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<mbbAbsoluteToRelativeTargetPose> cCREATE_ACTION_FOR_MBB_ABSOLUTETORELATIVETARGETPOSE("AbsoluteToRelativeTargetPose");
#endif

mbbAbsoluteToRelativeTargetPose::mbbAbsoluteToRelativeTargetPose(core::tFrameworkElement *parent, const std::string &name,
                                                                 ib2c::tStimulationMode stimulation_mode) : 
  tModule(parent, name, stimulation_mode, false)
{

}

bool mbbAbsoluteToRelativeTargetPose::ProcessTransferFunction()
{
	auto current_pose = in_current_pose.DataPort().GetPointer();
	auto target_pose = in_target_pose.DataPort().GetPointer();

	rrlib::localization::tPose2D<double> relative_target_pose(
		target_pose->X() - current_pose->X(),
		target_pose->Y() - current_pose->Y(),
		target_pose->Yaw() - current_pose->Yaw()
	);

	std::vector<ib2c::tSigma> sigma_output;



	// out_relative_target_pose.DataPort().Publish(relative_target_pose);
	// out_relative_target_pose.CertaintyPort().Publish(sigma_output, current_pose.GetTimestamp());

		

	return true; 
}

ib2c::tTargetRating mbbAbsoluteToRelativeTargetPose::CalculateTargetRating() const
{
	// This module is a pure transformation module, so it does not have a meaningful target rating.
	return 1.0; 
}

}