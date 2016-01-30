#include <string>

namespace binary {
    uint64_t convert(std::string const& s) {
        uint64_t r = 0;
        for (char ch : s) {
            r *= 2;
            if (ch=='1') r += 1;
            else if (ch!='0') return 0;
        }
        return r;
    }
}

