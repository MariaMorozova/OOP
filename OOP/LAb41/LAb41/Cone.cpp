#include "Cone.h"

CCone::CCone()
	: CBody()
{
}

CCone::CCone(double r, double height, double density)
	: CBody(density)
{
	m_r = r;
	m_height = height;
}

CCone::~CCone()
{
}

double CCone::Volume() const
{
	return  (1.0 / 3.0) * M_PI * pow(m_r, 2) * m_height;
}

void CCone::Info() const
{
	std::cout << "Cone. Radius = " << m_r << ", Height = " << m_height << ", Density = " << m_density << std::endl;
}
