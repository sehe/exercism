#include <stdexcept>

namespace hamming {
    template <typename R1, typename R2>
    size_t compute(R1 const& a, R2 const& b) {
        using namespace std;
        auto af = begin(a), al = end(a);
        auto bf = begin(b), bl = end(b);

        size_t distance = 0;

        while (af != al && bf != bl) {
            if (*af++ != *bf++)
                distance += 1;
            if ((af==al) != (bf==bl))
                throw std::domain_error("Lengths don't match");
        }

        return distance;
    }
}
