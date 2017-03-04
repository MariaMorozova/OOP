#pragma once
#include <string> 

class Identificator
{
public:
	Identificator();
	~Identificator();
	virtual double Calculate() const = 0;
	void SetValue(double val) { m_value = val; }

protected:
	double m_value;
};

std::ostream& operator<<(std::ostream& os, Identificator& id);