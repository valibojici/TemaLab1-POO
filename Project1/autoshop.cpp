#include "autoshop.h"

float AutoShop::getCostCar()
{
	float cost = 0;
	cost += m_car.get_wheelFL().getRepairCost(*this, true);
	cost += m_car.get_wheelFR().getRepairCost(*this, true);
	cost += m_car.get_wheelRL().getRepairCost(*this, false);
	cost += m_car.get_wheelRR().getRepairCost(*this, false);
	cost += m_car.get_emissions().getRepairCost(*this);
	cost += m_car.get_headlightFL().getRepairCost(*this);
	cost += m_car.get_headlightFR().getRepairCost(*this);
	cost += m_car.get_brakelightRL().getRepairCost(*this);
	cost += m_car.get_brakelightRR().getRepairCost(*this);
	cost += m_car.get_engine().getRepairCost(*this);
	cost += m_car.get_body().getRepairCost(*this);
	return cost;
}



// TO DO:
void AutoShop::mainMenu()
{

}

void AutoShop::carMenu()
{

}

void AutoShop::bikeMenu()
{

}

void AutoShop::motoMenu()
{

}