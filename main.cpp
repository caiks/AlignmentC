#include "AlignmentUtil.h"
#include "Alignment.h"
#include "AlignmentApprox.h"
#include "AlignmentAeson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <iomanip>
#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <thread>

using namespace Alignment;
namespace js = rapidjson;
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

    if (true)
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

	auto hsys = historiesSystemImplied;

	cout << "hsys(hh)" << endl
	    << *hsys(*hh) << endl << endl;
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

	auto sys = histogramsSystemImplied;

	cout << "sys(regcart(3,2))" << endl
	    << *sys(*regcart(3, 2)) << endl << endl;

	cout << "sys(regsing(3,2))" << endl
	    << *sys(*regsing(3, 2)) << endl << endl;

	cout << "sys(regdiag(3,2))" << endl
	    << *sys(*regdiag(3, 2)) << endl << endl;

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

    if (false)
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

    if (false)
    {
	auto lluu = listsSystem_u;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ent = histogramsEntropy;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto lent = [size, ent, ared](const VarUSet& vv, const Histogram& aa)
	{
	    return size(aa).getDouble() * (ent(aa) - ent(*ared(aa, vv)));
	};
	auto algn = histogramsAlignment;

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
	auto uu = lluu(std::vector<VarValSetPair>{VarValSetPair(suit, wws), VarValSetPair(rank, wwr)});

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "vv" << endl
	    << sorted(vv) << endl << endl;

	auto aa = unit(*cart(*uu, vv));
	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	cout << "ent(aa)" << endl
	    << setprecision(17) << ent(*aa) << endl << endl;

	double z = size(*aa).getDouble();

	cout << "z * ent(aa)" << endl
	    << setprecision(17) << z * ent(*aa) << endl << endl;

	cout << "ent(regsing(2,2))" << endl
	    << setprecision(17) << ent(*regsing(2, 2)) << endl << endl;

	cout << "lent([suit, rank],aa)" << endl
	    << setprecision(17) << lent(VarUSet{ suit, rank }, *aa) << endl << endl;

	cout << "lent([],aa)" << endl
	    << setprecision(17) << lent(VarUSet{}, *aa) << endl << endl;

	cout << "lent([suit],aa)" << endl
	    << setprecision(17) << lent(VarUSet{ suit }, *aa) << endl << endl;

	cout << "lent([rank],aa)" << endl
	    << setprecision(17) << lent(VarUSet{ rank }, *aa) << endl << endl;

	aa = norm(*regsing(3, 2));
	aa = add(*aa, *norm(*regdiag(3, 2)));
	aa = add(*aa, *norm(*regcart(3, 2)));
	aa = resize(100, *aa);

	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	cout << "algn(aa)" << endl
	    << setprecision(17) << algn(*aa) << endl << endl;

	cout << "algn(scalar(100))" << endl
	    << setprecision(17) << algn(*scalar(100)) << endl << endl;
	cout << "algn(resize(100,regdiag(3,1)))" << endl
	    << setprecision(17) << algn(*resize(100, *regdiag(3, 1))) << endl << endl;
	cout << "algn(resize(100,regcart(3,3)))" << endl
	    << setprecision(17) << algn(*resize(100, *regcart(3, 3))) << endl << endl;
	cout << "algn(resize(100,regsing(3,3)))" << endl
	    << setprecision(17) << algn(*resize(100, *regsing(3, 3))) << endl << endl;

	cout << "algn(resize(100,regdiag(3,2)))" << endl
	    << setprecision(17) << algn(*resize(100, *regdiag(3, 2))) << endl << endl;
    }

    if (false)
    {
	auto uvars = systemsSetVar;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto vol = systemsSetVarsVolume_u;
	auto ssplit = [](const VarUSet& vv, const Histogram& aa)
	{
	    return setVarsSetStatesSplit(vv, *histogramsStates(aa));
	};

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
	auto ent = histogramsEntropy;
	auto lent = [size, ent, ared](const VarUSet& vv, const Histogram& aa)
	{
	    return size(aa).getDouble() * (ent(aa) - ent(*ared(aa, vv)));
	};
	auto algn = histogramsAlignment;

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
	auto vv = uvars(*uu);
	auto hh = llhh(VarList{ pressure, cloud, wind, rain }, IntValListPairList{
	    IntValListPair(1, ValList{ high, none, none, none }),
	    IntValListPair(2, ValList{ medium, light, none, light }),
	    IntValListPair(3, ValList{ high, none, light, none }),
	    IntValListPair(4, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(5, ValList{ low, none, light, light }),
	    IntValListPair(6, ValList{ medium, none, light, light }),
	    IntValListPair(7, ValList{ low, heavy, light, heavy }),
	    IntValListPair(8, ValList{ high, none, light, none }),
	    IntValListPair(9, ValList{ medium, light, strong, heavy }),
	    IntValListPair(10, ValList{ medium, light, light, light }),
	    IntValListPair(11, ValList{ high, light, light, heavy }),
	    IntValListPair(12, ValList{ medium, none, none, none }),
	    IntValListPair(13, ValList{ medium, light, none, none }),
	    IntValListPair(14, ValList{ high, light, strong, light }),
	    IntValListPair(15, ValList{ medium, none, light, light }),
	    IntValListPair(16, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(17, ValList{ low, heavy, light, heavy }),
	    IntValListPair(18, ValList{ high, none, none, none }),
	    IntValListPair(19, ValList{ low, light, none, light }),
	    IntValListPair(20, ValList{ high, none, none, none }) });
	auto aa = hhaa(*hh);

	cout << "size(aa)" << endl
	    << size(*aa) << endl << endl;

	double z = size(*aa).getDouble();

	cout << "z * ent(aa)" << endl
	    << setprecision(17) << z * ent(*aa) << endl << endl;

	cout << "z * ent(ind(aa))" << endl
	    << setprecision(17) << z * ent(*ind(*aa)) << endl << endl;

	cout << "algn(aa)" << endl
	    << setprecision(17) << algn(*aa) << endl << endl;

	cout << "algn(red(aa,[pressure,rain]))" << endl
	    << setprecision(17) << algn(*ared(*aa, VarUSet{ pressure, rain })) << endl << endl;

	cout << "algn(red(aa,[pressure,cloud]))" << endl
	    << setprecision(17) << algn(*ared(*aa, VarUSet{ pressure,cloud })) << endl << endl;

	cout << "lent([pressure],red(aa,[pressure,rain]))" << endl
	    << setprecision(17) << lent(VarUSet{ pressure }, *ared(*aa, VarUSet{ pressure, rain })) << endl << endl;

    }
    
    if (false)
    {
	auto lluu = listsSystem_u;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
	    }
	    return listsHistory_u(ii);
	};
	auto hhaa = historiesHistogram;
	auto trans = histogramsSetVarsTransform;
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};

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
	auto uu = lluu(std::vector<VarValSetPair>{VarValSetPair(suit, wws), VarValSetPair(rank, wwr)});

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "vv" << endl
	    << sorted(vv) << endl << endl;

	auto aa = unit(*cart(*uu, vv));
	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	auto colour = Variable("colour");
	auto red = Value("red");
	auto black = Value("black");

	auto xx = hhaa(*llhh(VarList{ suit, colour }, IntValListPairList{
	    IntValListPair(1, ValList{ hearts, red }),
	    IntValListPair(2, ValList{ clubs, black }),
	    IntValListPair(3, ValList{ diamonds, red }),
	    IntValListPair(4, ValList{ spades, black }) }));

	cout << "rpln(aall(xx))" << endl;
	rpln(cout, sorted(*aall(*xx))); cout << endl;

	auto ww = VarUSet{ colour };

	auto tt = trans(*xx, ww);

	cout << "trans(xx,ww)" << endl
	    << *tt << endl << endl;

	cout << "Transform(xx,ww)" << endl
	    << Transform(xx, ww) << endl << endl;

	cout << "xx" << endl
	    << (xx ? "set" : "reset") << endl << endl;

	cout << "rpln(aall(ttaa(tt)))" << endl;
	rpln(cout, sorted(*aall(ttaa(*tt)))); cout << endl;

	cout << "und(tt)" << endl
	    << sorted(*und(*tt)) << endl << endl;

	cout << "der(tt)" << endl
	    << sorted(der(*tt)) << endl << endl;

	cout << "rpln(aall(tmul(aa, tt)))" << endl;
	rpln(cout, sorted(*aall(*tmul(*aa,*tt)))); cout << endl;

    }

    if (false)
    {
	auto uvars = systemsSetVar;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto vol = systemsSetVarsVolume_u;
	auto ssplit = [](const VarUSet& vv, const Histogram& aa)
	{
	    return setVarsSetStatesSplit(vv, *histogramsStates(aa));
	};
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
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
	auto ind = histogramsIndependent;
	auto ent = histogramsEntropy;
	auto lent = [size, ent, ared](const VarUSet& vv, const Histogram& aa)
	{
	    return size(aa).getDouble() * (ent(aa) - ent(*ared(aa, vv)));
	};
	auto algn = histogramsAlignment;
	auto trans = histogramsSetVarsTransform;
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};
	auto lltt = [llss, trans](const VarList& kk, const VarList& ww, const ValListList& qq)
	{
	    VarList vv(kk.begin(),kk.end());
	    vv.insert(vv.end(), ww.begin(), ww.end());
	    std::vector<StateRationalPair> ii;
	    for (auto& ll : qq)
	    {
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(StateRationalPair(*llss(jj),1));
	    }
	    return trans(Histogram(ii), VarUSet(ww.begin(), ww.end()));
	};

	auto pressure = Variable("pressure");
	auto cloud = Variable("cloud");
	auto wind = Variable("wind");
	auto rain = Variable("rain");
	auto cloud_and_wind = Variable("cloud_and_wind");
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
	auto vv = uvars(*uu);
	auto hh = llhh(VarList{ pressure, cloud, wind, rain }, IntValListPairList{
	    IntValListPair(1, ValList{ high, none, none, none }),
	    IntValListPair(2, ValList{ medium, light, none, light }),
	    IntValListPair(3, ValList{ high, none, light, none }),
	    IntValListPair(4, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(5, ValList{ low, none, light, light }),
	    IntValListPair(6, ValList{ medium, none, light, light }),
	    IntValListPair(7, ValList{ low, heavy, light, heavy }),
	    IntValListPair(8, ValList{ high, none, light, none }),
	    IntValListPair(9, ValList{ medium, light, strong, heavy }),
	    IntValListPair(10, ValList{ medium, light, light, light }),
	    IntValListPair(11, ValList{ high, light, light, heavy }),
	    IntValListPair(12, ValList{ medium, none, none, none }),
	    IntValListPair(13, ValList{ medium, light, none, none }),
	    IntValListPair(14, ValList{ high, light, strong, light }),
	    IntValListPair(15, ValList{ medium, none, light, light }),
	    IntValListPair(16, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(17, ValList{ low, heavy, light, heavy }),
	    IntValListPair(18, ValList{ high, none, none, none }),
	    IntValListPair(19, ValList{ low, light, none, light }),
	    IntValListPair(20, ValList{ high, none, none, none }) });
	auto aa = hhaa(*hh);

	cout << "size(aa)" << endl
	    << size(*aa) << endl << endl;

	auto tt = lltt(VarList{ cloud, wind }, VarList{ cloud_and_wind }, ValListList{
	    ValList{none, none, none},
	    ValList{none, light, light},
	    ValList{none, strong, light},
	    ValList{light, none, light},
	    ValList{light, light, light},
	    ValList{light, strong, light},
	    ValList{heavy, none, strong},
	    ValList{heavy, light, strong},
	    ValList{heavy, strong, strong}});

	cout << "rpln(aall(ttaa(tt)))" << endl;
	rpln(cout, sorted(*aall(ttaa(*tt)))); cout << endl;

	cout << "rpln(ssplit([cloud, wind], ttaa(tt)))" << endl;
	rpln(cout, *ssplit(VarUSet{ cloud, wind }, ttaa(*tt))); cout << endl;

	cout << "und(tt)" << endl
	    << sorted(*und(*tt)) << endl << endl;

	cout << "der(tt)" << endl
	    << sorted(der(*tt)) << endl << endl;

	cout << "rpln(aall(tmul(aa, tt)))" << endl;
	rpln(cout, sorted(*aall(*tmul(*aa, *tt)))); cout << endl;
    }

    if (false)
    {
	auto lluu = listsSystem_u;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
	    }
	    return listsHistory_u(ii);
	};
	auto hhaa = historiesHistogram;
	auto trans = [](std::unique_ptr<Histogram>& xx, const VarUSet& ww)
	{
	    return std::make_shared<Transform>(std::move(xx), ww);
	};
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};
	auto lltt = [llss, trans](const VarList& kk, const VarList& ww, const ValListList& qq)
	{
	    VarList vv(kk.begin(), kk.end());
	    vv.insert(vv.end(), ww.begin(), ww.end());
	    std::vector<StateRationalPair> ii;
	    for (auto& ll : qq)
	    {
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(StateRationalPair(*llss(jj), 1));
	    }
	    return trans(std::make_unique<Histogram>(ii), VarUSet(ww.begin(), ww.end()));
	};
	auto llff = setTransformsFud_u;
	auto fhis = fudsSetHistogram;
	auto fvars = fudsSetVar;
	auto fder = fudsDerived;
	auto fund = fudsUnderlying;
	auto fftt = fudsTransform;
	auto dep = fudsSetVarsDepends_u;

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
	auto uu = lluu(std::vector<VarValSetPair>{VarValSetPair(suit, wws), VarValSetPair(rank, wwr)});

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "vv" << endl
	    << sorted(vv) << endl << endl;

	auto aa = unit(*cart(*uu, vv));
	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	auto colour = Variable("colour");
	auto red = Value("red");
	auto black = Value("black");

	auto ttc = lltt(VarList{ suit }, VarList{ colour }, ValListList{
	    ValList{ hearts, red },
	    ValList{ clubs, black },
	    ValList{ diamonds, red },
	    ValList{ spades, black } });

	cout << "rpln(aall(ttaa(ttc)))" << endl;
	rpln(cout, sorted(*aall(ttaa(*ttc)))); cout << endl;

	cout << "und(ttc)" << endl
	    << sorted(*und(*ttc)) << endl << endl;

	cout << "der(ttc)" << endl
	    << sorted(der(*ttc)) << endl << endl;

	auto pip_or_face = Variable("pip_or_face");
	auto pip = Value("pip");
	auto face = Value("face");

	auto xxt = ValListList{
	    ValList{ ace, pip },
	    ValList{ king, face },
	    ValList{ queen, face },
	    ValList{ jack, face } };
	for (int i = 2; i <= 10; i++)
	    xxt.push_back(ValList{Value(i),pip});

	auto ttt = lltt(VarList{ rank }, VarList{ pip_or_face }, xxt);

	cout << "rpln(aall(ttaa(ttt)))" << endl;
	rpln(cout, sorted(*aall(ttaa(*ttt)))); cout << endl;

	cout << "und(ttt)" << endl
	    << sorted(*und(*ttt)) << endl << endl;

	cout << "der(ttt)" << endl
	    << sorted(der(*ttt)) << endl << endl;

	auto ff = llff(TransformPtrList{ ttc, ttt });

	cout << "ff" << endl
	    << *ff << endl << endl;

	cout << "rpln(fhis(ff))" << endl;
	rpln(cout, *fhis(*ff)); cout << endl;

	cout << "fvars(ff)" << endl
	    << sorted(*fvars(*ff)) << endl << endl;

	cout << "fund(ff)" << endl
	    << sorted(*fund(*ff)) << endl << endl;

	cout << "fder(ff)" << endl
	    << sorted(*fder(*ff)) << endl << endl;

	cout << "rpln(aall(ttaa(fftt(ff))))" << endl;
	rpln(cout, sorted(*aall(ttaa(*fftt(*ff))))); cout << endl;

	auto red_face = Variable("red_face");
	auto yes = Value("yes");
	auto no = Value("no");

	auto ttrf = lltt(VarList{ colour,pip_or_face }, VarList{ red_face }, ValListList{
	    ValList{ red, face, yes },
	    ValList{ red, pip, no },
	    ValList{ black, face, no },
	    ValList{ black, pip, no } });

	auto gg = llff(TransformPtrList{ ttc, ttt, ttrf });

	cout << "gg" << endl
	    << *gg << endl << endl;

	cout << "rpln(fhis(gg))" << endl;
	rpln(cout, *fhis(*gg)); cout << endl;

	cout << "fvars(gg)" << endl
	    << sorted(*fvars(*gg)) << endl << endl;

	cout << "fund(gg)" << endl
	    << sorted(*fund(*gg)) << endl << endl;

	cout << "fder(gg)" << endl
	    << sorted(*fder(*gg)) << endl << endl;

	cout << "dep(gg,colour)" << endl
	    << *dep(*gg, VarUSet{ colour }) << endl << endl;
	cout << "dep(gg,pip_or_face)" << endl
	    << *dep(*gg, VarUSet{ pip_or_face }) << endl << endl;
	cout << "dep(gg,red_face)" << endl
	    << *dep(*gg, VarUSet{ red_face }) << endl << endl;
    }

    if (false)
    {
	auto uvars = systemsSetVar;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto vol = systemsSetVarsVolume_u;
	auto ssplit = [](const VarUSet& vv, const Histogram& aa)
	{
	    return setVarsSetStatesSplit(vv, *histogramsStates(aa));
	};
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
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
	auto ind = histogramsIndependent;
	auto ent = histogramsEntropy;
	auto lent = [size, ent, ared](const VarUSet& vv, const Histogram& aa)
	{
	    return size(aa).getDouble() * (ent(aa) - ent(*ared(aa, vv)));
	};
	auto algn = histogramsAlignment;
	auto trans = [](std::unique_ptr<Histogram>& xx, const VarUSet& ww)
	{
	    return std::make_shared<Transform>(std::move(xx), ww);
	};
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};
	auto lltt = [llss, trans](const VarList& kk, const VarList& ww, const ValListList& qq)
	{
	    VarList vv(kk.begin(), kk.end());
	    vv.insert(vv.end(), ww.begin(), ww.end());
	    std::vector<StateRationalPair> ii;
	    for (auto& ll : qq)
	    {
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(StateRationalPair(*llss(jj), 1));
	    }
	    return trans(std::make_unique<Histogram>(ii), VarUSet(ww.begin(), ww.end()));
	};
	auto llff = setTransformsFud_u;
	auto fhis = fudsSetHistogram;
	auto fvars = fudsSetVar;
	auto fder = fudsDerived;
	auto fund = fudsUnderlying;
	auto fftt = fudsTransform;
	auto dep = fudsSetVarsDepends_u;

	auto pressure = Variable("pressure");
	auto cloud = Variable("cloud");
	auto wind = Variable("wind");
	auto rain = Variable("rain");
	auto cloud_and_wind = Variable("cloud_and_wind");
	auto cloud_and_pressure = Variable("cloud_and_pressure");
	auto cloud_wind_pressure = Variable("cloud_wind_pressure");
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
	auto vv = uvars(*uu);
	auto hh = llhh(VarList{ pressure, cloud, wind, rain }, IntValListPairList{
	    IntValListPair(1, ValList{ high, none, none, none }),
	    IntValListPair(2, ValList{ medium, light, none, light }),
	    IntValListPair(3, ValList{ high, none, light, none }),
	    IntValListPair(4, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(5, ValList{ low, none, light, light }),
	    IntValListPair(6, ValList{ medium, none, light, light }),
	    IntValListPair(7, ValList{ low, heavy, light, heavy }),
	    IntValListPair(8, ValList{ high, none, light, none }),
	    IntValListPair(9, ValList{ medium, light, strong, heavy }),
	    IntValListPair(10, ValList{ medium, light, light, light }),
	    IntValListPair(11, ValList{ high, light, light, heavy }),
	    IntValListPair(12, ValList{ medium, none, none, none }),
	    IntValListPair(13, ValList{ medium, light, none, none }),
	    IntValListPair(14, ValList{ high, light, strong, light }),
	    IntValListPair(15, ValList{ medium, none, light, light }),
	    IntValListPair(16, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(17, ValList{ low, heavy, light, heavy }),
	    IntValListPair(18, ValList{ high, none, none, none }),
	    IntValListPair(19, ValList{ low, light, none, light }),
	    IntValListPair(20, ValList{ high, none, none, none }) });
	auto aa = hhaa(*hh);

	cout << "size(aa)" << endl
	    << size(*aa) << endl << endl;

	auto ttcw = lltt(VarList{ cloud, wind }, VarList{ cloud_and_wind }, ValListList{
	    ValList{ none, none, none },
	    ValList{ none, light, light },
	    ValList{ none, strong, light },
	    ValList{ light, none, light },
	    ValList{ light, light, light },
	    ValList{ light, strong, light },
	    ValList{ heavy, none, strong },
	    ValList{ heavy, light, strong },
	    ValList{ heavy, strong, strong } });

	auto ttcp = lltt(VarList{ cloud, pressure }, VarList{ cloud_and_pressure }, ValListList{
	    ValList{none, high, none},
	    ValList{none, medium, light},
	    ValList{none, low, light},
	    ValList{light, high, light},
	    ValList{light, medium, light},
	    ValList{light, low, light},
	    ValList{heavy, high, strong},
	    ValList{heavy, medium, strong},
	    ValList{heavy, low, strong} });

	auto ff = llff(TransformPtrList{ ttcw, ttcp });

	cout << "fder(ff)" << endl
	    << sorted(*fder(*ff)) << endl << endl;

	cout << "fund(ff)" << endl
	    << sorted(*fund(*ff)) << endl << endl;

	cout << "der(fftt(ff))" << endl
	    << sorted(der(*fftt(*ff))) << endl << endl;

	cout << "und(fftt(ff))" << endl
	    << sorted(*und(*fftt(*ff))) << endl << endl;

	auto ttcwp = lltt(VarList{ cloud_and_wind,cloud_and_pressure }, VarList{ cloud_wind_pressure }, ValListList{
	    ValList{ none, none, none },
	    ValList{ none, light, none },
	    ValList{ none, strong, none },
	    ValList{ light, none, none },
	    ValList{ light, light, light },
	    ValList{ light, strong, light },
	    ValList{ strong, none, none },
	    ValList{ strong, light, light },
	    ValList{ strong, strong, strong } });

	auto gg = llff(TransformPtrList{ ttcw, ttcp, ttcwp });

	cout << "fder(gg)" << endl
	    << sorted(*fder(*gg)) << endl << endl;

	cout << "fund(gg)" << endl
	    << sorted(*fund(*gg)) << endl << endl;

	cout << "der(fftt(gg))" << endl
	    << sorted(der(*fftt(*gg))) << endl << endl;

	cout << "und(fftt(gg))" << endl
	    << sorted(*und(*fftt(*gg))) << endl << endl;

	cout << "len(dep(gg,fder(gg)))" << endl
	    << dep(*gg, *fder(*gg))->list_u().size() << endl << endl;

	cout << "len(dep(gg,fder(ff)))" << endl
	    << dep(*gg, *fder(*ff))->list_u().size() << endl << endl;

	cout << "len(dep(gg,[cloud_and_pressure]))" << endl
	    << dep(*gg, VarUSet{ cloud_and_pressure })->list_u().size() << endl << endl;

    }

    if (false)
    {
	Tree<int> x;
	x._list.push_back(std::pair<int, Tree<int>>(3, Tree<int>()));

	cout << "x" << endl
	    << x << endl << endl;

	cout << "treesPaths(x)" << endl
	    << *treesPaths(x) << endl << endl;

	Tree<int> y;
	y._list.push_back(std::pair<int, Tree<int>>(2, x));
	y._list.push_back(std::pair<int, Tree<int>>(1, Tree<int>()));

	cout << "y" << endl
	    << y << endl << endl;

	cout << "treesPaths(y)" << endl
	    << *treesPaths(y) << endl << endl;

	Tree<int> z;
	z._list.push_back(std::pair<int, Tree<int>>(3, y));
	z._list.push_back(std::pair<int, Tree<int>>(2, x));
	z._list.push_back(std::pair<int, Tree<int>>(1, Tree<int>()));

	cout << "z" << endl
	    << z << endl << endl;

	cout << "treesPaths(z)" << endl
	    << *treesPaths(z) << endl << endl;

	cout << "y.sort()" << endl;
	y.sort();

	cout << "y" << endl
	    << y << endl << endl;


	cout << "z.sort()" << endl;
	z.sort();

	cout << "z" << endl
	    << z << endl << endl;

	cout << "treesPaths(z)" << endl
	    << *treesPaths(z) << endl << endl;

	cout << "pairTreesUnion(x,x)" << endl
	    << *pairTreesUnion(x, x) << endl << endl;

	cout << "pairTreesUnion(x,y)" << endl
	    << *pairTreesUnion(x, y) << endl << endl;

	cout << "pairTreesUnion(x,z)" << endl
	    << *pairTreesUnion(x, z) << endl << endl;

	cout << "pairTreesUnion(y,y)" << endl
	    << *pairTreesUnion(y, y) << endl << endl;

	cout << "pairTreesUnion(y,z)" << endl
	    << *pairTreesUnion(y, z) << endl << endl;

	cout << "pairTreesUnion(z,z)" << endl
	    << *pairTreesUnion(z, z) << endl << endl;

	auto tt = pathsTree(std::vector<std::vector<int>>{
	    std::vector<int>{9},
	    std::vector<int>{1, 3, 4, 5, 6, 7},
	    std::vector<int>{1, 2},
	    std::vector<int>{1, 3},
	    std::vector<int>{1},
	    std::vector<int>{1, 8},
	    std::vector<int>{1, 3, 4}});

	cout << "rpln(treesPaths(tt))" << endl;
	rpln(cout, *treesPaths(*tt)); cout << endl;

	cout << "tt.sort()" << endl;
	tt->sort();

	cout << "rpln(treesPaths(tt))" << endl;
	rpln(cout, *treesPaths(*tt)); cout << endl;

	cout << "tt" << endl
	    << *tt << endl << endl;



    }

    if (false)
    {
	auto lluu = listsSystem_u;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
	    }
	    return listsHistory_u(ii);
	};
	auto hhaa = historiesHistogram;
	auto trans = [](std::unique_ptr<Histogram>& xx, const VarUSet& ww)
	{
	    return std::make_shared<Transform>(std::move(xx), ww);
	};
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};
	auto lltt = [llss, trans](const VarList& kk, const VarList& ww, const ValListList& qq)
	{
	    VarList vv(kk.begin(), kk.end());
	    vv.insert(vv.end(), ww.begin(), ww.end());
	    std::vector<StateRationalPair> ii;
	    for (auto& ll : qq)
	    {
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(StateRationalPair(*llss(jj), 1));
	    }
	    return trans(std::make_unique<Histogram>(ii), VarUSet(ww.begin(), ww.end()));
	};
	auto llff = setTransformsFud_u;
	auto fhis = fudsSetHistogram;
	auto fvars = fudsSetVar;
	auto fder = fudsDerived;
	auto fund = fudsUnderlying;
	auto fftt = fudsTransform;
	auto dep = fudsSetVarsDepends_u;
	typedef std::pair<VarValPairList, TransformPtrList> VarValPairListTransformPtrListPair;
	typedef std::vector<VarValPairListTransformPtrListPair> VarValPairListTransformPtrListPairList;
	typedef std::vector<VarValPairListTransformPtrListPairList> VarValPairListTransformPtrListPairListList;
	auto lldf = [llss, llff](const VarValPairListTransformPtrListPairListList& zz)
	{
	    auto jj = std::vector<std::vector<StatePtrFudPtrPair>>();
	    jj.reserve(zz.size());
	    for (auto& ll : zz)
	    {
		auto kk = std::vector<StatePtrFudPtrPair>();
		kk.reserve(ll.size());
		for (auto& pp : ll)
		{
		    StatePtrFudPtrPair qq(std::move(llss(pp.first)), std::move(llff(pp.second)));
		    kk.push_back(qq);
		}
		jj.push_back(kk);
	    }
	    auto tt = std::make_unique<DecompFud>();
	    tt->tree_u() = *pathsTree(jj);
	    return tt;
	};
	auto dfll = [](const DecompFud& df)
	{
	    return treesPaths(df.tree_u());
	};
	auto dfund = decompFudsUnderlying;


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
	auto uu = lluu(std::vector<VarValSetPair>{VarValSetPair(suit, wws), VarValSetPair(rank, wwr)});

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "vv" << endl
	    << sorted(vv) << endl << endl;

	auto colour = Variable("colour");
	auto red = Value("red");
	auto black = Value("black");

	auto ttc = lltt(VarList{ suit }, VarList{ colour }, ValListList{
	    ValList{ hearts, red },
	    ValList{ clubs, black },
	    ValList{ diamonds, red },
	    ValList{ spades, black } });

	auto pip_or_face = Variable("pip_or_face");
	auto pip = Value("pip");
	auto face = Value("face");

	auto xxt = ValListList{
	    ValList{ ace, pip },
	    ValList{ king, face },
	    ValList{ queen, face },
	    ValList{ jack, face } };
	for (int i = 2; i <= 10; i++)
	    xxt.push_back(ValList{ Value(i),pip });

	auto ttt = lltt(VarList{ rank }, VarList{ pip_or_face }, xxt);

	auto odd_pip = Variable("odd_pip");
	auto yes = Value("yes");
	auto no = Value("no");

	auto xxop = ValListList{
	    ValList{ ace, yes },
	    ValList{ king, no },
	    ValList{ queen, no },
	    ValList{ jack, no } };
	for (int i = 2; i <= 10; i += 2)
	    xxop.push_back(ValList{ Value(i),no });
	for (int i = 3; i <= 9; i += 2)
	    xxop.push_back(ValList{ Value(i),yes });

	auto ttop = lltt(VarList{ rank }, VarList{ odd_pip }, xxop);

	auto df = lldf(VarValPairListTransformPtrListPairListList{
	    VarValPairListTransformPtrListPairList{
		VarValPairListTransformPtrListPair(VarValPairList{},TransformPtrList{ttop}),
		VarValPairListTransformPtrListPair(VarValPairList{VarValPair(odd_pip, no)},TransformPtrList{ ttc, ttt})},
	    VarValPairListTransformPtrListPairList{
		VarValPairListTransformPtrListPair(VarValPairList{},TransformPtrList{ ttop }),
		VarValPairListTransformPtrListPair(VarValPairList{VarValPair(odd_pip, yes)},TransformPtrList{ttc})} });

	cout << "df" << endl
	    << *df << endl << endl;

	cout << "treesSize(dfzz(df))" << endl
	    << treesSize(df->tree_u()) << endl << endl;

	cout << "dfund(df)" << endl
	    << sorted(*dfund(*df)) << endl << endl;

	cout << "rpln(dfll(df))" << endl;
	rpln(cout, *dfll(*df)); cout << endl;


    }

    if (false)
    {
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	js::Document d;
	d.Parse(json);

	js::Value& s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	js::StringBuffer buffer;
	js::Writer<js::StringBuffer> writer(buffer);
	d.Accept(writer);

	std::cout << buffer.GetString() << std::endl;
    }

    if (false)
    {
	FILE* fp = std::fopen("../NISTPy-master/NIST_model1.json", "rb");
	assert(fp);
	char readBuffer[65536];
	js::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	js::Document d;
	d.ParseStream(is);

	cout << "d.IsObject()" << endl
	    << d.IsObject() << endl << endl;

	cout << "d.HasMember(\"paths\")" << endl
	    << d.HasMember("paths") << endl << endl;

	cout << "d.HasMember(\"nodes\")" << endl
	    << d.HasMember("nodes") << endl << endl;
    }

    if (false)
    {
	auto v1 = stringsVariable("aa");
	cout << v1 << endl;
	v1 = stringsVariable("1");
	cout << v1 << endl;
	v1 = stringsVariable("123");
	cout << v1 << endl;
	v1 = stringsVariable("<5,2>");
	cout << v1 << endl;
	v1 = stringsVariable("<<7,1>,2>");
	cout << v1 << endl;
    }

    if (false)
    {
	auto v1 = stringsValue("aa");
	cout << v1 << endl;
	v1 = stringsValue("1");
	cout << v1 << endl;
	v1 = stringsValue("1.23");
	cout << v1 << endl;
	v1 = stringsValue("9    ");
	cout << v1 << endl;
	v1 = stringsValue("  4.56   ");
	cout << v1 << endl;

    }

    if (false)
    {
	auto v1 = stringsRational("123 % 456");
	cout << v1 << endl;
	v1 = stringsRational("1");
	cout << v1 << endl;
	v1 = stringsRational(" % 456");
	cout << v1 << endl;
	v1 = stringsRational("123 % ");
	cout << v1 << endl;
	v1 = stringsRational("");
	cout << v1 << endl;

    }

    if (false)
    {
	cout << rationalsString(Rational(123, 456)) << endl;
	cout << rationalsString(Rational(123, 1)) << endl;
	cout << rationalsString(Rational(123.456)) << endl;

    }

    if (true)
    {
	auto uvars = systemsSetVar;
	auto cart = systemsSetVarsSetStateCartesian_u;
	auto llss = listsState;
	auto vol = systemsSetVarsVolume_u;
	auto ssplit = [](const VarUSet& vv, const Histogram& aa)
	{
	    return setVarsSetStatesSplit(vv, *histogramsStates(aa));
	};
	auto unit = setStatesHistogramUnit_u;
	auto aall = histogramsList;
	auto size = histogramsSize;
	auto resize = histogramsResize;
	auto norm = [](const Histogram& aa)
	{
	    return histogramsResize(1, aa);
	};
	auto add = pairHistogramsAdd_u;
	auto scalar = histogramScalar_u;
	auto regsing = histogramRegularUnitSingleton_u;
	auto regdiag = histogramRegularUnitDiagonal_u;
	auto regcart = histogramRegularCartesian_u;
	auto ared = [](const Histogram& aa, const VarUSet& vv)
	{
	    return setVarsHistogramsReduce(vv, aa);
	};
	auto llhh = [llss](const VarList& vv, const IntValListPairList& ee)
	{
	    std::vector<IdStatePair> ii;
	    for (auto& pp : ee)
	    {
		auto i = pp.first;
		auto& ll = pp.second;
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(IdStatePair(Id(i), *llss(jj)));
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
	auto ind = histogramsIndependent;
	auto ent = histogramsEntropy;
	auto lent = [size, ent, ared](const VarUSet& vv, const Histogram& aa)
	{
	    return size(aa).getDouble() * (ent(aa) - ent(*ared(aa, vv)));
	};
	auto algn = histogramsAlignment;
	auto trans = [](std::unique_ptr<Histogram>& xx, const VarUSet& ww)
	{
	    return std::make_shared<Transform>(std::move(xx), ww);
	};
	auto ttaa = transformsHistogram;
	auto und = transformsUnderlying;
	auto der = transformsDerived;
	auto tmul = [](const Histogram& aa, const Transform& tt)
	{
	    return transformsHistogramsApply(tt, aa);
	};
	auto lltt = [llss, trans](const VarList& kk, const VarList& ww, const ValListList& qq)
	{
	    VarList vv(kk.begin(), kk.end());
	    vv.insert(vv.end(), ww.begin(), ww.end());
	    std::vector<StateRationalPair> ii;
	    for (auto& ll : qq)
	    {
		auto jj = std::vector<VarValPair>();
		for (int j = 0; j < ll.size(); j++)
		    jj.push_back(VarValPair(vv[j], ll[j]));
		ii.push_back(StateRationalPair(*llss(jj), 1));
	    }
	    return trans(std::make_unique<Histogram>(ii), VarUSet(ww.begin(), ww.end()));
	};
	auto llff = setTransformsFud_u;
	auto fhis = fudsSetHistogram;
	auto fvars = fudsSetVar;
	auto fder = fudsDerived;
	auto fund = fudsUnderlying;
	auto fftt = fudsTransform;
	auto dep = fudsSetVarsDepends_u;

	auto pressure = Variable("pressure");
	auto cloud = Variable("cloud");
	auto wind = Variable("wind");
	auto rain = Variable("rain");
	auto cloud_and_wind = Variable("cloud_and_wind");
	auto cloud_and_pressure = Variable("cloud_and_pressure");
	auto cloud_wind_pressure = Variable("cloud_wind_pressure");
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
	auto vv = uvars(*uu);
	auto hh = llhh(VarList{ pressure, cloud, wind, rain }, IntValListPairList{
	    IntValListPair(1, ValList{ high, none, none, none }),
	    IntValListPair(2, ValList{ medium, light, none, light }),
	    IntValListPair(3, ValList{ high, none, light, none }),
	    IntValListPair(4, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(5, ValList{ low, none, light, light }),
	    IntValListPair(6, ValList{ medium, none, light, light }),
	    IntValListPair(7, ValList{ low, heavy, light, heavy }),
	    IntValListPair(8, ValList{ high, none, light, none }),
	    IntValListPair(9, ValList{ medium, light, strong, heavy }),
	    IntValListPair(10, ValList{ medium, light, light, light }),
	    IntValListPair(11, ValList{ high, light, light, heavy }),
	    IntValListPair(12, ValList{ medium, none, none, none }),
	    IntValListPair(13, ValList{ medium, light, none, none }),
	    IntValListPair(14, ValList{ high, light, strong, light }),
	    IntValListPair(15, ValList{ medium, none, light, light }),
	    IntValListPair(16, ValList{ low, heavy, strong, heavy }),
	    IntValListPair(17, ValList{ low, heavy, light, heavy }),
	    IntValListPair(18, ValList{ high, none, none, none }),
	    IntValListPair(19, ValList{ low, light, none, light }),
	    IntValListPair(20, ValList{ high, none, none, none }) });
	auto aa = hhaa(*hh);
	auto ttcw = lltt(VarList{ cloud, wind }, VarList{ cloud_and_wind }, ValListList{
	    ValList{ none, none, none },
	    ValList{ none, light, light },
	    ValList{ none, strong, light },
	    ValList{ light, none, light },
	    ValList{ light, light, light },
	    ValList{ light, strong, light },
	    ValList{ heavy, none, strong },
	    ValList{ heavy, light, strong },
	    ValList{ heavy, strong, strong } });
	auto ttcp = lltt(VarList{ cloud, pressure }, VarList{ cloud_and_pressure }, ValListList{
	    ValList{ none, high, none },
	    ValList{ none, medium, light },
	    ValList{ none, low, light },
	    ValList{ light, high, light },
	    ValList{ light, medium, light },
	    ValList{ light, low, light },
	    ValList{ heavy, high, strong },
	    ValList{ heavy, medium, strong },
	    ValList{ heavy, low, strong } });
	auto ff = llff(TransformPtrList{ ttcw, ttcp });
	auto ttcwp = lltt(VarList{ cloud_and_wind,cloud_and_pressure }, VarList{ cloud_wind_pressure }, ValListList{
	    ValList{ none, none, none },
	    ValList{ none, light, none },
	    ValList{ none, strong, none },
	    ValList{ light, none, none },
	    ValList{ light, light, light },
	    ValList{ light, strong, light },
	    ValList{ strong, none, none },
	    ValList{ strong, light, light },
	    ValList{ strong, strong, strong } });
	auto gg = llff(TransformPtrList{ ttcw, ttcp, ttcwp });

	cout << "uu" << endl
	    << *uu << endl << endl;

	cout << "systemsPersistent(uu,cout)" << endl;
	systemsPersistent(*uu, cout); cout << endl << endl;

	cout << "systemsPersistentSorted(uu,cout)" << endl;
	systemsPersistentSorted(*uu, cout); cout << endl << endl;

	std::stringstream str;
	systemsPersistent(*uu, str);
	auto uu1 = persistentsSystem(str);
	cout << "uu1 = persistentsSystem(str)" << endl
	    << *uu1 << endl << endl;

	std::stringstream str2;
	systemsPersistentSorted(*uu, str2);
	auto uu2 = persistentsSystem(str2);
	cout << "uu2 = persistentsSystem(str2)" << endl
	    << *uu2 << endl << endl;

	cout << "historiesPersistent(hh,cout)" << endl;
	historiesPersistent(*hh, cout); cout << endl << endl;

	std::stringstream str3;
	historiesPersistent(*hh, str3);
	auto hh2 = persistentsHistory(str3);
	cout << "hh2 = persistentsHistory(str3)" << endl
	    << *hh2 << endl << endl;

	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	cout << "rpln(aall(hhaa(hh2)))" << endl;
	rpln(cout, sorted(*aall(*hhaa(*hh2)))); cout << endl;

	cout << "historiesPersistentPretty(1,hh,cout)" << endl;
	historiesPersistentPretty(1,*hh, cout); cout << endl << endl;

	std::stringstream str4;
	historiesPersistentPretty(1,*hh, str4);
	auto hh3 = persistentsHistory(str4);
	cout << "hh3 = persistentsHistory(str4)" << endl
	    << *hh3 << endl << endl;

	cout << "rpln(aall(aa))" << endl;
	rpln(cout, sorted(*aall(*aa))); cout << endl;

	cout << "rpln(aall(hhaa(hh3)))" << endl;
	rpln(cout, sorted(*aall(*hhaa(*hh3)))); cout << endl;

	cout << "transformsPersistent(ttcw,cout)" << endl;
	transformsPersistent(*ttcw, cout); cout << endl << endl;

	cout << "transformsPersistent(ttcp,cout)" << endl;
	transformsPersistent(*ttcp, cout); cout << endl << endl;

	cout << "transformsPersistent(ttcwp,cout)" << endl;
	transformsPersistent(*ttcwp, cout); cout << endl << endl;

	cout << "transformsPersistent(fftt(ff),cout)" << endl;
	transformsPersistent(*fftt(*ff), cout); cout << endl << endl;

	cout << "transformsPersistentPretty(1,ttcwp,cout)" << endl;
	transformsPersistentPretty(1, *ttcwp, cout); cout << endl << endl;

	cout << "transformsPersistentPretty(1,fftt(ff),cout)" << endl;
	transformsPersistentPretty(1, *fftt(*ff), cout); cout << endl << endl;

    }

    if (false)
    {
	unsigned int n = std::thread::hardware_concurrency();
	std::cout << n << " concurrent threads are supported.\n";
    }
}
