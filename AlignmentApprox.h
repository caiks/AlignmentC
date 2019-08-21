#ifndef ALIGNMENTAPPROX_H
#define ALIGNMENTAPPROX_H

#include "Alignment.h"

namespace Alignment
{
    // histogramsEntropy :: Histogram -> Double
    double histogramsEntropy(const Histogram&);

    // histogramsEntropy :: Histogram -> Double
    double histogramsAlignment(const Histogram&);

}



#endif