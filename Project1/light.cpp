#include "light.h"
#include "autoshop.h"

Light::Light(bool isBroken, bool isDisconnected) : 
	m_isBroken(isBroken), 
	m_isDisconnected(isDisconnected) {}

Light::Light(const Light& other) :
	m_isBroken(other.m_isBroken),
	m_isDisconnected(other.m_isDisconnected) {}

float Light::getRepairCost(const AutoShop& shop) const
{
	float cost = 0;
	if (m_isBroken)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_lightbulbCost();
		cost += shop.get_screwCost() * 8;
	}
	if (m_isDisconnected)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_wireCost() * 4;
		cost += shop.get_screwCost() * 5;
	}
	return float(cost * 100) / 100;
}

void Light::wear() {
	m_isBroken = rand() % 2;
	m_isDisconnected = rand() % 2;
}

void Light::menu()
{
	int option = 0;
	do {
		std::cout << "	Light Menu:\n - 1. Break lightbulb\n - 2. Disconnect\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: this->set_isBroken(true);
			break;
		case 2: this->set_isDisconnected(true);
			break;
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out, const Light& light)
{
	if (light.m_isBroken || light.m_isDisconnected)
	{
		out << (light.m_isBroken ? "broken " : "");
		out << (light.m_isDisconnected ? "disconnected " : "");
		out << "lamp";
	}
	return out;
}

Light& Light::operator=(const Light& other)
{
	if (this != &other)
	{
		m_isBroken = other.m_isBroken;
		m_isDisconnected = other.m_isDisconnected;
	}
	return* this;
}

Light::~Light()
{
	//std::cout << "Light D\n";
}