#include <iostream>
#include <fstream> 

#include "dictionary.h"



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	bool needToUpdate = true;
	std::string name = "dictionary.txt"; //передавать путь к файлу в кач аргумента командной строки
	if (argc == 2)
	{
		name = argv[1];
		std::ifstream istream(name);
		if (!istream)
		{
			std::cout << "input file not found" << std::endl;
			return 1;
		}

		char cStr[1024]; //убрать
		while (!istream.eof())
		{
			istream.getline(cStr, 1024);
			std::string str(cStr);
			int position = str.find(':');//todo: boost split
			if (position != -1) 
			{
				dictionary[str.substr(0, position - 1)] = str.substr(position + 2, str.length() - position - 2);
			}
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
			std::cout << "Ќеизвестное слово У" + str + "Ф. ¬ведите перевод или пустую строку дл€ отказа." 
				<< std::endl;
			std::string translatedWord;
			std::getline(std::cin, translatedWord);
			for (auto ch = translatedWord.begin(); ch != translatedWord.end(); ++ch)
			{
				(*ch) += (*ch) >= -32 ? 16 : 64; //magic. russian local
			}

			if (translatedWord == "")
			{
				std::cout << "—лово У" + str + "Фпроигнорировано" << std::endl;
			}
			else
			{
				dictionary[str] = translatedWord;
				std::cout << "—лово У" + str + "Ф сохранено в словаре как У" + translatedWord + "Ф" << std::endl;
				needToUpdate = true;
			}
		}
	} while (str != "...");

	if (needToUpdate)
	{
		std::cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом.\n>";
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
			std::cout << "»зменени€  сохранены. ƒо свидани€.";
		}
	}

	return 0;
}