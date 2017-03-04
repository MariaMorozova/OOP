#include "Function.h"
#include <iostream>

Function::Function(Identificator * var)
{
	if (var)
	{
		m_var1 = var;
		m_var2 = nullptr;

		m_bin = false; //todo переименовать bin
		m_value = Calculate();
	}
}

Function::Function(Identificator * var1, char op, Identificator * var2)
{
	if (var1 && var2)
	{
		m_var1 = var1;
		m_var2 = var2;
		m_operand = op;
		m_bin = true;

		m_value = Calculate();
	}
}

Function::~Function()
{
}

double Function::Calculate() const
{
	if (m_bin)
	{
		double val1 = m_var1->Calculate();
		double val2 = m_var2->Calculate();
		switch (m_operand)
		{
		case '+':
			return val1 + val2;
		case '-':
			return val1 - val2;
		case '/':
			return val1 / val2;
		case '*':
			return val1 * val2;
		default:
			break;
		}
	}
	return m_var1->Calculate();
}
