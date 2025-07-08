#include <cassert>
#include "projects/thesis_passberg/obstacle_avoidance/gbbAvoideObstacle.h"

namespace finroc::thesis_passberg::obstacle_avoidance
{
//----------------------------------------------------------------------
gbbAvoideObstacle::~gbbAvoideObstacle()
{}


#ifdef _LIB_FINROC_PLUGINS_RUNTIME_CONSTRUCTION_ACTIONS_PRESENT_
static const runtime_construction::tStandardCreateModuleAction<gbbAvoideObstacle> cCREATE_ACTION_FOR_GBB_AVOIDEOBSTACLE("AvoideObstacle");
#endif

gbbAvoideObstacle::gbbAvoideObstacle(core::tFrameworkElement *parent, const std::string &name,
                                     ib2c::tStimulationMode stimulation_mode,
                                    const std::string &structure_config_file) : 
  tGroup(parent, name, stimulation_mode, structure_config_file, false)
{

}



}
