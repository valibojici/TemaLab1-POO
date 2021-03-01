#include "engine.h"
#include "autoshop.h"


std::string Engine::diagnose()
{
	std::string diagnostic = "";
	if (m_lowOilLevel)
	{
		diagnostic += "low oil level; ";
	}
	if (m_engineIsMelted)
	{
		diagnostic += "engine is melted; ";
	}
	if (m_isDirty)
	{
		diagnostic += "engine is dirty; ";
	}
	if (m_batteryIsDischarghed)
	{
		diagnostic += "discharged battery; ";
	}
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Engine::getRepairCost(const AutoShop& shop)
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_engineIsMelted || m_lowOilLevel)
	{
		cost += shop.get_oilCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 4;
		cost += shop.get_lubricantCost() * 2;
	}
	if (m_isDirty)
	{
		cost += shop.get_cleaningProductsCost() * 5;
		cost += shop.get_screwCost() * 6;
		cost += shop.get_lubricantCost() * 2;
	}
	return round(cost * 100) / 100;
}

void Engine::wear()
{
	m_lowOilLevel = rand() % 2;
	m_engineIsMelted = rand() % 2;
	m_isDirty = rand() % 2;
	m_batteryIsDischarghed = rand() % 2;
	m_hasExtremeDamage = !bool(rand() % 10);
}