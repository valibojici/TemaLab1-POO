#pragma once
#include <string>

class AutoShop;

class Emissions {
private:
	bool m_isMadeBefore2000;
	bool m_isBurningOil;

public:
	void set_isMadeBefore2000(bool value) { m_isMadeBefore2000 = value; }
	void set_isBurningOil(bool value) { m_isBurningOil = value; }

	bool get_isMadeBefore2000() { return m_isMadeBefore2000; }
	bool get_isBurningOil() { return m_isBurningOil; }

	Emissions() : m_isBurningOil(0), m_isMadeBefore2000(0) {}
	Emissions(bool isMadeBefore2000, bool isBurningOil)
		: m_isMadeBefore2000(isMadeBefore2000), m_isBurningOil(isBurningOil) {}

	void wear();
	float getRepairCost(const AutoShop& shop);
	std::string diagnose();
};