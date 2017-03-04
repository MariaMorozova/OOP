#include "Cylinder.h"

CCylinder::CCylinder() 
	:CBody()
{
}

CCylinder::CCylinder(double r, double height, double density)
	: CBody(density)
	, m_r(r)
	, m_height(height)
{
}

CCylinder::~CCylinder()
{
}

double CCylinder::Volume() const
{
	return M_PI * pow(m_r, 2) * m_height;
}

void CCylinder::Info() const
{
	std::cout << "Cylinder. Radius = " << m_r << ", Height = " << m_height << ", Density = " << m_density << std::endl;
}
