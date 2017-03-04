// Lab41Test.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*1. ������ ������ ��������. ����� ������ � ���������� ������. ������ � ��������
2. ���� ����� � "����� ������ ���� � ����"*/

#include "stdafx.h"

#include "../LAb41/Cone.h"
#include "../LAb41/Cylinder.h"
#include "../LAb41/Parallelepiped.h"
#include "../LAb41/Sphere.h"
#include "../Lab41/CompareBodies.h"
#include "../LAb41/Body.h"

//todo �������� ������� ���������

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