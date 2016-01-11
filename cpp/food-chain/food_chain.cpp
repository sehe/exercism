#include "food_chain.h"
#include <iterator>
#include <algorithm>
#include <cassert>
#include <vector>

namespace food_chain {
    std::string sing() {
        return verses(1, 8);
    }

    std::string verses(int from, int const to) {
        using namespace std;
        assert(from <= to);

        string builder;
        while (from <= to) {
            builder += verse(from++) + "\n";
        }

        return builder;
    }

    std::string verse(int index) {
        using namespace std;

        struct configitem { const string species, decoration, recurring_decoration; };

        using Config = vector<configitem>;
        static Config const config {
            { "fly", "I don't know why she swallowed the fly. Perhaps she'll die.", ".\nI don't know why she swallowed the fly. Perhaps she'll die" },
            { "spider", "It wriggled and jiggled and tickled inside her.", " that wriggled and jiggled and tickled inside her" },
            { "bird", "How absurd to swallow a bird!", "" },
            { "cat", "Imagine that, to swallow a cat!", "" },
            { "dog", "What a hog, to swallow a dog!", "" },
            { "goat", "Just opened her throat and swallowed a goat!", "" },
            { "cow", "I don't know how she swallowed a cow!", "" },
            { "horse", "She's dead, of course!", "" },
        };

        assert(begin(config) + index <= end(config));

        string builder;
        bool first = true;

        using RIt = Config::const_reverse_iterator;

        for(auto it = RIt(begin(config) + index), prev = it; it != config.rend(); prev = it++) {
            if (first) {
                first = false;

                builder += "I know an old lady who swallowed a " + it->species + ".\n";

                if (!it->decoration.empty()) {
                    builder += it->decoration + "\n";
                }

                if ("horse" == it->species)
                    return builder; // EARLY OUT!
            } else {
                builder += "She swallowed the " + prev->species + " to catch the " + it->species;
                
                if (!it->recurring_decoration.empty()) {
                    builder += it->recurring_decoration;
                }

                builder += ".\n";
            }
        }

        //builder += "I don't know why she swallowed the fly. Perhaps she'll die.\n";

        return builder;
    }
}

