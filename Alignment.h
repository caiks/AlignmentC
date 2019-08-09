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

	public: Variable(const std::string& s)
	{
	    _hash = 0;
	    _cl = 1;
	    _str = std::make_shared<std::string>(s);
	}

	public: Variable(int i)
	{
	    _hash = 0;
	    _cl = 2;
	    _int = i;
	}

	public: Variable(const Variable& v0, const Variable& v1)
	{
	    _hash = 0;
	    _cl = 5;
	    _var0 = std::make_shared<Variable>(v0);
	    _var1 = std::make_shared<Variable>(v1);
	}

	friend bool operator==(const Variable& l, const Variable& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return *l._str == *r._str;
	    else if (l._cl == 2)
		return l._int == r._int;
	    return *l._var0 == *r._var0 && *l._var1 == *r._var1;
	}
	friend inline bool operator!=(const Variable& l, const Variable& r) { return !(l == r); }
	friend bool operator<(const Variable& l, const Variable& r)
	{
	    if (l._cl < r._cl)
		return true;
	    if (l._cl > r._cl)
		return false;
	    if (l._cl == 1)
		return *l._str < *r._str;
	    else if (l._cl == 2)
		return l._int < r._int;
	    return *l._var0 < *r._var0 || ( *r._var0 == *l._var0 && *l._var1 < *r._var1);
	}
	friend inline bool operator> (const Variable& l, const Variable& r) { return r < l; }
	friend inline bool operator<=(const Variable& l, const Variable& r) { return !(l > r); }
	friend inline bool operator>=(const Variable& l, const Variable& r) { return !(l < r); }
	
	public: std::size_t hash() const
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

	friend std::ostream& operator<<(std::ostream& out, const Variable& v)
	{
	    if (v._cl == 1)
		out << *v._str;
	    else if (v._cl == 2)
		out << v._int;
	    else
		out << "<" << *v._var0 << "," << *v._var1 << ">";
	    return out;
	}

	private: char _cl;
	private: std::shared_ptr<std::string> _str;
	private: int _int;
	private: std::shared_ptr<Variable> _var0;
	private: std::shared_ptr<Variable> _var1;
	private: std::size_t _hash;
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

	public: Value(const std::string& s)
	{
	    _hash = 0;
	    _cl = 1;
	    _str = std::make_shared<std::string>(s);
	}

	public: Value(int i)
	{
	    _hash = 0;
	    _cl = 2;
	    _int = i;
	}

	public: Value(double d)
	{
	    _hash = 0;
	    _cl = 3;
	    this->_double = d;
	}

	friend bool operator==(const Value& l, const Value& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return *l._str == *r._str;
	    else if (l._cl == 2)
		return l._int == r._int;
	    return l._double == r._double;
	}
	friend inline bool operator!=(const Value& l, const Value& r) { return !(l == r); }

	friend bool operator<(const Value& l, const Value& r)
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
	friend inline bool operator> (const Value& l, const Value& r) { return r < l; }
	friend inline bool operator<=(const Value& l, const Value& r) { return !(l > r); }
	friend inline bool operator>=(const Value& l, const Value& r) { return !(l < r); }

	public: std::size_t hash() const
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

	friend std::ostream& operator<<(std::ostream& out, const Value& v)
	{
	    if (v._cl == 1)
		out << *v._str;
	    else if (v._cl == 2)
		out << v._int;
	    else
		out << v._double;
	    return out;
	}

	private: char _cl;
	private: std::shared_ptr<std::string> _str;
	private: int _int;
	private: double _double;
	private: std::size_t _hash;
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

	public: Id(const std::string& s)
	{
	    _hash = 0;
	    _cl = 1;
	    _str = std::make_shared<std::string>(s);
	}

	public: Id(int i)
	{
	    _hash = 0;
	    _cl = 2;
	    _int = i;
	}

	friend bool operator==(const Id& l, const Id& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return *l._str == *r._str;
	    return l._int == r._int;
	}
	friend inline bool operator!=(const Id& l, const Id& r) { return !(l == r); }

	friend bool operator<(const Id& l, const Id& r)
	{
	    if (l._cl < r._cl)
		return true;
	    if (l._cl > r._cl)
		return false;
	    if (l._cl == 1)
		return *l._str < *r._str;
	    return l._int < r._int;
	}
	friend inline bool operator> (const Id& l, const Id& r) { return r < l; }
	friend inline bool operator<=(const Id& l, const Id& r) { return !(l > r); }
	friend inline bool operator>=(const Id& l, const Id& r) { return !(l < r); }

	public: std::size_t hash() const
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

	friend std::ostream& operator<<(std::ostream& out, const Id& v)
	{
	    if (v._cl == 1)
		out << *v._str;
	    else
		out << v._int;
	    return out;
	}

	private: char _cl;
	private: std::shared_ptr<std::string> _str;
	private: int _int;
	private: std::size_t _hash;
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

	public: std::map<Variable, std::set<Value>>& map_u() const
	{
	    return (std::map<Variable, std::set<Value>>&)_map;
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

	private: std::map<Variable,std::set<Value>> _map;
    };

    // listsSystem_u ::[(Variable, Set.Set Value)]->System
    System listsSystem_u(const std::vector<std::pair<Variable, std::set<Value>>>& ll);

    // systemsList::System ->[(Variable, Set.Set Value)]
    std::vector<std::pair<Variable, std::set<Value>>> systemsList(const System& uu);

    // pairSystemsUnion::System -> System -> System
    System pairSystemsUnion(const System&, const System&);
}

std::ostream& operator<<(std::ostream& out, const Alignment::System& uu);



#endif