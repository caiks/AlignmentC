#ifndef ALIGNMENTAESON_H
#define ALIGNMENTAESON_H

#include "Alignment.h"

namespace Alignment
{
    // stringsVariable :: String -> Variable
    Variable stringsVariable(const std::string&);

    // stringsValue :: String -> Value
    Value stringsValue(const std::string&);


}



#endif