//
// Created by alexb on 1/3/2023.
//

#include "BiletTramvai.h"

BiletTramvai::BiletTramvai(int nrCalatorii_) : Bilet("Tramvai", 3 * nrCalatorii_, 60, GenerateID::getID()), nrCalatorii(nrCalatorii_) {
    GenerateID::id++;
}

BiletTramvai::~BiletTramvai() {
    GenerateID::id--;
}

void BiletTramvai::print(std::ostream &os) const {

    os << "Mijloc Transport: " << this->getMijlocTransport() << std::endl;
    os << "Pret: " << this->getPret() << std::endl;
    os << "Valabilitate: " << this->getValabilitate() << std::endl;
    os << "Nr. Calatorii: " << this->getNrCalatorii() << std::endl;
    os << "ID: " << this->getIdBilet() << std::endl << std::endl;
}

Bilet* BiletTramvai::clone() const {

    return new BiletTramvai(*this);
}

int BiletTramvai::getNrCalatorii() const {
    return nrCalatorii;
}

void BiletTramvai::setNrCalatorii(int nrCalatorii) {
    BiletTramvai::nrCalatorii = nrCalatorii;
}
