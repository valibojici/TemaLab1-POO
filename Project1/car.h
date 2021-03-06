#pragma once

#include <string>
#include <iostream>
#include "engine.h"
#include "wheel.h"
#include "emissions.h"
#include "light.h"
#include "body.h"
 
class AutoShop;

class Car {
private:
	Engine m_engine;
	Body m_body;
	Wheel m_wheelFL, m_wheelFR, m_wheelRL, m_wheelRR; // FL = front right RL = rear right
	Emissions m_emissions;
	Light m_headlightFL, m_headlightFR, m_brakelightRL, m_brakelightRR;
	const AutoShop* m_shop;
public:
	Car() : m_shop(0) {}
	Car(const AutoShop &shop) : m_shop(&shop) {}

	Engine get_engine() const { return m_engine; }
	Body get_body() const { return m_body; }
	Wheel get_wheelFL() const { return m_wheelFL; }
	Wheel get_wheelFR() const { return m_wheelFR; }
	Wheel get_wheelRL() const { return m_wheelRL; }
	Wheel get_wheelRR() const { return m_wheelRR; }
	Emissions get_emissions() const { return m_emissions; }
	Light get_headlightFL() const { return m_headlightFL; }
	Light get_headlightFR() const { return m_headlightFR; }
	Light get_brakelightRL() const { return m_brakelightRL; }
	Light get_brakelightRR() const { return m_brakelightRR; }


	void set_shop(const AutoShop& shop) { m_shop = &shop; }
	void set_engine(Engine value) { m_engine = value; }
	void set_body(Body value) { m_body = value; }
	void set_wheelFL(Wheel value) { m_wheelFL = value; }
	void set_wheelFR(Wheel value) { m_wheelFR = value; }
	void set_wheelRL(Wheel value) { m_wheelRL = value; }
	void set_wheelRR(Wheel value) { m_wheelRR = value; }
	void set_emissions(Emissions value) { m_emissions = value; }
	void set_headlightFL(Light value) { m_headlightFL = value; }
	void set_headlightFR(Light value) { m_headlightFR = value; }
	void set_brakelightRL(Light value) { m_brakelightRL = value; }
	void set_brakelightRR(Light value) { m_brakelightRR = value; }

	void wear(); 

	void menu();

	float getRepairCost() const;

	friend std::ostream& operator<<(std::ostream& out,const Car& car);
};