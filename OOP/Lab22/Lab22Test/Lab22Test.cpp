// Lab22Test.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <string>
//todo: ������� � ������� h � cpp �����

std::string HtmlDecode(std::string const& html);
void Replace(std::string& str, const std::string& from, const std::string& to);

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	std::string html = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	const std::string etalon = "Cat <says> \"Meow\". M&M's";

	std::string decode = HtmlDecode(html);

	BOOST_CHECK_EQUAL(decode, etalon);
}//�������� �� ������������� ������� ������
  
std::string HtmlDecode(std::string const& html)
{
	std::string decode(html);
	Replace(decode, "&quot;", "\"");
	Replace(decode, "&apos;", "'");
	Replace(decode, "&lt;", "<");
	Replace(decode, "&gt;", ">");
	Replace(decode, "&amp;", "&");

	return decode;
}

void Replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from); //�������� �� startPos
	while (start_pos != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos = str.find(from);
	}
}