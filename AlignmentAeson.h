#ifndef ALIGNMENTAESON_H
#define ALIGNMENTAESON_H

#include "Alignment.h"

namespace Alignment
{
    // stringsVariable :: String -> Variable
    Variable stringsVariable(const std::string&);

    // stringsValue :: String -> Value
    Value stringsValue(const std::string&);

    // stringsRational :: String -> Rational
    Rational stringsRational(const std::string&);

    // rationalsString :: Rational -> String
    std::string rationalsString(const Rational&);

    // systemsPersistent :: System -> SystemPersistent
    void systemsPersistent(const System&, std::ostream&);

    // systemsPersistentSorted :: System -> SystemPersistent
    void systemsPersistentSorted(const System&, std::ostream&);

    // persistentsSystem :: SystemPersistent -> Maybe System
    std::unique_ptr<System> persistentsSystem(std::istream&);

    // historiesPersistent :: History -> HistoryPersistent
    void historiesPersistent(const History&, std::ostream&);


}



#endif