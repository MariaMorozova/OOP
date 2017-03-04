// Lab31Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab31/TVSet.h"
//при инициализации класса проверить данные
//разобраться с дублированием файла TVSet

BOOST_AUTO_TEST_CASE(EverythingIsOk1) //имя теста = что проверяет
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