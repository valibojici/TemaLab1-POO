#include "autoshop.h"

AutoShop::AutoShop()
{
	m_car.set_shop(*this);
	m_moto.set_shop(*this);
	m_bike.set_shop(*this);
}

void AutoShop::mainMenu()
{
	int option = 0;
	std::string client = "";
	do {
		std::cout << "	Main Menu:\n - 1. Create car\n - 2. Create motorcycle\n - 3. Create bicycle\n - 4. View history\n - 0. Exit.\n";
		std::cin >> option;
		if (option >= 1 && option <= 3)
		{
			std::cout << "Client name: ";
			std::cin >> client;
			switch (option)
			{
			case 1:
				m_car = Car(*this);
				m_car.menu();
				*this += std::pair<std::string, const Car>(client, m_car);
				break;
			case 2:
				m_moto = Moto(*this);
				m_moto.menu();
				*this += std::pair<std::string, const Moto>(client, m_moto);
				break;
			case 3:
				m_bike = Bike(*this);
				m_bike.menu();
				*this += std::pair<std::string, const Bike>(client, m_bike);
				break;
			}
		}
		else
		if (option == 4)
		{
			unsigned count = 1;
			for (auto& x : m_cars)
			{
				std::cout << (count++) << ". Client: " << x.first << " | Vehicle type: Car | Cost: " << x.second.getRepairCost() << "\n";
			}
			 
			for (auto& x : m_motos)
			{
				std::cout << (count++) << ". Client: " << x.first << " | Vehicle type: Moto | Cost: " << x.second.getRepairCost() << "\n";
			}

			for (auto& x : m_bikes)
			{
				std::cout << (count++) << ". Client: " << x.first << " | Vehicle type: Bike | Cost: " << x.second.getRepairCost() << "\n";
			}
		}
		
	} while (option != 0);
}


AutoShop& AutoShop::operator+=(std::pair<std::string, const Car> info)
{
	m_cars.push_back({ info.first,info.second });
	return *this;
}

AutoShop& AutoShop::operator+=(std::pair<std::string, const Moto> info)
{
	m_motos.push_back({ info.first,info.second });
	return *this;
}

AutoShop& AutoShop::operator+=(std::pair<std::string, const Bike> info)
{
	m_bikes.push_back({ info.first,info.second });
	return *this;
}