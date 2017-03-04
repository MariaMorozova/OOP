#include <iostream>
#include <fstream> 
#include "Filtr.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	std::ifstream istream;
	std::set<std::string> filtr;
	if (argc == 2)
	{
		istream.open(argv[1]);
		if (!istream.is_open())
		{
			std::cout << "input file not found" << std::endl;
			return 1;
		}

		std::string word;
		while (istream >> word)
		{
			std::transform(word.begin(), word.end(), word.begin(), ::tolower); //TODO tolower for string
			filtr.insert(word);
		}
	}

	istream.open("text.txt");
	//todo: ввод строки из станд потока, не из файла и вывод в станд поток
	//todo класс CObsceneWordsFilter for Filtr
	if (!istream)
	{
		std::cout << "input file not found" << std::endl;
		return 1;
	}

	while (!istream.eof())
	{
		std::string word;
		istream >> word;
		
		if (CheckWord(filtr, word))
		{
			std::cout << word << " ";
		}
	}
	istream.close();

	return 0;
}