#include "phone_number.h"
#include <algorithm>
#include <stdexcept>

phone_number::phone_number(std::string input) {
    // remove+erase idiom
    input.erase(
            std::remove_if(
                input.begin(), input.end(),
                [](uint8_t c) { return !std::isdigit(c); }
            ),
            input.end());

    if (input.length() == 10)
        _rep = input;
    else if (input.length() == 11 && input.front() == '1')
        _rep = input.substr(1);
    else _rep = "0000000000";
}

std::string phone_number::area_code() const {
    return _rep.substr(0,3);
}

std::string phone_number::number() const {
    return _rep; 
}

phone_number::operator std::string() const {
    return "(" + area_code() + ") " + _rep.substr(3,3) + "-" + _rep.substr(6);
}
