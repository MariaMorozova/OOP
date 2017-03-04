#pragma once
#include "Body.h"
class CParallelepiped :
	public CBody
{
public:
	CParallelepiped();
	CParallelepiped(double height, double width, double depth, double density);
	~CParallelepiped();

	virtual double Volume() const;
	virtual void Info() const;

private:
	double m_width;
	double m_height;
	double m_depth;
};

