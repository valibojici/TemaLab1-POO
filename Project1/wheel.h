#pragma once
#include <string>
#include <cmath>

class AutoShop;

class Wheel {
private:
	bool m_brakePad;
	bool m_brakeDisc;
	bool m_flatTire;
	unsigned m_alignment; // (0 = perfect condition ; 3 = very poor condition)
	bool m_hasExtremeDamage;
public:
	Wheel() : m_brakePad(0), m_brakeDisc(0), m_flatTire(0), m_alignment(0), m_hasExtremeDamage(0) {}
	Wheel(bool, bool, bool, int, bool extremeDamage = false);
	Wheel(const Wheel&);

	bool get_brakePad() const { return m_brakePad; }
	bool get_brakeDisc() const { return m_brakeDisc; }
	bool get_flatTire() const { return m_flatTire; }
	unsigned get_alignment() const { return m_alignment; }
	bool get_hasExtremeDamage() const { return m_hasExtremeDamage; }
	
	void set_brakePad(bool value) { m_brakePad = value; }
	void set_brakeDisc(bool value) { m_brakeDisc = value; }
	void set_flatTire(bool value) { m_flatTire = value; }
	void set_alignment(unsigned value);
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	void wear();
	void menu();
	float getRepairCost(const AutoShop&, bool) const;
	
	friend std::ostream& operator<<(std::ostream&, const Wheel&);
	Wheel& operator=(const Wheel&);
	~Wheel();
};

