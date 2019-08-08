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

	public: Variable(const Variable& v)
	{
	    _cl = v._cl;
	    _str = v._str;
	    _int = v._int;
	    _var0 = v._var0;
	    _var1 = v._var1;
	}

	public: Variable(const std::string& s)
	{
	    _cl = 1;
	    _str = s;
	}

	public: Variable(int i)
	{
	    _cl = 2;
	    _int = i;
	}

	public: Variable(const Variable& v0, const Variable& v1)
	{
	    _cl = 5;
	    _var0 = std::make_shared<Variable>(v0);
	    _var1 = std::make_shared<Variable>(v1);
	}

	friend bool operator<(const Variable& l, const Variable& r)
	{
	    if (l._cl < r._cl)
		return true;
	    if (l._cl > r._cl)
		return false;
	    if (l._cl == 1)
		return l._str < r._str;
	    else if (l._cl == 2)
		return l._int < r._int;
	    return *l._var0 < *r._var0 || ( !(*r._var0 < *l._var0) && *l._var1 < *r._var1);
	}
	friend inline bool operator> (const Variable& l, const Variable& r) { return r < l; }
	friend inline bool operator<=(const Variable& l, const Variable& r) { return !(l > r); }
	friend inline bool operator>=(const Variable& l, const Variable& r) { return !(l < r); }
	friend bool operator==(const Variable& l, const Variable& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return l._str == r._str;
	    else if (l._cl == 2)
		return l._int == r._int;
	    return *l._var0 == *r._var0 && *l._var1 == *r._var1;
	}
	friend inline bool operator!=(const Variable& l, const Variable& r) { return !(l == r); }

	public: std::size_t hash() const
	{
	    if (_cl == 1)
		return _cl + (std::hash<std::string>{}(_str) << 3);
	    else if (_cl == 2)
		return _cl + (std::hash<int>{}(_int) << 3);
	    return _cl + (_var0->hash() << 3) + (_var1->hash() << 4);
	}

	friend std::ostream& operator<<(std::ostream& out, const Variable& v)
	{
	    if (v._cl == 1)
		out << v._str;
	    else if (v._cl == 2)
		out << v._int;
	    else
		out << "<" << *v._var0 << "," << *v._var1 << ">";
	    return out;
	}

	private: char _cl;
	private: std::string _str;
	private: int _int;
	private: std::shared_ptr<Variable> _var0;
	private: std::shared_ptr<Variable> _var1;
    };
}

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

	public: Value(const Value& v)
	{
	    _cl = v._cl;
	    _str = v._str;
	    _int = v._int;
	    this->_double = v._double;
	}

	public: Value(const std::string& s)
	{
	    _cl = 1;
	    _str = s;
	}

	public: Value(int i)
	{
	    _cl = 2;
	    _int = i;
	}

	public: Value(double d)
	{
	    _cl = 3;
	    this->_double = d;
	}

	friend bool operator<(const Value& l, const Value& r)
	{
	    if (l._cl < r._cl)
		return true;
	    if (l._cl > r._cl)
		return false;
	    if (l._cl == 1)
		return l._str < r._str;
	    else if (l._cl == 2)
		return l._int < r._int;
	    return l._double < r._double;
	}
	friend inline bool operator> (const Value& l, const Value& r) { return r < l; }
	friend inline bool operator<=(const Value& l, const Value& r) { return !(l > r); }
	friend inline bool operator>=(const Value& l, const Value& r) { return !(l < r); }
	friend bool operator==(const Value& l, const Value& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return l._str == r._str;
	    else if (l._cl == 2)
		return l._int == r._int;
	    return l._double == r._double;
	}
	friend inline bool operator!=(const Value& l, const Value& r) { return !(l == r); }

	public: std::size_t hash() const
	{
	    if (_cl == 1)
		return _cl + (std::hash<std::string>{}(_str) << 2);
	    else if (_cl == 2)
		return _cl + (std::hash<int>{}(_int) << 2);
	    return _cl + (std::hash<int>{}(this->_double) << 2);
	}

	friend std::ostream& operator<<(std::ostream& out, const Value& v)
	{
	    if (v._cl == 1)
		out << v._str;
	    else if (v._cl == 2)
		out << v._int;
	    else
		out << v._double;
	    return out;
	}

	private: char _cl;
	private: std::string _str;
	private: int _int;
	private: double _double;
    };
}

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

	public: Id(const Id& v)
	{
	    _cl = v._cl;
	    _str = v._str;
	    _int = v._int;
	}

	public: Id(const std::string& s)
	{
	    _cl = 1;
	    _str = s;
	}

	public: Id(int i)
	{
	    _cl = 2;
	    _int = i;
	}

	friend bool operator<(const Id& l, const Id& r)
	{
	    if (l._cl < r._cl)
		return true;
	    if (l._cl > r._cl)
		return false;
	    if (l._cl == 1)
		return l._str < r._str;
	    return l._int < r._int;
	}
	friend inline bool operator> (const Id& l, const Id& r) { return r < l; }
	friend inline bool operator<=(const Id& l, const Id& r) { return !(l > r); }
	friend inline bool operator>=(const Id& l, const Id& r) { return !(l < r); }
	friend bool operator==(const Id& l, const Id& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return l._str == r._str;
	    return l._int == r._int;
	}
	friend inline bool operator!=(const Id& l, const Id& r) { return !(l == r); }

	public: std::size_t hash() const
	{
	    if (_cl == 1)
		return _cl + (std::hash<std::string>{}(_str) << 2);
	    return _cl + (std::hash<int>{}(_int) << 2);
	}

	friend std::ostream& operator<<(std::ostream& out, const Id& v)
	{
	    if (v._cl == 1)
		out << v._str;
	    else
		out << v._int;
	    return out;
	}

	private: char _cl;
	private: std::string _str;
	private: int _int;
    };
}

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
	public: System(const std::map<Variable, std::set<Value>>& m) : _map(m) {}

	public: std::map<Variable, std::set<Value>>& map_u()
	{
	    return _map;
	}

	friend inline bool operator<(const System& l, const System& r)
	{
	    return l._map < r._map;
	}
	friend inline bool operator> (const System& l, const System& r) { return r < l; }
	friend inline bool operator<=(const System& l, const System& r) { return !(l > r); }
	friend inline bool operator>=(const System& l, const System& r) { return !(l < r); }
	friend inline bool operator==(const System& l, const System& r)
	{
	    return l._map == r._map;
	}
	friend inline bool operator!=(const System& l, const System& r) { return !(l == r); }

	// listsSystem_u ::[(Variable, Set.Set Value)]->System

	friend System listsSystem_u(const std::vector<std::pair<Variable, std::set<Value>>>& ll)
	{
	    std::map<Variable, std::set<Value>> m(ll.begin(), ll.end());
	    return System(m);
	}

	// systemsList::System ->[(Variable, Set.Set Value)]

	friend std::vector<std::pair<Variable, std::set<Value>>> systemsList(const System& uu)
	{
	    std::vector<std::pair<Variable, std::set<Value>>> ll(uu._map.begin(), uu._map.end());
	    return ll;
	}

	private: std::map<Variable,std::set<Value>> _map;
    };
}

std::ostream& operator<<(std::ostream& out, const Alignment::System& uu);



#endif