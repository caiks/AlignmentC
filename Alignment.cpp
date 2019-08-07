#include "AlignmentUtil.h"
#include "Alignment.h"

using namespace Alignment;

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    auto qq = ((System&)uu).map_u();
    out << "{";
    for (auto it = qq.begin(); it != qq.end(); ++it)
    {
	if (it != qq.begin())
	    out << ",";
	out << *it;
    }
    out << "}";
    return out;
}

