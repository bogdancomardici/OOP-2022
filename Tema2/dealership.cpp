#include "dealership.h"

void dealership::read() {
    int type = -1;
    std::cout << "Vehicle Type" << std::endl << "Car - 0" << std::endl << "Truck - 1" << std::endl;
    std::cin >> type;
    if(type == 0)
    {
        std::string m, c, f;
        int y, p, s;

        std::cout << "Manufacturer Name: ";
        std::cin >> m;

        std::cout << "Country: ";
        std::cin >> c;

        std::cout << "Fuel: ";
        std::cin >> f;

        std::cout << "Production Year: ";
        std::cin >> y;

        std::cout << "Power: ";
        std::cin >> p;

        std::cout << "Maximum Speed: ";
        std::cin >> s;

        auto* temp = new car(m, c, f, y, p, s);
        man.push_back(std::shared_ptr<manufacturer>(temp));
    }
    else if(type == 1)
    {
        std::string m, c, f;
        int y, l;
        float fc;

        std::cout << "Manufacturer Name: ";
        std::cin >> m;

        std::cout << "Country: ";
        std::cin >> c;

        std::cout << "Fuel: ";
        std::cin >> f;

        std::cout << "Production Year: ";
        std::cin >> y;

        std::cout << "Maximum Load: ";
        std::cin >> l;

        std::cout << "Fuel Economy: ";
        std::cin >> fc;

        auto* temp = new truck(m, c, f, y, l, fc);
        man.push_back(std::shared_ptr<manufacturer>(temp));
    }


}

void dealership::print() {
    for(auto & i : man)
    {
        i->print(std::cout);
    }
}

std::shared_ptr<manufacturer> dealership::operator[](int i) {
    return man[i];
}

int dealership::noVehicles() {
    return (int)man.size();
}

void dealership::delete_vehicle(int i) {
    man.erase(man.begin() + i);
}

void dealership::printAllCars() {
    for(auto & i : man)
    {
        car* temp = dynamic_cast<car*>(i.get());
        if(temp != nullptr)
            i->print(std::cout);
    }

}

void dealership::printAllTrucks() {
    for(auto & i : man)
    {
        auto* temp = dynamic_cast<truck*>(i.get());
        if(temp != nullptr)
            i->print(std::cout);
    }
}
