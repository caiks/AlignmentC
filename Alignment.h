#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <iostream>
#include <memory>
#include <string>

namespace Alignment
{
    // data Variable = VarStr String | VarInt Integer | VarPartition Partition | VarIndex Int | VarPair(Variable, Variable)

    class Var
    {
	private: Var() = default;

	public: Var(const Var& v)
	{
	    _cl = v._cl;
	    _str = v._str;
	    _int = v._int;
	    _var0 = v._var0;
	    _var1 = v._var1;
	}

	public: Var(const std::string& s)
	{
	    _cl = 1;
	    _str = s;
	}

	public: Var(int i)
	{
	    _cl = 2;
	    _int = i;
	}

	public: Var(const Var& v0, const Var& v1)
	{
	    _cl = 5;
	    _var0 = std::make_shared<Var>(v0);
	    _var1 = std::make_shared<Var>(v1);
	}

	friend bool operator<(const Var& l, const Var& r)
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
	friend inline bool operator> (const Var& l, const Var& r) { return r < l; }
	friend inline bool operator<=(const Var& l, const Var& r) { return !(l > r); }
	friend inline bool operator>=(const Var& l, const Var& r) { return !(l < r); }
	friend bool operator==(const Var& l, const Var& r)
	{
	    if (l._cl != r._cl)
		return false;
	    if (l._cl == 1)
		return l._str == r._str;
	    else if (l._cl == 2)
		return l._int == r._int;
	    return *l._var0 == *r._var0 && *l._var1 == *r._var1;
	}
	friend inline bool operator!=(const Var& l, const Var& r) { return !(l == r); }

	public: std::size_t hash() const
	{
	    if (_cl == 1)
		return _cl + (std::hash<std::string>{}(_str) << 3);
	    else if (_cl == 2)
		return _cl + (std::hash<int>{}(_int) << 3);
	    return _cl + (_var0->hash() << 3) + (_var1->hash() << 4);
	}

	friend std::ostream& operator<<(std::ostream& out, const Var& v)
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
	private: std::shared_ptr<Var> _var0;
	private: std::shared_ptr<Var> _var1;
    };
}

template<> struct std::hash<Alignment::Var>
{
    std::size_t operator()(Alignment::Var const& v) const noexcept
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


#endif