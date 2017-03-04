#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

std::string HtmlDecode(std::string html);
void Replace(std::string& str, const std::string& from, const std::string& to);

int main(int argc, char** argv)
{
	std::ifstream istream("input.txt"); //ввод с консоли
	if (!istream.is_open())
	{
		std::cout << "input file not found" << std::endl;
		system("pause");
		return 1;
	}

	char cNum[256]; //std::string
	istream.getline(cNum, 256); //изменить cNum

	istream.close();//
	std::string html(cNum);//

	std::string decodeStr = HtmlDecode(html);

	std::ofstream ostream("output.txt");//
	ostream << decodeStr;//
	ostream.close();//
	//вывод в консоль
	return 0;
}

std::string HtmlDecode(std::string html)
{
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