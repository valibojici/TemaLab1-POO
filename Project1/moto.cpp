#include "moto.h"

void Moto::wear()
{
	m_engine.wear();
	m_headLight.wear();
	m_brakeLight.wear();
	m_wheelFront.wear();
	m_wheelRear.wear();
	m_chain.wear();
	m_emissions.wear();
	m_handlebars.wear();
}

void Moto::menu()
{
	int option = 0;
	do {
		std::cout << "	Moto Menu:\n";
		std::cout << " - 1. Engine problems\n";
		std::cout << " - 2. Headlight problems\n";
		std::cout << " - 3. Brakelight problems\n";
		std::cout << " - 4. Front Wheel problems\n";
		std::cout << " - 5. Rear Wheel problems\n";
		std::cout << " - 6. Chain problems\n";
		std::cout << " - 7. Handlebars problems\n";
		std::cout << " - 8. Emissions problems\n";
		std::cout << " - 9. Random damage\n";
		std::cout << " - 10. Diagnose\n";
		std::cout << " - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: m_engine.menu();
			break;
		case 2: m_headLight.menu();
			break;
		case 3: m_brakeLight.menu();
			break;
		case 4: m_wheelFront.menu();
			break;
		case 5: m_wheelRear.menu();
			break;
		case 6: m_chain.menu();
			break;
		case 7: m_handlebars.menu();
			break;
		case 8: m_emissions.menu();
			break;
		case 9: this->wear();
			break;
		case 10: std::cout << (*this) << '\n';
			break;
		}
	} while (option != 0);
}

std::ostream& operator<< (std::ostream& out, const Moto& moto)
{
	float cost = 0;
	float total = moto.getRepairCost();

	// engine
	cost = moto.get_engine().getRepairCost(*moto.m_shop);

	if(cost || moto.get_engine().get_hasExtremeDamage())
	{
		out << "-> Engine: " << cost << " $\n" << moto.get_engine() << "\n\n";
	}

	// headlight
	cost = moto.get_headLight().getRepairCost(*moto.m_shop);
	
	if (cost)
	{
		out << "-> Head light: " << cost << " $\n" << moto.get_headLight() << "\n\n";
	}

	// brakelight
	cost = moto.get_brakeLight().getRepairCost(*moto.m_shop);
	
	if (cost)
	{
		out << "-> Brake light: " << cost << " $\n" << moto.get_brakeLight() << "\n\n";
	}

	// front wheel
	cost = moto.get_wheelFront().getRepairCost(*moto.m_shop, true);
	
	if (cost || moto.get_wheelFront().get_hasExtremeDamage())
	{
		out << "-> Front wheel: " << cost << " $\n" << moto.get_wheelFront() << "\n\n";
	}

	// rear wheel
	cost = moto.get_wheelRear().getRepairCost(*moto.m_shop, false);
	
	if (cost || moto.get_wheelRear().get_hasExtremeDamage())
	{
		out << "-> Rear wheel: " << cost << " $\n" << moto.get_wheelRear() << "\n\n";
	}

	// handlebars
	cost = moto.get_handlebars().getRepairCost(*moto.m_shop);
	
	if (cost)
	{
		out << "-> Handlebars: " << cost << " $\n" << moto.get_handlebars() << "\n\n";
	}

	// chain
	cost = moto.get_chain().getRepairCost(*moto.m_shop, false);
	
	if (cost)
	{
		out << "-> Chain: " << cost << " $\n" << moto.get_chain() << "\n\n";
	}

	// emissions
	cost = moto.get_emissions().getRepairCost(*moto.m_shop);
	
	if (cost)
	{
		out << "-> Emissions: " << cost << " $\n" << moto.get_emissions() << "\n\n";
	}

	out << "\nTOTAL: " << total << " $\n";
	return out;
}

float Moto::getRepairCost() const
{
	return m_engine.getRepairCost(*m_shop) +
		m_headLight.getRepairCost(*m_shop) +
		m_brakeLight.getRepairCost(*m_shop) +
		m_wheelFront.getRepairCost(*m_shop, true) +
		m_wheelRear.getRepairCost(*m_shop, false) +
		m_chain.getRepairCost(*m_shop, false) +
		m_handlebars.getRepairCost(*m_shop) +
		m_emissions.getRepairCost(*m_shop);
}