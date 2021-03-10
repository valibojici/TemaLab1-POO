#pragma once
#include <string>
#include <iostream>
#include <cmath>

class AutoShop;

class Chain {
private:
	bool m_isBroken;
	bool m_isWornOut;
	bool m_isMissing;

public:
	Chain() : m_isBroken(0), m_isWornOut(0), m_isMissing(0) {}
	Chain(bool, bool, bool);
	Chain(const Chain&);

	bool get_isBroken() const { return m_isBroken; }
	bool get_isWornOut() const { return m_isWornOut; }
	bool get_isMissing() const { return m_isMissing; }

	void set_isBroken(bool value) { m_isBroken = value; }
	void set_isWornOut(bool value) { m_isWornOut = value; }
	void set_isMissing(bool value) { m_isMissing = value; }

	void menu();
	void wear();
	float getRepairCost(const AutoShop&, bool) const;
	
	friend std::ostream& operator<<(std::ostream&, const Chain&);
	Chain& operator=(const Chain&);
	~Chain();
};

