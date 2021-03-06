#pragma once
#include <string>
#include <iostream>
#include "engine.h"
#include "light.h"
#include "wheel.h"
#include "chain.h"
#include "emissions.h"
#include "handlebars.h"

class AutoShop;

class Moto
{
private:
	Engine m_engine;
	Light m_headLight, m_brakeLight;
	Wheel m_wheelFront, m_wheelRear;
	Chain m_chain;
	Handlebars m_handlebars;
	Emissions m_emissions;
	const AutoShop* m_shop;

public:
	Moto() : m_shop(0) {}
	Moto(const AutoShop& shop) : m_shop(&shop) {}

	void set_engine(Engine engine) { m_engine = engine; }
	void set_headLight(Light light) { m_headLight = light; }
	void set_brakeLight(Light light) { m_brakeLight = light; }
	void set_wheelFront(Wheel wheel) { m_wheelFront = wheel; }
	void set_wheelRear(Wheel wheel) { m_wheelRear = wheel; }
	void set_chain(Chain chain) { m_chain = chain; }
	void set_handlebars(Handlebars handle) { m_handlebars = handle; }
	void set_emissions(Emissions emissions) { m_emissions = emissions; }
	void set_shop(const AutoShop& shop) { m_shop = &shop; }

	Engine get_engine() const {return m_engine; }
	Light get_headLight() const {return m_headLight; }
	Light get_brakeLight() const {return m_brakeLight; }
	Wheel get_wheelFront() const { return m_wheelFront; }
	Wheel get_wheelRear() const { return m_wheelRear; }
	Chain get_chain() const { return m_chain; }
	Handlebars get_handlebars() const { return m_handlebars; }
	Emissions get_emissions() const { return m_emissions; }

	void wear();

	void menu();

	friend std::ostream& operator<<(std::ostream& out, const Moto& moto);

	float getRepairCost() const;
};

