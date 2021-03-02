#pragma once

#include <string>
#include "engine.h"
#include "wheel.h"
#include "emissions.h"
#include "light.h"
#include "body.h"


class Car {
private:
	Engine m_engine;
	Body m_body;
	Wheel m_wheelFL, m_wheelFR, m_wheelRL, m_wheelRR; // FL = front right RL = rear right
	Emissions m_emissions;
	Light m_headlightFL, m_headlightFR, m_brakelightRL, m_brakelightRR;

public:
	Car() {}

	Engine get_engine() { return m_engine; }
	Body get_body() { return m_body; }
	Wheel get_wheelFL() { return m_wheelFL; }
	Wheel get_wheelFR() { return m_wheelFL; }
	Wheel get_wheelRL() { return m_wheelFL; }
	Wheel get_wheelRR() { return m_wheelFL; }
	Emissions get_emissions() { return m_emissions; }
	Light get_headlightFL() { return m_headlightFL; }
	Light get_headlightFR() { return m_headlightFR; }
	Light get_brakelightRL() { return m_brakelightRL; }
	Light get_brakelightRR() { return m_brakelightRR; }

	void set_engine(Engine value) { m_engine = value; }
	void set_body(Body value) { m_body = value; }
	void set_wheelFL(Wheel value) { m_wheelFL = value; }
	void set_wheelFR(Wheel value) { m_wheelFL = value; }
	void set_wheelRL(Wheel value) { m_wheelFL = value; }
	void set_wheelRR(Wheel value) { m_wheelFL = value; }
	void set_emissions(Emissions value) { m_emissions = value; }
	void set_headlightFL(Light value) { m_headlightFL = value; }
	void set_headlightFR(Light value) { m_headlightFR = value; }
	void set_brakelightRL(Light value) { m_brakelightRL = value; }
	void set_brakelightRR(Light value) { m_brakelightRR = value; }


	void dischargeBattery();
	void meltEngine();
	void lowerOilLevel();
	void dirtEngine();
	void destroyEngine();

	void misalignWheel(std::string pos, int value);
	void wearBrakeDisc(std::string pos);
	void wearBrakePad(std::string pos);
	void flatTire(std::string pos);
	void destroyWheel(std::string pos);
 
	void madeBefore2000();
	void burnOil();

	void damageWing(std::string pos, int value);
	void damageBumper(int value);
	void damageHood(int value);
	void rust(int value);
	void destroyBody();

	void breakLight(std::string pos);
	void disconnectLight(std::string pos);

	void wear(); 
};