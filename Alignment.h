#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>
#include <iostream>

namespace Alignment
{
    class Var
    {
	public: Var(const std::string&);
	public: Var(const int&);
	public: Var(const Var*, const Var*);
	protected: int cl;
	protected: std::string rep_str;
	protected: int rep_int;
	protected: const Var* rep0;
	protected: const Var* rep1;
	friend std::ostream& operator<<(std::ostream&, const Var&);
    };
}
#endif