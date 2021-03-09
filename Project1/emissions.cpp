#include "emissions.h"
#include "autoshop.h"

Emissions::Emissions(bool isMadeBefore2000, bool isBurningOil):
	m_isMadeBefore2000(isMadeBefore2000), 
	m_isBurningOil(isBurningOil) {}

Emissions::Emissions(const Emissions& other) :
	m_isMadeBefore2000(other.m_isMadeBefore2000),
	m_isBurningOil(other.m_isBurningOil) {}

float Emissions::getRepairCost(const AutoShop& shop) const
{
	float cost = 0;
	if (m_isBurningOil)
	{
		cost += shop.get_manHourCost() * 1.5f;
		cost += m_isBurningOil * shop.get_oilCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
	}
	if (m_isMadeBefore2000)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += m_isMadeBefore2000 * shop.get_emissionSensorCost();
		cost += shop.get_screwCost() * 12;
		cost += shop.get_aluminiumCost() * 5;
	}
	return round(cost * 100) / 100;
}


void Emissions::wear()
{
	m_isBurningOil = rand() % 2;
	m_isMadeBefore2000 = rand() % 2;
}

void Emissions::menu()
{
	int option = 0;
	do {
		std::cout << "	Emissions menu\n" << " - 1. Burn Oil\n - 2. Made before 2000\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: this->set_isBurningOil(true);
			break;
		case 2: this->set_isMadeBefore2000(true);
			break;
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out, const Emissions& em)
{
	out << (em.m_isBurningOil ? "is burning oil; " : "");
	out << (em.m_isMadeBefore2000 ? "is made before 2000; " : "");
	return out;
}

Emissions& Emissions::operator=(const Emissions& other)
{
	if (this != &other)
	{
		m_isMadeBefore2000 = other.m_isMadeBefore2000;
		m_isBurningOil = other.m_isBurningOil;
	}
	return *this;
}