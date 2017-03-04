#include "Compound.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include "CompareBodies.h"

#include <fstream>
#include <string>
#include <algorithm>

CBody* Factory(std::ifstream& istream);

int main()
{
	setlocale(LC_ALL, "Russian");

	std::vector<CBody*> bodies;

	std::ifstream istream("input.txt");
	if (!istream.is_open())
	{
		std::cout << "input file not found" << std::endl;
		system("pause");
		return 1;
	}

	while (!istream.eof())
	{
		CBody* body = Factory(istream);
		if (body)
			bodies.push_back(body);
	}
	istream.close();
	
	std::cout << "1" << std::endl; 
	CBody* max = BodyWithTheGreatestWeight(bodies);	//тело с наибольшей массой
	if (max)
		max->Info();
	else
		std::cout << "Not found" << std::endl;

	std::cout << "2" << std::endl; 
	CBody* min = EasiestBodyInWater(bodies);	// самое легкое тело в воде
	
	if (min)
		min->Info();
	else
		std::cout << "Not found" << std::endl;

	for (auto obj : bodies)
		if (obj)
			delete obj;

	return 0;
}

CBody* Factory(std::ifstream& istream)
{
	double density;
	std::string str;
	istream >> str;

	if (str == "Cone")
	{
		double r, height;
		istream >> r >> height >> density;
		return new CCone(r, height, density);
	}
	else if (str == "Sphere")
	{
		double r;
		istream >> r >> density;
		return new CSphere(r, density);
	}
	else if (str == "Cylinder")
	{
		double r, height;
		istream >> r >> height >> density;
		return new CCylinder(r, height, density);
	}
	else if (str == "Parallelepiped")
	{
		double height, width, depth;
		istream >> height >> width >> depth >> density;
		return new CParallelepiped(height, width, depth, density);
	}
	else if (str == "Compound")
	{
		CCompound* compound = new CCompound();
		CBody* body = Factory(istream);
		while (body)
		{
			compound->AddBody(body);
			body = Factory(istream);
		}
		return compound;
	}

	return nullptr;
}
