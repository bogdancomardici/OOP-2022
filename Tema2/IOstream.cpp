#include "IOstream.h"

std::ostream & operator <<(std::ostream &os, const IOStream&rhs) {
    rhs.print(os);
    return os;
}

std::ostream &operator<<(std::ostream &os, const IOStream *rhs) {
    rhs->print(os);
    return os;
}
