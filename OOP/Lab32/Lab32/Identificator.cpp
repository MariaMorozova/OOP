#include "Identificator.h"
#include <iomanip> 


std::ostream& operator<<(std::ostream& os, Identificator& id)
{
	double value = id.Calculate();
	os << std::fixed;
	if (isnan(value))
	{
		os << "nan";
	}
	else
	{
		os << std::setprecision(2) << value;
	}

	return os;
}

Identificator::Identificator()
{
	m_value = NAN;
}

Identificator::~Identificator()
{
}
