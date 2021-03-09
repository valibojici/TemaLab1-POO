#include "wheel.h"
#include "autoshop.h"

Wheel::Wheel(bool brakePad, bool brakeDisc, bool m_flatTire, int alignment, bool extremeDamage): 
	m_brakePad(brakePad), 
	m_brakeDisc(brakeDisc), 
	m_flatTire(m_flatTire),
	m_alignment(alignment),
	m_hasExtremeDamage(extremeDamage) {}

Wheel::Wheel(const Wheel& other):
	m_brakePad(other.m_brakePad),
	m_brakeDisc(other.m_brakeDisc),
	m_flatTire(other.m_flatTire),
	m_alignment(other.m_alignment),
	m_hasExtremeDamage(other.m_hasExtremeDamage) {}

void Wheel::set_alignment(unsigned value)
{
	m_alignment = value > 3 ? 3 : value;
}

float Wheel::getRepairCost(const AutoShop& shop, bool isFrontWheel) const
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_brakePad)
	{
		cost += shop.get_manHourCost() * 1;
		cost += isFrontWheel * shop.get_brakePadFrontCost();
		cost += !isFrontWheel * shop.get_brakePadRearCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
		cost += shop.get_aluminiumCost() * 4;
	}
	if (m_brakeDisc)
	{
		cost += shop.get_manHourCost() * 1;
		cost += shop.get_brakeDiscCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_rivetCost() * 5;
		cost += shop.get_steelCost() * 5;
	}
	if (m_flatTire)
	{
		cost += shop.get_manHourCost() * 0.2f;
		cost += shop.get_tireCost() * m_flatTire;
		cost += shop.get_screwCost() * 5;
	}
	if (m_alignment)
	{
		cost += shop.get_manHourCost() * 1;
		cost += m_alignment * shop.get_wheelAlignmentCost();
		cost += shop.get_screwCost() * 10;
		cost += shop.get_lubricantCost();
	}
	return round(cost * 100.0f) / 100;
}

void Wheel::wear()
{
	m_brakePad = rand() % 2;
	m_brakeDisc = rand() % 2;
	m_flatTire = rand() % 2;
	m_alignment = rand() % 4;
	m_hasExtremeDamage = !bool(rand() % 8);
}

void Wheel::menu()
{
	int option = 0;
	do {
		std::cout << "	Wheel Menu:\n - 1. Damage Brake Pad\n - 2. Damage Brake Disc\n - 3. Damage Tire\n - 4. Wheel alignment\n - 5. Destroy wheel\n - 0. Back\n";
		std::cin >> option;
		if (option == 4)
		{
			unsigned value = 0;
			std::cout << "Enter alignment value (0 aligned - 3 major misalignment): ";
			std::cin >> value;
			this->set_alignment(value);
		}
		else
		{
			switch (option)
			{
			case 1: this->set_brakePad(true);
				break;
			case 2: this->set_brakeDisc(true);
				break;
			case 3: this->set_flatTire(true);
				break;
			case 5: this->set_hasExtremeDamage(true);
				break;
			}
		}
	} while (option != 0);
}

std::ostream& operator<<(std::ostream& out, const Wheel& w)
{
	if (w.m_hasExtremeDamage)
	{
		out << "Destroyed";
		return out;
	}
	std::string prefix[] = { "", "slight", "medium", "major" };

	out << (w.m_brakeDisc ? "damaged brake disc; " : "");

	out << (w.m_brakePad ? "damaged brake pad; " : "");

	out << (w.m_flatTire ? "flat tire; " : "");

	out << (w.m_alignment ? prefix[w.m_alignment] + " misaligment; " : "");

	return out;
}

Wheel& Wheel::operator=(const Wheel& other)
{
	if (this != &other)
	{
		m_brakePad = other.m_brakePad;
		m_brakeDisc = other.m_brakeDisc;
		m_flatTire = other.m_flatTire;
		m_alignment = other.m_alignment;
		m_hasExtremeDamage = other.m_hasExtremeDamage;
	}
	return *this;
}