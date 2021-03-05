#pragma once
#include <string>

class AutoShop;

class Chain {
private:
	bool m_isBroken;
	bool m_isWornOut;
	bool m_isMissing;

public:
	bool get_isBroken() const { return m_isBroken; }
	bool get_isWornOut() const { return m_isWornOut; }
	bool get_isMissing() const { return m_isMissing; }

	void set_isBroken(bool value) { m_isBroken = value; }
	void set_isWornOut(bool value) { m_isWornOut = value; }
	void set_isMissing(bool value) { m_isMissing = value; }

	Chain() : m_isBroken(0), m_isWornOut(0), m_isMissing(0) {}
	Chain(bool isBroken, bool isWornOut, bool isMissing)
		: m_isBroken(isBroken), m_isWornOut(isWornOut), m_isMissing(isMissing) {}

	void wear();
	float getRepairCost(const AutoShop& shop, bool isBicycle);
	std::string diagnose();

	void menu();
};

