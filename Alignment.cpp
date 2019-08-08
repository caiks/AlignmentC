#include "Alignment.h"

using namespace Alignment;

// listsSystem_u ::[(Variable, Set.Set Value)]->System
System Alignment::listsSystem_u(const std::vector<std::pair<Variable, std::set<Value>>>& ll)
{
    std::map<Variable, std::set<Value>> m(ll.begin(), ll.end());
    return System(m);
}

// systemsList::System ->[(Variable, Set.Set Value)]
std::vector<std::pair<Variable, std::set<Value>>> Alignment::systemsList(const System& uu)
{
    std::vector<std::pair<Variable, std::set<Value>>> ll(uu._map.begin(), uu._map.end());
    return ll;
}

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    out << ((System&)uu).map_u();
    return out;
}
