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

namespace finroc::thesis_passberg::obstacle_avoidance
{
/** 
 * Group responsible for avoiding obstacles.
 */
class gbbAvoideObstacle : public ib2c::tGroup
{
public:

public:
  gbbAvoideObstacle(core::tFrameworkElement *parent, const std::string &name = "AvoideObstacle",
                    ib2c::tStimulationMode stimulation_mode = ib2c::tStimulationMode::AUTO,
                    const std::string &structure_config_file = __FILE__".xml");



protected:
  /** Destructor
   *
   * The destructor of modules is declared protected to avoid accidental deletion. Deleting
   * modules is already handled by the framework.
   */
  virtual ~gbbAvoideObstacle();


private:


};
}
