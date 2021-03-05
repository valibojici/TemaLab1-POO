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
	float cost = 0;
	float total = 0;

	// front wheel
	cost = bike.get_wheelFront().getRepairCost(*bike.m_shop, true);
	total += cost;
	if (cost || bike.get_wheelFront().get_hasExtremeDamage())
	{
		out << "-> Front wheel: " << cost << " $\n" << bike.get_wheelFront() << "\n\n";
	}

	// rear wheel
	cost = bike.get_wheelRear().getRepairCost(*bike.m_shop, false);
	total += cost;
	if (cost || bike.get_wheelRear().get_hasExtremeDamage())
	{
		out << "-> Rear wheel: " << cost << " $\n" << bike.get_wheelRear() << "\n\n";
	}

	// handlebars
	cost = bike.get_handlebars().getRepairCost(*bike.m_shop);
	total += cost;
	if (cost) 
	{
		out << "-> Handlebars: " << cost << " $\n" << bike.get_handlebars() << "\n\n";
	}

	// chain
	cost = bike.get_chain().getRepairCost(*bike.m_shop, false);
	total += cost;
	if (cost)
	{
		out << "-> Chain: " << cost << " $\n" << bike.get_chain() << "\n\n";
	}
 
	out << "\nTOTAL: " << total << " $\n";
	return out;
}