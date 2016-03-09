// Extract.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		std::cout << "Не верное количество аргументов.\nФормат командной строки: extract.exe <input file> <output file> <start position> <fragment size>\n";
		return 1;
	}

	std::ifstream fileIn(argv[1], std::ios::in | std::ios::binary);
	std::ofstream fileOut(argv[2], std::ios::out | std::ios::binary | std::ios::trunc);
	//trunc - отсечение размера до нуля

	struct stat fileSize;
	stat(argv[1], &fileSize);

	if (!fileIn.is_open())
	{
		std::cout << "Файл не может быть открыт!\n";
		return 1;
	}
	else if (fileSize.st_size > 2147483647)
	{
		std::cout << "file size larger than 2 GB\nUse a file size less then 2GB please\n";
		return 1;
	}

	int startPosition = std::atoi(argv[3]);
	fileIn.seekg(startPosition, std::ios::beg);

	int fragmentSize = std::atoi(argv[4]);

	while (!fileIn.eof() && fragmentSize)
	{
		fileOut.put(fileIn.get()); //запись считаных байт
		fragmentSize--;
	}
	fileIn.close();
	fileOut.close();

	return 0;
}