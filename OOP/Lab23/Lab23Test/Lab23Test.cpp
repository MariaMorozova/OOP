// Lab23Test.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "..\Lab23\dictionary.h"

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	dictionary["cat"] = "�����";
	dictionary["dog"] = "������";
		
	std::string ru;

	BOOST_CHECK_EQUAL(Translate("cat", ru), true);
	BOOST_CHECK_EQUAL(ru, "�����");

	BOOST_CHECK_EQUAL(Translate("dog", ru), true);
	BOOST_CHECK_EQUAL(ru, "������");

	BOOST_CHECK_EQUAL(Translate("cow", ru), false);
}

//todo: �������� �����
//���������� ����� � �������
