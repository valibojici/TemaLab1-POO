#include "light.h"
#include "autoshop.h"

void Light::wear() {
	m_isBroken = rand() % 2;
	m_isDisconnected = rand() % 2;
}

float Light::getRepairCost(const AutoShop& shop)
{
	float cost = 0;
	if (m_isBroken)
	{
		cost += shop.get_lightbulbCost();
		cost += shop.get_screwCost() * 8;
	}
	if (m_isDisconnected)
	{
		cost += shop.get_wireCost() * 4;
		cost += shop.get_screwCost() * 5;
	}
	return float(cost * 100) / 100;
}

std::string Light::diagnose()
{
	std::string diagnostic = "lamp";
	if (m_isBroken)
	{
		diagnostic = "broken " + diagnostic;
	}
	if (m_isDisconnected)
	{
		diagnostic = "disconnected " + diagnostic;
	}
	return diagnostic == "lamp" ? "No problem" : diagnostic;
}
