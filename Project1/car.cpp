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
	float total = 0, aux = 0;
	
	out << "\n-> Engine:\n" << car.get_engine().diagnose() << '\n';
	aux = car.get_engine().getRepairCost(*car.m_shop);
	out << "Cost : " << aux << '\n';

	out << "\n-> Front Left Headlight:\n" << car.get_headlightFL().diagnose() << '\n';
	out << "\n-> Front Right Headlight:\n" << car.get_headlightFR().diagnose() << '\n';
	out << "\n-> Rear Left Brakelight:\n" << car.get_brakelightRL().diagnose() << '\n';
	out << "\n-> Rear Right Brakelight:\n" << car.get_brakelightRR().diagnose() << '\n';

	out << "\n-> Body:\n" << car.get_body().diagnose() << '\n';

	out << "\n-> Front Left Wheel:\n" << car.get_wheelFL().diagnose() << '\n';
	out << "\n-> Front Right Wheel:\n" << car.get_wheelFR().diagnose() << '\n';
	out << "\n-> Rear Left Wheel:\n" << car.get_wheelRL().diagnose() << '\n';
	out << "\n-> Rear Right Wheel:\n" << car.get_wheelRR().diagnose() << '\n';

	out << "\n-> Emissions:\n" << car.get_emissions().diagnose() << '\n';
	return out;
}