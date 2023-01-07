#ifndef TEMA3_MENU_H
#define TEMA3_MENU_H

#include "Bilet.h"
#include "BiletTramvai.h"
#include "BiletMetrou.h"
#include "BiletAutobuz.h"
#include "Abonament.cpp"
#include "IOstream.h"
#include <vector>
#include <string>

class Menu {

private:

    static Menu* menuPtr;
    Menu()= default;
    std::vector<Bilet*> B;
    std::vector<Abonament<Bilet>*> A;

public:

    static Menu* getInstance()
    {
        if(menuPtr == nullptr)
        {
            menuPtr = new Menu;
            return menuPtr;
        }
        else
            return menuPtr;
    }
    void begin();

    void addBilet();

    void addAbonament();

    void printBilete();

    void printAbonamente();

    void deleteBilet();

    void deleteAbonament();
};


#endif //TEMA3_MENU_H
