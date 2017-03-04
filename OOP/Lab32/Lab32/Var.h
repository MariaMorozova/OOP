#pragma once
#include <math.h>
#include "Identificator.h"

class Var: public Identificator
{
public:
	Var();
	Var(double);
	~Var();

	double Calculate() const { return m_value; }
};


