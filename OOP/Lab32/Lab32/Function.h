#pragma once
#include "Var.h"

class Function: public Identificator
{
public:
	Function(Identificator* var);
	Function(Identificator* var1, char op, Identificator* var2);
	~Function();

	double Calculate() const;

private:
	Identificator *m_var1, *m_var2;
	char m_operand;
	bool m_bin;
};

