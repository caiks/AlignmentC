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
    std::vector<std::pair<Variable, std::set<Value>>> ll(uu.map_u().begin(), uu.map_u().end());
    return ll;
}

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    out << uu.map_u();
    return out;
}

// pairSystemsUnion::System -> System -> System
System Alignment::pairSystemsUnion(const System& uu, const System& xx)
{
    auto& uum = uu.map_u();
    auto& xxm = xx.map_u();
    auto yym = std::map<Variable, std::set<Value>>(uum);
    for (auto it = xxm.begin(); it != xxm.end(); ++it)
    {
	auto& v = it->first;
	auto& ww = it->second;
	auto& yymv = yym[v];
	for (auto it2 = ww.begin(); it2 != ww.end(); ++it2)
	    yymv.insert(Value(*it2));
    }
    return System(yym);
}