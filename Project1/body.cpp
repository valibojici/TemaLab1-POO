#include "body.h"
#include "autoshop.h"



std::string Body::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return "Destroyed";
	}

	std::string diagnostic = "";
	std::string prefix[] = { "", "slight", "medium", "major" };

	if (m_wingFrontLeft)
	{
		diagnostic += prefix[m_wingFrontLeft] + " dent front left wing; ";
	}
	if (m_wingFrontRight)
	{
		diagnostic += prefix[m_wingFrontRight] + " dent front right wing; ";
	}
	if (m_wingRearLeft)
	{
		diagnostic += prefix[m_wingRearLeft] + " dent rear left wing; ";
	}
	if (m_wingRearRight)
	{
		diagnostic += prefix[m_wingRearRight] + " dent rear right wing; ";
	}
	if (m_bumper)
	{
		diagnostic += prefix[m_bumper] + " dent bumper; ";
	}
	if (m_hood)
	{
		diagnostic += prefix[m_hood] + " dent hood; ";
	}
	if (m_rust)
	{
		diagnostic += prefix[m_rust] + " rust problem; ";
	}
	return diagnostic == "" ? "No problems" : diagnostic;
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
		cost += m_wingFrontLeft / 3.0 * shop.get_aluminiumCost() * 10;
		cost += m_wingFrontRight / 3.0 * shop.get_aluminiumCost() * 10;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0 * shop.get_screwCost() * 6;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0 * shop.get_rivetCost() * 4;
	}
	if (m_wingRearLeft || m_wingRearRight)
	{
		cost += m_wingFrontLeft / 3.0 * (shop.get_aluminiumCost() * 7 + shop.get_steelCost() * 3);
		cost += m_wingFrontRight / 3.0 * (shop.get_aluminiumCost() * 7 + shop.get_steelCost() * 3);
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0 * shop.get_screwCost() * 8;
		cost += (m_wingFrontRight + m_wingFrontLeft) / 3.0 * shop.get_rivetCost() * 6;
	}
	if (m_bumper)
	{
		cost += m_bumper / 3.0 * (shop.get_screwCost() * 20 + shop.get_steelCost() * 15);
	}
	if (m_hood)
	{
		cost += m_hood / 3.0 * (shop.get_screwCost() * 10 + shop.get_rivetCost() * 6 + shop.get_aluminiumCost() * 20);
	}
	if (m_rust)
	{
		cost += shop.get_cleaningProductsCost() * 2;
		cost += m_rust * shop.get_paintCost() * 4;
		if (m_rust >= 2)
		{
			cost += shop.get_cleaningProductsCost() * 2;
			cost += shop.get_steelCost() * 12 + shop.get_aluminiumCost() * 10 + shop.get_screwCost() * 12;
		}
	}
	return round(cost * 100.0) / 100;
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
			int condition = 0;
			std::cout << "Enter condition 0(perfect) - 3(very bad): ";
			std::cin >> condition;
			condition = std::min(3, condition);
			condition = std::max(0, condition);

			switch (option)
			{
			case 1: m_wingFrontLeft = condition;
				break;
			case 2: m_wingFrontRight = condition;
				break;
			case 3: m_wingRearLeft = condition;
				break;
			case 4: m_wingRearRight = condition;
				break;
			case 5: m_hood = condition;
				break;
			case 6: m_bumper = condition;
				break;
			case 7: m_rust = condition;
				break;
			}
		}
		else if (option == 8)
		{
			m_hasExtremeDamage = true;
		}
	} while (option != 0);
}