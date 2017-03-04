#pragma once
#include "Body.h"
class CCylinder :
	public CBody
{
public:
	CCylinder();
	CCylinder(double r, double height, double density);
	~CCylinder();

	virtual double Volume() const;
	virtual void Info() const;

private:
	double m_r;
	double m_height;
};

