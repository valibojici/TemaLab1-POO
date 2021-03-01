#include "car.h"

void Car::dischargeBattery() { m_engine.set_batteryIsDischarghed(true); }
void Car::meltEngine() { m_engine.set_engineIsMelted(true); }
void Car::lowerOilLevel() { m_engine.set_lowOilLevel(true); }
void Car::dirtEngine() { m_engine.set_isDirty(true); }
void Car::destroyEngine() { m_engine.set_hasExtremeDamage(true); }

void Car::misalignWheel(std::string pos, int value)
{
	if (pos == "FL")
	{
		m_wheelFL.set_alignment(value);
	}
	else if (pos == "FR")
	{
		m_wheelFR.set_alignment(value);
	}
	else if (pos == "RL")
	{
		m_wheelRL.set_alignment(value);
	}
	else if (pos == "RR")
	{
		m_wheelRR.set_alignment(value);
	}
}

void Car::wearBrakeDisc(std::string pos)
{
	if (pos == "FL")
	{
		m_wheelFL.set_brakeDisc(1);
	}
	else if (pos == "FR")
	{
		m_wheelFR.set_brakeDisc(1);
	}
	else if (pos == "RL")
	{
		m_wheelRL.set_brakeDisc(1);
	}
	else if (pos == "RR")
	{
		m_wheelRR.set_brakeDisc(1);
	}
}

void Car::wearBrakePad(std::string pos)
{
	if (pos == "FL")
	{
		m_wheelFL.set_brakePad(1);
	}
	else if (pos == "FR")
	{
		m_wheelFR.set_brakePad(1);
	}
	else if (pos == "RL")
	{
		m_wheelRL.set_brakePad(1);
	}
	else if (pos == "RR")
	{
		m_wheelRR.set_brakePad(1);
	}
}

void Car::flatTire(std::string pos)
{
	if (pos == "FL")
	{
		m_wheelFL.set_flatTire(1);
	}
	else if (pos == "FR")
	{
		m_wheelFR.set_flatTire(1);
	}
	else if (pos == "RL")
	{
		m_wheelRL.set_flatTire(1);
	}
	else if (pos == "RR")
	{
		m_wheelRR.set_flatTire(1);
	}
}

void Car::destroyWheel(std::string pos)
{
	if (pos == "FL")
	{
		m_wheelFL.set_hasExtremeDamage(1);
	}
	else if (pos == "FR")
	{
		m_wheelFR.set_hasExtremeDamage(1);
	}
	else if (pos == "RL")
	{
		m_wheelRL.set_hasExtremeDamage(1);
	}
	else if (pos == "RR")
	{
		m_wheelRR.set_hasExtremeDamage(1);
	}
}

void Car::wear()
{
	m_engine.wear();
	m_body.wear();
	m_wheelFL.wear();
	m_wheelFR.wear();
	m_wheelRL.wear();
	m_wheelRR.wear();
	m_headlightFL.wear();
	m_headlightFR.wear();
	m_brakelightRL.wear();
	m_brakelightRR.wear();
}