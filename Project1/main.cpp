#include <iostream>
#include <random>
#include <time.h>

#include "autoshop.h"


int main()
{
	srand(time(0));

	AutoShop a;
	
	a.set_manHourCost(50);
	a.set_brakePadFrontCost(100);
	a.set_brakePadRearCost(50);
	a.set_brakeDiscCost(100);
	a.set_tireCost(350);
	a.set_wheelAlignmentCost(100);
	a.set_oilCost(60);
	a.set_cleaningProductsCost(100);
	a.set_batteryCost(200);
	a.set_paintCost(250);
	a.set_motoChainCost(200);
	a.set_bikeChainCost(100);
	a.set_aluminiumCost(7) ;
	a.set_steelCost(6);
	a.set_screwCost(3);
	a.set_rivetCost(4);
	a.set_wireCost(4);
	a.set_lubricantCost(10);
	a.set_lightbulbCost(75);
	a.set_emissionSensorCost(350);

	a.mainMenu();
 
}