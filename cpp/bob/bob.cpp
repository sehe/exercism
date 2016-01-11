#include <string>
#include <algorithm>

namespace bob {
    std::string hey(std::string s) {
        auto isspace = [](uint8_t c) { return std::isspace(c); };
        auto isupalp = [](uint8_t c) { return std::isupper(c) || !std::isalpha(c); };
        auto isalpha = [](uint8_t c) { return std::isalpha(c); };

        using namespace std;
        // trim
        auto f = find_if_not(s.begin() , s.end() , isspace);
        auto l = find_if_not(s.rbegin(), s.rend(), isspace).base();

        if (f >= l) {
            return "Fine. Be that way!";
        }

        bool shouting = std::any_of(f, l, isalpha) && std::all_of(f, l, isupalp);
        bool question = *(l-1) == '?';

        if (shouting)
            return "Whoa, chill out!";
        if (question)
            return "Sure.";

        return "Whatever.";
    }
}
