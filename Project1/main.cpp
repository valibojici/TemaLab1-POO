#include <iostream>
#include <random>
#include <time.h>

class Wheel {
private:
	static const int s_brakePadFrontCost = 300;
	static const int s_brakePadRearCost = 200;
	static const int s_brakeDiscCost = 700;
	static const int s_tireCost = 150;
	static const int s_alignmentCost = 500;

	bool m_brakePad;
	bool m_brakeDisc;
	bool m_hasExtremeDamage;
	bool m_flatTire;
	int m_alignment; // value from 0 to 3 (0 = perfect condition ; 3 = very poor condition)
public:
	bool get_brakePad() { return m_brakePad; }
	bool get_brakeDisc() { return m_brakeDisc; }
	int get_tireQuality() { return m_flatTire; }
	int get_alignment() { return m_alignment; }
	bool get_hasExtremeDamage() { return m_hasExtremeDamage; }
	void set_brakePad(bool value) { m_brakePad = value; }
	void set_brakeDisc(bool value) { m_brakeDisc = value; }
	void set_tireQuality(bool value) { m_flatTire = value; }
	void set_alignment(int value) { m_alignment = value; }
	void set_hasExtremeDamage(bool value) { m_hasExtremeDamage = value; }

	Wheel() : m_brakePad(0), m_brakeDisc(0), m_flatTire(0), m_alignment(0), m_hasExtremeDamage(0) {}
	Wheel(bool brakePad, bool brakeDisc, bool m_flatTire, int alignment,bool extremeDamage=false)
		: m_brakePad(brakePad), m_brakeDisc(brakeDisc), m_flatTire(m_flatTire), m_alignment(alignment), m_hasExtremeDamage(extremeDamage) {}

	void wear(bool brakePad, bool brakeDisc, bool m_flatTire, int alignment, bool extremeDamage = false);
	void wear();
	std::string diagnose();
};

class Engine {
private:
	static const int s_oilChangeCost = 60;
	static const int s_cleanCost = 100;

	bool m_lowOilLevel;
	bool m_engineIsMelted;
	bool m_isDirty;

public:

	bool get_lowOilLevel() { return m_lowOilLevel; }
	bool get_engineIsMelted() { return m_engineIsMelted; }
	bool get_isDirty() { return m_isDirty; }
	void set_lowOilLevel(bool value) {  m_lowOilLevel = value; }
	void set_engineIsMelted(bool value) {  m_engineIsMelted = value; }
	void set_isDirty(bool value) {  m_isDirty = value; }

	Engine() : m_lowOilLevel(0), m_engineIsMelted(0), m_isDirty(0) {}
	Engine(bool lowOilLevel, bool engineIsMelted, bool isDirty)
		: m_lowOilLevel(lowOilLevel), m_engineIsMelted(engineIsMelted), m_isDirty(isDirty) {}

	void wear(bool lowOilLevel, bool engineIsMelted, bool isDirty);
	void wear();
	std::string diagnose();
};

class Body {
private:
	// values from 0 to 3 (0 = perfect condition/no rust 3 = very poor condition/a lot of rust)
	int m_wingFrontLeft;
	int m_wingFrontRight;
	int m_wingRearLeft;
	int m_wingRearRight;
	int m_bumper;
	int m_hood;
	int m_rust;
	bool m_hasExtremeDamage;

public:
	int get_wingFrontLeft() { return m_wingFrontLeft; }
	int get_wingFrontRight() { return m_wingFrontRight; }
	int get_wingRearLeft(){ return m_wingRearLeft; }
	int get_wingRearRight(){ return m_wingRearRight; }
	int get_bumper(){ return m_bumper; }
	int get_hood(){ return m_hood; }
	int get_rust(){ return m_rust; }
	bool get_hasExtremeDamage() { return m_hasExtremeDamage; }

	void set_wingFrontLeft(int value) { m_wingFrontLeft = value; }
	void set_wingFrontRight(int value) { m_wingFrontRight = value; }
	void set_wingRearLeft(int value) { m_wingRearLeft = value; }
	void set_wingRearRight(int value) { m_wingRearRight = value; }
	void set_bumper(int value) { m_bumper = value; }
	void set_hood(int value) { m_hood = value; }
	void set_rust(int value) { m_rust = value; }
	void set_hasExtremeDamage(int value) { m_hasExtremeDamage = value; }

	Body() : m_wingFrontRight(0), m_wingFrontLeft(0), m_wingRearLeft(0), m_wingRearRight(0), m_bumper(0), m_hood(0), m_rust(0), m_hasExtremeDamage(0) {}
	Body(int wingFR, int wingFL, int wingRL, int wingRR, int bumper, int hood, int rust, bool extremeDamage = 0)
		: m_wingFrontRight(wingFR), m_wingFrontLeft(wingFL), m_wingRearLeft(wingRL), m_wingRearRight(wingRR),
		m_bumper(bumper), m_hood(hood), m_rust(rust), m_hasExtremeDamage(extremeDamage) {}

	void wear();
	void wear(int wingFR, int wingFL, int wingRL, int wingRR, int bumper, int hood, int rust, bool extremeDamage = 0);
	std::string diagnose();
};

class Chain {
private:
	static const int s_newBicycleChainPrice = 100;
	static const int s_newBikeChainPrice = 2000;
	static const int s_repairBicyleChainPrice = 50;
	static const int s_repairBikeChainPrice = 800;

	bool m_isBroken;
	bool m_isWornOut;
	bool m_isMissing;

public:
	bool get_isBroken() { return m_isBroken; }
	bool get_isWornOut() { return m_isWornOut; }
	bool get_isMissing() { return m_isMissing; }

	int set_isBroken(bool value) { m_isBroken = value; }
	int set_isWornOut(bool value) { m_isWornOut = value; }
	int set_isMissing(bool value) { m_isMissing = value; }

	Chain() : m_isBroken(0), m_isWornOut(0), m_isMissing(0) {}
	Chain(bool isBroken, bool isWornOut, bool isMissing)
		: m_isBroken(isBroken), m_isWornOut(isWornOut), m_isMissing(isMissing) {}

	void wear();
	void wear(bool isBroken, bool isWornOut, bool isMissing);
	std::string diagnose();
};

class Emissions {
private:
	static const int s_oilChangeCost = 60;
	static const int s_emissionsRepairCost = 3000;

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

	std::string diagnose();
};

class Car {
private:
	Engine engine;
	Body body;
	Wheel wheelFL, wheelFR, wheelRL, wheelRR;
	Emissions emissions;
public:
	Car() {}
	void wear()
	{
		engine.wear();
		body.wear();
		wheelFL.wear();
		wheelFR.wear();
		wheelRL.wear();
		wheelRR.wear();
	}

	friend std::ostream& operator<<(std::ostream& stream,Car& car)
	{
		stream << "Engine:\n" << car.engine.diagnose() << '\n';
		stream << "Body:\n" << car.body.diagnose() << '\n';
		stream << "Front Left Wheel:\n" << car.wheelFL.diagnose() << '\n';
		stream << "Front Right Wheel:\n" << car.wheelFR.diagnose() << '\n';
		stream << "Rear Left Wheel:\n" << car.wheelRL.diagnose() << '\n';
		stream << "Rear Right Wheel:\n" << car.wheelRR.diagnose() << '\n';
		return stream;
	}
};
int main()
{
	srand(time(0));

	Car c;
	c.wear();
	std::cout << c;
}


std::string Wheel::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return std::string("Extreme Damage");
	}

	std::string diagnostic = "";
	if (m_brakeDisc)
	{
		diagnostic += "damaged brake disc; ";
	}
	if (m_brakePad)
	{
		diagnostic += "damaged brake pad; ";
	}
	if (m_flatTire)
	{
		diagnostic += "flat tire; ";
	}
	if (m_alignment > 0)
	{
		if (m_alignment == 1)
		{
			diagnostic += "slight misalignment; ";
		}
		else if (m_alignment == 2)
		{
			diagnostic += "medium misalignment; ";
		}
		else
		{
			diagnostic += "major misalignment; ";
		}
	}
	return diagnostic;
}

void Wheel::wear()
{
	m_brakePad = rand() % 2;
	m_brakeDisc = rand() % 2;
	m_flatTire = rand() % 2;
	m_alignment = rand() % 4;
	if (m_brakeDisc && m_brakePad && m_flatTire && m_alignment >= 2)
	{
		m_hasExtremeDamage = true;
	}
}

void Wheel::wear(bool brakePad, bool brakeDisc, bool m_flatTire, int alignment, bool extremeDamage)
{
	m_hasExtremeDamage = extremeDamage;
	if (extremeDamage)
	{
		return;
	}
	m_brakePad = brakePad;
	m_brakeDisc = brakeDisc;
	m_flatTire = m_flatTire;
	m_alignment = alignment;
	if (m_brakeDisc && m_brakePad && m_flatTire && m_alignment >= 2)
	{
		m_hasExtremeDamage = true;
	}
}

std::string Engine::diagnose()
{
	std::string diagnostic = "";
	if (m_lowOilLevel)
	{
		diagnostic += "low oil level; ";
	}
	if (m_engineIsMelted)
	{
		diagnostic += "engine is melted; ";
	}
	if (m_isDirty)
	{
		diagnostic += "engine is dirty; ";
	}
	return diagnostic;
}

void Engine::wear()
{
	m_lowOilLevel = rand() % 2;
	m_engineIsMelted = rand() % 2;
	m_isDirty = rand() % 2;
}

void Engine::wear(bool lowOilLevel, bool engineIsMelted, bool isDirty)
{
	m_lowOilLevel = lowOilLevel;
	m_engineIsMelted = engineIsMelted;
	m_isDirty = isDirty;
}

std::string Body::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return "Extreme Damage";
	}

	std::string diagnostic = "";
	std::string prefix[] = {"", "slight", "medium", "major" };

	if (m_wingFrontLeft)
	{
		diagnostic += prefix[m_wingFrontLeft] + " dent front left wing; ";
	}
	if (m_wingFrontRight)
	{
		diagnostic += prefix[m_wingFrontRight] + " dent front right wing; ";
	}
	if (m_wingRearLeft)
	{
		diagnostic += prefix[m_wingRearLeft] + " dent rear left wing; ";
	}
	if (m_wingRearRight)
	{
		diagnostic += prefix[m_wingRearRight] + " dent rear right wing; ";
	}
	if (m_bumper)
	{
		diagnostic += prefix[m_bumper] + " dent bumper; ";
	}
	if (m_hood)
	{
		diagnostic += prefix[m_hood] + " dent hood; ";
	}
	if (m_rust)
	{
		diagnostic += prefix[m_rust] + " rust problem; ";
	}
	return diagnostic;
}

void Body::wear()
{
	m_wingFrontLeft = rand() % 4;
	m_wingFrontRight = rand() % 4;
	m_wingRearLeft = rand() % 4;
	m_wingRearRight = rand() % 4;
	m_bumper = rand() % 4;
	m_hood = rand() % 4;
	m_rust = rand() % 4;
	m_hasExtremeDamage = !bool(rand() % 11);
}

void Body::wear(int wingFR, int wingFL, int wingRL, int wingRR, int bumper, int hood, int rust, bool extremeDamage)
{
	m_wingFrontRight = wingFR;
	m_wingFrontLeft = wingFL;
	m_wingRearLeft = wingRL;
	m_wingRearRight= wingRR;
	m_bumper = bumper;
	m_hood = hood;
	m_rust = rust;
	m_hasExtremeDamage = extremeDamage;
}

std::string Chain::diagnose()
{
	if (m_isMissing)
	{
		return "Missing chain";
	}
	std::string diagnose = "chain";
	if (m_isBroken)
	{
		diagnose = "broken " + diagnose;
	}
	if (m_isWornOut)
	{
		diagnose = "worn out " + diagnose;
	}
	return diagnose != "chain" ? diagnose + '\n' : "";
}

void Chain::wear()
{
	m_isBroken = rand() % 2;
	m_isWornOut = rand() % 2;
	m_isMissing = !bool(rand() % 5);
}

void Chain::wear(bool isBroken, bool isWornOut, bool isMissing)
{
	m_isBroken = isBroken;
	m_isWornOut = isWornOut;
	m_isMissing = isMissing;
}

std::string Emissions::diagnose() 
{
	std::string diagnose = "";
	if (m_isBurningOil)
	{
		diagnose += "is burning oil\n";
	}
	if (m_isMadeBefore2000)
	{
		diagnose += "is made before 2000\n";
	}
	return diagnose;
}