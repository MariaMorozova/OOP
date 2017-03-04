#include "Sphere.h"

CSphere::CSphere(): CBody()
{
	m_r = 0;
}

CSphere::CSphere(double r, double density): CBody(density)
{
	m_r = r;
}

CSphere::~CSphere()
{
}

double CSphere::Volume() const
{
	return 4 * pow(m_r, 3) * M_PI / 3;
}

void CSphere::Info() const
{
	std::cout << "Sphere. r = " << m_r << ", Density = " << m_density << std::endl;
}

