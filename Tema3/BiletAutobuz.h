#ifndef TEMA3_BILETAUTOBUZ_H
#define TEMA3_BILETAUTOBUZ_H

#include "Bilet.h"
#include "IOstream.h"
#include <string>
class BiletAutobuz : public Bilet{

    std::string metodaAchizitie;

public:
    const std::string &getMetodaAchizitie() const;

    void setMetodaAchizitie(const std::string &metodaAchizitie);

    explicit BiletAutobuz(std::string metodaAchizitie_ = "");

    ~BiletAutobuz() override;

    void print(std::ostream &os) const override;

    Bilet * clone() const override;
};


#endif //TEMA3_BILETAUTOBUZ_H
