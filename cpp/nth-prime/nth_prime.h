#include <cstdint>
#include <stdexcept>
#include <deque>

namespace  prime {

    uint64_t nth(unsigned n) {
        if (!n)   throw std::domain_error("n");
        if (!--n) return 2;

        std::deque<uint64_t> primes;
        primes.push_back(2);

        auto is_prime = [&](uint64_t p) {
            for (auto known : primes) {
                if (!(p % known)) return false;
                if (known > p/2)  break;
            }
            return true;
        };

        for (uint64_t p = 3; n; p+=2) {
            if (is_prime(p)) {
                primes.push_back(p);
                if (!--n)
                    return p;
            }
        }

        throw std::logic_error("unreachable");
    }
}
