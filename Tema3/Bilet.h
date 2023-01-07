#ifndef TEMA3_BILET_H
#define TEMA3_BILET_H
#include <string>
#include "GenerateID.h"
#include "IOstream.h"

class Bilet: public GenerateID, public IOstream{

    std::string mijlocTransport;
    float pret;
    int valabilitate;
    int idBilet;

public:
    Bilet(std::string mijlocTransport, float pret, int valabilitate, int idBilet);

    int getIdBilet() const;

    void setIdBilet(int idBilet_);

    virtual ~Bilet();

    const std::string &getMijlocTransport() const;

    void setMijlocTransport(const std::string &mijlocTransport_);

    float getPret() const;

    void setPret(float pret_);

    int getValabilitate() const;

    void setValabilitate(int valabilitate_);

    virtual Bilet* clone() const = 0;

    void print(std::ostream &os) const override = 0;
};


#endif //TEMA3_BILET_H
