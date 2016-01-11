#include "grade_school.h"
#include <algorithm>

using namespace std;

namespace grade_school {
    school::Roster const& school::roster() const   { return _roster; }
    school::Grade  const& school::grade(int which) { return _roster[which]; }

    void school::add(string name, int into) {
        auto& g = _roster[into];

        auto range = equal_range(g.begin(), g.end(), name);

        if (range.first == range.second) {
            g.insert(range.second, std::move(name));
        }
    }
}

