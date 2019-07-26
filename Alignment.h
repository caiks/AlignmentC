#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>
#include <iostream>

namespace Alignment
{
    class Variable
    {
	protected: int cl;
    };

    class VarStr : public Variable
    {
	public: VarStr(const std::string&);
	protected: std::string rep;

	friend std::ostream& operator<<(std::ostream&, const VarStr&);
    };
}
#endif