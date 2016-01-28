#include <string>
#include <sstream>
#include <iomanip>

namespace date_independent {

    struct time_of_day {
        time_of_day(unsigned mm) : _rep(mm % (24*60)) { }
        time_of_day(signed mm) {
            while (mm<0) mm += 24*60;
            _rep = mm % (24*60);
        }

        operator std::string() const {
            using namespace std;
            ostringstream oss;

            auto hh = _rep / 60;
            auto mm = _rep % 60;

            oss << setw(2) << setfill('0') << hh << ':'
                << setw(2) << setfill('0') << mm;
            return oss.str();
        }
        
        time_of_day plus (int mm) { return { _rep+24*60 + time_of_day{mm}._rep }; }
        time_of_day minus(int mm) { return { _rep+24*60 - time_of_day{mm}._rep }; }

        bool operator==(time_of_day const& other) const { return _rep == other._rep; }
        bool operator!=(time_of_day const& other) const { return _rep != other._rep; }

        friend std::ostream& operator<<(std::ostream& os, time_of_day const& tod) {
            return os << static_cast<std::string>(tod);
        }
      private:
        unsigned _rep;
    };

    struct clock {
        static time_of_day at(unsigned hh = 0, unsigned mm = 0) {
            return {hh*60 + mm};
        };
    };

}

