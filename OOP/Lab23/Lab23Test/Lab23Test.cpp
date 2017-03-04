// Lab23Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Lab23\dictionary.h"

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	dictionary["cat"] = "кошка";
	dictionary["dog"] = "собака";
		
	std::string ru;

	BOOST_CHECK_EQUAL(Translate("cat", ru), true);
	BOOST_CHECK_EQUAL(ru, "кошка");

	BOOST_CHECK_EQUAL(Translate("dog", ru), true);
	BOOST_CHECK_EQUAL(ru, "собака");

	BOOST_CHECK_EQUAL(Translate("cow", ru), false);
}

//todo: добавить тесты
//добавление слова в словарь
