#include <boost/dynamic_bitset.hpp>
#include <vector>
#include <iostream>

namespace sieve {
    std::vector<int> primes(unsigned n)
    {
        using namespace std;
        boost::dynamic_bitset<> sieve(n);
        sieve = ~sieve;
        
        std::vector<int> result;
        for(auto p = sieve.find_next(1); p < n; p = sieve.find_next(p)) {
            result.push_back(p);
            for(unsigned removal = p+p; removal < n; removal += p)
                sieve.reset(removal);
        }

        return result;
    }
}

