#include "AlignmentApprox.h"

#include <math.h>

using namespace Alignment;

// histogramsEntropy :: Histogram -> Double
double Alignment::histogramsEntropy(const Histogram& aa)
{
    auto s = histogramsSize(aa);
    double e = 0.0;
    for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
	if (it->second > 0)
	{
	    double a = (double)it->second.getNumerator() * (double)s.getDenominator() / (double)it->second.getDenominator() / (double)s.getNumerator();
	    e -= a * log(a);
	}
    return e;
}
