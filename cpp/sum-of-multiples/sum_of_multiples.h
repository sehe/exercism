#include <set>
#include <cstdint>
#include <numeric>
#include <iostream>

namespace sum_of_multiples {
    uint64_t to(std::set<uint16_t> const& ff, uint64_t const n) {
        if (!n) return 0;

        auto series = [n](uint64_t f) {
            auto m = (n-1)/f;
            return f * m * (m+1); // dropped the `/2`, because it can be done in the very end
        };

        return std::accumulate(ff.begin(), ff.end(), uint64_t{0},
            [&](uint64_t acc, uint64_t f) {
                return acc 
                  + series(f) 
                  - std::accumulate(ff.begin(), ff.lower_bound(f), uint64_t{0}, [&](uint64_t acc, uint16_t f2) { return acc + series(f*f2); });
            }) / 2; // division by two added here
    }

    uint64_t to(uint64_t n) {
        return to({3,5}, n);
    }
}

