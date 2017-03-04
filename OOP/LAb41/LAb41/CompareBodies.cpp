#include "CompareBodies.h"

CBody* BodyWithTheGreatestWeight(std::vector<CBody*> bodies)
{
	auto max = std::max_element(bodies.begin(), bodies.end(),
		[](CBody* a, CBody* b)
	{ return a->Weight() < b->Weight(); });
	return *max;
}

CBody* EasiestBodyInWater(std::vector<CBody*> bodies)
{
	CBody* min = NULL;
	double minWeight = 1e+100; //гугл
	for (auto obj : bodies)
		if (obj->Density() > 1000)
		{
			double weight = obj->Volume() * (obj->Density() - 1000);
			if (weight < minWeight)
				minWeight = weight, min = obj;
		}
	return min;
}