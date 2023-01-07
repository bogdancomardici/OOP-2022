#include "Bilet.h"

#include <utility>

Bilet::Bilet(std::string mijlocTransport, float pret, int valabilitate, int idBilet) : mijlocTransport(std::move(mijlocTransport)),
                                                                                              pret(pret),
                                                                                              valabilitate(valabilitate),
                                                                                              idBilet(idBilet){}
Bilet::~Bilet() = default;

const std::string &Bilet::getMijlocTransport() const {
    return mijlocTransport;
}

void Bilet::setMijlocTransport(const std::string &mijlocTransport_) {
    Bilet::mijlocTransport = mijlocTransport_;
}

float Bilet::getPret() const {
    return pret;
}

void Bilet::setPret(float pret_) {
    Bilet::pret = pret_;
}

int Bilet::getValabilitate() const {
    return valabilitate;
}

void Bilet::setValabilitate(int valabilitate_) {
    Bilet::valabilitate = valabilitate_;
}

int Bilet::getIdBilet() const {
    return idBilet;
}

void Bilet::setIdBilet(int idBilet_) {
    idBilet = idBilet_;
}











