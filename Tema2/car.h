#ifndef TEMA2_V3_CAR_H
#define TEMA2_V3_CAR_H

#include "vehicle.h"
#include "exception_negative_number.h"
#include "exception_invalid_year.h"
class car: public vehicle {

    static int car_count;
    int power;
    int maximum_speed;

public:

    static int getCarCount();

    explicit car(const std::string &manufacturerName = "", const std::string &country = "", const std::string &fuel = "", int productionYear = -1,
        int power = 0, int maximumSpeed = 0);

    car(const car& c);

    ~car() override;

    int getPower() const;

    void setPower(int power);

    int getMaximumSpeed() const;

    void setMaximumSpeed(int maximumSpeed);

    int getMax() override;

    void print(std::ostream &os) const override;

    car& operator=(const car& rhs);

};


#endif //TEMA2_V3_CAR_H
