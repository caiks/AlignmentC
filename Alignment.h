#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "AlignmentUtil.h"

#include <iostream>
#include <memory>
#include <string>

namespace Alignment
{
    // data Variable = VarStr String | VarInt Integer | VarPartition Partition | VarIndex Int | VarPair(Variable, Variable)

    class Variable
    {
    private: Variable() = default;

    public: Variable(const std::string& s);

    public: Variable(int i);

    public: Variable(const Variable& v0, const Variable& v1);

    friend bool operator==(const Variable& l, const Variable& r);
    friend inline bool operator!=(const Variable& l, const Variable& r) { return !(l == r); }
    friend bool operator<(const Variable& l, const Variable& r);
    friend inline bool operator> (const Variable& l, const Variable& r) { return r < l; }
    friend inline bool operator<=(const Variable& l, const Variable& r) { return !(l > r); }
    friend inline bool operator>=(const Variable& l, const Variable& r) { return !(l < r); }

    public: std::size_t hash() const;
    public: void write(std::ostream& out) const;

    private: char _cl;
    private: std::shared_ptr<std::string> _str;
    private: int _int;
    private: std::shared_ptr<Variable> _var0;
    private: std::shared_ptr<Variable> _var1;
    private: std::size_t _hash;
    };

    typedef std::set<Variable> VarSet;
    typedef std::unordered_set<Variable> VarUSet;
    typedef std::vector<Variable> VarList;
    typedef std::unordered_map<Variable, Variable> VarVarUMap;
}

std::ostream& operator<<(std::ostream&, const Alignment::Variable&);

template<> struct std::hash<Alignment::Variable>
{
    std::size_t operator()(Alignment::Variable const& v) const noexcept
    {
	return v.hash();
    }
};

namespace Alignment
{
    // data Value = ValStr String | ValInt Integer | ValDouble Double | ValComponent Component | ValIndex Int

    class Value
    {
    private: Value() = default;

    public: Value(const std::string& s);

    public: Value(int i);

    public: Value(double d);

    friend bool operator==(const Value& l, const Value& r);
    friend inline bool operator!=(const Value& l, const Value& r) { return !(l == r); }
    friend bool operator<(const Value& l, const Value& r);
    friend inline bool operator> (const Value& l, const Value& r) { return r < l; }
    friend inline bool operator<=(const Value& l, const Value& r) { return !(l > r); }
    friend inline bool operator>=(const Value& l, const Value& r) { return !(l < r); }

    public: std::size_t hash() const;

    public: void write(std::ostream& out) const;

    private: char _cl;
    private: std::shared_ptr<std::string> _str;
    private: int _int;
    private: double _double;
    private: std::size_t _hash;
    };

    typedef std::set<Value> ValSet;
    typedef std::unordered_set<Value> ValUSet;
    typedef std::vector<Value> ValList;

    typedef std::pair<Variable, Value> VarValPair;
    typedef std::pair<Variable, ValSet> VarValSetPair;
    typedef std::pair<Variable, ValUSet> VarValUSetPair;
    typedef std::map<Variable, Value> VarValMap;
    typedef std::unordered_map<Variable, ValSet> VarValSetUMap;

    typedef std::pair<int, ValList> IntValListPair;
    typedef std::vector<IntValListPair> IntValListPairList;

}

std::ostream& operator<<(std::ostream&, const Alignment::Value&);


template<> struct std::hash<Alignment::Value>
{
    std::size_t operator()(Alignment::Value const& v) const noexcept
    {
	return v.hash();
    }
};

namespace Alignment
{
    // data Id = IdStr String | IdInt Integer | IdStateInteger (State, Integer) | IdListId [Id] | IdIntId (Integer,Id) | IdPair (Id,Id) | IdNull

    class Id
    {
    private: Id() = default;

    public: Id(const std::string& s);

    public: Id(int i);

    friend bool operator==(const Id& l, const Id& r);
    friend inline bool operator!=(const Id& l, const Id& r) { return !(l == r); }

    friend bool operator<(const Id& l, const Id& r);
    friend inline bool operator> (const Id& l, const Id& r) { return r < l; }
    friend inline bool operator<=(const Id& l, const Id& r) { return !(l > r); }
    friend inline bool operator>=(const Id& l, const Id& r) { return !(l < r); }

    public: std::size_t hash() const;
    public: void write(std::ostream& out) const;

    private: char _cl;
    private: std::shared_ptr<std::string> _str;
    private: int _int;
    private: std::size_t _hash;
    };
}

std::ostream& operator<<(std::ostream&, const Alignment::Id&);


template<> struct std::hash<Alignment::Id>
{
    std::size_t operator()(Alignment::Id const& v) const noexcept
    {
	return v.hash();
    }
};

namespace Alignment
{
    // newtype System = System (Map.Map Variable (Set.Set Value)) 

    class System
    {
    public: System(const VarValSetUMap&);

    public: System(const std::vector<VarValSetPair>&);

    public: inline VarValSetUMap& map_u() const
    {
	return (VarValSetUMap&)_map;
    }

    public: void update(const System&);

    friend inline bool operator==(const System& l, const System& r)
    {
	return l._map == r._map;
    }
    friend inline bool operator!=(const System& l, const System& r) { return !(l == r); }

    private: VarValSetUMap _map;
    };

    // listsSystem_u ::[(Variable, Set.Set Value)]->System
    std::unique_ptr<System> listsSystem_u(const std::vector<VarValSetPair>& ll);

    // systemsList::System ->[(Variable, Set.Set Value)]
    std::unique_ptr<std::vector<VarValSetPair>> systemsList(const System& uu);

    // pairSystemsUnion::System -> System -> System
    std::unique_ptr<System> pairSystemsUnion(const System&, const System&);

    // systemsSetVar :: System -> Set.Set Variable
    std::unique_ptr<VarUSet> systemsSetVar(const System&);

    // systemsVarsSetValue :: System -> Variable -> Maybe (Set.Set Value)
    ValSet systemsVarsSetValue(const System&, const Variable&);

    // systemsSetVarsVolume_u :: System -> Set.Set Variable -> Integer
    unsigned long long systemsSetVarsVolume_u(const System&, const VarUSet&);

    // systemRegular_u::Integer->Integer-> System
    std::unique_ptr<System> systemRegular_u(int, int);
}

std::ostream& operator<<(std::ostream& out, const Alignment::System& uu);

namespace Alignment
{
    // newtype State = State (Map.Map Variable Value)

    class State
    {
    public: State();
    public: State(const VarValMap&);
    public: State(const std::vector<VarValPair>&);
    public: State(const Variable&, const Value&);

    public: inline VarValMap& map_u() const
    {
	return (VarValMap&)_map;
    }

    public: void update(const State&);

    friend inline bool operator==(const State& l, const State& r)
    {
	return l._map == r._map;
    }
    friend inline bool operator!=(const State& l, const State& r) { return !(l == r); }

    friend bool operator<(const State& l, const State& r)
    {
	return l._map < r._map;
    }
    friend inline bool operator> (const State& l, const State& r) { return r < l; }
    friend inline bool operator<=(const State& l, const State& r) { return !(l > r); }
    friend inline bool operator>=(const State& l, const State& r) { return !(l < r); }

    public: std::size_t hash() const;

    private: VarValMap _map;
    private: std::size_t _hash;
    };

    typedef std::unordered_set<State> StateUSet;

    typedef std::pair<State,Rational> StateRationalPair;
    typedef std::unordered_map<State, Rational> StateRationalUMap;

    typedef std::pair<Id, State> IdStatePair;
    typedef std::unordered_map<Id, State> IdStateUMap;

    // listsState :: [(Variable, Value)] -> State
    std::unique_ptr<State> listsState(const std::vector<VarValPair>&);

    // statesList :: State -> [(Variable, Value)]
    std::unique_ptr<std::vector<VarValPair>> statesList(const State&);

    // statesSetVar :: State -> Set.Set Variable
    std::unique_ptr<VarUSet> statesSetVar(const State&);

    // statesVarsValue::State -> Variable -> Maybe Value
    Value statesVarsValue(const State&, const Variable&);

    // stateEmpty :: State
    State stateEmpty();

    // setVarsStatesStateFiltered :: Set.Set Variable -> State -> State
    std::unique_ptr<State> setVarsStatesStateFiltered(const VarUSet&, const State&);

}

std::ostream& operator<<(std::ostream&, const Alignment::State&);


template<> struct std::hash<Alignment::State>
{
    std::size_t operator()(Alignment::State const& v) const noexcept
    {
	return v.hash();
    }
};

namespace Alignment
{
    // systemsSetVarsSetStateCartesian_u :: System -> Set.Set Variable -> Maybe (Set.Set State)
    std::unique_ptr<StateUSet> systemsSetVarsSetStateCartesian_u(const System&, const VarUSet&);

    // setVarsSetStatesSplit :: Set.Set Variable -> Set.Set State -> Set.Set (State,State) 
    std::unique_ptr<std::set<std::pair<State, State>>> setVarsSetStatesSplit(const VarUSet&, const StateUSet&);
}

namespace Alignment
{
    // newtype History = History (Map.Map Id State)

    class History
    {
    public: History();

    public: History(const IdStateUMap&);

    public: History(const std::vector<IdStatePair>&);

    public: inline IdStateUMap& map_u() const
    {
	return (IdStateUMap&)_map;
    }

    friend inline bool operator==(const History& l, const History& r)
    {
	return l._map == r._map;
    }
    friend inline bool operator!=(const History& l, const History& r) { return !(l == r); }

    private: IdStateUMap _map;
    };

    // listsHistory_u :: [(Id, State)] -> History
    std::unique_ptr<History> listsHistory_u(const std::vector<IdStatePair>&);

    // historiesList :: History -> [(Id, State)]
    std::unique_ptr<std::vector<IdStatePair>> historiesList(const History&);

    // historiesSetVar :: History -> Set.Set Variable
    std::unique_ptr<VarUSet> historiesSetVar(const History&);

    // setVarsHistoriesReduce :: Set.Set Variable -> History -> History 
    std::unique_ptr<History> setVarsHistoriesReduce(const VarUSet&, const History&);

    // historiesSize :: History -> Integer
    inline int historiesSize(const History& hh) 
    {
	return hh.map_u().size();
    }


}

std::ostream& operator<<(std::ostream& out, const Alignment::History&);

namespace Alignment
{
    // newtype Histogram = Histogram (Map.Map State Rational)

    class Histogram
    {
    public: Histogram();
    public: Histogram(const StateRationalUMap&);
    public: Histogram(const std::vector<StateRationalPair>&);
    public: Histogram(const State&, const Rational&);
    public: Histogram(const StateUSet&);
    public: Histogram(const Rational&);

    public: inline StateRationalUMap& map_u() const
    {
	return (StateRationalUMap&)_map;
    }

    friend inline bool operator==(const Histogram& l, const Histogram& r)
    {
	return l._map == r._map;
    }
    friend inline bool operator!=(const Histogram& l, const Histogram& r) { return !(l == r); }

    private: StateRationalUMap _map;
    };

    // listsHistogram_u :: [(State, Rational)] -> Histogram
    std::unique_ptr<Histogram> listsHistogram_u(const std::vector<StateRationalPair>&);

    // histogramsList :: Histogram -> [(State, Rational)]
    std::unique_ptr<std::vector<StateRationalPair>> histogramsList(const Histogram&);

    // histogramsSetVar :: Histogram -> Set.Set Variable
    std::unique_ptr<VarUSet> histogramsSetVar(const Histogram&);

    // histogramsMapVarsFrame :: Histogram -> Map.Map Variable Variable -> Maybe Histogram
    std::unique_ptr<Histogram> histogramsMapVarsFrame_u(const Histogram&, const VarVarUMap&);

    // histogramsStates :: Histogram -> Set.Set State
    std::unique_ptr<StateUSet> histogramsStates(const Histogram&);

    // histogramsStatesCount :: Histogram -> State -> Maybe Rational
    Rational histogramsStatesCount(const Histogram&, const State&);

    // histogramsSize :: Histogram -> Rational
    Rational histogramsSize(const Histogram&);

    // histogramsResize :: Rational -> Histogram -> Maybe Histogram
    std::unique_ptr<Histogram> histogramsResize(const Rational&, const Histogram&);

    // histogramScalar_u :: Rational -> Histogram
    std::unique_ptr<Histogram> histogramScalar_u(const Rational&);

    // histogramSingleton_u :: State -> Rational -> Histogram
    std::unique_ptr<Histogram> histogramSingleton_u(const State&, const Rational&);

    // setStatesHistogramUnit_u :: Set.Set State -> Histogram
    std::unique_ptr<Histogram> setStatesHistogramUnit_u(const StateUSet&);

    // histogramsTrim :: Histogram -> Histogram
    std::unique_ptr<Histogram> histogramsTrim(const Histogram&);

    // histogramsEffective :: Histogram -> Histogram
    std::unique_ptr<Histogram> histogramsEffective(const Histogram&);

    // histogramRegularCartesian_u :: Integer -> Integer -> Histogram
    std::unique_ptr<Histogram> histogramRegularCartesian_u(int, int);

    // histogramRegularUnitSingleton_u :: Integer -> Integer -> Histogram
    std::unique_ptr<Histogram> histogramRegularUnitSingleton_u(int, int);

    // histogramRegularUnitDiagonal_u :: Integer -> Integer -> Histogram
    std::unique_ptr<Histogram> histogramRegularUnitDiagonal_u(int, int);

    // historiesHistogram :: History -> Histogram
    std::unique_ptr<Histogram> historiesHistogram(const History&);

    // histogramsHistory_u :: Histogram -> History
    std::unique_ptr<History> histogramsHistory_u(const Histogram&);

    // setVarsHistogramsReduce :: Set.Set Variable -> Histogram -> Histogram 
    std::unique_ptr<Histogram> setVarsHistogramsReduce(const VarUSet&, const Histogram&);

    // pairHistogramsAdd_u :: Histogram -> Histogram -> Histogram 
    std::unique_ptr<Histogram> pairHistogramsAdd_u(const Histogram&, const Histogram&);

    // pairHistogramsAdd_u_1 :: Histogram -> Histogram -> Histogram 
    std::unique_ptr<Histogram> pairHistogramsAdd_u_1(const Histogram&, const Histogram&);

    // pairHistogramsMultiply :: Histogram -> Histogram -> Histogram 
    std::unique_ptr<Histogram> pairHistogramsMultiply(const Histogram&, const Histogram&);

    // histogramsIndependent :: Histogram -> Histogram
    std::unique_ptr<Histogram> histogramsIndependent(const Histogram&);
}

std::ostream& operator<<(std::ostream& out, const Alignment::Histogram&);

namespace Alignment
{
    typedef std::pair<std::unique_ptr<Histogram>, VarUSet> HistogramPtrVarUSetPair;

    // newtype Transform = Transform (Histogram, (Set.Set Variable))

    class Transform
    {
    public: Transform();
    public: Transform(const Histogram&, const VarUSet&);
    public: Transform(std::unique_ptr<Histogram>&, const VarUSet&);

    public: inline HistogramPtrVarUSetPair& pair_u() const
    {
	return (HistogramPtrVarUSetPair&)_pair;
    }

    friend inline bool operator==(const Transform& l, const Transform& r)
    {
	return l._pair == r._pair;
    }
    friend inline bool operator!=(const Transform& l, const Transform& r) { return !(l == r); }

    private: HistogramPtrVarUSetPair _pair;
    };

    // histogramsSetVarsTransform :: Histogram -> Set.Set Variable -> Maybe Transform
    std::unique_ptr<Transform> histogramsSetVarsTransform(const Histogram&, const VarUSet&);

}

std::ostream& operator<<(std::ostream& out, const Alignment::Transform&);





#endif