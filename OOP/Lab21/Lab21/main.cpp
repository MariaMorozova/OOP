#include "stdafx.h"
#include "VectorUtils.h"

int main(int argc, char** argv)
{
	std::ifstream istream("input.txt");
	if (!istream)
	{
		std::cout << "input file not found" << std::endl;
		return 1;
	}
	//��������� ���������� string ��� cNum � ���� ���������� � ����� �������
	char cNum[20]; 
	std::vector<float> vector;
	while (istream.good()) //istream >> str
	{
		istream.getline(cNum, 20, ',');
		float f = atof(cNum);
		vector.push_back(f);
	}
	istream.close();

	HandleVector(vector);

	std::ofstream ostream("output.txt");
	for (int i = 0; i < vector.size() - 1; ++i) //-1 ������ 
	{
		ostream << vector[i] << ", ";
	}
	ostream << vector[vector.size() - 1]; //������ 
	ostream.close();

	//��������� �������� ����� � ����

	return 0;
}

