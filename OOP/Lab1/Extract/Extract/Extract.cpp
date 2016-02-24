// Extract.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

//const  MAX_SIZE = 2147483648;

int main(int argc, char *argv[])
{
	//для тестов функция которая проверяет содержимое входного файла с выходным (записали ли нужное)

	if (argc != 5)
	{
		std::cout << "Не верное количество аргументов. \n Формат командной строки: extract.exe <input file> <output file> <start position> <fragment size>";
		return 1;
	}
	else
	{
		std::ifstream fileIn(argv[1], std::ios::in | std::ios::binary);
		std::ofstream fileOut(argv[2], std::ios::out | std::ios::binary | std::ios::trunc);
		//trunc - отсечение размера до нуля

		if (!fileIn.is_open())
		{
			std::cout << "Файл не может быть открыт!\n";
			return 1;
		}
		else
		{
			std::ifstream::pos_type size = 0;
			fileIn.seekg(0, std::ios::end);
			size = fileIn.tellg();

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
		}
	}

    return 0;
}