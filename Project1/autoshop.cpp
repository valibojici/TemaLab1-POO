#include "autoshop.h"

AutoShop::AutoShop()
{
	m_car.set_shop(*this);
	m_moto.set_shop(*this);
	m_bike.set_shop(*this);
}

AutoShop::AutoShop(const AutoShop& other) :
	m_manHourCost(other.m_manHourCost),
	m_brakePadFrontCost(other.m_brakePadFrontCost),
	m_brakePadRearCost(other.m_brakePadRearCost),
	m_brakeDiscCost(other.m_brakeDiscCost),
	m_tireCost(other.m_tireCost),
	m_wheelAlignmentCost(other.m_wheelAlignmentCost),
	m_oilCost(other.m_oilCost),
	m_cleaningProductsCost(other.m_cleaningProductsCost),
	m_batteryCost(other.m_batteryCost),
	m_paintCost(other.m_paintCost),
	m_motoChainCost(other.m_motoChainCost),
	m_bikeChainCost(other.m_bikeChainCost),
	m_aluminiumCost(other.m_aluminiumCost),
	m_steelCost(other.m_steelCost),
	m_screwCost(other.m_screwCost),
	m_rivetCost(other.m_rivetCost),
	m_wireCost(other.m_wireCost),
	m_lubricantCost(other.m_lubricantCost),
	m_lightbulbCost(other.m_lightbulbCost),
	m_emissionSensorCost(other.m_emissionSensorCost),
	m_car(other.m_car),
	m_bike(other.m_bike),
	m_moto(other.m_moto),
	m_history(other.m_history) {}

void AutoShop::mainMenu()
{
	int option;
	std::string client = "";
	do {
		std::cout << "	Main Menu:\n - 1. Create car\n - 2. Create motorcycle\n - 3. Create bicycle\n - 4. View history\n - 0. Exit.\n";
		std::cin >> option;
		if (option >= 1 && option <= 3)
		{
			std::cout << "Client name: ";
			std::cin.get();
			std::getline(std::cin, client);
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
			if (!m_history.size())
			{
				std::cout << "No history\n";
			}
			for (unsigned i = 0; i < m_history.size(); ++i)
			{
				std::cout << i + 1 << ": " << m_history[i] << '\n';
			}
		}
		
	} while (option != 0);
}


AutoShop& AutoShop::operator+=(std::pair<std::string, Car> info)
{
	m_history.push_back({info.first, info.second});
	return *this;
}

AutoShop& AutoShop::operator+=(std::pair<std::string, Moto> info)
{
	m_history.push_back({ info.first, info.second });
	return *this;
}

AutoShop& AutoShop::operator+=(std::pair<std::string, Bike> info)
{
	m_history.push_back({ info.first, info.second });
	return *this;
}

AutoShop& AutoShop::operator=(const AutoShop& other)
{
	if (this != &other)
	{
		m_manHourCost = other.m_manHourCost;
		m_brakePadFrontCost = other.m_brakePadFrontCost;
		m_brakePadRearCost = other.m_brakePadRearCost;
		m_brakeDiscCost = other.m_brakeDiscCost;
		m_tireCost = other.m_tireCost;
		m_wheelAlignmentCost = other.m_wheelAlignmentCost;
		m_oilCost = other.m_oilCost;
		m_cleaningProductsCost = other.m_cleaningProductsCost;
		m_batteryCost = other.m_batteryCost;
		m_paintCost = other.m_paintCost;
		m_motoChainCost = other.m_motoChainCost;
		m_bikeChainCost = other.m_bikeChainCost;
		m_aluminiumCost = other.m_aluminiumCost;
		m_steelCost = other.m_steelCost;
		m_screwCost = other.m_screwCost;
		m_rivetCost = other.m_rivetCost;
		m_wireCost = other.m_wireCost;
		m_lubricantCost = other.m_lubricantCost;
		m_lightbulbCost = other.m_lightbulbCost;
		m_emissionSensorCost = other.m_emissionSensorCost;
		m_car = other.m_car;
		m_moto = other.m_moto;
		m_bike = other.m_bike;
		m_history = other.m_history;
	}
	return	*this;
}

AutoShop::~AutoShop()
{
	//std::cout << "AutoShop D\n";
}