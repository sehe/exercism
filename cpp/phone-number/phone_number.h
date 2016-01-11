#pragma once
#include <string>

struct phone_number {
    phone_number(std::string input);

    std::string number() const;
    std::string area_code() const;

    explicit operator std::string() const;

  private:
    std::string _rep;
};

