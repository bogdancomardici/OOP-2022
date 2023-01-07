#include <iostream>
#include "dealership.h"
#include "car.h"
#include "truck.h"

using namespace std;

int car::car_count = 0;
int truck::truck_count = 0;
int main() {

/*
    manufacturer M("VW", "Germany");
    manufacturer B("Dacia", "Romania");
    manufacturer F(M);
    B = M;
    M.print(cout);
    cout << M << B << F;

    car C("VW","Germany","Gasoline",2020,150,200);
    car cc(C);

    cout << cc;
    cout << "car count: " << car::getCarCount() << endl;
    cout << C;
    C.print(cout);


    truck T("Scania", "Sweden", "Diesel", 2015, 13000, 7.3);
    cout << "truck count: " << truck::getTruckCount() << endl;
    cout << T;
    T.print(cout);

    cout << "GETMAX: " << endl << C.getMax() << endl << T.getMax() << endl << endl;

    vehicle* v = &T;
    v->print(cout);
    v = &C;
    v->print(cout);


*/

    cout << "FOR VIRTUAL FUNCTIONS AND COPY CONSTRUCTOR DEMOS UNCOMMENT THE CODE ABOVE" << endl << endl;
    int choice = -1;
    dealership d;
    while(choice != 0)
    {
        cout << "1 - Add Vehicle" << endl;
        cout << "2 - Delete Vehicle" << endl;
        cout << "3 - List Vehicles" << endl;
        cout << "4 - List cars" << endl;
        cout << "5 - List trucks" << endl;
        cout << "0 - Exit" << endl;

        cin >> choice;

        if(choice == 0)
            break;

        if(choice == 1)
            try
            {
                d.read();
            }
            catch(exception_invalid_year &e)
            {
                cout << e.what();
            }
            catch(exception_negative_number &e)
            {
                cout << e.what();
            }
            catch(...)
            {
                cout << "An unknown exception occurred" << endl;
            }

        if(choice == 2)
        {
            if(d.noVehicles() == 0)
                cout << "No vehicles found" << endl;
            else
            {
                int del = -1;
                cout << "Choose which vehicle to delete" << endl;

                for (int i = 0; i < d.noVehicles(); i++)
                    cout << i << "." << endl << d[i];

                cin >> del;

                if (del >= 0 and del < d.noVehicles())
                    d.delete_vehicle(del);
                else
                    cout << "Invalid Vehicle Index" << endl;
            }
        }

        if(choice == 3)
        {
            if(d.noVehicles() == 0)
                cout << "No vehicles found" << endl;
            else
                d.print();
        }

        if(choice == 4)
        {
            if(d.noVehicles() == 0)
                cout << "No vehicles found" << endl;
            else
                d.printAllCars();
        }

        if(choice == 5)
        {
            if(d.noVehicles() == 0)
                cout << "No vehicles found" << endl;
            else
                d.printAllTrucks();
        }

    }

    return 0;
}
