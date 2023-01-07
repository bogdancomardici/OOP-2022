// 1. Doua sabolane de proiectare
// a) Clasa Menu e Singleton deoarece exista doar un singur meniu in aolicatie
// b) Clasa Bilet e Prototype deoarece defineste functia clone iar toate subclasele sale o implementeaza
// 2. O clasa sablon
// -Clasa Abonament este sablon, se pot crea abonamente pe baza oricarui tip de bilet
// 3. O metoda sablon
// -Metoda sablon de reducere a pretului functioneaza atat pe bilete cat si pe abonamente sau alte obiecte care au pret
// 4. O metoda sablon specializata
// -Metoda reducere este specializata pentru obiectele de tip bilet, reducerea aplicata acestora fiind diferita de restul
// 5. O clasa pentru generat ID-uri
// -Clasa GenerateID genereaza cate un ID unic pentru fiecare bilet prin intermediul unei variabile si a unei functii statice
// 6. Metoda clone
// - Este implementata de toate subclasele clasei Bilet care este de tip Prototype
// 7. Code Style
// - Pe tot parcursul proiectului a fost folosit camelCase
// 8. Metoda virtuala de afisare
// - Toate obiectele care trebuies afisate mostenesc clasa IOstream si implementeaza functia de afisare,
//   operatorul de afisare fiind functie prieten care apeleaza metoda de afisare

#include "Bilet.h"
#include "Menu.h"

int GenerateID::id = 0;
Menu* Menu::menuPtr = nullptr;
int main() {

    /*
    {
        BiletAutobuz a;
        BiletTramvai t;
        BiletMetrou m;

        std::cout << a << t << m;
        a.print(std::cout);
        t.print(std::cout);
        m.print(std::cout);
    }

    BiletMetrou m1;
    std::cout << m1;

    Abonament<BiletMetrou> a1("Andrei");
    Abonament<BiletTramvai> a2("Bogdan");
    Abonament<BiletAutobuz> a3("Cristi");

    std::cout << a1 << a2 << a3;



    BiletAutobuz a;
    BiletMetrou m;

    Bilet* b = a.clone();
    b->print(std::cout);

    auto m1  = m.clone();
    m1->print(std::cout);

    Abonament<BiletMetrou> t1("bogdan");
    t1.print(std::cout);

    reducere(&t1);
    t1.print(std::cout);

    BiletTramvai t4;
    t4.print(std::cout);
    reducere((Bilet*)&t4);
    t4.print(std::cout);
*/

    auto m = Menu::getInstance();
    m->begin();

    return 0;
}
