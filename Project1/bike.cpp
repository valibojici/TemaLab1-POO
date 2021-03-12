#include "bike.h"

Bike::Bike(const Bike& other) :
	m_wheelFront(other.m_wheelFront),
	m_wheelRear(other.m_wheelRear),
	m_chain(other.m_chain),
	m_handlebars(other.m_handlebars),
	m_shop(other.m_shop) {}


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

float Bike::getRepairCost() const
{
	return m_wheelFront.getRepairCost(*m_shop, true) +
		m_wheelRear.getRepairCost(*m_shop, false) +
		m_chain.getRepairCost(*m_shop, true) +
		m_handlebars.getRepairCost(*m_shop);
}

std::ostream& operator<<(std::ostream& out, const Bike& bike)
{
	float cost = 0;
	float total = bike.getRepairCost();

	// front wheel
	cost = bike.get_wheelFront().getRepairCost(*bike.m_shop, true);

	if (cost || bike.get_wheelFront().get_hasExtremeDamage())
	{
		out << "-> Front wheel: " << cost << " $\n" << bike.get_wheelFront() << "\n\n";
	}

	// rear wheel
	cost = bike.get_wheelRear().getRepairCost(*bike.m_shop, false);

	if (cost || bike.get_wheelRear().get_hasExtremeDamage())
	{
		out << "-> Rear wheel: " << cost << " $\n" << bike.get_wheelRear() << "\n\n";
	}

	// handlebars
	cost = bike.get_handlebars().getRepairCost(*bike.m_shop);

	if (cost) 
	{
		out << "-> Handlebars: " << cost << " $\n" << bike.get_handlebars() << "\n\n";
	}

	// chain
	cost = bike.get_chain().getRepairCost(*bike.m_shop, true);

	if (cost)
	{
		out << "-> Chain: " << cost << " $\n" << bike.get_chain() << "\n\n";
	}
 
	out << "TOTAL: " << total << " $\n";
	return out;
}

Bike& Bike::operator=(const Bike& other)
{
	if (this != &other)
	{
		m_wheelFront = other.m_wheelFront;
		m_wheelRear = other.m_wheelRear;
		m_handlebars = other.m_handlebars;
		m_chain = other.m_chain;
		m_shop = other.m_shop;
	}
	return *this;
}

Bike::~Bike()
{
	//std::cout << "Bike D\n";
}