#pragma once
#include <map>
#include <vector>
#include <string>
#include <ostream>

namespace std
{
    template <typename T>
        inline ostream& operator<<(ostream& wrapped, std::vector<T> const& item) {
            wrapped << '[';
            bool first = true;
            for (auto const& element : item) {
                wrapped << (!first ? "," : "") << element;
                first = false;
            }
            return wrapped << ']';
        }

    // teach Boost.Test how to print std::pair
    template <typename K, typename V>
        inline ostream&
        operator<<(ostream& wrapped, std::pair<const K, V> const& item)
        {
            return wrapped << '<' << item.first << ',' << item.second << '>';
        }

}
namespace grade_school {
    struct school {
        using Grade  = std::vector<std::string>;
        using Roster = std::map<int, Grade>;

        Roster const& roster() const;
        Grade  const& grade(int);

        void add(std::string name, int grade);

      private:
        Roster _roster;
    };
}

