#ifndef TEMA2_V3_TRUCK_H
#define TEMA2_V3_TRUCK_H

#include "vehicle.h"
class truck: public vehicle {

    static int truck_count;
    int maximum_load;
    float fuel_economy;

public:

    static int getTruckCount();
    explicit truck(const std::string &manufacturerName = "", const std::string &country = "", const std::string &fuel = "", int productionYear = -1,
          int maximumLoad = 0, float fuelEconomy = 0.0);

    ~truck() override;

    truck(const truck& t);

    int getMaximumLoad() const;

    void setMaximumLoad(int maximumLoad);

    float getFuelEconomy() const;

    void setFuelEconomy(float fuelEconomy);

    int getMax() override;

    void print(std::ostream &os) const override;

    truck& operator=(const truck& rhs);
};


#endif //TEMA2_V3_TRUCK_H
