#include "BiletAutobuz.h"
#include <utility>

BiletAutobuz::BiletAutobuz(std::string metodaAchizitie_) : Bilet("Autobuz", 2, 90, GenerateID::getID()), metodaAchizitie(std::move(metodaAchizitie_)) {
    GenerateID::id++;
}

void BiletAutobuz::print(std::ostream &os) const {

    os << "Mijloc Transport: " << this->getMijlocTransport() << std::endl;
    os << "Pret: " << this->getPret() << std::endl;
    os << "Valabilitate: " << this->getValabilitate() << std::endl;
    os << "Metoda Achizitie: " << this->getMetodaAchizitie() << std::endl;
    os << "ID: " << this->getIdBilet() << std::endl << std::endl;

}

BiletAutobuz::~BiletAutobuz(){
    GenerateID::id--;
}

Bilet* BiletAutobuz::clone() const {
    return new BiletAutobuz(*this);
}

const std::string &BiletAutobuz::getMetodaAchizitie() const {
    return metodaAchizitie;
}

void BiletAutobuz::setMetodaAchizitie(const std::string &metodaAchizitie_) {
    BiletAutobuz::metodaAchizitie = metodaAchizitie_;
}
