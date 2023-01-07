#ifndef TEMA3_IOSTREAM_H
#define TEMA3_IOSTREAM_H

#include <iostream>
class IOstream {

protected:

    virtual void print(std::ostream &os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const IOstream& rhs);
};


#endif //TEMA3_IOSTREAM_H
