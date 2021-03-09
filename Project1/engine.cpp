#include "engine.h"
#include "autoshop.h"


Engine::Engine(bool lowOilLevel, bool engineIsMelted, bool isDirty, bool batteryIsDischarged, bool extremeDamage):
	m_lowOilLevel(lowOilLevel),
	m_engineIsMelted(engineIsMelted),
	m_isDirty(isDirty),
	m_hasExtremeDamage(extremeDamage),
	m_batteryIsDischarghed(batteryIsDischarged) {}

Engine::Engine(const Engine& other) :
	m_lowOilLevel(other.m_lowOilLevel),
	m_engineIsMelted(other.m_engineIsMelted),
	m_isDirty(other.m_isDirty),
	m_hasExtremeDamage(other.m_hasExtremeDamage),
	m_batteryIsDischarghed(other.m_batteryIsDischarghed) {}

float Engine::getRepairCost(const AutoShop& shop) const
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_engineIsMelted)
	{
		cost += shop.get_manHourCost() * 2.5f;
		cost += shop.get_oilCost() * 2;
		cost += shop.get_screwCost() * 20;
		cost += shop.get_rivetCost() * 10;
		cost += shop.get_steelCost() * 10;
		cost += shop.get_lubricantCost() * 2;
	}

	if (m_lowOilLevel)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_oilCost();
		cost += shop.get_screwCost() * 4;
	}

	if (m_batteryIsDischarghed)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_aluminiumCost() * 3;
		cost += shop.get_screwCost() * 10;
		cost += shop.get_wireCost() * 5;
	}

	if (m_isDirty)
	{
		cost += shop.get_manHourCost() * 1.5f;
		cost += shop.get_cleaningProductsCost() * 2;
		cost += shop.get_screwCost() * 6;
		cost += shop.get_lubricantCost() * 2;
	}
	return round(cost * 100.0f) / 100;
}

void Engine::wear()
{
	m_lowOilLevel = rand() % 2;
	m_engineIsMelted = rand() % 2;
	m_isDirty = rand() % 2;
	m_batteryIsDischarghed = rand() % 2;
	m_hasExtremeDamage = !bool(rand() % 10);
}

void Engine::menu()
{
	int option = 0;
	do {
		std::cout << "	Engine Menu\n";
		std::cout << " - 1. Lower oil level\n - 2. Melt engine\n - 3. Make engine dirty\n - 4. Discharge battery\n - 5. Destroy engine\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: this->set_lowOilLevel(true);
			break;
		case 2: this->set_engineIsMelted(true);
			break;
		case 3: this->set_isDirty(true);
			break;
		case 4: this->set_batteryIsDischarghed(true);
			break;
		case 5: this->set_hasExtremeDamage(true);
			break;
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out, const Engine& en)
{
	if (en.m_hasExtremeDamage)
	{
		out << "Destroyed";
		return out;
	}

	out << (en.m_lowOilLevel ? "low oil level; " : "");

	out << (en.m_engineIsMelted ? "engine is melted; " : "");

	out << (en.m_isDirty ? "engine is dirty; " : "");

	out << (en.m_batteryIsDischarghed ? "discharged battery; " : "");

	return out;
}

Engine& Engine::operator=(const Engine& other)
{
	if (this != &other)
	{
		m_lowOilLevel = other.m_lowOilLevel;
		m_engineIsMelted = other.m_engineIsMelted;
		m_isDirty = other.m_isDirty;
		m_hasExtremeDamage = other.m_hasExtremeDamage;
		m_batteryIsDischarghed = other.m_batteryIsDischarghed;
	}
	return *this;
}	