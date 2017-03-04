#include "stdafx.h"
#include "TVSet.h"

CTVSet::CTVSet()
{
	m_on = false;
	m_channel = 1;
}


CTVSet::~CTVSet()
{
}

void CTVSet::TurnOn()
{
	if (!m_on)
		m_on = true;
}

void CTVSet::TurnOff()
{
	if (m_on)
		m_on = false;
}

void CTVSet::SetChannel(int channel)
{
	if (m_on && channel >= 1 && channel <= 99)
		m_channel = channel;
}

void CTVSet::Info() const
{
	std::cout << "Состояние: " << (m_on ? "Включен" : "Выключен") << std::endl;
	if (m_on)
		std::cout << "Канал: " << m_channel << std::endl;
}
