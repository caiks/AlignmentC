#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <iostream>
#include <memory>
#include <string>

namespace Alignment
{
    class Var
    {
	private: Var() = default;

	public: Var(const Var& _v)
	{
	    this->cl = _v.cl;
	    this->rep_str = _v.rep_str;
	    this->rep_int = _v.rep_int;
	    this->rep_var0 = _v.rep_var0;
	    this->rep_var1 = _v.rep_var1;
	}

	public: Var(const std::string& _s)
	{
	    this->cl = 1;
	    this->rep_str = _s;
	}

	public: Var(int _i)
	{
	    this->cl = 2;
	    this->rep_int = _i;
	}

	public: Var(const Var& _v0, const Var& _v1)
	{
	    this->cl = 5;
	    this->rep_var0 = std::make_shared<Var>(_v0);
	    this->rep_var1 = std::make_shared<Var>(_v1);
	}

	public: friend bool operator<(const Var& _l, const Var& _r)
	{
	    if (_l.cl < _r.cl)
		return true;
	    if (_l.cl > _r.cl)
		return false;
	    if (_l.cl == 1)
		return _l.rep_str < _r.rep_str;
	    else if (_l.cl == 2)
		return _l.rep_int < _r.rep_int;
	    return *_l.rep_var0 < *_r.rep_var0 || ( !(*_r.rep_var0 < *_l.rep_var0) && *_l.rep_var1 < *_r.rep_var1);
	}
	public: friend inline bool operator> (const Var& _l, const Var& _r) { return _r < _l; }
	public: friend inline bool operator<=(const Var& _l, const Var& _r) { return !(_l > _r); }
	public: friend inline bool operator>=(const Var& _l, const Var& _r) { return !(_l < _r); }
	public: friend bool operator==(const Var& _l, const Var& _r)
	{
	    if (_l.cl != _r.cl)
		return false;
	    if (_l.cl == 1)
		return _l.rep_str == _r.rep_str;
	    else if (_l.cl == 2)
		return _l.rep_int == _r.rep_int;
	    return *_l.rep_var0 == *_r.rep_var0 && *_l.rep_var1 == *_r.rep_var1;
	}
	public: friend inline bool operator!=(const Var& _l, const Var& _r) { return !(_l == _r); }

	public: friend std::ostream& operator<<(std::ostream& _out, const Var& _v)
	{
	    if (_v.cl == 1)
		_out << _v.rep_str;
	    else if (_v.cl == 2)
		_out << _v.rep_int;
	    else
		_out << "<" << *_v.rep_var0 << "," << *_v.rep_var1 << ">";
	    return _out;
	}

        public: std::size_t hash() const
	{
	    if (this->cl == 1)
		return this->cl + (std::hash<std::string>{}(this->rep_str) << 3);
	    else if (this->cl == 2)
		return this->cl + (std::hash<int>{}(this->rep_int) << 3);
	    return this->cl + (this->rep_var0->hash() << 3) + (this->rep_var1->hash() << 4);
	}

	private: char cl;
	private: std::string rep_str;
	private: int rep_int;
	private: std::shared_ptr<Var> rep_var0;
	private: std::shared_ptr<Var> rep_var1;
    };
}

template<> struct std::hash<Alignment::Var>
{
    std::size_t operator()(Alignment::Var const& _v) const noexcept
    {
	return _v.hash();
    }
};


#endif