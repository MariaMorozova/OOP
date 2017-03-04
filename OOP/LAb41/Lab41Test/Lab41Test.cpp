// Lab41Test.cpp: определяет точку входа для консольного приложения.
//
/*1. сделай вектор объектов. найди объект с наибольшей массой. сравни с эталоном
2. тоже самое с "самое легкое тело в воде"*/

#include "stdafx.h"

#include "../LAb41/Cone.h"
#include "../LAb41/Cylinder.h"
#include "../LAb41/Parallelepiped.h"
#include "../LAb41/Sphere.h"
#include "../Lab41/CompareBodies.h"
#include "../LAb41/Body.h"

//todo выделить простые указатели

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	std::vector<CBody*> bodies;
	bodies.push_back(new CSphere(10, 100.0));
	bodies.push_back(new CParallelepiped(10, 20, 15, 11.0));
	bodies.push_back(new CCone(17, 8.4, 1100.0));
	bodies.push_back(new CCylinder(10, 6, 1050.0));

	//std::vector<CBody*> etalonInWater = ();
	std::vector<CBody*> etalonTheGreatestWeight = (10, 6, 1050.0);

	CBody* max = BodyWithTheGreatestWeight(bodies);
	std::cout << max->Info() << std::endl;

	BOOST_CHECK_EQUAL(max, etalonTheGreatestWeight);
}