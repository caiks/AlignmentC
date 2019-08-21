#include "AlignmentUtil.h"
#include "Alignment.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace Alignment;
using namespace std;

void main()
{
    if (false)
    {
	Rational a, b;
	a = 5;
	cout << a << endl;
	b = a + 7;
	cout << b << endl;
	b = 0.75;
	cout << b << endl;
	a++;
	cout << a << endl;
    }

    if (false) 
    {
	Variable v1("aa");
	cout << v1 << endl;

	Variable v2(3);
	cout << v2 << endl;

	Variable v3(Variable("aa"), Variable(3));
	cout << v3 << endl;

	Variable v4(Variable("aa"), Variable(Variable("aa"), Variable(3)));
	cout << v4 << endl;

	Variable v5(Variable("aa"), Variable(Variable(3),Variable("aa")));
	cout << v5 << endl;

	cout << "v1 < v1 == " << (v1 < v1) << endl;
	cout << "v1 > v1 == " << (v1 > v1) << endl;
	cout << "v1 == v1 == " << (v1 == v1) << endl;

	cout << "v2 < v2 == " << (v2 < v2) << endl;
	cout << "v2 > v2 == " << (v2 > v2) << endl;
	cout << "v2 == v2 == " << (v2 == v2) << endl;

	cout << "v3 < v3 == " << (v3 < v3) << endl;
	cout << "v3 > v3 == " << (v3 > v3) << endl;
	cout << "v3 == v3 == " << (v3 == v3) << endl;

	cout << "v4 < v4 == " << (v4 < v4) << endl;
	cout << "v4 > v4 == " << (v4 > v4) << endl;
	cout << "v4 == v4 == " << (v4 == v4) << endl;

	cout << "v5 < v5 == " << (v5 < v5) << endl;
	cout << "v5 > v5 == " << (v5 > v5) << endl;
	cout << "v5 == v5 == " << (v5 == v5) << endl;

	cout << "v1 < v2 == " << (v1 < v2) << endl;
	cout << "v1 > v2 == " << (v1 > v2) << endl;
	cout << "v1 == v2 == " << (v1 == v2) << endl;

	cout << "v2 < v3 == " << (v2 < v3) << endl;
	cout << "v2 > v3 == " << (v2 > v3) << endl;
	cout << "v2 == v3 == " << (v2 == v3) << endl;

	cout << "v3 < v4 == " << (v3 < v4) << endl;
	cout << "v3 > v4 == " << (v3 > v4) << endl;
	cout << "v3 == v4 == " << (v3 == v4) << endl;

	cout << "v4 < v5 == " << (v4 < v5) << endl;
	cout << "v4 > v5 == " << (v4 > v5) << endl;
	cout << "v4 == v5 == " << (v4 == v5) << endl;

	set<Variable> vv1 = { v1,v2,v3,v4,v5 };
	cout << "vv1 =" << vv1 << endl;

	set<Variable> vv2 = { v5,v4,v3,v2,v1 };
	cout << "vv2 =" << vv2 << endl;

	cout << "v1.hash() == " << v1.hash() << endl;
	cout << "v2.hash() == " << v2.hash() << endl;
	cout << "v3.hash() == " << v3.hash() << endl;
	cout << "v4.hash() == " << v4.hash() << endl;
	cout << "v5.hash() == " << v5.hash() << endl;

	unordered_set<Variable> vv3 = { v5,v4,v3,v2,v1 };
	cout << "vv3 =" << vv3 << endl;
    }

    if (false) 
    {
	Value v1("aa");
	cout << v1 << endl;

	Value v2(3);
	cout << v2 << endl;

	Value v3(1.23);
	cout << v3 << endl;


	cout << "v1 < v1 == " << (v1 < v1) << endl;
	cout << "v1 > v1 == " << (v1 > v1) << endl;
	cout << "v1 == v1 == " << (v1 == v1) << endl;

	cout << "v2 < v2 == " << (v2 < v2) << endl;
	cout << "v2 > v2 == " << (v2 > v2) << endl;
	cout << "v2 == v2 == " << (v2 == v2) << endl;

	cout << "v3 < v3 == " << (v3 < v3) << endl;
	cout << "v3 > v3 == " << (v3 > v3) << endl;
	cout << "v3 == v3 == " << (v3 == v3) << endl;

	cout << "v1 < v2 == " << (v1 < v2) << endl;
	cout << "v1 > v2 == " << (v1 > v2) << endl;
	cout << "v1 == v2 == " << (v1 == v2) << endl;

	cout << "v2 < v3 == " << (v2 < v3) << endl;
	cout << "v2 > v3 == " << (v2 > v3) << endl;
	cout << "v2 == v3 == " << (v2 == v3) << endl;

	set<Value> vv1 = { v1,v2,v3 };
	cout << "vv1 =" << vv1 << endl;

	set<Value> vv2 = { v3,v2,v1 };
	cout << "vv2 =" << vv2 << endl;

	cout << "v1.hash() == " << v1.hash() << endl;
	cout << "v2.hash() == " << v2.hash() << endl;
	cout << "v3.hash() == " << v3.hash() << endl;

	unordered_set<Value> vv3 = { v3,v2,v1 };
	cout << "vv3 =" << vv3 << endl;
    }

    if (false)
    {
	Id v1("aa");
	cout << v1 << endl;

	Id v2(3);
	cout << v2 << endl;

	cout << "v1 < v1 == " << (v1 < v1) << endl;
	cout << "v1 > v1 == " << (v1 > v1) << endl;
	cout << "v1 == v1 == " << (v1 == v1) << endl;

	cout << "v2 < v2 == " << (v2 < v2) << endl;
	cout << "v2 > v2 == " << (v2 > v2) << endl;
	cout << "v2 == v2 == " << (v2 == v2) << endl;

	cout << "v1 < v2 == " << (v1 < v2) << endl;
	cout << "v1 > v2 == " << (v1 > v2) << endl;
	cout << "v1 == v2 == " << (v1 == v2) << endl;

	set<Id> vv1 = { v1,v2 };
	cout << "vv1 =" << vv1 << endl;

	set<Id> vv2 = { v2,v1 };
	cout << "vv2 =" << vv2 << endl;

	cout << "v1.hash() == " << v1.hash() << endl;
	cout << "v2.hash() == " << v2.hash() << endl;

	unordered_set<Id> vv3 = { v2,v1 };
	cout << "vv3 =" << vv3 << endl;
    }

    if (false)
    {
	auto suit = Variable("suit");
	auto rank = Variable("rank");

	auto vv = vector<Variable>{ suit, rank };

	cout << vv << endl;
    }

    if (false)
    {
	auto suit = Variable("suit");
	auto rank = Variable("rank");

	auto vv = VarUSet{ suit,rank };

	cout << "vv" << endl 
	    << sorted(vv) << endl << endl;

	auto hearts = Value("hearts");
	auto clubs = Value("clubs");
	auto diamonds = Value("diamonds");
	auto spades = Value("spades");

	auto wws = ValSet{hearts,clubs,diamonds,spades};

	cout << "wws" << endl 
	    << wws << endl << endl;

	auto jack = Value("J");
	auto queen = Value("Q");
	auto king = Value("K");
	auto ace = Value("A");

	auto wwr = ValSet{jack,queen,king,ace };
	for (int i = 2; i <= 10; i++)
	    wwr.insert(Value(i));

	cout << "wwr" << endl 
	    << wwr << endl << endl;

	auto uu = listsSystem_u(std::vector<VarValSetPair> {VarValSetPair(suit,wws), VarValSetPair(rank,wwr)});

	cout << "uu" << endl 
	    << *uu << endl << endl;

	cout << "rpln(cout,systemsList(uu))" << endl;
	rpln(cout,*systemsList(*uu)); cout << endl;

	//auto uu1 = listsSystem_u(std::vector<VarValUSetPair> {VarValUSetPair(suit, wws)});
	//auto uu2 = listsSystem_u(std::vector<VarValUSetPair> {VarValUSetPair(rank, wwr)});

	//cout << pairSystemsUnion(uu1,uu2) << endl;

	auto uvars = systemsSetVar;
	cout << "uvars(uu)" << endl 
	    << sorted(*uvars(*uu)) << endl << endl;

	auto uat = systemsVarsSetValue;
	cout << "uat(uu,suit)" << endl
	    << uat(*uu,suit) << endl << endl;
	cout << "uat(uu,suit).size()" << endl
	    << uat(*uu,suit).size() << endl << endl;
	cout << "uat(uu,rank).size()" << endl
	    << uat(*uu,rank).size() << endl << endl;

	auto vol = systemsSetVarsVolume_u;
	cout << "vol(uu,vv)" << endl
	    << vol(*uu,vv) << endl << endl;
	cout << "vol(uu,VarUSet{suit})" << endl
	    << vol(*uu,VarUSet{suit}) << endl << endl;
	cout << "vol(uu,VarUSet{rank})" << endl
	    << vol(*uu,VarUSet{rank}) << endl << endl;

	auto sysreg = systemRegular_u;

	auto uu1 = sysreg(3, 2);
	cout << "uu1" << endl
	    << *uu1 << endl << endl;
	cout << "vol(uu1,uvars(uu1))" << endl
	    << vol(*uu1,*uvars(*uu1)) << endl << endl;

	auto llss = listsState;
	auto ssll = statesList;

	auto ss = llss(std::vector<VarValPair>{VarValPair(suit, spades), VarValPair(rank, ace)});
	cout << "ss" << endl
	    << *ss << endl << endl;
	cout << "rpln(cout,ssll(ss))" << endl;
	rpln(cout,*ssll(*ss)); cout << endl;

	auto svars = statesSetVar;
	cout << "svars(ss)" << endl
	    << sorted(*svars(*ss)) << endl << endl;

	auto sat = statesVarsValue;
	cout << "sat(ss,suit)" << endl
	    << sat(*ss,suit) << endl << endl;

	cout << "svars(stateEmpty())" << endl
	    << sorted(*svars(stateEmpty())) << endl << endl;

	auto cart = systemsSetVarsSetStateCartesian_u;
	cout << "rpln(cout,cart(uu,vv))" << endl;
	rpln(cout,sorted(*cart(*uu,vv))); cout << endl;
	cout << "cart(uu,vv).size()" << endl
	    << cart(*uu, vv)->size() << endl << endl;
	cout << "vol(uu,vv)" << endl
	    << vol(*uu,vv) << endl << endl;

	auto sred = [](const State& ss, const VarUSet& vv) 
	{
	    return setVarsStatesStateFiltered(vv,ss);
	};
	cout << "sred(ss,svars(ss))" << endl
	    << *sred(*ss,*svars(*ss)) << endl << endl;
	cout << "sred(ss,set())" << endl
	    << *sred(*ss,VarUSet()) << endl << endl;
	cout << "sred(ss,set([suit]))" << endl
	    << *sred(*ss,VarUSet{suit}) << endl << endl;
	cout << "sred(ss,set([rank]))" << endl
	    << *sred(*ss,VarUSet{rank}) << endl << endl;

	auto ssplit = setVarsSetStatesSplit;
	cout << "rpln(ssplit(sset([suit]),cart(uu,vv)))" << endl;
	rpln(cout,*ssplit(VarUSet{suit},*cart(*uu,vv))); cout << endl;
    }

    if (false)
    {
	auto cart = systemsSetVarsSetStateCartesian_u;

	auto suit = Variable("suit");
	auto rank = Variable("rank");
	auto vv = VarUSet{suit,rank};
	auto hearts = Value("hearts");
	auto clubs = Value("clubs");
	auto diamonds = Value("diamonds");
	auto spades = Value("spades");
	auto wws = ValSet{hearts,clubs,diamonds,spades};
	auto jack = Value("J");
	auto queen = Value("Q");
	auto king = Value("K");
	auto ace = Value("A");
	auto wwr = ValSet{jack,queen,king,ace};
	for (int i = 2; i <= 10; i++)
	    wwr.insert(Value(i));
	auto uu = listsSystem_u(std::vector<VarValSetPair>{VarValSetPair(suit,wws),VarValSetPair(rank,wwr)});

	auto llhh = listsHistory_u;
	auto hhll = historiesList;

	std::vector<IdStatePair> ll;
	{
	    auto qq = cart(*uu,vv);
	    int i = 1;
	    for (auto ss : *qq)
		ll.push_back(IdStatePair(Id(i++),ss));
	}
	auto hh = llhh(ll);

	cout << "hh" << endl
	    << *hh << endl << endl;
	cout << "rpln(hhll(hh))" << endl;
	rpln(cout,*hhll(*hh)); cout << endl;

	auto hvars = historiesSetVar;
	cout << "hvars(hh)" << endl
	    << sorted(*hvars(*hh)) << endl << endl;

	auto hred = [](const History& hh, const VarUSet& vv)
	{
	    return setVarsHistoriesReduce(vv, hh);
	};
	cout << "rpln(hhll(hred(hh,set([suit])))" << endl;
	rpln(cout, *hhll(*hred(*hh, VarUSet{ suit }))); cout << endl;
	cout << "rpln(hhll(hred(hh,set([rank])))" << endl;
	rpln(cout, *hhll(*hred(*hh, VarUSet{ rank }))); cout << endl;

	auto hsize = historiesSize;
	cout << "hsize(hh)" << endl
	    << hsize(*hh) << endl << endl;
    }

    if (false)
    {
	auto cart = systemsSetVarsSetStateCartesian_u;

	auto suit = Variable("suit");
	auto rank = Variable("rank");
	auto vv = VarUSet{ suit,rank };
	auto hearts = Value("hearts");
	auto clubs = Value("clubs");
	auto diamonds = Value("diamonds");
	auto spades = Value("spades");
	auto wws = ValSet{ hearts,clubs,diamonds,spades };
	auto jack = Value("J");
	auto queen = Value("Q");
	auto king = Value("K");
	auto ace = Value("A");
	auto wwr = ValSet{ jack,queen,king,ace };
	for (int i = 2; i <= 10; i++)
	    wwr.insert(Value(i));
	auto uu = listsSystem_u(std::vector<VarValSetPair>{VarValSetPair(suit, wws), VarValSetPair(rank, wwr)});

	auto llaa = listsHistogram_u;
	auto aall = histogramsList;

	std::vector<StateRationalPair> ll;
	{
	    auto qq = cart(*uu, vv);
	    for (auto ss : *qq)
		ll.push_back(StateRationalPair(ss,1.0));
	}
	auto aa = llaa(ll);

	cout << "aa" << endl
	    << *aa << endl << endl;
	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	auto vars = histogramsSetVar;
	cout << "vars(aa)" << endl
	    << sorted(*vars(*aa)) << endl << endl;

	auto reframe = histogramsMapVarsFrame_u;

	auto mm = VarVarUMap{{suit,Variable("S")},{rank,Variable("R")}};
	cout << "rpln(aall(reframe(aa,mm)))" << endl;
	rpln(cout, sorted(*aall(*reframe(*aa,mm)))); cout << endl;
	cout << "vars(reframe(aa,mm))" << endl
	    << sorted(*vars(*reframe(*aa, mm))) << endl << endl;

	auto states = histogramsStates;
	cout << "rpln(states(aa))" << endl;
	rpln(cout, sorted(*states(*aa))); cout << endl;

	auto aat = histogramsStatesCount;
	auto ss = State(std::vector<VarValPair>{VarValPair(suit,spades),VarValPair(rank,ace)});

	cout << "ss" << endl
	    << ss << endl << endl;
	cout << "aat(aa,ss)" << endl
	    << aat(*aa,ss) << endl << endl;

	auto size = histogramsSize;
	cout << "size(aa)" << endl
	    << size(*aa) << endl << endl;

	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	cout << "rpln(aall(norm(aa)))" << endl;
	rpln(cout, sorted(*aall(*norm(*aa)))); cout << endl;
	cout << "size(norm(aa))" << endl
	    << size(*norm(*aa)) << endl << endl;

	auto scalar = histogramScalar_u;

	cout << "scalar(52)" << endl
	    << *scalar(52) << endl << endl;

	auto single = histogramSingleton_u;
	auto rr = State(std::vector<VarValPair>{VarValPair(suit, hearts), VarValPair(rank, queen)});

	cout << "single(ss,1)" << endl
	    << *single(ss, 1) << endl << endl;
	cout << "single(rr,1)" << endl
	    << *single(rr, 1) << endl << endl;

	auto unit = setStatesHistogramUnit_u;
	cout << "rpln(aall(unit(cart(uu,vv))))" << endl;
	rpln(cout, sorted(*aall(*unit(*cart(*uu, vv))))); cout << endl;
	cout << "rpln(aall(unit(StateUSet{rr,ss})))" << endl;
	rpln(cout, sorted(*aall(*unit(StateUSet{ rr,ss })))); cout << endl;

	auto trim = histogramsTrim;
	cout << "rpln(aall(trim(llaa([(ss, 3), (rr, 0)]))))" << endl;
	rpln(cout, sorted(*aall(*trim(*llaa(std::vector<StateRationalPair>{StateRationalPair(ss, 3), StateRationalPair(rr, 0)}))))); cout << endl;
	cout << "rpln(aall(trim(llaa([(ss, 3), (rr, 5)]))))" << endl;
	rpln(cout, sorted(*aall(*trim(*llaa(std::vector<StateRationalPair>{StateRationalPair(ss, 3), StateRationalPair(rr, 5)}))))); cout << endl;

	auto eff = histogramsEffective;
	cout << "rpln(aall(eff(llaa([(ss, 3), (rr, 0)]))))" << endl;
	rpln(cout, sorted(*aall(*eff(*llaa(std::vector<StateRationalPair>{StateRationalPair(ss, 3), StateRationalPair(rr, 0)}))))); cout << endl;
	cout << "rpln(aall(eff(llaa([(ss, 3), (rr, 5)]))))" << endl;
	rpln(cout, sorted(*aall(*eff(*llaa(std::vector<StateRationalPair>{StateRationalPair(ss, 3), StateRationalPair(rr, 5)}))))); cout << endl;

	auto regcart = histogramRegularCartesian_u;
	cout << "rpln(aall(regcart(3,2)))" << endl;
	rpln(cout, sorted(*aall(*regcart(3, 2)))); cout << endl;

	auto regsing = histogramRegularUnitSingleton_u;
	cout << "rpln(aall(regsing(3,2)))" << endl;
	rpln(cout, sorted(*aall(*regsing(3, 2)))); cout << endl;

	auto regdiag = histogramRegularUnitDiagonal_u;
	cout << "rpln(aall(regdiag(3,2)))" << endl;
	rpln(cout, sorted(*aall(*regdiag(3, 2)))); cout << endl;

	auto hhll = historiesList;
	auto hhaa = historiesHistogram;
	auto aahh = histogramsHistory_u;

	cout << "rpln(hhll(aahh(aa)))" << endl;
	rpln(cout, *hhll(*aahh(*aa))); cout << endl;
	cout << "rpln(aall(hhaa(aahh(aa))))" << endl;
	rpln(cout, sorted(*aall(*hhaa(*aahh(*aa))))); cout << endl;

	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	cout << "rpln(aall(ared(aa,sset([suit]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{suit})))); cout << endl;
	cout << "rpln(aall(ared(aa,sset([rank]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ rank })))); cout << endl;
	cout << "rpln(aall(ared(aa,sset([]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet())))); cout << endl;
	cout << "rpln(aall(ared(aa,vars(aa))))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa,*vars(*aa))))); cout << endl;

	auto bb = single(State(std::vector<VarValPair>{VarValPair(suit, spades), VarValPair(rank, ace)}),1);

	auto cc = llaa(std::vector<StateRationalPair>{StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, spades), VarValPair(rank, ace)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, hearts), VarValPair(rank, queen)}), 1)});

	auto dd = llaa(std::vector<StateRationalPair>{StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, spades), VarValPair(rank, ace)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, hearts), VarValPair(rank, queen)}), 2)});

	auto add = pairHistogramsAdd_u;

	cout << "bb" << endl
	    << *bb << endl << endl;
	cout << "cc" << endl
	    << *cc << endl << endl;
	cout << "dd" << endl
	    << *dd << endl << endl;
	cout << "add(bb,cc)" << endl
	    << *add(*bb, *cc) << endl << endl;
	cout << "add(cc,dd)" << endl
	    << *add(*cc, *dd) << endl << endl;
	cout << "add(bb,add(cc,dd))" << endl
	    << *add(*bb, *add(*cc, *dd)) << endl << endl;

	auto mul = pairHistogramsMultiply;

	auto colour = Variable("colour");
	auto red = Value("red");
	auto black = Value("black");

	bb = llaa(std::vector<StateRationalPair>{StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, hearts), VarValPair(colour, red)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, clubs), VarValPair(colour, black)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, diamonds), VarValPair(colour, red)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(suit, spades), VarValPair(colour, black)}), 1)});

	cout << "rpln(aall(bb))" << endl;
	rpln(cout, sorted(*aall(*bb))); cout << endl;
	cout << "rpln(aall(mul(aa,bb)))" << endl;
	rpln(cout, sorted(*aall(*mul(*aa, *bb)))); cout << endl;
	cout << "rpln(aall(ared(mul(aa,bb),sset([rank,colour]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*mul(*aa,*bb), VarUSet{ rank, colour })))); cout << endl;
	cout << "rpln(aall(ared(mul(aa,bb),sset([colour]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*mul(*aa, *bb), VarUSet{ colour })))); cout << endl;

	auto coin = Variable("coin");
	auto heads = Value("heads");
	auto tails = Value("tails");

	cc = llaa(std::vector<StateRationalPair>{StateRationalPair(State(std::vector<VarValPair>{VarValPair(coin, heads)}), 1), StateRationalPair(State(std::vector<VarValPair>{VarValPair(coin, tails)}), 1)});

	cout << "rpln(aall(cc))" << endl;
	rpln(cout, sorted(*aall(*cc))); cout << endl;
	cout << "rpln(aall(mul(aa,cc)))" << endl;
	rpln(cout, sorted(*aall(*mul(*aa, *cc)))); cout << endl;
	cout << "rpln(aall(ared(mul(aa,cc),sset([coin]))))" << endl;
	rpln(cout, sorted(*aall(*ared(*mul(*aa, *cc), VarUSet{ coin })))); cout << endl;

	auto ind = histogramsIndependent;
	cout << "rpln(aall(ind(aa)))" << endl;
	rpln(cout, sorted(*aall(*ind(*aa)))); cout << endl;
	cout << "size(ind(aa))" << endl
	    << size(*ind(*aa)) << endl << endl;
	cout << "rpln(aall(ind(regdiag(2,2))))" << endl;
	rpln(cout, sorted(*aall(*ind(*regdiag(2, 2))))); cout << endl;
	cout << "rpln(aall(ind(regsing(2,2))))" << endl;
	rpln(cout, sorted(*aall(*ind(*regsing(2, 2))))); cout << endl;
	cout << "rpln(aall(ind(regcart(2,2))))" << endl;
	rpln(cout, sorted(*aall(*ind(*regcart(2, 2))))); cout << endl;
    }

    if (true)
    {
	auto uvars = systemsSetVar;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto vol = systemsSetVarsVolume_u;
	auto ssplit = [](const VarUSet& vv, const Histogram& aa)
	{
	    return setVarsSetStatesSplit(vv, *histogramsStates(aa));
	};
	typedef std::pair<int, ValList> IntValListPair;
	typedef std::vector<IntValListPair> IntValListPairList;
	auto llhh = [](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *listsState(jj)));
	    }
	    return listsHistory_u(ii);
	};
	auto hhll = historiesList;
	auto hvars = historiesSetVar;
	auto hsize = historiesSize;
	auto hred = [](const History& hh, const VarUSet& vv)
	{
	    return setVarsHistoriesReduce(vv, hh);
	};
	auto hhaa = historiesHistogram;
	auto aahh = histogramsHistory_u;
	auto aall = histogramsList;
	auto vars = histogramsSetVar;
	auto size = histogramsSize;
	auto unit = setStatesHistogramUnit_u;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto ind = histogramsIndependent;

	auto pressure = Variable("pressure");
	auto cloud = Variable("cloud");
	auto wind = Variable("wind");
	auto rain = Variable("rain");
	auto low = Value("low");
	auto medium = Value("medium");
	auto high = Value("high");
	auto none = Value("none");
	auto light = Value("light");
	auto heavy = Value("heavy");
	auto strong = Value("strong");

	auto uu = listsSystem_u(std::vector<VarValSetPair>{
	    VarValSetPair(pressure, ValSet{ low,medium,high }),
		VarValSetPair(cloud, ValSet{ none,light,heavy }),
		VarValSetPair(wind, ValSet{ none,light,strong }),
		VarValSetPair(rain, ValSet{ none,light,heavy })});

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "uvars(uu)" << endl
	    << sorted(*uvars(*uu)) << endl << endl;

	auto vv = uvars(*uu);

	cout << "vol(uu,vv)" << endl
	    << vol(*uu, *vv) << endl << endl;

	auto hh = llhh(VarList{ pressure, cloud, wind, rain }, IntValListPairList{
	    IntValListPair(1, ValList{high, none, none, none}),
	    IntValListPair(2, ValList{medium, light, none, light}),
	    IntValListPair(3, ValList{high, none, light, none}),
	    IntValListPair(4, ValList{low, heavy, strong, heavy}),
	    IntValListPair(5, ValList{low, none, light, light}),
	    IntValListPair(6, ValList{medium, none, light, light}),
	    IntValListPair(7, ValList{low, heavy, light, heavy}),
	    IntValListPair(8, ValList{high, none, light, none}),
	    IntValListPair(9, ValList{medium, light, strong, heavy}),
	    IntValListPair(10, ValList{medium, light, light, light}),
	    IntValListPair(11, ValList{high, light, light, heavy}),
	    IntValListPair(12, ValList{medium, none, none, none}),
	    IntValListPair(13, ValList{medium, light, none, none}),
	    IntValListPair(14, ValList{high, light, strong, light}),
	    IntValListPair(15, ValList{medium, none, light, light}),
	    IntValListPair(16, ValList{low, heavy, strong, heavy}),
	    IntValListPair(17, ValList{low, heavy, light, heavy}),
	    IntValListPair(18, ValList{high, none, none, none}),
	    IntValListPair(19, ValList{low, light, none, light}),
	    IntValListPair(20, ValList{high, none, none, none})});

	cout << "rpln(hhll(hh))" << endl;
	rpln(cout, sorted(*hhll(*hh))); cout << endl;

	cout << "hvars(hh)" << endl
	    << sorted(*hvars(*hh)) << endl << endl;

	cout << "hsize(hh)" << endl
	    << hsize(*hh) << endl << endl;

	cout << "rpln(hhll(hred(hh,[pressure,rain])))" << endl;
	rpln(cout, *hhll(*hred(*hh, VarUSet{ pressure,rain }))); cout << endl;

	auto aa = hhaa(*hh);
	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	cout << "vars(aa)" << endl
	    << sorted(*vars(*aa)) << endl << endl;

	cout << "size(aa)" << endl
	    << size(*aa) << endl << endl;

	cout << "size(unit(cart(uu,vv)))" << endl
	    << size(*unit(*cart(*uu, *vv))) << endl << endl;

	cout << "rpln(aall(norm(aa)))" << endl;
	rpln(cout, sorted(*aall(*norm(*aa)))); cout << endl;

	cout << "rpln(aall(red(aa,[pressure,rain])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ pressure,rain })))); cout << endl;

	cout << "rpln(ssplit([pressure],red(aa,[pressure,rain]))))" << endl;
	rpln(cout, *ssplit(VarUSet{ pressure }, *ared(*aa, VarUSet{ pressure,rain }))); cout << endl;

	cout << "rpln(aall(red(aa,[cloud,wind,rain])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ cloud,wind,rain })))); cout << endl;

	cout << "rpln(ssplit([cloud,wind],red(aa,[cloud,wind,rain])))" << endl;
	rpln(cout, *ssplit(VarUSet{ cloud,wind }, *ared(*aa, VarUSet{ cloud,wind,rain }))); cout << endl;

	cout << "rpln(aall(red(aa,[pressure])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ pressure })))); cout << endl;

	cout << "rpln(aall(red(aa,[cloud])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ cloud })))); cout << endl;

	cout << "rpln(aall(red(aa,[wind])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ wind })))); cout << endl;

	cout << "rpln(aall(red(aa,[rain])))" << endl;
	rpln(cout, sorted(*aall(*ared(*aa, VarUSet{ rain })))); cout << endl;

	cout << "rpln(aall(ind(aa)))" << endl;
	rpln(cout, sorted(*aall(*ind(*aa)))); cout << endl;

    }

}
