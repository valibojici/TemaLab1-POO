#include "chain.h"
#include "autoshop.h"

Chain::Chain(bool isBroken, bool isWornOut, bool isMissing):
	m_isBroken(isBroken),
	m_isWornOut(isWornOut),
	m_isMissing(isMissing) {}



std::ostream& operator<<(std::ostream& out, const Chain& chain)
{
	if (chain.m_isMissing)
	{
		out << "missing chain";
		return out;
	}

	if (chain.m_isBroken || chain.m_isWornOut)
	{
		out << (chain.m_isBroken ? "broken " : "");
		out << (chain.m_isWornOut ? "worn out " : "");
		out << "chain";
	}
	return out;
}

float Chain::getRepairCost(const AutoShop& shop, bool isBicycle) const
{
	float cost = 0;
	if (m_isWornOut || m_isMissing)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += isBicycle * shop.get_bikeChainCost() + !isBicycle * shop.get_motoChainCost();
		cost += shop.get_lubricantCost();
	}
	else if (m_isBroken)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_rivetCost() * 5 + shop.get_screwCost() * 10;
		cost += shop.get_lubricantCost();
	}

	return round(cost * 100) / 100;
}

void Chain::wear()
{
	m_isBroken = rand() % 2;
	m_isWornOut = rand() % 2;
	m_isMissing = !bool(rand() % 5);
}

void Chain::menu()
{
	
	int option = 0;
	do {
		std::cout << "	Chain menu:\n";
		std::cout << " - 1. Break chain\n - 2. Wear out chain\n - 3. Missing chain\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: this->set_isBroken(true);
			break;
		case 2: this->set_isWornOut(true);
			break;
		case 3: this->set_isMissing(true);
			break;
		}
	} while (option != 0);
}