//
// Created by alexb on 1/3/2023.
//

#include "BiletMetrou.h"

BiletMetrou::BiletMetrou() : Bilet("Metrou" ,3 , 0, GenerateID::getID()) {
    GenerateID::id++;
}

BiletMetrou::~BiletMetrou() {
    GenerateID::id--;
}

void BiletMetrou::print(std::ostream &os) const {

    os << "Mijloc Transport: " << this->getMijlocTransport() << std::endl;
    os << "Pret: " << this->getPret() << std::endl;
    os << "Valabilitate: " << this->getValabilitate() << std::endl;
    os << "ID: " << this->getIdBilet() << std::endl << std::endl;
}

Bilet *BiletMetrou::clone() const {

    return new BiletMetrou(*this);
}
