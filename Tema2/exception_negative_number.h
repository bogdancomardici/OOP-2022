#ifndef TEMA2_V3_EXCEPTION_NEGATIVE_NUMBER_H
#define TEMA2_V3_EXCEPTION_NEGATIVE_NUMBER_H

#include <exception>
#include <cstring>
class exception_negative_number: public std::exception {

    char field_name[20];
public:
    explicit exception_negative_number(char fname[20]);
    const char * what() const noexcept override;
};


#endif //TEMA2_V3_EXCEPTION_NEGATIVE_NUMBER_H
