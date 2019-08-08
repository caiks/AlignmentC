#include "Alignment.h"

using namespace Alignment;

std::ostream& operator<<(std::ostream& out, const System& uu)
{
    out << ((System&)uu).map_u();
    return out;
}

