#include "stdafx.h"
#include "ProcessVector.h"

void ProcessVector(std::vector<double> & numbers)
{
	double minElement = *std::min_element(numbers.begin(), numbers.end());

	for (auto i = numbers.begin(); i != numbers.end(); i++)
		*i *= minElement;
}