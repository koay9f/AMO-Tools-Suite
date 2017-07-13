#ifndef AMO_TOOLS_SUITE_SOLIDLIQUIDFLUEGASMATERIAL_H
#define AMO_TOOLS_SUITE_SOLIDLIQUIDFLUEGASMATERIAL_H

#include <string>

/**
 * Solid Liquid Flue Gas Material class
 * Contains all of the properties of a solid or liquid flue gas material.
 * Used to calculate the heat loss caused by carrying the products of combustion out of the system through the flue.
 */
class SolidLiquidFlueGasMaterial {
public:
	/**
	 * Constructor for the SolidLiquidFlueGasMaterial losses with all inputs specified
	 *
	 * @param flueGasTemperature - double, Furnace Flue Gas Temperature in °F
	 * @param excessAirPercentage - double, Percent Excess Air, expressed in normal percentage (i.e. 9% as 9 instead of 0.09)
	 * @param combustionAirTemperature - double, Combustion Air Temperature in °F
	 * @param fuelTemperature - double, fuel Temperature in °F
	 * @param moistureInAirCombustion - double, moisture in Air Combustion as %
	 * @param ashDischargeTemperature - double, ash discharge Temperature in °F
	 * @param unburnedCarbonInAsh - double, unburned carbon in ash expressed as %
	 * @param carbon, hydrogen, sulphur, inertAsh, o2, moisture, nitrogen content in fuel (as percentage)
	 * @return nothing
	 *
	 * */
	SolidLiquidFlueGasMaterial(
			const double flueGasTemperature,
			const double excessAirPercentage,
			const double combustionAirTemperature,
			const double fuelTemperature,
			const double moistureInAirCombustion,
			const double ashDischargeTemperature,
			const double unburnedCarbonInAsh,
			const double carbon,
			const double hydrogen,
			const double sulphur,
			const double inertAsh,
			const double o2,
			const double moisture,
			const double nitrogen) :
			flueGasTemperature(flueGasTemperature),
			excessAirPercentage(excessAirPercentage / 100.0),
			combustionAirTemperature(combustionAirTemperature),
			fuelTemperature(fuelTemperature),
			moistureInAirCombustion(moistureInAirCombustion),
			ashDischargeTemperature(ashDischargeTemperature),
			unburnedCarbonInAsh(unburnedCarbonInAsh / 100.0),
			carbon(carbon / 100),
			hydrogen(hydrogen / 100),
			sulphur(sulphur / 100),
			inertAsh(inertAsh / 100),
			o2(o2 / 100),
			moisture(moisture / 100),
			nitrogen(nitrogen / 100)
	{}

	/**
     * Gets the total heat loss
     *
     * @return double, total heat loss in btu/hr
     */
	double getHeatLoss();

	/**
     * Gets the ID of substance
     *
     * @return int, ID of the substance
     */
	int getID() const { return id; }

	/**
     * Gets the name of the substance
     *
     * @return string, name of the substance
     */
	std::string getSubstance() const { return substance; }

	/**
     * Gets the furnace flue gas temperature
     *
     * @return double, cfurnace flue gas temperature in °F
     */
	double getFlueGasTemperature() const { return flueGasTemperature; }

	/**
     * Gets the excess air percentage
     *
     * @return double, excess air as %
     */
	double getExcessAirPercentage() const { return excessAirPercentage; }

	/**
     * Gets the combustion air temperature
     *
     * @return double, combustion air temperature in °F
     */
	double getCombustionAirTemperature() const { return combustionAirTemperature; }

	/**
     * Gets the fuel temperature
     *
     * @return double, fuel temperature in °F
     */
	double getFuelTemperature() const { return fuelTemperature; }

	/**
     * Gets the moisture in air combustion
     *
     * @return double, moisture in air combustion in %
     */
	double getMoistureInAirCombustion() const { return moistureInAirCombustion; }

	/**
     * Gets the ash discharge temperature
     *
     * @return double, ash discharge temperature in °F
     */
	double getAshDischargeTemperature() const { return ashDischargeTemperature; }

	/**
     * Gets the unburned carbon in ash
     *
     * @return double, % of unburned carbon in ash
     */
	double getUnburnedCarbonInAsh() const { return unburnedCarbonInAsh; }

	/**
     * Gets the percentage of carbon uin fuel
     *
     * @return double, % of carbon in fuel
     */
	double getCarbon() const { return carbon; }

	/**
     * Gets the percentage of hydrogen in fuel
     *
     * @return double, % of hydrogen in fuel
     */
	double getHydrogen() const { return hydrogen; }

	/**
     * Gets the percentage of sulfer in fuel
     *
     * @return double, % of sulfer in fuel
     */
	double getSulphur() const { return sulphur; }

	/**
     * Gets the percentage of inert ash in fuel
     *
     * @return double, % of inert ash in fuel
     */
	double getInertAsh() const { return inertAsh; }

	/**
     * Gets the percentage of O2 in fuel
     *
     * @return double, % of O2 in fuel
     */
	double getO2() const { return o2; }

	/**
     * Gets the percentage of moisture in fuel
     *
     * @return double, % of moisture in fuel
     */
	double getMoisture() const { return moisture; }

	/**
     * Gets the percentage of nitrogen in fuel
     *
     * @return double, % of nitrogen in fuel
     */
	double getNitrogen() const { return nitrogen; }

	/**
     * Sets the ID of substance
     *
     * @param id int, ID of substance
     *
     * @return nothing
     */
	void setID( int const id ) { this->id = id; }

	/**
     * Sets the name of substance
     *
     * @param substanceName string, name of substance
     *
     * @return nothing
     */
	void setSubstance( std::string const & substanceName ) { substance = substanceName; }

	/**
     * Sets the furnace flue gas temperature
     *
     * @param temperature double, flue gas temperature in °F
     *
     * @return nothing
     */
	void setFlueGasTemperature( const double temperature ) { flueGasTemperature = temperature; }

	/**
     * Sets the excess air percentage
     *
     * @param excessAir double, % of excess air
     *
     * @return nothing
     */
	void setExcessAirPercentage( const double excessAir ) { excessAirPercentage = excessAir; }

	/**
     * Sets the combustion air temperature
     *
     * @param temperature double, combustion air temperature in °F
     *
     * @return nothing
     */
	void setCombustionAirTemperature( const double temperature ) { combustionAirTemperature = temperature; }

	/**
     * Sets the fuel temperature
     *
     * @param temperature double, fuel temperature in °F
     *
     * @return nothing
     */
	void setFuelTemperature( const double temperature ) { fuelTemperature = temperature; }

	/**
     * Sets the moisture in air combustion
     *
     * @param moisture double, moisture in air combustion as %
     *
     * @return nothing
     */
	void setMoistureInAirCombustion( const double moisture ) { moistureInAirCombustion = moisture; }

	/**
     * Sets the ash discharge temperature
     *
     * @param temperature double, ash discharge temperature in °F
     *
     * @return nothing
     */
	void setAshDischargeTemperature( const double temperature ) { ashDischargeTemperature = temperature; }

	/**
     * Sets the percentage of unburned carbon in ash
     *
     * @param unburnedCarbon double, % of unburned carbon in ash
     *
     * @return nothing
     */
	void setUnburnedCarbonInAsh( const double unburnedCarbon ) { unburnedCarbonInAsh = unburnedCarbon; }

private:
	friend class SQLite;

	SolidLiquidFlueGasMaterial(
			const std::string & substance,
			const double carbon,
			const double hydrogen,
			const double sulphur,
			const double inertAsh,
			const double o2,
			const double moisture,
			const double nitrogen) :
			substance(substance),
			carbon(carbon / 100),
			hydrogen(hydrogen / 100),
			sulphur(sulphur / 100),
			inertAsh(inertAsh / 100),
			o2(o2 / 100),
			moisture(moisture / 100),
			nitrogen(nitrogen / 100)
	{}

	int id = 0;
	std::string substance = "UndefinedSubstance";
	double flueGasTemperature, excessAirPercentage, combustionAirTemperature;
	double fuelTemperature, moistureInAirCombustion, ashDischargeTemperature, unburnedCarbonInAsh;
	const double carbon, hydrogen, sulphur, inertAsh, o2, moisture, nitrogen;
};

#endif //AMO_TOOLS_SUITE_SOLIDLIQUIDFLUEGASMATERIAL_H
