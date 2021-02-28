#include <iostream>
#include <random>
#include <time.h>

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

	void wear();
	float getRepairCost(bool isFrontWheel);
	std::string diagnose();
};

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
	void set_lowOilLevel(bool value) {  m_lowOilLevel = value; }
	void set_engineIsMelted(bool value) {  m_engineIsMelted = value; }
	void set_isDirty(bool value) {  m_isDirty = value; }

	Engine() : m_lowOilLevel(0), m_engineIsMelted(0), m_isDirty(0), m_batteryIsDischarghed(0), m_hasExtremeDamage(0) {}
	Engine(bool lowOilLevel, bool engineIsMelted, bool isDirty, bool batteryIsDischarged, bool extremeDamage)
		: m_lowOilLevel(lowOilLevel), m_engineIsMelted(engineIsMelted), m_isDirty(isDirty), m_hasExtremeDamage(extremeDamage),
			m_batteryIsDischarghed(batteryIsDischarged) {}

	void wear();
	float getRepairCost();
	std::string diagnose();
};

class Body {
private:
	static const int s_componentRepairCost = 300;
	static const int s_paintCost = 700;

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
	float getRepairCost();
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
	float getRepairCost(bool isBicycle);
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

	void wear();
	float getRepairCost();
	std::string diagnose();
};

class Light {
private:
	static const int s_lightCost = 500;
	static const int s_wiresCost = 200;

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
	float getRepairCost();
	std::string diagnose();
};

class Car {
private:
	Engine engine;
	Body body;
	Wheel wheelFL, wheelFR, wheelRL, wheelRR; // FL = front right RL = rear right
	Emissions emissions;
	Light lampFL, lampFR, brakeRL, brakeRR;

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
		lampFL.wear();
		lampFR.wear();
		brakeRL.wear();
		brakeRR.wear();
	}

	friend std::ostream& operator<<(std::ostream& stream,Car& car)
	{
		stream << "Engine:" << car.engine.diagnose() << '\n';
		stream << car.engine.getRepairCost() << '\n';
		stream << "Body:\n" << car.body.diagnose() << '\n';
		stream << car.engine.getRepairCost() << '\n';
		stream << "Front Left Wheel:" << car.wheelFL.diagnose() << '\n';
		stream << car.wheelFL.getRepairCost(true) << '\n';
		stream << "Front Right Wheel:" << car.wheelFR.diagnose() << '\n';
		stream << car.wheelFR.getRepairCost(true) << '\n';
		stream << "Rear Left Wheel:" << car.wheelRL.diagnose() << '\n';
		stream << car.wheelRL.getRepairCost(false) << '\n';
		stream << "Rear Right Wheel:" << car.wheelRR.diagnose() << '\n';
		stream << car.wheelRR.getRepairCost(false) << '\n';
		stream << "Front Left Headlamp:" << car.lampFL.diagnose() << '\n';
		stream << car.lampFL.getRepairCost() << '\n';
		stream << "Front Right Head light:" << car.lampFR.diagnose() << '\n';
		stream << car.lampFR.getRepairCost() << '\n';
		stream << "Rear Left Brake light:" << car.brakeRL.diagnose() << '\n';
		stream << car.brakeRL.getRepairCost() << '\n';
		stream << "Rear Right Brake light:" << car.brakeRR.diagnose() << '\n';
		stream << car.brakeRR.getRepairCost() << '\n';
		return stream;
	}
};

class Bike{};

class Moto {};

class AutoShop {
private:
	int m_brakePadFrontCost = 0;
	int m_brakePadRearCost = 0;
	int m_brakeDiscCost = 0;
	int m_tireCost = 0;
	int m_wheelAlignmentCost = 0;
	int m_oilCost = 0;
	int m_cleaningProductsCost = 0;
	int m_batteryCost = 0;
	int m_paintCost = 0;
	int m_motoChainCost = 0;
	int m_bikeChainCost = 0;
	int m_aluminiumCost = 0;
	int m_steelCost = 0;
	int m_screwCost = 0;
	int m_rivetCost = 0;
	int m_wireCost = 0;
	int m_lubricantCost = 0;

	Car m_car;
	Bike m_bike;
	Moto m_moto;

public:
	AutoShop() {}
	void set_brakePadFrontCost(int value) { m_brakePadFrontCost = value;}
	void set_brakePadRearCost(int value) { m_brakePadRearCost = value;}
	void set_brakeDiscCost(int value) { m_brakeDiscCost = value;}
	void set_tireCost(int value) { m_tireCost = value;}
	void set_wheelAlignmentCost(int value) { m_wheelAlignmentCost = value;}
	void set_oilCost(int value) { m_oilCost = value;}
	void set_cleaningProductsCost(int value) { m_cleaningProductsCost = value;}
	void set_batteryCost(int value) { m_batteryCost = value;}
	void set_paintCost(int value) { m_paintCost = value;}
	void set_motoChainCost(int value) { m_motoChainCost = value;}
	void set_bikeChainCost(int value) { m_bikeChainCost = value;}
	void set_aluminiumCost(int value) { m_aluminiumCost = value;}
	void set_steelCost(int value) { m_steelCost = value;}
	void set_screwCost(int value) { m_screwCost = value;}
	void set_rivetCost(int value) { m_rivetCost = value;}
	void set_wireCost(int value) { m_wireCost = value;}
	void set_lubricantCost(int value) { m_lubricantCost = value;}
	
	int get_brakePadFrontCost() { return m_brakePadFrontCost; }
	int get_brakePadRearCost() { return m_brakePadRearCost; }
	int get_brakeDiscCost() { return m_brakeDiscCost; }
	int get_tireCost() { return m_tireCost; }
	int get_wheelAlignmentCost() { return m_wheelAlignmentCost; }
	int get_oilCost() { return m_oilCost; }
	int get_cleaningProductsCost() { return m_cleaningProductsCost; }
	int get_batteryCost() { return m_batteryCost; }
	int get_paintCost() { return m_paintCost; }
	int get_motoChainCost() { return m_motoChainCost; }
	int get_bikeChainCost() { return m_bikeChainCost; }
	int get_aluminiumCost() { return m_aluminiumCost; }
	int get_steelCost() { return m_steelCost; }
	int get_screwCost() { return m_screwCost; }
	int get_rivetCost() { return m_rivetCost; }
	int get_wireCost() { return m_wireCost; }
	int get_lubricantCost() { return m_lubricantCost; }
	
	void set_car(Car car) { m_car = car; }
	Car get_car() { return m_car; }
	void set_bike(Bike bike) { m_bike = bike; }
	Bike get_bike() { return m_bike; }
	void set_moto(Moto moto) { m_moto = moto; }
	Moto get_moto() { return m_moto; }
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
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Wheel::getRepairCost(bool isFrontWheel)
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	cost += isFrontWheel * m_brakePadFrontCost * m_brakePad;
	cost += !isFrontWheel * s_brakePadRearCost * m_brakePad;
	cost += s_brakeDiscCost * m_brakeDisc;
	cost += s_tireCost * m_flatTire;
	cost += s_alignmentCost/3 * m_alignment;
	return round(cost * 100) / 100;
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
	if (m_batteryIsDischarghed)
	{
		diagnostic += "discharged battery; ";
	}
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Engine::getRepairCost()
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_engineIsMelted || m_lowOilLevel)cost = s_oilChangeCost;
	cost += m_isDirty * s_cleanCost;
	cost += m_batteryIsDischarghed * s_batteryCost;
	return round(cost * 100) / 100;
}

void Engine::wear()
{
	m_lowOilLevel = rand() % 2;
	m_engineIsMelted = rand() % 2;
	m_isDirty = rand() % 2;
	m_batteryIsDischarghed = rand() % 2;
	m_hasExtremeDamage = !bool(rand() % 10);
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
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Body::getRepairCost()
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	cost += (m_wingFrontLeft/3 + m_wingFrontRight/3 + m_wingRearLeft/3 + m_wingRearRight/3) * s_componentRepairCost;
	cost += (m_bumper/3 + m_hood/3)  * s_componentRepairCost;
	cost += m_rust / 3 * s_paintCost;
	return round(cost * 100) / 100;
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
	return diagnose == "chain" ? "No problems" : diagnose;
}

float Chain::getRepairCost(bool isBicycle)
{
	float cost = 0;
	if (m_isWornOut || m_isMissing)
	{
		cost += isBicycle * s_newBicycleChainPrice + !isBicycle * s_newBikeChainPrice;
	}
	else if (m_isBroken)
	{
		cost += isBicycle * s_repairBicyleChainPrice + !isBicycle * s_repairBikeChainPrice;
	}
	return round(cost * 100) / 100;
}

void Chain::wear()
{
	m_isBroken = rand() % 2;
	m_isWornOut = rand() % 2;
	m_isMissing = !bool(rand() % 5);
}

void Emissions::wear()
{
	m_isBurningOil = rand() % 2;
	m_isMadeBefore2000 = rand() % 2;
}

float Emissions::getRepairCost()
{
	float cost = 0;
	cost += m_isBurningOil* s_oilChangeCost;
	cost += m_isMadeBefore2000 * s_emissionsRepairCost;
	return round(cost * 100) / 100;
}

std::string Emissions::diagnose() 
{
	std::string diagnostic = "";
	if (m_isBurningOil)
	{
		diagnostic += "is burning oil\n";
	}
	if (m_isMadeBefore2000)
	{
		diagnostic += "is made before 2000\n";
	}
	return diagnostic != "" ? "No problems" : diagnostic;
}

void Light::wear() {
	m_isBroken = rand() % 2;
	m_isDisconnected = rand() % 2;
}

float Light::getRepairCost()
{
	float cost = 0;
	cost += m_isBroken* s_lightCost;
	cost += m_isDisconnected * s_wiresCost;
	return float(cost * 100) / 100;
}

std::string Light::diagnose()
{
	std::string diagnostic = "lamp";
	if (m_isBroken)
	{
		diagnostic = "broken " + diagnostic;
	}
	if (m_isDisconnected)
	{
		diagnostic = "disconnected " + diagnostic;
	}
	return diagnostic == "lamp" ? "No problem" : diagnostic;
}