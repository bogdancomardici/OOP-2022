#include "exception_invalid_year.h"

const char *exception_invalid_year::what() const noexcept {
    return "The Production Year can't be  greater than current year\n";
}
