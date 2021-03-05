#include "handlebars.h"
#include "autoshop.h"

void Handlebars::set_alignment(unsigned value)
{
	m_alignment = value > 3 ? 3 : value;
}


void Handlebars::wear()
{
	m_isShaking = rand() % 2;
	m_alignment = rand() % 4;
}

std::ostream& operator<<(std::ostream& out, const Handlebars& hand)
{
	std::string prefix[] = { "", "slight", "medium", "major" };
	if (hand.m_isShaking || hand.m_alignment)
	{
		out << (hand.m_isShaking ? "shaking " : "");
		out << (hand.m_alignment ? prefix[hand.m_alignment] + " misaligned " : "");
		out << "handlebars";
	}
	return out;
}

float Handlebars::getRepairCost(const AutoShop& shop)
{
	float cost = 0;
	if (m_isShaking)
	{
		cost += shop.get_manHourCost() * 1;
		cost += shop.get_screwCost() * 10 + shop.get_steelCost() * 5;
	}
	if (m_alignment)
	{
		cost += shop.get_manHourCost() * 1;
		cost += shop.get_aluminiumCost() * 4 + shop.get_screwCost() * 5;
	}
	return round(cost * 100) / 100;
}

void Handlebars::menu()
{
	int option = 0;
	do {
		std::cout << "Handlebars menu:\n";
		std::cout << " - 1. Shaking handlebars\n - 2. Misaligned handlebars\n - 3. Back\n";
		std::cin >> option;
		if (option == 1)
		{
			this->set_isShaking(true);
		}
		if (option == 2)
		{
			unsigned value;
			std::cout << "Enter condition (0 perfect - 3 very bad): ";
			std::cin >> value;
			this->set_alignment(value);
		}
	} while (option != 0);
}