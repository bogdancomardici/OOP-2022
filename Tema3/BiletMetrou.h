#ifndef TEMA3_BILETMETROU_H
#define TEMA3_BILETMETROU_H

#include "Bilet.h"
#include "IOstream.h"

class BiletMetrou : public Bilet{
public:

    BiletMetrou();

    ~BiletMetrou() override;

    void print(std::ostream& os) const override;

    Bilet * clone() const override;
};


#endif //TEMA3_BILETMETROU_H
