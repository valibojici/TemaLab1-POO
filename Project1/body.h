#pragma once
#include <string>
#include <iostream>

class AutoShop;


class Body {
private:
	// values from 0 to 3 (0 = perfect condition/no rust 3 = very poor condition/a lot of rust)
	int m_wingFrontLeft;
	int m_wingFrontRight;
	int m_wingRearLeft;
	int m_wingRearRight;
	int m_bumper;
	int m_hood;
	int m_rust;
	bool m_hasExtremeDamage;

public:
	int get_wingFrontLeft() const  { return m_wingFrontLeft; }
	int get_wingFrontRight() const { return m_wingFrontRight; }
	int get_wingRearLeft() const { return m_wingRearLeft; }
	int get_wingRearRight() const { return m_wingRearRight; }
	int get_bumper() const { return m_bumper; }
	int get_hood() const { return m_hood; }
	int get_rust() const { return m_rust; }
	bool get_hasExtremeDamage() const { return m_hasExtremeDamage; }

	void set_wingFrontLeft(int value) { m_wingFrontLeft = value; }
	void set_wingFrontRight(int value) { m_wingFrontRight = value; }
	void set_wingRearLeft(int value) { m_wingRearLeft = value; }
	void set_wingRearRight(int value) { m_wingRearRight = value; }
	void set_bumper(int value) { m_bumper = value; }
	void set_hood(int value) { m_hood = value; }
	void set_rust(int value) { m_rust = value; }
	void set_hasExtremeDamage(int value) { m_hasExtremeDamage = value; }

	Body() : m_wingFrontRight(0), m_wingFrontLeft(0), m_wingRearLeft(0), m_wingRearRight(0), m_bumper(0), m_hood(0), m_rust(0), m_hasExtremeDamage(0) {}
	
	Body(int wingFR, int wingFL, int wingRL, int wingRR, int bumper, int hood, int rust, bool extremeDamage = 0)
		: m_wingFrontRight(wingFR), m_wingFrontLeft(wingFL), m_wingRearLeft(wingRL), m_wingRearRight(wingRR),
		m_bumper(bumper), m_hood(hood), m_rust(rust), m_hasExtremeDamage(extremeDamage) {}

	void wear();
	float getRepairCost(const AutoShop& shop);
	std::string diagnose();

	void menu();
};

