// TheApplicationTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ArrayOfNumbers/ProcessVector.h"

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	std::vector<double> numbers;
	for (int i = 10; i < 100; i++)
		numbers.push_back(i);

	std::vector<double> numbers2;
	for (int i = 1; i < 100; i++)
		numbers2.push_back(i);

	ProcessVector(numbers);

	BOOST_CHECK_EQUAL(numbers, numbers2);
}