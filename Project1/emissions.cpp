#include "emissions.h"
#include "autoshop.h"

float Emissions::getRepairCost(const AutoShop& shop)
{
	float cost = 0;
	if (m_isBurningOil)
	{
		cost += m_isBurningOil * shop.get_oilCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
	}
	if (m_isMadeBefore2000)
	{
		cost += m_isMadeBefore2000 * shop.get_emissionSensorCost();
		cost += shop.get_screwCost() * 12;
		cost += shop.get_aluminiumCost() * 5;
	}
	return round(cost * 100) / 100;
}

std::string Emissions::diagnose()
{
	std::string diagnostic = "";
	if (m_isBurningOil)
	{
		diagnostic += "is burning oil\n";
	}
	if (m_isMadeBefore2000)
	{
		diagnostic += "is made before 2000\n";
	}
	return diagnostic != "" ? "No problems" : diagnostic;
}


void Emissions::wear()
{
	m_isBurningOil = rand() % 2;
	m_isMadeBefore2000 = rand() % 2;
}
