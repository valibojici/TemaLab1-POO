#include "handlebars.h"
#include "autoshop.h"

void Handlebars::wear()
{
	m_isShaking = rand() % 2;
	m_alignment = rand() % 4;
}

std::string Handlebars::diagnose()
{
	std::string diagnostic = "handlebars";
	std::string prefix[] = { "", "slight", "medium", "major" };
	if (m_isShaking)
	{
		diagnostic = "shaking " + diagnostic;
	}
	if (m_alignment)
	{
		diagnostic = prefix[m_alignment] + " misaligned " + diagnostic;
	}
	return diagnostic == "handlebars" ? "No problems" : diagnostic;
}

float Handlebars::getRepairCost(const AutoShop& shop)
{
	float cost = 0;
	if (m_isShaking)
	{
		cost += shop.get_screwCost() * 10 + shop.get_steelCost() * 5;
	}
	if (m_alignment)
	{
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
			m_isShaking = true;
		}
		if (option == 2)
		{
			int value;
			std::cout << "Enter condition (0 perfect - 3 very bad): ";
			std::cin >> value;
			value = std::min(value, 3);
			value = std::max(value, 0);
			m_alignment = value;
		}
	} while (option != 0);
}