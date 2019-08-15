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

	auto sysreg = systemRegular;

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
    }

}
