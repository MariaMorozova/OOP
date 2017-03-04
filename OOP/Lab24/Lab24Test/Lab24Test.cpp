// Lab24Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab24/Filtr.h"


BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	std::set<std::string> badWords = {"bad", "notgood"};

	BOOST_CHECK_EQUAL(CheckWord(badWords, "bad"), false);
	BOOST_CHECK_EQUAL(CheckWord(badWords, "byaka"), true);
	BOOST_CHECK_EQUAL(CheckWord(badWords, "NoTgooD"), false);
}

