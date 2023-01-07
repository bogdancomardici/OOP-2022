#include "truck.h"
#include "exception_negative_number.h"
#include "exception_invalid_year.h"
#include <ctime>
truck::truck(const std::string &manufacturerName, const std::string &country, const std::string &fuel,
             int productionYear, int maximumLoad, float fuelEconomy) : vehicle(manufacturerName, country, fuel,
                                                                               productionYear),
                                                                       maximum_load(maximumLoad),
                                                                       fuel_economy(fuelEconomy) {
    truck_count++;
    if(productionYear < 0)
    {
        throw exception_negative_number((char*)"productionYear");
    }

    if(maximumLoad < 0)
    {
        throw exception_negative_number((char*)"maximumLoad");
    }

    if(fuelEconomy < 0)
    {
        throw exception_negative_number((char*)"fuelEconomy");
    }

    if(productionYear > 1970 + time(nullptr) / 31537970)
    {
        throw exception_invalid_year();
    }
}

truck::~truck() {
    truck_count--;
}

truck::truck(const truck &t): vehicle(t.getManufacturerName(), t.getCountry(), t.getFuel(), t.getProductionYear()) {
    this->maximum_load = t.maximum_load;
    this->fuel_economy = t.fuel_economy;
    this->setProductionYear(t.getProductionYear());
    this->setFuel(t.getFuel());
    this->setCountry(t.getCountry());
    this->setManufacturerName(t.getManufacturerName());

    truck_count++;
}

int truck::getMaximumLoad() const {
    return maximum_load;
}

void truck::setMaximumLoad(int maximumLoad_) {
    maximum_load = maximumLoad_;
}

float truck::getFuelEconomy() const {
    return fuel_economy;
}

void truck::setFuelEconomy(float fuelEconomy_) {
    fuel_economy = fuelEconomy_;
}

int truck::getMax() {
    return maximum_load;
}

void truck::print(std::ostream &os) const {

    os << "Manufacturer Name: " << this->getManufacturerName() << std::endl;
    os << "Country: " << this->getCountry() << std::endl;
    os << "Fuel: " << this->getFuel() << std::endl;
    os << "Production Year: " << this->getProductionYear() << std::endl;
    os << "Maximum Load: " << maximum_load << std::endl;
    os << "Fuel Economy: " << fuel_economy << std::endl;
    os << std::endl;
}

truck& truck::operator=(const truck& rhs){

    this->maximum_load = rhs.maximum_load;
    this->fuel_economy = rhs.fuel_economy;
    this->setProductionYear(rhs.getProductionYear());
    this->setFuel(rhs.getFuel());
    this->setCountry(rhs.getCountry());
    this->setManufacturerName(rhs.getManufacturerName());

    return *this;

}

int truck::getTruckCount() {
    return truck_count;
}

