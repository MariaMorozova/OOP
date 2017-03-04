#include "stdafx.h"
#include "VectorUtils.h"

void HandleVector(std::vector<float>& v)
{
	float min = *std::min(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); ++it) //range based for
	{
		(*it) *= min;
	}
	std::sort(v.begin(), v.end());
}