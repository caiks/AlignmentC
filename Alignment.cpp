#include "Alignment.h"

using namespace Alignment;

Var::Var(const std::string& s)
{
    cl = 1;
    rep_str = s;
}

Var::Var(int i)
{
    cl = 2;
    rep_int = i;
}

Var::Var(std::shared_ptr<Var> v0, std::shared_ptr<Var> v1)
{
    cl = 5;
    rep0 = v0;
    rep1 = v1;
}

std::ostream& Alignment::operator<<(std::ostream& stream, const Var& v) {
    switch (v.cl) {
    case 1: 
	stream << v.rep_str;
	break;       
    case 2: 
	stream << v.rep_int;
	break;
    case 5: 
	stream << "<" << *v.rep0  << "," << *v.rep1 << ">";
	break;
    default:
	throw std::runtime_error("std::ostream& operator<<(std::ostream&, const Var&) fail");
    }
    return stream;
}

