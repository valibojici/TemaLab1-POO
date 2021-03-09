#pragma once
#include <string>
#include <iostream>

class AutoShop;

class Light {
private:
	bool m_isBroken;
	bool m_isDisconnected;
public:
	Light() : m_isBroken(0), m_isDisconnected(0) {}
	Light(bool, bool);
	Light(const Light&);

	void set_isBroken(bool value) { m_isBroken = value; }
	void set_isDisconnected(bool value) { m_isDisconnected = value; }
	
	bool get_isBroken() const { return m_isBroken; }
	bool get_isDisconnected() const { return m_isDisconnected; }

	void wear();
	void menu();
	float getRepairCost(const AutoShop&) const;
	
	friend std::ostream& operator<< (std::ostream&, const Light&);
	Light& operator=(const Light&);
};

