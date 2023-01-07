#include "car.h"
#include "exception_negative_number.h"
#include "exception_invalid_year.h"
#include <ctime>
car::car(const std::string &manufacturerName, const std::string &country, const std::string &fuel, int productionYear,
         int power, int maximumSpeed) : vehicle(manufacturerName, country, fuel, productionYear), power(power),
                                        maximum_speed(maximumSpeed) {
    car_count++;
    if(power < 0)
    {
        throw exception_negative_number((char*)"Power");
    }

    if(productionYear < 0)
    {
        throw exception_negative_number((char*)"productionYear");
    }

    if(maximumSpeed < 0)
    {
        throw exception_negative_number((char*)"maximumSpeed");
    }

    if(productionYear > 1970 + time(nullptr) / 31537970)
    {
        throw exception_invalid_year();
    }
}

car::~car() {
car_count--;
}

car::car(const car &c): vehicle(c.getManufacturerName(), c.getCountry(), c.getFuel(), c.getProductionYear()) {
    this->maximum_speed = c.maximum_speed;
    this->power = c.power;
    this->setManufacturerName(c.getManufacturerName());
    this->setCountry(c.getCountry());
    this->setFuel(c.getFuel());
    this->setProductionYear(c.getProductionYear());

    car_count++;
}

int car::getPower() const {
    return power;
}

void car::setPower(int power_) {
    car::power = power_;
}

int car::getMaximumSpeed() const {
    return maximum_speed;
}

void car::setMaximumSpeed(int maximumSpeed_) {
    maximum_speed = maximumSpeed_;
}

int car::getMax(){
    return maximum_speed;
}

void car::print(std::ostream &os) const {

    os << "Manufacturer Name: " << this->getManufacturerName() << std::endl;
    os << "Country: " << this->getCountry() << std::endl;
    os << "Fuel: " << this->getFuel() << std::endl;
    os << "Production Year: " << this->getProductionYear() << std::endl;
    os << "Power: " << power << std::endl;
    os << "Maximum Speed: " << maximum_speed << std::endl;
    os << std::endl;
}

car& car::operator=(const car &rhs) {
    this->maximum_speed = rhs.maximum_speed;
    this->power = rhs.power;
    this->setManufacturerName(rhs.getManufacturerName());
    this->setCountry(rhs.getCountry());
    this->setFuel(rhs.getFuel());
    this->setProductionYear(rhs.getProductionYear());

    return *this;
}

int car::getCarCount()
{
    return car_count;
}