#pragma once
#include <string>
#include <iostream>

class AutoShop;

class Handlebars
{
private:
	bool m_isShaking;
	unsigned  m_alignment;
public:
	Handlebars() : m_isShaking(0), m_alignment(0) {}
	Handlebars(bool, unsigned);
	Handlebars(const Handlebars&);

	void set_isShaking(bool value) { m_isShaking = value; }
	void set_alignment(unsigned);

	bool get_isShaking() const { return m_isShaking; }
	unsigned get_alignment() const { return m_alignment; }

	void wear();
	void menu();
	float getRepairCost(const AutoShop&) const;

	friend std::ostream& operator<<(std::ostream&, const Handlebars&);
	Handlebars& operator=(const Handlebars&);
	~Handlebars();
};

