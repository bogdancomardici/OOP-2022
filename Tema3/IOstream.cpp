//
// Created by alexb on 1/3/2023.
//

#include "IOstream.h"

std::ostream& operator<<(std::ostream &os, const IOstream& rhs){
    rhs.print(os);
    return os;
}