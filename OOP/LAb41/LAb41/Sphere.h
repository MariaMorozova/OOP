#pragma once
#include "Body.h"

class CSphere :
	public CBody
{
public:
	CSphere();
	CSphere(double r, double density);
	~CSphere();

	double Volume() const override;
	void Info() const override;

private:
	double m_r;
};

