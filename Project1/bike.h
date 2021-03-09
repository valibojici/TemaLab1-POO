#pragma once

#include <string>
#include <iostream>
#include "chain.h"
#include "wheel.h"
#include "handlebars.h"

class AutoShop;

class Bike
{
private:
	Wheel m_wheelFront, m_wheelRear;
	Chain m_chain;
	Handlebars m_handlebars;
	const AutoShop* m_shop;

public:
	Bike() : m_shop(nullptr) {}
	Bike(const AutoShop& shop) : m_shop(&shop) {}
	Bike(const Bike&);


	void set_wheelFront(Wheel wheel) { m_wheelFront = wheel; }
	void set_wheelRear(Wheel wheel) { m_wheelRear = wheel; }
	void set_chain(Chain chain) { m_chain = chain; }
	void set_handlebars(Handlebars handle) { m_handlebars = handle; }
	void set_shop(const AutoShop& shop) { m_shop = &shop; }

	Wheel get_wheelFront() const {return m_wheelFront; }
	Wheel get_wheelRear() const {return m_wheelRear; }
	Chain get_chain() const {return m_chain; }
	Handlebars get_handlebars() const {return m_handlebars; }

	void wear();
	void menu();
	float getRepairCost() const;
	Bike& operator=(const Bike&);

	friend std::ostream& operator<<(std::ostream&, const Bike&);
};

