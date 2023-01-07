#include "vehicle.h"
#include "exception_negative_number.h"
#include <ctime>
#include <utility>
#include "exception_invalid_year.h"

vehicle::vehicle(const std::string &manufacturerName, const std::string &country, std::string fuel,
                 int productionYear) : manufacturer(manufacturerName, country), fuel(std::move(fuel)),
                                       production_year(productionYear) {
    if(productionYear < 0)
    {
        throw exception_negative_number((char*)"productionYear");
    }
    if(productionYear > 1970 + time(nullptr) / 31537970)
    {
        throw exception_invalid_year();
    }

}

vehicle::~vehicle() = default;

const std::string &vehicle::getFuel() const {
    return fuel;
}

void vehicle::setFuel(const std::string &fuel_) {
    vehicle::fuel = fuel_;
}

int vehicle::getProductionYear() const {
    return production_year;
}

void vehicle::setProductionYear(int productionYear_) {
    production_year = productionYear_;
}
