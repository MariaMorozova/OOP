#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include "dictionary.h"

#include <vector>



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	bool needToUpdate = true;
	std::string name = "dictionary.txt"; 
	//���������� ���� � ����� � ��� ��������� ��������� ������
	if (argc == 2)
	{
		name = argv[1];
		std::ifstream istream(name);
		if (!istream)
		{
			std::cout << "input file not found" << std::endl;
			return 1;
		}
		//std::vector <std::string, std::string> results;
		char cStr[1024]; //������
		while (!istream.eof())
		{
			istream.getline(cStr, 1024);
			std::string str(cStr);
			int position = str.find(':');//todo: boost split

			if (position != -1) 
			{
				dictionary[str.substr(0, position - 1)] = str.substr(position + 2, str.length() - position - 2);
			}
			//boost::split(results, str, boost::is_any_of(":"));
		}
		needToUpdate = false;
	}
	
	std::string str;
	do
	{
		std::cout << ">";
		std::getline(std::cin, str);
		if (str == "")
		{
			continue;
		}

		std::string ru;
		if (Translate(str, ru))
		{
			std::cout << ru << std::endl;
		}
		else
		{
			std::cout << "����������� ����� �" + str + "�. ������� ������� ��� ������ ������ ��� ������." 
				<< std::endl;
			std::string translatedWord;
			std::getline(std::cin, translatedWord);
			for (auto ch = translatedWord.begin(); ch != translatedWord.end(); ++ch)
			{
				(*ch) += (*ch) >= -32 ? 16 : 64; //magic. russian local
			}

			if (translatedWord == "")
			{
				std::cout << "����� �" + str + "����������������" << std::endl;
			}
			else
			{
				dictionary[str] = translatedWord;
				std::cout << "����� �" + str + "� ��������� � ������� ��� �" + translatedWord + "�" << std::endl;
				needToUpdate = true;
			}
		}
	} while (str != "...");

	if (needToUpdate)
	{
		std::cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n>";
		char ch;
		std::cin.get(ch);
		
		if (ch == 'y' || ch == 'Y') //todo: tolower 
		{
			std::ofstream ostream(name);
			for (const auto &pair : dictionary)
			{
				ostream << pair.first << " : " << pair.second << std::endl;
			}
			ostream.close();
			std::cout << "���������  ���������. �� ��������.";
		}
	}

	return 0;
}