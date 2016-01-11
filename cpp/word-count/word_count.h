#include <string>
#include <iterator>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <map>

using Map = std::map<std::string, int>;
namespace std {
    static inline std::ostream& operator<<(std::ostream& os, Map::value_type const& p) {
        return os << "{" << p.first << ", " << p.second << "}";
    }
}

namespace word_count {
    Map words(std::string const& text) {
        using namespace std;

        auto ignorable = [] (uint8_t c) { return ispunct(c) || isspace(c); } ;
        auto delim     = [=](uint8_t c) { return (c!='\'') && ignorable(c); } ;

        string accum;
        Map m;

        auto emit = [&] {
            // case fold & trim quotes
            boost::algorithm::to_lower(accum);
            boost::algorithm::trim_if(accum, boost::is_any_of("'"));

            if (!accum.empty() && !all_of(accum.begin(), accum.end(), ignorable))
                m[accum]++; 

            accum.clear();
        };

        for(auto f = begin(text), l = end(text); f!=l; ++f)
            if (delim(*f))
                emit();
            else
                accum += *f;

        emit();

        return m;
    }
}
