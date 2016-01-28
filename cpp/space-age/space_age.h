#include <cstddef>

namespace space_age {
    struct space_age {
        space_age(size_t seconds) : _seconds(seconds) {}

        size_t seconds() const { return _seconds; }

        double    on_earth() const { return _seconds / (       1.0 * 31557600); }
        double  on_mercury() const { return _seconds / ( 0.2408467 * 31557600); }
        double    on_venus() const { return _seconds / (0.61519726 * 31557600); }
        double     on_mars() const { return _seconds / ( 1.8808158 * 31557600); }
        double  on_jupiter() const { return _seconds / ( 11.862615 * 31557600); }
        double   on_saturn() const { return _seconds / ( 29.447498 * 31557600); }
        double   on_uranus() const { return _seconds / ( 84.016846 * 31557600); }
        double  on_neptune() const { return _seconds / ( 164.79132 * 31557600); }
      private:
        size_t _seconds;
    };
}

