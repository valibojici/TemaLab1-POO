#pragma once
#include <iostream>

#include "car.h"
#include "moto.h"
#include "bike.h"

class AutoShop {
private:
	int m_brakePadFrontCost = 0;
	int m_brakePadRearCost = 0;
	int m_brakeDiscCost = 0;
	int m_tireCost = 0;
	int m_wheelAlignmentCost = 0;
	int m_oilCost = 0;
	int m_cleaningProductsCost = 0;
	int m_batteryCost = 0;
	int m_paintCost = 0;
	int m_motoChainCost = 0;
	int m_bikeChainCost = 0;
	int m_aluminiumCost = 0;
	int m_steelCost = 0;
	int m_screwCost = 0;
	int m_rivetCost = 0;
	int m_wireCost = 0;
	int m_lubricantCost = 0;
	int m_lightbulbCost = 0;
	int m_emissionSensorCost = 0;

	Car m_car;
	Bike m_bike;
	Moto m_moto;

public:
	AutoShop() { m_car.set_shop(*this); }

	void set_brakePadFrontCost(int value) { m_brakePadFrontCost = value; }
	void set_brakePadRearCost(int value) { m_brakePadRearCost = value; }
	void set_brakeDiscCost(int value) { m_brakeDiscCost = value; }
	void set_tireCost(int value) { m_tireCost = value; }
	void set_wheelAlignmentCost(int value) { m_wheelAlignmentCost = value; }
	void set_oilCost(int value) { m_oilCost = value; }
	void set_cleaningProductsCost(int value) { m_cleaningProductsCost = value; }
	void set_batteryCost(int value) { m_batteryCost = value; }
	void set_paintCost(int value) { m_paintCost = value; }
	void set_motoChainCost(int value) { m_motoChainCost = value; }
	void set_bikeChainCost(int value) { m_bikeChainCost = value; }
	void set_aluminiumCost(int value) { m_aluminiumCost = value; }
	void set_steelCost(int value) { m_steelCost = value; }
	void set_screwCost(int value) { m_screwCost = value; }
	void set_rivetCost(int value) { m_rivetCost = value; }
	void set_wireCost(int value) { m_wireCost = value; }
	void set_lubricantCost(int value) { m_lubricantCost = value; }
	void set_lightbulbCost(int value) { m_lightbulbCost = value; }
	void set_emissionSensorCost(int value) { m_emissionSensorCost = value; }

	void set_car(Car car) { m_car = car; }
	void set_bike(Bike bike) { m_bike = bike; }
	void set_moto(Moto moto) { m_moto = moto; }


	int get_brakePadFrontCost() const { return m_brakePadFrontCost; }
	int get_brakePadRearCost() const { return m_brakePadRearCost; }
	int get_brakeDiscCost() const { return m_brakeDiscCost; }
	int get_tireCost() const { return m_tireCost; }
	int get_wheelAlignmentCost() const { return m_wheelAlignmentCost; }
	int get_oilCost() const { return m_oilCost; }
	int get_cleaningProductsCost() const { return m_cleaningProductsCost; }
	int get_batteryCost() const { return m_batteryCost; }
	int get_paintCost() const { return m_paintCost; }
	int get_motoChainCost() const { return m_motoChainCost; }
	int get_bikeChainCost() const { return m_bikeChainCost; }
	int get_aluminiumCost() const { return m_aluminiumCost; }
	int get_steelCost() const { return m_steelCost; }
	int get_screwCost() const { return m_screwCost; }
	int get_rivetCost() const { return m_rivetCost; }
	int get_wireCost() const { return m_wireCost; }
	int get_lubricantCost() const { return m_lubricantCost; }
	int get_lightbulbCost() const { return m_lightbulbCost; }
	int get_emissionSensorCost() const { return m_emissionSensorCost; }

	Car get_car() const { return m_car; }
	Bike get_bike() const { return m_bike; }
	Moto get_moto() const { return m_moto; }

	float getCostCar();

	void mainMenu();

};
