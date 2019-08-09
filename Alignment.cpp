#include "Alignment.h"

using namespace Alignment;

void Alignment::System::update(const System& xx)
{
    for (auto it = xx.map_u().begin(); it != xx.map_u().end(); ++it)
    {
	auto& yymv = _map[it->first];
	for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	    yymv.insert(*it2);
    }
}

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    std::map<Variable, std::set<Value>> mm;
    for (auto it = uu.map_u().begin(); it != uu.map_u().end(); ++it)
	mm[it->first] = std::set<Value>(it->second.begin(), it->second.end());
    out << mm;
    return out;
}


// listsSystem_u ::[(Variable, Set.Set Value)]->System
System Alignment::listsSystem_u(const std::vector<VarValUSetPair>& ll)
{
    return System(ll);
}

// systemsList::System ->[(Variable, Set.Set Value)]
std::vector<VarValUSetPair> Alignment::systemsList(const System& uu)
{
    return std::vector<VarValUSetPair>(uu.map_u().begin(), uu.map_u().end());;
}


// pairSystemsUnion::System -> System -> System
System Alignment::pairSystemsUnion(const System& uu, const System& xx)
{
    System yy(uu);
    yy.update(xx);
    return yy;
}


// systemsSetVar :: System -> Set.Set Variable
VarUSet Alignment::systemsSetVar(const System& uu)
{
    VarUSet qq(uu.map_u().size());
    for (auto it = uu.map_u().begin(); it != uu.map_u().end(); ++it)
	qq.insert(it->first);
    return qq;
}

// systemsVarsSetValue :: System -> Variable -> Maybe (Set.Set Value)
ValUSet Alignment::systemsVarsSetValue(const System& uu, const Variable& u)
{
    auto it = uu.map_u().find(u);
    if (it != uu.map_u().end())
	return it->second;
    return ValUSet();
}

// systemsSetVarsVolume_u :: System -> Set.Set Variable -> Integer
unsigned long long Alignment::systemsSetVarsVolume_u(const System& uu, const VarUSet& vv)
{
    auto v = 1;
    for (auto it = vv.begin(); it != vv.end(); ++it)
    {
	auto it2 = uu.map_u().find(*it);
	if (it2 != uu.map_u().end())
	    v *= it2->second.size();
    }
    return v;
}

// pairSystemsUnion::System -> System -> System
System Alignment::systemRegular(int d, int n)
{
    ValUSet ww(d);
    for (int j = 1; j <= d; j++)
	ww.insert(Value(j));
    VarValUSetUMap mm(n);
    for (int i = 1; i <=n; i++)
	mm[Variable(i)] = ww;
    return System(mm);
}

std::ostream& operator<<(std::ostream& out, const State& ss)
{
    out << ss.map_u();
    return out;
}

// listsState :: [(Variable, Value)] -> State
State Alignment::listsState(const std::vector<VarValPair>& ll)
{
    return State(ll);
}

// statesList :: State -> [(Variable, Value)]
std::vector<VarValPair> Alignment::statesList(const State& ss)
{
    return std::vector<VarValPair>(ss.map_u().begin(), ss.map_u().end());
}

