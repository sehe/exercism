#pragma once
#include <map>
#include <ostream>

namespace std
{
    template <typename K, typename V>
        inline ostream&
        operator<<(ostream& os, pair<const K, V> const& item) {
            return os << '<' << item.first << ',' << item.second << '>';
        }
}

namespace dna {
    struct counter {
        using Map = std::map<char, int>;

        counter(std::string const& dna_sequence);
        Map const& nucleotide_counts() const { return _counts;                } 
        size_t count(char nucleotide) const; 

      private:
        Map _counts;
    };

}
