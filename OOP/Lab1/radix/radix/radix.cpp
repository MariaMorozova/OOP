// Radix.mcpp: определ¤ет точку входа дл¤ консольного приложени¤.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

const char str[7];

int StringToInt(const char* str, int radix, bool & wasError)
{
	while (str != 0)
	{

	}
}

void IntToString(int n, int radix, char* str, int bufferLenght, bool & wasError)
{

}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "¬ведено неверное количество аргументов.";
		return 1;
	}

	char *sourseNotation = argv[1];


	return 0;
}