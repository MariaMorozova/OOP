#include "Body.h"



CBody::CBody()
{
}

CBody::CBody(double density)
{
	m_density = density;
}


CBody::~CBody()
{
	m_density = 0.0;
}
