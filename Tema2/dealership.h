#ifndef TEMA2_V3_DEALERSHIP_H
#define TEMA2_V3_DEALERSHIP_H

#include <iostream>
#include "manufacturer.h"
#include "car.h"
#include "truck.h"
#include <vector>
#include <memory>



class dealership {

    std::vector<std::shared_ptr<manufacturer>> man;

public:

    void read();
    void print();
    void delete_vehicle(int i);
    int noVehicles();
    void printAllCars();
    void printAllTrucks();
    std::shared_ptr<manufacturer> operator[] (int i);

};


#endif //TEMA2_V3_DEALERSHIP_H
