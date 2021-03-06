#pragma once
#include <string>
#include <iostream>
#include <cmath>

class AutoShop;


class Body {
private:
	// values from 0 to 3 (0 = perfect condition/no rust 3 = very poor condition/a lot of rust)
	unsigned m_wingFrontRight;
	unsigned m_wingFrontLeft;
	unsigned m_wingRearLeft;
	unsigned m_wingRearRight;
	unsigned m_bumper;
	unsigned m_hood;
	unsigned m_rust;
	bool m_hasExtremeDamage;

public:
	Body() : m_wingFrontRight(0), m_wingFrontLeft(0), m_wingRearLeft(0), m_wingRearRight(0), m_bumper(0), m_hood(0), m_rust(0), m_hasExtremeDamage(0) {}
	Body(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, bool extremeDamage = 0);
	Body(const Body&);

	unsigned get_wingFrontLeft() const  { return m_wingFrontLeft; }
	unsigned get_wingFrontRight() const { return m_wingFrontRight; }
	unsigned get_wingRearLeft() const { return m_wingRearLeft; }
	unsigned get_wingRearRight() const { return m_wingRearRight; }
	unsigned get_bumper() const { return m_bumper; }
	unsigned get_hood() const { return m_hood; }
	unsigned get_rust() const { return m_rust; }
	bool get_hasExtremeDamage() const { return m_hasExtremeDamage; }

	void set_wingFrontLeft(unsigned);
	void set_wingFrontRight(unsigned);
	void set_wingRearLeft(unsigned);
	void set_wingRearRight(unsigned);
	void set_bumper(unsigned);
	void set_hood(unsigned);
	void set_rust(unsigned);
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	void wear();
	float getRepairCost(const AutoShop&) const;
	void menu();
	
	friend std::ostream& operator<<(std::ostream&, const Body&);
	Body& operator=(const Body&);

	~Body();
};

