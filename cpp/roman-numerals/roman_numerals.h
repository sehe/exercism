#include <string>
#include <stdexcept>
#include <cassert>
#include <cstring>
#include <iostream>

namespace roman {
    std::string convert(unsigned n) {
        assert(n <= 3000);

        std::string r;

        auto pick = [&r](int dig, char const* set) {
            switch(dig) {
                case 0: break; // skip

                // additives
                case 1: case 2: case 3:              r.append(dig-0, set[0]); break;
                case 6: case 7: case 8: r += set[1]; r.append(dig-5, set[0]); break;

                // middle
                case 5: r += set[1]; break;

                // subtractive
                case 4: r += set[0]; r += set[1]; break;
                case 9: r += set[0]; r += set[2]; break;

                default: throw std::logic_error("invalid digit");
            }
        };

#if 1
        struct { int scale; char const* set; } const system[] = {
            { 1000, "M  " },
            {  100, "CDM" },
            {   10, "XLC" },
            {    1, "IVX" },
        };

        for (auto& p : system)
            pick((n%(10*p.scale)/p.scale), p.set);
#else
        // this removes some repetition from the meta data
        // at the cost of legibilty

        auto numerals = "IVXLCDM  ";
        auto set      = strchr(numerals, 'M');
        auto clip     = 10000;

        while (clip>1) {
            n %= clip;
            clip /= 10;
            pick(n / clip, set);
            set -= 2;
        }
#endif

        return r;
    }
}

