#include <stdexcept>
#include <algorithm>

namespace triangle {
    enum kinds { isosceles, equilateral, scalene };

    using Side = double;

    kinds kind(Side a, Side b, Side c) {
        using namespace std;
        bool ok = (a+b>c) && (a+c>b) && (b+c>a);
        if (!ok)
            throw domain_error("invalid sides");

        Side sides[] = { a,b,c };
        sort(begin(sides), end(sides));
        if (sides[0] == sides[2])
            return equilateral;
        else if (sides[0] == sides[1] || sides[1] == sides[2])
            return isosceles;
        return scalene;
    }
}

