#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <map>


std::string HtmlDecode(std::string html);
void Replace(std::string& str, const std::string& from, const std::string& to);

int main(int argc, char** argv)
{
	std::string html;
	std::cout << "Enter the string which you want to decode" << std::endl;
	std::getline(std::cin, html);

	std::string decodeStr = HtmlDecode(html);

	std::cout << decodeStr << std::endl;

	return 0;
}

std::string HtmlDecode(std::string html)
{
	std::map <std::string, std::string> mapDec{ { "&quot;", "\"" },
												{ "&apos;", "'" },
												{ "&lt;", "<" },
												{ "&gt;", ">" },
												{ "&amp;", "&" } };


	//map сущность html - key, value  то что заменить

	Replace(html, "&quot;", "\"");
	Replace(html, "&apos;", "'");
	Replace(html, "&lt;", "<");
	Replace(html, "&gt;", ">");
	Replace(html, "&amp;", "&");
	return html;
}

void Replace(std::string& str, const std::string& from, const std::string& to) 
{
	size_t start_pos = str.find(from);
	while (start_pos != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos = str.find(from);
	}
}