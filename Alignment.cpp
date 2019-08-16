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

System::System(const VarValSetUMap& m) : _map(m) 
{
}

System::System(const std::vector<VarValSetPair>& ll)
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
    out << sorted(uu.map_u());
    return out;
}

// listsSystem_u ::[(Variable, Set.Set Value)]->System
std::unique_ptr<System> Alignment::listsSystem_u(const std::vector<VarValSetPair>& ll)
{
    return std::make_unique<System>(ll);
}

// systemsList::System ->[(Variable, Set.Set Value)]
std::unique_ptr<std::vector<VarValSetPair>> Alignment::systemsList(const System& uu)
{
    return std::make_unique<std::vector<VarValSetPair>>(uu.map_u().begin(), uu.map_u().end());
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
ValSet Alignment::systemsVarsSetValue(const System& uu, const Variable& u)
{
    auto it = uu.map_u().find(u);
    if (it != uu.map_u().end())
	return it->second;
    return ValSet();
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
std::unique_ptr<System> Alignment::systemRegular_u(int d, int n)
{
    ValSet ww;
    for (int j = 1; j <= d; j++)
	ww.insert(Value(j));
    VarValSetUMap mm(n);
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

State::State(const Variable& v, const Value& u)
{
    _hash = 0;
    _map.insert_or_assign(v, u);
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

// setVarsSetStatesSplit :: Set.Set Variable -> Set.Set State -> Set.Set (State,State) 
std::unique_ptr<std::set<std::pair<State,State>>> Alignment::setVarsSetStatesSplit(const VarUSet& vv, const StateUSet& qq)
{
    auto sred = setVarsStatesStateFiltered;
    auto svars = statesSetVar;
    auto xx = std::make_unique<std::set<std::pair<State,State>>>();
    for (auto& rr : qq)
    {
	auto ww = svars(rr);
	for (auto& v : vv)
	    ww->erase(v);
	xx->insert(std::pair<State,State>(*sred(vv,rr),*sred(*ww,rr)));
    }
    return xx;
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

History::History() : _map()
{
}

History::History(const IdStateUMap& m) : _map(m)
{
}

History::History(const std::vector<IdStatePair>& ll)
{
    _map.reserve(ll.size());
    for (auto it = ll.begin(); it != ll.end(); ++it)
	_map[it->first] = it->second;
}

std::ostream& operator<<(std::ostream& out, const History& hh)
{
    out << sorted(hh.map_u());
    return out;
}

// listsHistory_u :: [(Id, State)] -> History
std::unique_ptr<History> Alignment::listsHistory_u(const std::vector<IdStatePair>& ll)
{
    return std::make_unique<History>(ll);
}

// historiesList :: History -> [(Id, State)]
std::unique_ptr<std::vector<IdStatePair>> Alignment::historiesList(const History& hh)
{
    return std::make_unique<std::vector<IdStatePair>>(hh.map_u().begin(), hh.map_u().end());
}

// historiesSetVar :: History -> Set.Set Variable
std::unique_ptr<VarUSet> Alignment::historiesSetVar(const History& hh)
{
    auto it = hh.map_u().begin();
    if (it == hh.map_u().end())
	return std::make_unique<VarUSet>();
    return statesSetVar(it->second);
}

// setVarsHistoriesReduce :: Set.Set Variable -> History -> History
std::unique_ptr<History> Alignment::setVarsHistoriesReduce(const VarUSet& vv, const History& hh)
{
    auto filt = setVarsStatesStateFiltered;
    auto ii = std::make_unique<History>();
    ii->map_u().reserve(hh.map_u().size());
    for (auto it = hh.map_u().begin(); it != hh.map_u().end(); ++it)
	    ii->map_u().insert_or_assign(it->first, *filt(vv,it->second));
    return ii;
}


Histogram::Histogram() : _map()
{
}

Histogram::Histogram(const StateRationalUMap& m) : _map(m)
{
}

Histogram::Histogram(const std::vector<StateRationalPair>& ll)
{
    _map.reserve(ll.size());
    for (auto it = ll.begin(); it != ll.end(); ++it)
	_map[it->first] += it->second;
}

Histogram::Histogram(const State& ss, const Rational& a)
{
    _map.reserve(1);
    _map.insert_or_assign(ss, a);
}

Histogram::Histogram(const StateUSet& qq)
{
    _map.reserve(qq.size());
    for (auto it = qq.begin(); it != qq.end(); ++it)
	_map.insert_or_assign(*it,1);
}

std::ostream& operator<<(std::ostream& out, const Histogram& aa)
{
    out << sorted(aa.map_u());
    return out;
}

// listsHistogram_u :: [(State, Rational)] -> Histogram
std::unique_ptr<Histogram> Alignment::listsHistogram_u(const std::vector<StateRationalPair>& ll)
{
    return std::make_unique<Histogram>(ll);
}

// histogramsList :: Histogram -> [(State, Rational)]
std::unique_ptr<std::vector<StateRationalPair>> Alignment::histogramsList(const Histogram& aa)
{
    return std::make_unique<std::vector<StateRationalPair>>(aa.map_u().begin(), aa.map_u().end());
}

// histogramsSetVar :: Histogram -> Set.Set Variable
std::unique_ptr<VarUSet> Alignment::histogramsSetVar(const Histogram& aa)
{
    auto it = aa.map_u().begin();
    if (it == aa.map_u().end())
	return std::make_unique<VarUSet>();
    return statesSetVar(it->first);
}

// histogramsMapVarsFrame_u :: Histogram -> Map.Map Variable Variable -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramsMapVarsFrame_u(const Histogram& aa, const VarVarUMap& nn)
{
    auto bb = std::make_unique<Histogram>();
    bb->map_u().reserve(aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
    {
	auto& ss = it->first;
	auto rr = ss;
	for (auto it2 = ss.map_u().begin(); it2 != ss.map_u().end(); ++it2)
	{
	    auto it3 = nn.find(it2->first);
	    if (it3 != nn.end())
	    {
		rr.map_u().erase(it3->first);
		rr.map_u().insert_or_assign(it3->second, it2->second);
	    }
	}
	bb->map_u()[rr] += it->second;
    }
    return bb;
}

// histogramsStates :: Histogram -> Set.Set State
std::unique_ptr<StateUSet> Alignment::histogramsStates(const Histogram& aa)
{
    auto qq = std::make_unique<StateUSet>();
    qq->reserve(aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	qq->insert(it->first);
    return qq;
}

// histogramsStatesCount :: Histogram -> State -> Maybe Rational
Rational Alignment::histogramsStatesCount(const Histogram& aa, const State& ss)
{
    auto it = aa.map_u().find(ss);
    if (it != aa.map_u().end())
	return it->second;
    return Rational();
}

// histogramsSize :: Histogram -> Rational
Rational Alignment::histogramsSize(const Histogram& aa)
{
    Rational a;
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	a += it->second;
    return a;
}

// histogramsResize :: Rational -> Histogram -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramsResize(const Rational& z, const Histogram& aa)
{
    auto y = histogramsSize(aa);
    auto bb = std::make_unique<Histogram>();
    if (z >= 0 && y > 0)
    {
	bb->map_u().reserve(aa.map_u().size());
	for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	    bb->map_u().insert_or_assign(it->first,it->second*z/y);
    }
    return bb;
}

// histogramSingleton :: State -> Rational -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramSingleton_u(const State& ss, const Rational& a)
{
    return std::make_unique<Histogram>(ss,a);
}

// setStatesHistogramUnit :: Set.Set State -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::setStatesHistogramUnit_u(const StateUSet& qq)
{
    return std::make_unique<Histogram>(qq);
}

// histogramsTrim :: Histogram -> Histogram
std::unique_ptr<Histogram> Alignment::histogramsTrim(const Histogram& aa)
{
    auto bb = std::make_unique<Histogram>();
    bb->map_u().reserve(aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	if (it->second > 0)
	    bb->map_u().insert_or_assign(it->first, it->second);
    return bb;
}

// histogramsEffective :: Histogram -> Histogram
std::unique_ptr<Histogram> Alignment::histogramsEffective(const Histogram& aa)
{
    auto bb = std::make_unique<Histogram>();
    bb->map_u().reserve(aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	if (it->second > 0)
	    bb->map_u().insert_or_assign(it->first, 1);
    return bb;
}

// histogramRegularCartesian_u :: Integer -> Integer -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramRegularCartesian_u(int d, int n)
{
    auto unit = setStatesHistogramUnit_u;
    auto sysreg = systemRegular_u;
    auto cart = systemsSetVarsSetStateCartesian_u;
    auto uvars = systemsSetVar;
    auto uu = sysreg(d, n);
    auto vv = uvars(*uu);
    return unit(*cart(*uu, *vv));
}

// histogramRegularUnitSingleton_u :: Integer -> Integer -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramRegularUnitSingleton_u(int d, int n)
{
    auto llss = listsState;
    auto single = histogramSingleton_u;
    std::vector<VarValPair> ll;
    ll.reserve(n);
    for (int j = 1; j <= n; j++)
	ll.push_back(VarValPair(Variable(j),Value(1)));
    return single(*llss(ll),1);
}


// histogramRegularUnitDiagonal_u :: Integer -> Integer -> Maybe Histogram
std::unique_ptr<Histogram> Alignment::histogramRegularUnitDiagonal_u(int d, int n)
{
    auto llss = listsState;
    auto llaa = listsHistogram_u;
    std::vector<StateRationalPair> qq;
    qq.reserve(d);
    for (int i = 1; i <= d; i++)
    {
	std::vector<VarValPair> ll;
	ll.reserve(n);
	for (int j = 1; j <= n; j++)
	    ll.push_back(VarValPair(Variable(j),Value(i)));
	qq.push_back(StateRationalPair(*llss(ll),1));
    }
    return llaa(qq);
}

// historiesHistogram :: History -> Histogram
std::unique_ptr<Histogram> Alignment::historiesHistogram(const History& hh)
{
    auto llaa = listsHistogram_u;
    std::vector<StateRationalPair> qq;
    qq.reserve(hh.map_u().size());
    for (auto it = hh.map_u().begin(); it != hh.map_u().end(); ++it)
	qq.push_back(StateRationalPair(it->second,1));
    return llaa(qq);
}

// histogramsHistory_u :: Histogram -> History
std::unique_ptr<History> Alignment::histogramsHistory_u(const Histogram& aa)
{
    auto llhh = listsHistory_u;
    auto size = histogramsSize;
    std::vector<IdStatePair> qq;
    int s = size(aa).getNumerator();
    qq.reserve(s);
    int i = 1;
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	for (int j = 0; j < it->second.getNumerator(); j++)
	    qq.push_back(IdStatePair(Id(i++),it->first));
    return llhh(qq);
}


// setVarsHistogramsReduce :: Set.Set Variable -> Histogram -> Histogram 
std::unique_ptr<Histogram> Alignment::setVarsHistogramsReduce(const VarUSet& vv, const Histogram& aa)
{
    auto filt = setVarsStatesStateFiltered;
    auto bb = std::make_unique<Histogram>();
    bb->map_u().reserve(aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	bb->map_u()[*filt(vv, it->first)] += it->second;
    return bb;
}

// pairHistogramsAdd_u :: Histogram -> Histogram -> Histogram 
std::unique_ptr<Histogram> Alignment::pairHistogramsAdd_u(const Histogram& aa, const Histogram& bb)
{
    auto cc = std::make_unique<Histogram>();
    cc->map_u().reserve(aa.map_u().size()+ aa.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	cc->map_u().insert_or_assign(it->first, it->second);
    for (auto it = bb.map_u().begin(); it != bb.map_u().end(); ++it)
	cc->map_u()[it->first] += it->second;
    return cc;
}

// pairHistogramsAdd_u_1 :: Histogram -> Histogram -> Histogram 
std::unique_ptr<Histogram> Alignment::pairHistogramsAdd_u_1(const Histogram& aa, const Histogram& bb)
{
    auto aall = histogramsList;
    auto llaa = listsHistogram_u;
    auto pp = aall(aa);
    auto qq = aall(bb);
    pp->reserve(pp->size() + qq->size());
    pp->insert(pp->end(), qq->begin(), qq->end());
    return llaa(*qq);
}

// pairHistogramsMultiply :: Histogram -> Histogram -> Histogram 
std::unique_ptr<Histogram> Alignment::pairHistogramsMultiply(const Histogram& aa, const Histogram& bb)
{
    auto cc = std::make_unique<Histogram>();
    cc->map_u().reserve(aa.map_u().size() * bb.map_u().size());
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	for (auto it2 = bb.map_u().begin(); it2 != bb.map_u().end(); ++it2)
	{
	    auto& ll = it->first;
	    auto& rr = it2->first;
	    bool isjoin = true;
	    for (auto it3 = ll.map_u().begin(); isjoin && it3 != ll.map_u().end(); ++it3)
	    {
		auto it4 = rr.map_u().find(it3->first);
		isjoin = it4 == rr.map_u().end() || it4->second == it3->second;
	    }
	    if (isjoin)
	    {
		State tt(ll.map_u());
		tt.map_u().insert(rr.map_u().begin(), rr.map_u().end());
		cc->map_u().insert_or_assign(tt, it->second * it2->second);
	    }
	}
    return cc;
}