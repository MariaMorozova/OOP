// Lab31Test.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../Lab31/TVSet.h"
//��� ������������� ������ ��������� ������
//����������� � ������������� ����� TVSet

BOOST_AUTO_TEST_CASE(EverythingIsOk1) //��� ����� = ��� ���������
{
	CTVSet tv;
	
	BOOST_CHECK_EQUAL(tv.IsTurnedOn(), false);

	tv.SetChannel(10);
	BOOST_CHECK(tv.GetChannel() != 10);
}


BOOST_AUTO_TEST_CASE(EverythingIsOk2)
{
	CTVSet tv;
	tv.TurnOn();
	tv.SetChannel(10);
	tv.TurnOff();

	tv.TurnOn();
	BOOST_CHECK(tv.GetChannel() == 10);
}


BOOST_AUTO_TEST_CASE(EverythingIsOk3)
{
	CTVSet tv;
	tv.TurnOn();
	tv.SetChannel(-105);

	BOOST_CHECK(tv.GetChannel() != -105);
}