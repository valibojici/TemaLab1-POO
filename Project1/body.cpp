#include "body.h"
#include "autoshop.h"

Body::Body(unsigned wingFR, unsigned wingFL, unsigned wingRL, unsigned wingRR, unsigned bumper, unsigned hood, unsigned rust, bool extremeDamage) :
	m_wingFrontRight(wingFR),
	m_wingFrontLeft(wingFL),
	m_wingRearLeft(wingRL),
	m_wingRearRight(wingRR),
	m_bumper(bumper),
	m_hood(hood),
	m_rust(rust),
	m_hasExtremeDamage(extremeDamage) {}

void Body::set_wingFrontLeft(unsigned value)
{
	m_wingFrontLeft = value > 3 ? 3 : value;
}

void Body::set_wingFrontRight(unsigned value)
{
	m_wingFrontRight = value > 3 ? 3 : value;
}

void Body::set_wingRearLeft(unsigned value)
{
	m_wingRearLeft = value > 3 ? 3 : value;
}

void Body::set_wingRearRight(unsigned value)
{ 
	m_wingRearRight = value > 3 ? 3 : value;
}

void Body::set_bumper(unsigned value)
{ 
	m_bumper = value > 3 ? 3 : value;;
}

void Body::set_hood(unsigned value) 
{
	m_hood = value > 3 ? 3 : value;;
}

void Body::set_rust(unsigned value) 
{ 
	m_rust = value > 3 ? 3 : value;;
}

std::ostream& operator<<(std::ostream& out, const Body& body)
{
	if (body.m_hasExtremeDamage)
	{
		out << "Destroyed";
		return out;
	}

	std::string prefix[] = { "", "slight", "medium", "major" };

	out << (body.m_wingFrontLeft ? prefix[body.m_wingFrontLeft] + " dent front left wing; " : "");

	out << (body.m_wingFrontRight ? prefix[body.m_wingFrontRight] + " dent front right wing; " : "");

	out << (body.m_wingRearLeft ? prefix[body.m_wingRearLeft] + " dent rear left wing; " : "");

	out << (body.m_wingRearRight ? prefix[body.m_wingRearRight] + " dent rear right wing; " : "");

	out << (body.m_bumper ? prefix[body.m_bumper] + " dent bumper; " : "");

	out << (body.m_hood ? prefix[body.m_hood] + " dent hood; " : "");

	out << (body.m_rust ? prefix[body.m_rust] + " rust problem; " : "");
 
	return out;
}

float Body::getRepairCost(const AutoShop& shop)
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_wingFrontLeft || m_wingFrontRight)
	{
		cost += shop.get_manHourCost() * 2;
		cost += m_wingFrontLeft / 3.0f * shop.get_aluminiumCost() * 10;
		cost += m_wingFrontRight / 3.0f * shop.get_aluminiumCost() * 10;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0f * shop.get_screwCost() * 6;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0f * shop.get_rivetCost() * 4;
	}
	if (m_wingRearLeft || m_wingRearRight)
	{
		cost += shop.get_manHourCost() * 2;
		cost += m_wingFrontLeft / 3.0f * (shop.get_aluminiumCost() * 7 + shop.get_steelCost() * 3);
		cost += m_wingFrontRight / 3.0f * (shop.get_aluminiumCost() * 7 + shop.get_steelCost() * 3);
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0f * shop.get_screwCost() * 8;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0f * shop.get_rivetCost() * 6;
	}
	if (m_bumper)
	{
		cost += shop.get_manHourCost() * 1;
		cost += m_bumper / 3.0f * (shop.get_screwCost() * 20 + shop.get_steelCost() * 15);
	}
	if (m_hood)
	{
		cost += shop.get_manHourCost() * 1;
		cost += m_hood / 3.0f * (shop.get_screwCost() * 10 + shop.get_rivetCost() * 6 + shop.get_aluminiumCost() * 20);
	}
	if (m_rust)
	{
		cost += shop.get_manHourCost() * m_rust * 1.5f;
		cost += shop.get_cleaningProductsCost() * 2;
		cost += m_rust * shop.get_paintCost() * 4;
		if (m_rust >= 2)
		{
			cost += shop.get_cleaningProductsCost() * 2;
			cost += shop.get_steelCost() * 12 + shop.get_aluminiumCost() * 10 + shop.get_screwCost() * 12;
		}
	}
	return round(cost * 100.0f) / 100;
}

void Body::wear()
{
	m_wingFrontLeft = rand() % 4;
	m_wingFrontRight = rand() % 4;
	m_wingRearLeft = rand() % 4;
	m_wingRearRight = rand() % 4;
	m_bumper = rand() % 4;
	m_hood = rand() % 4;
	m_rust = rand() % 4;
	m_hasExtremeDamage = !bool(rand() % 11);
}

void Body::menu()
{
	int option = 0;
	do {
		std::cout << "	Body Menu\n";
		std::cout << "- 1. Front Left Wing Condition\n";
		std::cout << "- 2. Front Right Wing Condition\n";
		std::cout << "- 3. Rear Left Wing Condition\n";
		std::cout << "- 4. Rear Right Wing Condition\n";
		std::cout << "- 5. Hood Condition\n";
		std::cout << "- 6. Bumper Condition\n";
		std::cout << "- 7. Rust Condition\n";
		std::cout << "- 8. Destroy Body\n";
		std::cout << "- 0. Back\n";
		std::cin >> option;
		if (option >= 1 && option <= 7)
		{
			unsigned condition = 0;
			std::cout << "Enter condition 0(perfect) - 3(very bad): ";
			std::cin >> condition;

			switch (option)
			{
			case 1:this->set_wingFrontLeft(condition);
				break;
			case 2: this->set_wingFrontRight(condition);
				break;
			case 3: this->set_wingRearLeft(condition);
				break;
			case 4: this->set_wingRearRight(condition);
				break;
			case 5: this->set_hood(condition);
				break;
			case 6: this->set_bumper(condition);
				break;
			case 7: this->set_rust(condition);
				break;
			}
		}
		else if (option == 8)
		{
			this->set_hasExtremeDamage(true);
		}
	} while (option != 0);
}