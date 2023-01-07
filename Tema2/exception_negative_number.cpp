#include "exception_negative_number.h"

exception_negative_number::exception_negative_number(char *fname) {
    strcpy(this->field_name, fname);
}
const char *exception_negative_number::what() const noexcept {

    static char message[60] = "This field can't be a negative value: ";
    strcat(message, this->field_name);
    strcat(message, "\n");

    return message;
}
