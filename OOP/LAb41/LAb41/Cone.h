#pragma once
#include "Body.h"
class CCone //todo ��������� ����� � ����������� �� ����� �����������
	: public CBody
{
public:
	CCone();
	CCone(double r, double height, double density);
	~CCone();

	virtual double Volume() const;
	virtual void Info() const;

private:
	double m_r;
	double m_height;
};

