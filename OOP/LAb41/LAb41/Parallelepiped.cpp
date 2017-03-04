#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(): CBody()
{
}

CParallelepiped::CParallelepiped(double height, double width, double depth, double density)
	: CBody(density)
{
	m_depth = depth;
	m_width = width;
	m_height = height;
}

CParallelepiped::~CParallelepiped()
{
}

double CParallelepiped::Volume() const
{
	return m_depth * m_height * m_width;
}

void CParallelepiped::Info() const
{
	std::cout << "CParallelepiped. Width = " << m_width << ", Height = " << m_height
		<< ", Depth = " << m_depth << ", Density = " << m_density << std::endl;
}
