#pragma once
#include <string>

class AutoShop;

class Light {
private:
	bool m_isBroken;
	bool m_isDisconnected;
public:
	void set_isBroken(bool value) { m_isBroken = value; }
	void set_isDisconnected(bool value) { m_isDisconnected = value; }
	bool get_isBroken() { return m_isBroken; }
	bool get_isDisconnected() { return m_isDisconnected; }

	Light() : m_isBroken(0), m_isDisconnected(0) {}
	Light(bool isBroken, bool isDisconnected) : m_isBroken(isBroken), m_isDisconnected(isDisconnected) {}

	void wear();
	float getRepairCost(const AutoShop& shop);
	std::string diagnose();
};

