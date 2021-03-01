#pragma once
#include <string>

class AutoShop;

class Wheel {
	friend AutoShop;
private:
	bool m_brakePad;
	bool m_brakeDisc;
	bool m_hasExtremeDamage;
	bool m_flatTire;
	int m_alignment; // value from 0 to 3 (0 = perfect condition ; 3 = very poor condition)
public:
	bool get_brakePad() { return m_brakePad; }
	bool get_brakeDisc() { return m_brakeDisc; }
	int get_flatTire() { return m_flatTire; }
	int get_alignment() { return m_alignment; }
	bool get_hasExtremeDamage() { return m_hasExtremeDamage; }
	void set_brakePad(bool value) { m_brakePad = value; }
	void set_brakeDisc(bool value) { m_brakeDisc = value; }
	void set_flatTire(bool value) { m_flatTire = value; }
	void set_alignment(int value) { m_alignment = value; }
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	Wheel() : m_brakePad(0), m_brakeDisc(0), m_flatTire(0), m_alignment(0), m_hasExtremeDamage(0) {}
	Wheel(bool brakePad, bool brakeDisc, bool m_flatTire, int alignment, bool extremeDamage = false)
		: m_brakePad(brakePad), m_brakeDisc(brakeDisc), m_flatTire(m_flatTire), m_alignment(alignment), m_hasExtremeDamage(extremeDamage) {}

	void wear();
	float getRepairCost(const AutoShop& shop, bool isFrontWheel);
	std::string diagnose();
};

