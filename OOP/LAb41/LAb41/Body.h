#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

class CBody
{
public:
	CBody();
	CBody(double density);
	virtual ~CBody();
	
	double Weight() const { return Density() * Volume(); }
	virtual bool Find(CBody* body) const { return body == this; }

	virtual double Density() const { return m_density;}
	virtual double Volume() const = 0;
	virtual void Info() const  = 0;

protected:
	double m_density;
};

