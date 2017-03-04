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
		std::cout << "1. ��������" << std::endl;
		std::cout << "2. ���������" << std::endl;
		std::cout << "3. ����������� �����" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cout << "5. �����" << std::endl;
		
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
			std::cout << "������� �����: ";
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