#include "Alignment.h"

using namespace Alignment;

VarStr::VarStr(const std::string& s)
{
    cl = 1;
    rep = s;
}

std::ostream& Alignment::operator<<(std::ostream& stream,
    const VarStr& v) {
    stream << v.rep;
    return stream;
}