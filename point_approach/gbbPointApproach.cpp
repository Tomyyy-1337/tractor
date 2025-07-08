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
#include "projects/thesis_passberg/point_approach/gbbPointApproach.h"

namespace finroc::thesis_passberg::point_approach
{
//----------------------------------------------------------------------
gbbPointApproach::~gbbPointApproach()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<gbbPointApproach> cCREATE_ACTION_FOR_GBB_POINTAPPROACH("PointApproach");
#endif

gbbPointApproach::gbbPointApproach(core::tFrameworkElement *parent, const std::string &name,
                                   ib2c::tStimulationMode stimulation_mode,
                                  const std::string &structure_config_file) : 
  tGroup(parent, name, stimulation_mode, structure_config_file, false)
{

}



}
