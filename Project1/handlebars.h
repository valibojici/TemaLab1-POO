#pragma once
#include <string>

class AutoShop;

class Handlebars
{
private:
	bool m_isShaking;
	unsigned  m_alignment;
public:
	Handlebars() : m_isShaking(0), m_alignment(0) {}
	Handlebars(bool isShaking, unsigned alignment) : m_isShaking(isShaking), m_alignment(alignment) {}
	
	void set_isShaking(bool value) { m_isShaking = value; }
	void set_alignment(unsigned);

	bool get_isShaking() const { return m_isShaking; }
	unsigned get_alignment() const { return m_alignment; }

	void wear();
	
	float getRepairCost(const AutoShop& shop);

	friend std::ostream& operator<<(std::ostream& out, const Handlebars& hand);

	void menu();
};

