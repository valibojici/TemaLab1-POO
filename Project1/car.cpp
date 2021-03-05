#include "car.h"

void Car::wear()
{
	m_engine.wear();
	m_body.wear();
	m_wheelFL.wear();
	m_wheelFR.wear();
	m_wheelRL.wear();
	m_wheelRR.wear();
	m_headlightFL.wear();
	m_headlightFR.wear();
	m_brakelightRL.wear();
	m_brakelightRR.wear();
	m_emissions.wear();
}

void Car::menu()
{
	int option = 0;
	do {
		std::cout << "	Car Menu:\n";
		std::cout << " - 1. Engine problems\n";
		std::cout << " - 2. Front Left Headlight problems\n";
		std::cout << " - 3. Front Right Headlight problems\n";
		std::cout << " - 4. Rear Left Brakelight problems\n";
		std::cout << " - 5. Rear Right Brakelight problems\n";
		std::cout << " - 6. Front Left Wheel problems\n";
		std::cout << " - 7. Front Right Wheel problems\n";
		std::cout << " - 8. Rear Left Wheel problems\n";
		std::cout << " - 9. Rear Right Wheel problems\n";
		std::cout << " - 10. Emissions problems\n";
		std::cout << " - 11. Body problems\n";
		std::cout << " - 12. Random problems\n";
		std::cout << " - 13. Diagnose\n";
		std::cout << " - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: m_engine.menu();
			break;
		case 2: m_headlightFL.menu();
			break;
		case 3: m_headlightFR.menu();
			break;
		case 4: m_brakelightRL.menu();
			break;
		case 5: m_brakelightRR.menu();
			break;
		case 6: m_wheelFL.menu();
			break;
		case 7: m_wheelFR.menu();
			break;
		case 8: m_wheelRL.menu();
			break;
		case 9: m_wheelRR.menu();
			break;
		case 10: m_emissions.menu();
			break;
		case 11: m_body.menu();
			break;
		case 12: this->wear();
			break;
		case 13: std::cout << (*this) << '\n';
			break;
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out,const Car& car)
{
	float total = 0;
	float cost = 0;
	
	// engine
	cost = car.get_engine().getRepairCost(*car.m_shop);
	total += cost;
	if (cost || car.get_engine().get_hasExtremeDamage())
	{
		out << "-> Engine: " << cost << " $\n" << car.get_engine() << "\n\n";
	}

	// front left headlight
	cost = car.get_headlightFL().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Front Left Headlight: " << cost << " $\n" << car.get_headlightFL() << "\n\n";
	}
	
	// front right headlight
	cost = car.get_headlightFR().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Front Right Headlight: " << cost << " $\n" << car.get_headlightFR() << "\n\n";
	}

	// rear left brakelight
	cost = car.get_brakelightRL().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Rear Left Brakelight: " << cost << " $\n" << car.get_brakelightRL() << "\n\n";
	}

	// rear right brakelight
	cost = car.get_brakelightRR().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Rear Right Brakelight: " << cost << " $\n" << car.get_brakelightRR() << "\n\n";
	}
	
	// body
	cost = car.get_body().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Body: " << cost << " $\n" << car.get_body() << "\n\n";
	}

	// front left wheel
	cost = car.get_wheelFL().getRepairCost(*car.m_shop,true);
	total += cost;
	if (cost)
	{
		out << "-> Front Left Wheel: " << cost << " $\n" << car.get_wheelFL() << "\n\n";
	}

	// front right wheel
	cost = car.get_wheelFR().getRepairCost(*car.m_shop, true);
	total += cost;
	if (cost)
	{
		out << "-> Front Right Wheel: " << cost << " $\n" << car.get_wheelFR() << "\n\n";
	}

	// rear left wheel
	cost = car.get_wheelRL().getRepairCost(*car.m_shop, true);
	total += cost;
	if (cost)
	{
		out << "-> Rear Left Wheel: " << cost << " $\n" << car.get_wheelRL() << "\n\n";
	}

	// rear right wheel
	cost = car.get_wheelRR().getRepairCost(*car.m_shop, true);
	total += cost;
	if (cost)
	{
		out << "-> Rear Right Wheel: " << cost << " $\n" << car.get_wheelRR() << "\n\n";
	}

	// emissions
	cost = car.get_emissions().getRepairCost(*car.m_shop);
	total += cost;
	if (cost)
	{
		out << "-> Emissions: " << cost << " $\n" << car.get_emissions() << "\n\n";
	}
	
	out << "\nTOTAL: " << total << " $\n";

	return out;
}