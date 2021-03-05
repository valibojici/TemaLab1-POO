#include "wheel.h"
#include "autoshop.h"

std::string Wheel::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return std::string("Destroyed");
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
	m_hasExtremeDamage = !bool(rand() % 8);
}

void Wheel::menu()
{
	int option = 0;
	do {
		std::cout << "	Wheel Menu:\n - 1. Damage Brake Pad\n - 2. Damage Brake Disc\n - 3. Damage Tire\n - 4. Wheel alignment\n - 5. Destroy wheel\n - 0. Back\n";
		std::cin >> option;
		if (option == 4)
		{
			int align = 0;
			std::cout << "Enter alignment value (0 aligned - 3 major misalignment): ";
			std::cin >> align;
			align = std::min(align, 3);
			align = std::max(0, align);
			m_alignment = align;
		}
		else
		{
			switch (option)
			{
			case 1: m_brakePad = true;
				break;
			case 2: m_brakeDisc = true;
				break;
			case 3: m_flatTire = true;
				break;
			case 5: m_hasExtremeDamage = true;
				break;
			}
		}
	} while (option != 0);
}