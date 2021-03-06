#pragma once
#include <string>
#include <iostream> 

class AutoShop;

class Engine {
private:
	bool m_lowOilLevel;
	bool m_engineIsMelted;
	bool m_isDirty;
	bool m_batteryIsDischarghed;
	bool m_hasExtremeDamage;

public:

	bool get_lowOilLevel() const { return m_lowOilLevel; }
	bool get_engineIsMelted() const { return m_engineIsMelted; }
	bool get_isDirty() const { return m_isDirty; }
	bool get_batteryIsDischarghed() const { return m_batteryIsDischarghed; }
	bool get_hasExtremeDamage() const { return m_hasExtremeDamage; }

	void set_lowOilLevel(bool value) { m_lowOilLevel = value; }
	void set_engineIsMelted(bool value) { m_engineIsMelted = value; }
	void set_isDirty(bool value) { m_isDirty = value; }
	void set_batteryIsDischarghed(bool value) { m_batteryIsDischarghed = value; }
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	Engine() : m_lowOilLevel(0), m_engineIsMelted(0), m_isDirty(0), m_batteryIsDischarghed(0), m_hasExtremeDamage(0) {}
	Engine(bool lowOilLevel, bool engineIsMelted, bool isDirty, bool batteryIsDischarged, bool extremeDamage = 0);

	void wear();
	float getRepairCost(const AutoShop& shop) const;
	
	friend std::ostream& operator<< (std::ostream& out, const Engine& eng);

	void menu();
};
