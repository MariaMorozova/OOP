#pragma once

class CTVSet
{
public:
	CTVSet();
	~CTVSet();

	bool IsTurnedOn() const { return m_on; }
	void TurnOn();
	void TurnOff();
	void SetChannel(int channel);
	int GetChannel() const { return m_channel; }
	void Info() const;

private:
	int m_channel;
	bool m_on;
};

