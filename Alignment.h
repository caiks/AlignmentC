#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>

namespace Alignment
{
    class Variable
    {
	public: Variable();
	public: Variable(const Variable&);
	public: virtual ~Variable();
	public: int cl;
    };
}
#endif