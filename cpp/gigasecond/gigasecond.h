#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond {
    using boost::gregorian::date;
    namespace pt = boost::posix_time;

    date advance(date const& d) {
        return (pt::ptime(d, {}) + pt::seconds(1000000000u)).date();
    }
}
