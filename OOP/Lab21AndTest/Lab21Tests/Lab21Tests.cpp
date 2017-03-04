// Lab21Tests.cpp: определяет точку входа для консольного приложения.
//
#include "../../Lab21/Lab21/VectorUtils.h"
#include "stdafx.h"


BOOST_AUTO_TEST_CASE(EverythingIsOk)//пустой вектор, вектор из нулей
{
	std::vector<float> vect = {2, 3, 4, 5};
	const std::vector<float> etalon = { 4, 6, 8, 10 };

	HandleVector(vect);

	BOOST_CHECK(vect == etalon);
}

BOOST_AUTO_TEST_CASE(ghjhjgh_ghghjh_ghnfhn)//пустой вектор, вектор из нулей
{
	std::vector<float> vect = { 2, 3, 4, 5, 5 };
	const std::vector<float> etalon = { 4, 6, 8, 10 };

	HandleVector(vect);

	BOOST_CHECK(vect != etalon);
}



