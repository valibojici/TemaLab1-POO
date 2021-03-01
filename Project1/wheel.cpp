#include "wheel.h"
#include "autoshop.h"

std::string Wheel::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return std::string("Extreme Damage");
	}

	std::string diagnostic = "";
	if (m_brakeDisc)
	{
		diagnostic += "damaged brake disc; ";
	}
	if (m_brakePad)
	{
		diagnostic += "damaged brake pad; ";
	}
	if (m_flatTire)
	{
		diagnostic += "flat tire; ";
	}
	if (m_alignment > 0)
	{
		if (m_alignment == 1)
		{
			diagnostic += "slight misalignment; ";
		}
		else if (m_alignment == 2)
		{
			diagnostic += "medium misalignment; ";
		}
		else
		{
			diagnostic += "major misalignment; ";
		}
	}
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Wheel::getRepairCost(const AutoShop& shop, bool isFrontWheel)
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_brakePad)
	{
		cost += isFrontWheel * shop.get_brakePadFrontCost();
		cost += !isFrontWheel * shop.get_brakePadRearCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
		cost += shop.get_aluminiumCost() * 4;
	}
	if (m_brakeDisc)
	{
		cost += shop.get_brakeDiscCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
		cost += shop.get_steelCost() * 5;
	}
	if (m_flatTire)
	{
		cost += shop.get_tireCost() * m_flatTire;
		cost += shop.get_screwCost() * 5;
	}
	if (m_alignment)
	{
		cost += m_alignment * shop.get_wheelAlignmentCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_lubricantCost();
	}
	return round(cost * 100.0) / 100;
}

void Wheel::wear()
{
	m_brakePad = rand() % 2;
	m_brakeDisc = rand() % 2;
	m_flatTire = rand() % 2;
	m_alignment = rand() % 4;
	if (m_brakeDisc && m_brakePad && m_flatTire && m_alignment >= 2)
	{
		m_hasExtremeDamage = true;
	}
}