#pragma once
#include <string>
class AutoShop;

class Engine {
private:
	bool m_lowOilLevel;
	bool m_engineIsMelted;
	bool m_isDirty;
	bool m_batteryIsDischarghed;
	bool m_hasExtremeDamage;

public:

	bool get_lowOilLevel() { return m_lowOilLevel; }
	bool get_engineIsMelted() { return m_engineIsMelted; }
	bool get_isDirty() { return m_isDirty; }
	bool get_batteryIsDischarghed() { return m_batteryIsDischarghed; }
	bool get_hasExtremeDamage() { return m_hasExtremeDamage; }

	void set_lowOilLevel(bool value) { m_lowOilLevel = value; }
	void set_engineIsMelted(bool value) { m_engineIsMelted = value; }
	void set_isDirty(bool value) { m_isDirty = value; }
	void set_batteryIsDischarghed(bool value) { m_batteryIsDischarghed = value; }
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	Engine() : m_lowOilLevel(0), m_engineIsMelted(0), m_isDirty(0), m_batteryIsDischarghed(0), m_hasExtremeDamage(0) {}
	Engine(bool lowOilLevel, bool engineIsMelted, bool isDirty, bool batteryIsDischarged, bool extremeDamage)
		: m_lowOilLevel(lowOilLevel), m_engineIsMelted(engineIsMelted), m_isDirty(isDirty), m_hasExtremeDamage(extremeDamage),
		m_batteryIsDischarghed(batteryIsDischarged) {}

	void wear();
	float getRepairCost(const AutoShop& shop);
	std::string diagnose();
};
