#include <cstddef>

namespace squares {
    
    double square_of_sums(size_t n) {
        double r = n*n;
        r *= (n+1);
        r *= (n+1);
        r /= 4;
        return r;
    }

    double sum_of_squares(size_t n) {
        double r = n;
        r *= (n+1);
        r *= (2*n+1);
        r /= 6;
        return r;
    }

    double difference(size_t n) {
        return square_of_sums(n) - sum_of_squares(n);
    }
}

