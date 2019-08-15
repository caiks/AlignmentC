#include "Alignment.h"
#include <iostream>

using namespace Alignment;

Variable::Variable(const std::string& s)
{
    _hash = 0;
    _cl = 1;
    _str = std::make_shared<std::string>(s);
}

Variable::Variable(int i)
{
    _hash = 0;
    _cl = 2;
    _int = i;
}

Variable::Variable(const Variable& v0, const Variable& v1)
{
    _hash = 0;
    _cl = 5;
    _var0 = std::make_shared<Variable>(v0);
    _var1 = std::make_shared<Variable>(v1);
}

bool Alignment::operator==(const Variable& l, const Variable& r)
{
    if (l._cl != r._cl)
	return false;
    if (l._cl == 1)
	return *l._str == *r._str;
    else if (l._cl == 2)
	return l._int == r._int;
    return *l._var0 == *r._var0 && *l._var1 == *r._var1;
}

bool Alignment::operator<(const Variable& l, const Variable& r)
{
    if (l._cl < r._cl)
	return true;
    if (l._cl > r._cl)
	return false;
    if (l._cl == 1)
	return *l._str < *r._str;
    else if (l._cl == 2)
	return l._int < r._int;
    return *l._var0 < *r._var0 || (*r._var0 == *l._var0 && *l._var1 < *r._var1);
}

std::size_t Alignment::Variable::hash() const
{
    if (!_hash)
    {
	if (_cl == 1)
	    (std::size_t)_hash = _cl + (std::hash<std::string>{}(*_str) << 3);
	else if (_cl == 2)
	    (std::size_t)_hash = _cl + (std::hash<int>{}(_int) << 3);
	else
	    (std::size_t)_hash = _cl + (_var0->hash() << 3) + (_var1->hash() << 4);
    }
    return _hash;
}

void Alignment::Variable::write(std::ostream& out) const
{
    if (_cl == 1)
	out << *_str;
    else if (_cl == 2)
	out << _int;
    else
    {
	out << "<";
	_var0->write(out); 
	out << ",";
	_var1->write(out);
	out << ">";
    }
}

std::ostream& operator<<(std::ostream& out, const Variable& v)
{
    v.write(out);
    return out;
}

Value::Value(const std::string& s)
{
    _hash = 0;
    _cl = 1;
    _str = std::make_shared<std::string>(s);
}

Value::Value(int i)
{
    _hash = 0;
    _cl = 2;
    _int = i;
}

Value::Value(double d)
{
    _hash = 0;
    _cl = 3;
    this->_double = d;
}

bool Alignment::operator==(const Value& l, const Value& r)
{
    if (l._cl != r._cl)
	return false;
    if (l._cl == 1)
	return *l._str == *r._str;
    else if (l._cl == 2)
	return l._int == r._int;
    return l._double == r._double;
}

bool Alignment::operator<(const Value& l, const Value& r)
{
    if (l._cl < r._cl)
	return true;
    if (l._cl > r._cl)
	return false;
    if (l._cl == 1)
	return *l._str < *r._str;
    else if (l._cl == 2)
	return l._int < r._int;
    return l._double < r._double;
}

std::size_t Alignment::Value::hash() const
{
    if (!_hash)
    {
	if (_cl == 1)
	    (std::size_t)_hash = _cl + (std::hash<std::string>{}(*_str) << 2);
	else if (_cl == 2)
	    (std::size_t)_hash = _cl + (std::hash<int>{}(_int) << 2);
	else
	    (std::size_t)_hash = _cl + (std::hash<double>{}(_double) << 2);
    }
    return _hash;
}

void Alignment::Value::write(std::ostream& out) const
{
    if (_cl == 1)
	out << *_str;
    else if (_cl == 2)
	out << _int;
    else
	out << _double;
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
    v.write(out);
    return out;
}

Id::Id(const std::string& s)
{
    _hash = 0;
    _cl = 1;
    _str = std::make_shared<std::string>(s);
}

Id::Id(int i)
{
    _hash = 0;
    _cl = 2;
    _int = i;
}

bool Alignment::operator==(const Id& l, const Id& r)
{
    if (l._cl != r._cl)
	return false;
    if (l._cl == 1)
	return *l._str == *r._str;
    return l._int == r._int;
}

bool Alignment::operator<(const Id& l, const Id& r)
{
    if (l._cl < r._cl)
	return true;
    if (l._cl > r._cl)
	return false;
    if (l._cl == 1)
	return *l._str < *r._str;
    return l._int < r._int;
}

std::size_t Alignment::Id::hash() const
{
    if (!_hash)
    {
	if (_cl == 1)
	    (std::size_t)_hash = _cl + (std::hash<std::string>{}(*_str) << 2);
	else
	    (std::size_t)_hash = _cl + (std::hash<int>{}(_int) << 2);
    }
    return _hash;
}

void Alignment::Id::write(std::ostream& out) const
{
    if (_cl == 1)
	out << *_str;
    else
	out << _int;
}

std::ostream& operator<<(std::ostream& out, const Id& v)
{
    v.write(out);
    return out;
}

System::System(const VarValUSetUMap& m) : _map(m) 
{
}

System::System(const std::vector<VarValUSetPair>& ll)
{
    _map.reserve(ll.size());
    for (auto it = ll.begin(); it != ll.end(); ++it)
	_map[it->first] = it->second;
}

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
std::unique_ptr<System> Alignment::listsSystem_u(const std::vector<VarValUSetPair>& ll)
{
    return std::make_unique<System>(ll);
}

// systemsList::System ->[(Variable, Set.Set Value)]
std::unique_ptr<std::vector<VarValUSetPair>> Alignment::systemsList(const System& uu)
{
    return std::make_unique<std::vector<VarValUSetPair>>(uu.map_u().begin(), uu.map_u().end());
}


// pairSystemsUnion::System -> System -> System
std::unique_ptr<System> Alignment::pairSystemsUnion(const System& uu, const System& xx)
{
    auto yy = std::make_unique<System>(uu);
    yy->update(xx);
    return yy;
}


// systemsSetVar :: System -> Set.Set Variable
std::unique_ptr<VarUSet> Alignment::systemsSetVar(const System& uu)
{
    auto qq = std::make_unique<VarUSet>(uu.map_u().size());
    for (auto it = uu.map_u().begin(); it != uu.map_u().end(); ++it)
	qq->insert(it->first);
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
std::unique_ptr<System> Alignment::systemRegular(int d, int n)
{
    ValUSet ww(d);
    for (int j = 1; j <= d; j++)
	ww.insert(Value(j));
    VarValUSetUMap mm(n);
    for (int i = 1; i <=n; i++)
	mm[Variable(i)] = ww;
    return std::make_unique<System>(mm);
}

State::State() : _map(), _hash(0)
{
}

State::State(const VarValMap& m) : _map(m), _hash(0) 
{
}

State::State(const std::vector<VarValPair>& ll)
{
    _hash = 0;
    for (auto it = ll.begin(); it != ll.end(); ++it)
	_map.insert_or_assign(it->first, it->second);
}

std::size_t Alignment::State::hash() const
{
    if (!_hash)
	for (auto it = _map.begin(); it != _map.end(); ++it)
	{
	    (std::size_t)_hash *= 3;
	    (std::size_t)_hash += it->first.hash() + it->second.hash();
	}
    return _hash;
}

std::ostream& operator<<(std::ostream& out, const State& ss)
{
    out << ss.map_u();
    return out;
}

// listsState :: [(Variable, Value)] -> State
std::unique_ptr<State> Alignment::listsState(const std::vector<VarValPair>& ll)
{
    return std::make_unique<State>(ll);
}

// statesList :: State -> [(Variable, Value)]
std::unique_ptr<std::vector<VarValPair>> Alignment::statesList(const State& ss)
{
    return std::make_unique<std::vector<VarValPair>>(ss.map_u().begin(), ss.map_u().end());
}

// statesSetVar :: State -> Set.Set Variable
std::unique_ptr<VarUSet> Alignment::statesSetVar(const State& ss)
{
    auto qq = std::make_unique<VarUSet>(ss.map_u().size());
    for (auto it = ss.map_u().begin(); it != ss.map_u().end(); ++it)
	qq->insert(it->first);
    return qq;
}

// statesVarsValue::State -> Variable -> Maybe Value
Value Alignment::statesVarsValue(const State& ss, const Variable& u)
{
    auto it = ss.map_u().find(u);
    if (it != ss.map_u().end())
	return it->second;
    return Value("");
}

// stateEmpty :: State
State Alignment::stateEmpty()
{
    return State();
}

// setVarsStatesStateFiltered :: Set.Set Variable -> State -> State
std::unique_ptr<State> Alignment::setVarsStatesStateFiltered(const VarUSet& vv, const State& ss)
{
    auto rr = std::make_unique<State>();
    auto& mm = rr->map_u();
    for (auto it = ss.map_u().begin(); it != ss.map_u().end(); ++it)
    {
	auto it2 = vv.find(it->first);
	if (it2 != vv.end())
	    mm.insert_or_assign(it->first, it->second);
    }
    return rr;
}



// systemsSetVarsSetStateCartesian_u :: System -> Set.Set Variable -> Maybe (Set.Set State)
std::unique_ptr<StateUSet> Alignment::systemsSetVarsSetStateCartesian_u(const System& uu, const VarUSet& vv)
{
    if (vv.size() == 0)
	return std::unique_ptr<StateUSet>(new StateUSet{State()});
    std::vector<std::vector<VarValPair>> qq{std::vector<VarValPair>{}};
    for (auto& u : vv)
    {
	auto& ww = uu.map_u().at(u);
	std::vector<std::vector<VarValPair>> qq1;
	qq1.reserve(qq.size()*ww.size());
	for (auto& ss : qq)
	    for (auto& w : ww)
	    {
		auto ss1(ss);
		ss1.push_back(VarValPair(u,w));
		qq1.push_back(ss1);
	    }
	qq = qq1;
    }
    auto xx = std::make_unique<StateUSet>(qq.size());
    for (auto& ss : qq)
	xx->insert(State(ss));
    return xx;
}
