#include "catch.hpp"
#include <psat/Pump.h>
#include <psat/Motor.h>
#include <psat/FieldData.h>
#include <psat/Financial.h>
#include <psat/PSATResult.h>
#include <map>

TEST_CASE( "Calculate motor results", "[motor][efficiency][results]") {
	Pump::Style style1 = Pump::Style::END_SUCTION_ANSI_API;
	Pump::Drive drive1 = Pump::Drive::DIRECT_DRIVE;
	double viscosity =  1.0;
	double specifc_gravity = 1.0;
	int stages = 2;
	Pump::Speed fixed_speed = Pump::Speed::FIXED_SPEED;
	double pump_specified = 90;
	double pump_rated_speed = 1780;

	Motor::LineFrequency lineFrequency = Motor::LineFrequency::FREQ60;
	double motor_rated_power = 200;
	double motor_rated_speed = 1780;
	Motor::EfficiencyClass efficiencyClass = Motor::EfficiencyClass::SPECIFIED;
	double efficiency = 95;
	double motor_rated_voltage = 460;
	double motor_rated_fla = 225;
	double margin = 0;

	double fraction = 1;
	double cost = 0.05;

	double flow = 1840;
	double head = 174.85;

	// TODO check this enum for bug, TRY FieldData::LoadEstimationMethod::CURRENT
	FieldData::LoadEstimationMethod loadEstimationMethod1 = FieldData::LoadEstimationMethod::POWER;

	double motor_field_power = 80;
	double motor_field_current = 125.857;
	double motor_field_voltage = 480;

	Pump pump(style1, pump_specified, pump_rated_speed, drive1, viscosity, specifc_gravity, stages, fixed_speed);
	Motor motor(lineFrequency, motor_rated_power, motor_rated_speed, efficiencyClass, efficiency, motor_rated_voltage, motor_rated_fla, margin);
	Financial fin(fraction, cost);
	FieldData fd(flow, head, loadEstimationMethod1, motor_field_power, motor_field_current, motor_field_voltage);
	PSATResult psat(pump, motor, fin, fd);
	psat.calculateExisting();
	psat.calculateOptimal();
	auto ex = psat.getExisting();
	auto opt = psat.getOptimal();

	CHECK(ex.pumpEfficiency_ * 100.0 == Approx(80.26203812559545));
	CHECK(opt.pumpEfficiency_ * 100.0 == Approx(86.75480583084276));

	CHECK(ex.motorRatedPower_ == Approx(200));
	CHECK(opt.motorRatedPower_ == Approx(100));

	CHECK(ex.motorShaftPower_ == Approx(101.18747791246317));
	CHECK(opt.motorShaftPower_ == Approx(93.61456270075166));

	CHECK(ex.pumpShaftPower_ == Approx(101.18747791246317));
	CHECK(opt.pumpShaftPower_ == Approx(93.61456270075166));

	CHECK(ex.motorEfficiency_ * 100.0 == Approx(94.35732315337191));
	CHECK(opt.motorEfficiency_ * 100.0 == Approx(95.02783605700556));

	CHECK(ex.motorPowerFactor_ * 100.0 == Approx(76.45602656178534));
	CHECK(opt.motorPowerFactor_ * 100.0 == Approx(85.97645176630047));

	CHECK(ex.motorCurrent_ == Approx(125.85671685040634));
	CHECK(opt.motorCurrent_ == Approx(102.81349971661015));

	CHECK(ex.motorPower_ == Approx(80));
	CHECK(opt.motorPower_ == Approx(73.49055466145589));

	CHECK(ex.annualEnergy_ == Approx(700.8));
	CHECK(opt.annualEnergy_ == Approx(643.7772588343536));

	CHECK(ex.annualCost_ * 1000 == Approx(35040));
	CHECK(opt.annualCost_ * 1000 == Approx(32188.86294171768));

	CHECK(psat.getAnnualSavingsPotential() * 1000 == Approx(2851.1370582823192));
	CHECK(psat.getOptimizationRating() == Approx(0.9186319332681986));
}