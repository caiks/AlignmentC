#include "Alignment.h"

using namespace Alignment;

void Alignment::System::update(const System& xx)
{
    for (auto it = xx.map_u().begin(); it != xx.map_u().end(); ++it)
    {
	auto& v = it->first;
	auto& ww = it->second;
	auto& yymv = _map[v];
	for (auto it2 = ww.begin(); it2 != ww.end(); ++it2)
	    yymv.insert(*it2);
    }
}

// listsSystem_u ::[(Variable, Set.Set Value)]->System
System Alignment::listsSystem_u(const std::vector<VarValSetPair>& ll)
{
    return System(ll);
}

// systemsList::System ->[(Variable, Set.Set Value)]
std::vector<VarValSetPair> Alignment::systemsList(const System& uu)
{
    std::vector<VarValSetPair> ll(uu.map_u().begin(), uu.map_u().end());
    return ll;
}

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    std::map<Variable, std::set<Value>> mm;
    for (auto it = uu.map_u().begin(); it != uu.map_u().end(); ++it)
    {
	auto& v = it->first;
	auto& ww = it->second;
	std::set<Value> xx(ww.begin(),ww.end());
	mm[v] = xx;
    }
    out << mm;
    return out;
}

// pairSystemsUnion::System -> System -> System
System Alignment::pairSystemsUnion(const System& uu, const System& xx)
{
    System yy(uu);
    yy.update(xx);
    return yy;
}