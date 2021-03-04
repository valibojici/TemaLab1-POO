#include "bike.h"

void Bike::wear()
{
	m_wheelFront.wear();
	m_wheelRear.wear();
	m_chain.wear();
	m_handlebars.wear();
}

void Bike::menu()
{	
	int option = 0;
	do {
		std::cout << "	Bike menu:\n";
		std::cout << " - 1. Front wheel problems\n";
		std::cout << " - 2. Rear wheel problems\n";
		std::cout << " - 3. Chain problems\n";
		std::cout << " - 4. Handlebars problems\n";
		std::cout << " - 5. Random problems\n";
		std::cout << " - 6. Diagnose\n";
		std::cout << " - 0. Back\n";

		std::cin >> option;
		switch (option)
		{
		case 1:
			m_wheelFront.menu();
			break;
		case 2:
			m_wheelRear.menu();
			break;
		case 3:
			m_chain.menu();
			break;
		case 4:
			m_handlebars.menu();
			break;
		case 5:
			this->wear();
			break;
		case 6:
			std::cout << (*this) << '\n';
			break;
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out, const Bike& bike)
{
	bool ok = true;
	float cost = 0;
	float total = 0;

	cost = bike.get_wheelFront().getRepairCost(*bike.m_shop, true);
	total += cost;
	if (cost)
	{
		out << "-> Front wheel: " << cost << " $\n";
		out << bike.get_wheelFront().diagnose() << '\n';
	}

	cost = bike.get_wheelRear().getRepairCost(*bike.m_shop, false);
	total += cost;
	if (cost)
	{
		out << "-> Rear wheel: " << cost << " $\n";
		out << bike.get_wheelRear().diagnose() << '\n';
	}

	cost = bike.get_handlebars().getRepairCost(*bike.m_shop);
	total += cost;
	if (cost) 
	{
		out << "-> Handlebars: " << cost << " $\n";
		out << bike.get_handlebars().diagnose() << '\n';
	}

	cost = bike.get_chain().getRepairCost(*bike.m_shop, false);
	total += cost;
	if (cost)
	{
		out << "-> Chain: " << cost << " $\n";
		out << bike.get_chain().diagnose() << '\n';
	}
 
	if (total == 0)
	{
		out << "No problems\n";
	}
	else
	{
		out << "TOTAL : " << total << " $\n";
	}
	return out;
}