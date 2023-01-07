#ifndef TEMA3_BILETTRAMVAI_H
#define TEMA3_BILETTRAMVAI_H

#include "Bilet.h"
#include "IOstream.h"
class BiletTramvai : public Bilet{

    int nrCalatorii;

public:
    int getNrCalatorii() const;

    void setNrCalatorii(int nrCalatorii);

    BiletTramvai(int nrCalatorii_ = 1);

    ~BiletTramvai() override;

    void print(std::ostream& os) const override;

    Bilet *clone() const override;
};


#endif //TEMA3_BILETTRAMVAI_H
