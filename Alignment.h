#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>
#include <iostream>

namespace Alignment
{
    class Variable
    {
	public: virtual void printOn(std::ostream&) const {}
	protected: int cl;
    };

    class VarStr : public Variable
    {
	public: VarStr(const std::string&);
	public: virtual void printOn(std::ostream&) const;
	protected: std::string rep;
	friend std::ostream& operator<<(std::ostream&, const VarStr&);
    };

    class VarInt : public Variable
    {
	public: VarInt(const int&);
	public: virtual void printOn(std::ostream&) const;
	protected: int rep;
	friend std::ostream& operator<<(std::ostream&, const VarInt&);
    };

    class VarPair : public Variable
    {
	public: VarPair(const Variable*, const Variable*);
	public: virtual void printOn(std::ostream&) const;
	protected: const Variable* rep0;
	protected: const Variable* rep1;
	friend std::ostream& operator<<(std::ostream&, const VarPair&);
    };
}
#endif