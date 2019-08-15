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

    typedef std::set<Variable> VarSet;
    typedef std::unordered_set<Variable> VarUSet;
    typedef std::unordered_set<Value> ValUSet;
    typedef std::pair<Variable, ValUSet> VarValUSetPair;
    typedef std::unordered_map<Variable, ValUSet> VarValUSetUMap;


    class System
    {
    public: System(const VarValUSetUMap&);

    public: System(const std::vector<VarValUSetPair>&);

    public: inline VarValUSetUMap& map_u() const
    {
	return (VarValUSetUMap&)_map;
    }

    public: void update(const System&);

    friend inline bool operator==(const System& l, const System& r)
    {
	return l._map == r._map;
    }
    friend inline bool operator!=(const System& l, const System& r) { return !(l == r); }

    private: VarValUSetUMap _map;
    };

    // listsSystem_u ::[(Variable, Set.Set Value)]->System
    std::unique_ptr<System> listsSystem_u(const std::vector<VarValUSetPair>& ll);

    // systemsList::System ->[(Variable, Set.Set Value)]
    std::unique_ptr<std::vector<VarValUSetPair>> systemsList(const System& uu);

    // pairSystemsUnion::System -> System -> System
    std::unique_ptr<System> pairSystemsUnion(const System&, const System&);

    // systemsSetVar :: System -> Set.Set Variable
    std::unique_ptr<VarUSet> systemsSetVar(const System&);

    // systemsVarsSetValue :: System -> Variable -> Maybe (Set.Set Value)
    ValUSet systemsVarsSetValue(const System&, const Variable&);

    // systemsSetVarsVolume_u :: System -> Set.Set Variable -> Integer
    unsigned long long systemsSetVarsVolume_u(const System&, const VarUSet&);

    // systemRegular::Integer->Integer->Maybe System
    std::unique_ptr<System> systemRegular(int, int);
}

std::ostream& operator<<(std::ostream& out, const Alignment::System& uu);

namespace Alignment
{
    // newtype State = State (Map.Map Variable Value)

    typedef std::map<Variable, Value> VarValMap;
    typedef std::pair<Variable, Value> VarValPair;

    class State
    {
    public: State();

    public: State(const VarValMap&);

    public: State(const std::vector<VarValPair>&);

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
    std::unique_ptr<State> setVarsStatesStateFiltered(const VarUSet&,const State&);

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
    typedef std::unordered_set<State> StateUSet;

    // systemsSetVarsSetStateCartesian_u :: System -> Set.Set Variable -> Maybe (Set.Set State)
    std::unique_ptr<StateUSet> systemsSetVarsSetStateCartesian_u(const System&, const VarUSet&);


}


#endif