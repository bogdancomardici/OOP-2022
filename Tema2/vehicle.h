#ifndef TEMA2_V3_VEHICLE_H
#define TEMA2_V3_VEHICLE_H

#include "manufacturer.h"
#include <string>

class vehicle: public manufacturer {

    std::string fuel;
    int production_year;

public:

    explicit vehicle(const std::string &manufacturerName = "", const std::string &country = "", std::string fuel = "",
            int productionYear = 0);

    ~vehicle() override;

    const std::string &getFuel() const;

    void setFuel(const std::string &fuel);

    int getProductionYear() const;

    void setProductionYear(int productionYear);

    virtual int getMax() = 0;

};


#endif //TEMA2_V3_VEHICLE_H
