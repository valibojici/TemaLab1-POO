#pragma once
#include <string>

class AutoShop;

class Emissions {
private:
	bool m_isMadeBefore2000;
	bool m_isBurningOil;

public:
	Emissions() : m_isBurningOil(0), m_isMadeBefore2000(0) {}
	Emissions(bool, bool);
	Emissions(const Emissions&);

	void set_isMadeBefore2000(bool value)  { m_isMadeBefore2000 = value; }
	void set_isBurningOil(bool value)  { m_isBurningOil = value; }

	bool get_isMadeBefore2000() const { return m_isMadeBefore2000; }
	bool get_isBurningOil() const { return m_isBurningOil; }

	void wear();
	void menu();
	float getRepairCost(const AutoShop&) const;
	
	friend std::ostream& operator<<(std::ostream&, const Emissions&);
	Emissions& operator=(const Emissions&);
};