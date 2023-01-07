#ifndef TEMA2_V3_MANUFACTURER_H
#define TEMA2_V3_MANUFACTURER_H

#include <string>
#include "IOstream.h"
class manufacturer: public IOStream {

    std::string manufacturer_name;
    std::string country;

public:

    explicit manufacturer(std::string manufacturerName = "", std::string country = "");

    manufacturer(const manufacturer & m);

    virtual ~manufacturer();

    const std::string &getManufacturerName() const;

    void setManufacturerName(const std::string &manufacturerName);

    const std::string &getCountry() const;

    void setCountry(const std::string &country_);

    void print(std::ostream &os) const override;

    manufacturer& operator=(const manufacturer& rhs);
};


#endif //TEMA2_V3_MANUFACTURER_H
