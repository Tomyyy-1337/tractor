// #include <cassert>
#include <vector>
#include "plugins/structure/tTopLevelThreadContainer.h"

bool make_all_port_links_unique = true;

void StartUp()
{
    
}

void CreateMainGroup(const std::vector<std::string> &args)
{
    finroc::structure::tTopLevelThreadContainer<> *main_thread = new finroc::structure::tTopLevelThreadContainer<>("Main Thread", __FILE__".xml", true, make_all_port_links_unique);

    main_thread->SetCycleTime(std::chrono::milliseconds(50));


}

