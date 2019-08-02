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

	public: friend std::ostream& operator<<(std::ostream& _out, const Var& _v)
	{
	    switch (_v.cl) {
	    case 1:
		_out << _v.rep_str;
		break;
	    case 2:
		_out << _v.rep_int;
		break;
	    case 5:
		_out << "<" << *_v.rep_var0 << "," << *_v.rep_var1 << ">";
		break;
	    default:
		throw std::logic_error("std::ostream& operator<<(std::ostream&, const Var&)");
	    }
	    return _out;
	}

	private: char cl;
	private: std::string rep_str;
	private: int rep_int;
	private: std::shared_ptr<Var> rep_var0;
	private: std::shared_ptr<Var> rep_var1;
    };
}
#endif