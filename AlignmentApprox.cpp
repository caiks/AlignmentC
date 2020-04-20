#include "AlignmentApprox.h"

using namespace Alignment;

// histogramsEntropy :: Histogram -> Double
double Alignment::histogramsEntropy(const Histogram& aa)
{
	auto s = histogramsSize(aa);
	double e = 0.0;
	for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
		if (it->second > 0)
		{
			double a = it->second.getDouble() / s.getDouble();
			e -= a * log(a);
		}
	return e;
}

// histogramsAlignment :: Histogram -> Double
double Alignment::histogramsAlignment(const Histogram& aa)
{
	double e = 0.0;
	for (auto it = aa.map_u().begin(); it != aa.map_u().end(); ++it)
		e += alngam(it->second.getDouble() + 1.0);
	auto bb = histogramsIndependent(aa);
	for (auto it = bb->map_u().begin(); it != bb->map_u().end(); ++it)
		e -= alngam(it->second.getDouble() + 1.0);
	return e;
}

