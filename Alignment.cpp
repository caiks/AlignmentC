#include "Alignment.h"

using namespace Alignment;

VarStr::VarStr(const std::string& s)
{
    cl = 1;
    rep = s;
}

void VarStr::printOn(std::ostream& stream) const
{
    stream << rep;
}

std::ostream& Alignment::operator<<(std::ostream& stream, const VarStr& v) {
    v.printOn(stream);
    return stream;
}

VarInt::VarInt(const int& i)
{
    cl = 2;
    rep = i;
}

void VarInt::printOn(std::ostream& stream) const
{
    stream << rep;
}

std::ostream& Alignment::operator<<(std::ostream& stream, const VarInt& v) {
    v.printOn(stream);
    return stream;
}

VarPair::VarPair(const Variable* p0, const Variable* p1)
{
    cl = 5;
    rep0 = p0;
    rep1 = p1;
}

void VarPair::printOn(std::ostream& stream) const
{
    stream << "<";
    rep0->printOn(stream);
    stream << ",";
    rep1->printOn(stream);
    stream << ">";
}

std::ostream& Alignment::operator<<(std::ostream& stream, const VarPair& v) {
    v.printOn(stream);
    return stream;
}

