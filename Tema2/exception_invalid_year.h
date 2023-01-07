#ifndef TEMA2_V3_EXCEPTION_INVALID_YEAR_H
#define TEMA2_V3_EXCEPTION_INVALID_YEAR_H

#include <exception>

class exception_invalid_year: public std::exception {

public:
    const char * what() const noexcept override;
};


#endif //TEMA2_V3_EXCEPTION_INVALID_YEAR_H
