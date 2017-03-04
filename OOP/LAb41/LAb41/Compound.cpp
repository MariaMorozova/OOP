#include "Compound.h"

CCompound::CCompound()
{
}

CCompound::~CCompound()
{
	for (auto obj : m_bodies)
		if (obj)
			delete obj;
}

void CCompound::AddBody(CBody * body)
{
	if (body && !Find(body))
		m_bodies.push_back(body);
}

bool CCompound::Find(CBody * body) const
{
	bool find = false;
	for (auto obj : m_bodies)
		if (obj)
			find |= obj->Find(body);
	return find;
}

double CCompound::Density() const
{
	double density = 0.0;
	for (auto obj : m_bodies)
		if (obj)
			density += obj->Density();
	return density;
}

double CCompound::Volume() const
{
	double volume = 0.0;
	for (auto obj : m_bodies)
		if (obj)
			volume += obj->Volume();
	return volume;
}

void CCompound::Info() const
{
	std::cout << "Compound." << std::endl << "begin" << std::endl;
	for (auto obj : m_bodies)
		if (obj)
			obj->Info();
	std::cout << "end" << std::endl;
}
