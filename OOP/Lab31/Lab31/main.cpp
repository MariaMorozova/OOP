#include "stdafx.h"
#include "TVSet.h" 

int main()
{
	setlocale(LC_ALL, "Russian");
	CTVSet tv;

	char ch;
	do
	{
		system("cls");
		std::cout << "1. Включить" << std::endl;
		std::cout << "2. Выключить" << std::endl;
		std::cout << "3. Переключить канал" << std::endl;
		std::cout << "4. Инфо" << std::endl;
		std::cout << "5. Выйти" << std::endl;
		
		ch = std::cin.get();

		switch (ch)
		{
		case '1':
			tv.TurnOn();
			break;
		case '2':
			tv.TurnOff();
			break;
		case '3':
			int channel;
			std::cout << "Введите канал: ";
			std::cin >> channel;
			tv.SetChannel(channel);
			break;
		case '4':
			tv.Info();
			system("pause");
			break;
		}
	} while (ch != '5');

	return 0;
}