#include "manufacturer.h"

#include <utility>

manufacturer::manufacturer(std::string manufacturerName, std::string country) : manufacturer_name(std::move(manufacturerName)),
                                                                                    country(std::move(country)) {}

manufacturer::~manufacturer() = default;

const std::string &manufacturer::getManufacturerName() const {
    return manufacturer_name;
}

void manufacturer::setManufacturerName(const std::string &manufacturerName_) {
    manufacturer_name = manufacturerName_;
}

const std::string &manufacturer::getCountry() const {
    return country;
}

void manufacturer::setCountry(const std::string &country_) {
    manufacturer::country = country_;
}

void manufacturer::print(std::ostream &os) const {

    os << "Manufacturer Name: " << manufacturer_name << std::endl;
    os << "Country: " << country << std::endl;
    os << std::endl;
}

manufacturer::manufacturer(const manufacturer& m) {
    this->manufacturer_name = m.manufacturer_name;
    this->country = m.country;
}

manufacturer &manufacturer::operator=(const manufacturer &rhs) {
    this->manufacturer_name = rhs.manufacturer_name;
    this->country = rhs.country;

    return *this;
}



