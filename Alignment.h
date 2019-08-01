#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <iostream>
#include <memory>
#include <string>

namespace Alignment
{
    struct Var
    {
	Var(const std::string&);
	Var(int);
	Var(const Var&, const Var&);
	int cl;
	std::string rep_str;
	int rep_int;
	std::shared_ptr<Var> rep0;
	std::shared_ptr<Var> rep1;
	friend std::ostream& operator<<(std::ostream&, const Var&);
    };
}
#endif