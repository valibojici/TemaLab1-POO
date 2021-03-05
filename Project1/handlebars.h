#pragma once
#include <string>

class AutoShop;

class Handlebars
{
private:
	bool m_isShaking;
	int m_alignment;
public:
	Handlebars() : m_isShaking(0), m_alignment(0) {}
	Handlebars(bool isShaking, int alignment) : m_isShaking(isShaking), m_alignment(alignment) {}
	
	void set_isShaking(bool value) { m_isShaking = value; }
	void set_alignment(int value) { m_alignment = value; }

	bool get_isShaking() const { return m_isShaking; }
	int get_alignment() const { return m_alignment; }

	void wear();
	std::string diagnose();
	float getRepairCost(const AutoShop& shop);

	void menu();
};

