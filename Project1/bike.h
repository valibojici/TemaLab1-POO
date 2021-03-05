#pragma once

#include <string>
#include <iostream>
#include "chain.h"
#include "wheel.h"
#include "handlebars.h"


class Bike
{
private:
	Wheel m_wheelFront, m_wheelRear;
	Chain m_chain;
	Handlebars m_handlebars;
	const AutoShop* m_shop;

public:
	void set_wheelFront(Wheel wheel) { m_wheelFront = wheel; }
	void set_wheelRear(Wheel wheel) { m_wheelRear = wheel; }
	void set_chain(Chain chain) { m_chain = chain; }
	void set_handlebars(Handlebars handle) { m_handlebars = handle; }

	Wheel get_wheelFront() const {return m_wheelFront; }
	Wheel get_wheelRear() const {return m_wheelRear; }
	Chain get_chain() const {return m_chain; }
	Handlebars get_handlebars() const {return m_handlebars; }

	Bike() : m_shop(0) {}
	Bike(const AutoShop& shop) : m_shop(&shop) {}
	
	void wear();
	void menu();

	friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
};

