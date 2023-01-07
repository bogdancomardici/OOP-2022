#include "Menu.h"

void Menu::addBilet() {

    int tip;
    std::cout << "Tip Bilet: \n 1 - Autobuz \n 2 - Metrou \n 3 - Tramvai\n";
    std::cin >> tip;

    switch (tip) {
        case 1:
        {
            std::string metodaAchizitie_;
            int t = 0;
            std::cout << "Metoda de achizitie a biletului: \n 1 - Cash \n 2 - Card \n 3 - SMS \n";
            std::cin >> t;
            if(t < 1 || t > 3)
                std::cout << "Alegere invalida\n";
            else
            {
                if(t == 1)
                    metodaAchizitie_ = "Cash";
                else if(t == 2)
                    metodaAchizitie_ = "Card";
                else
                    metodaAchizitie_ = "SMS";
            }
            auto a = new BiletAutobuz(metodaAchizitie_);
            B.push_back(a);
            break;
        }
        case 2:
        {
            auto a = new BiletMetrou();
            B.push_back(a);
            break;
        }
        case 3:
        {
            int nrCalatorii = 0;
            std::cout << "Nr. Calatorii: ";
            std::cin >> nrCalatorii;
            auto a = new BiletTramvai(nrCalatorii);
            B.push_back(a);
            break;
        }
        default:
            std::cout << "Optiune invalida\n";


    }


}

void Menu::printBilete() {

    for(auto & i : B)
        i->print(std::cout);
}

void Menu::addAbonament() {

    int tip;
    std::string nume;
    std::cout << "Nume:";
    std::cin >> nume;
    std::cout << "Tip Abonament: \n 1 - Autobuz \n 2 - Metrou \n 3 - Tramvai\n";
    std::cin >> tip;

    switch (tip) {
        case 1:
        {
            auto a = new Abonament<BiletAutobuz>(nume);
            A.push_back(reinterpret_cast<Abonament<Bilet> *const>(a));
            break;
        }
        case 2:
        {
            auto a = new Abonament<BiletMetrou>(nume);
            A.push_back(reinterpret_cast<Abonament<Bilet> *const>(a));
            break;
        }
        case 3:
        {
            auto a = new Abonament<BiletTramvai>(nume);
            A.push_back(reinterpret_cast<Abonament<Bilet> *const>(a));
            break;
        }
        default:
            std::cout << "Optiune invalida\n";


    }
}

void Menu::printAbonamente() {

    for(auto & i : A)
        i->print(std::cout);
}

void Menu::deleteBilet() {

    std::cout << "Selecteaza biletul pentru stergere\n";

    int index = 0;
    for(auto & i : B)
    {
        std::cout << index << std::endl;
        i->print(std::cout);
        index++;
    }
    

    long int id;
    std::cout << "ID-ul biletului de sters:";
    std::cin >> id;
    if(id < 0 && id >= B.size())
        std::cout << "ID invalid\n";
    else
        B.erase(B.begin()+ id);
}

void Menu::deleteAbonament() {

    std::cout << "Selecteaza abonamentul pentru stergere\n";
    int index = 0;
    for(auto & i : A)
    {
        std::cout << index << std::endl;
        i->print(std::cout);
        index++;
    }

    long int id;
    std::cout << "ID-ul abonamentului de sters:";
    std::cin >> id;
    if(id < 0 && id >= A.size())
        std::cout << "ID invalid\n";
    else
        A.erase(A.begin()+ id);
}

void Menu::begin() {

    int action = -1;

    while(action != 0)
    {

        std::cout << "1 - Adauga Bilet\n";
        std::cout << "2 - Sterge Bilet\n";
        std::cout << "3 - Afiseaza Bilete\n";
        std::cout << "4 - Adauga Abonament\n";
        std::cout << "5 - Sterge Abonament\n";
        std::cout << "6 - Afiseaza Abonamente\n";
        std::cout << "7 - Reducere Bilet\n";
        std::cout << "8 - Reducere Abonament\n";
        std::cout << "0 - Iesi\n";

        std::cin >> action;
        if(action < 0 || action > 8)
            std::cout << "Actiune invalida\n";
        else {
            switch (action) {

                case 1:
                {
                    addBilet();
                    break;
                }
                case 2:
                {
                    deleteBilet();
                    break;
                }
                case 3:
                {
                    printBilete();
                    break;
                }
                case 4:
                {
                    addAbonament();
                    break;
                }
                case 5:
                {
                    deleteAbonament();
                    break;
                }
                case 6:
                {
                    printAbonamente();
                    break;
                }
                case 7:
                {
                    long int id;
                    int index = 0;
                    for(auto & i : B)
                    {
                        std::cout << index << std::endl;
                        i->print(std::cout);
                        index++;
                    }
                    std::cout << "Index-ul biletului redus:";
                    std::cin >> id;
                    if(id < 0 && id >= B.size())
                        std::cout << "ID invalid\n";
                    else
                        reducere((Bilet*)B[id]);
                    break;
                }
                case 8:
                {
                    int index = 0;
                    long int id;
                    for(auto & i : A)
                    {
                        std::cout << index << std::endl;
                        i->print(std::cout);
                        index++;
                    }
                    std::cout << "Index-ul abonamentului redus:";
                    std::cin >> id;
                    if(id < 0 && id >= A.size())
                        std::cout << "ID invalid\n";
                    else
                        reducere(A[id]);
                    break;
                }
                default:
                {
                    action = 0;
                    break;
                }
            }
        }
    }
}
