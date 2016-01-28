#include <cstdint>

namespace grains {
    uint64_t square(uint8_t number) {
        return uint64_t{1} << (number-1);
    }
    uint64_t total(uint8_t up_to_incl = 64) {
        if (up_to_incl)
            return square(up_to_incl) + total(up_to_incl-1);
        return 0;
    }
}
