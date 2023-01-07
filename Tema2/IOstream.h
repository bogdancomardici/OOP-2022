#ifndef TEMA2_V3_IOSTREAM_H
#define TEMA2_V3_IOSTREAM_H

#include <iostream>

class IOStream {

protected:

    virtual void print(std::ostream &os) const=0;
    friend std::ostream & operator <<(std::ostream &os, const IOStream& rhs);
    friend std::ostream & operator <<(std::ostream &os, const IOStream* rhs);

};


#endif //TEMA2_V3_IOSTREAM_H
