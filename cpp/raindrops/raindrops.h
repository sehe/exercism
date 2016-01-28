#include <string>
namespace raindrops {

    std::string convert(size_t n) {
        std::string r;
        if (n%3 == 0) r += "Pling";
        if (n%5 == 0) r += "Plang";
        if (n%7 == 0) r += "Plong";

        if (r.empty())
            return std::to_string(n);
        else
            return r;
    }
}

