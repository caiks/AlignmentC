#include "Alignment.h"

using namespace Alignment;

Variable::Variable() : cl(0)
{
}

Variable::Variable(const Variable& other) : cl(other.cl)
{
}

Variable::~Variable()
{
}