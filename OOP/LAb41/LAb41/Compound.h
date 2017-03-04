#pragma once
#include "Body.h"
#include <vector>

class CCompound :
	public CBody
{
public:
	CCompound();
	~CCompound();

	void AddBody(CBody* body);
	virtual bool Find(CBody* body) const;

	virtual double Density() const;
	virtual double Volume() const;
	virtual void Info() const;

private:
	std::vector<CBody*> m_bodies;
};

