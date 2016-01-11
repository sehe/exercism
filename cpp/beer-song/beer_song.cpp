#include "beer_song.h"
#include <cassert>

namespace beer {
    static std::string beer_expr(int i) {
        switch (i) {
            case 0: return "No more bottles of beer";
            case 1: return "1 bottle of beer";
        }
        return std::to_string(i) + " bottles of beer";
    }

    static void uncapitalize(std::string& sentence) {
        if (sentence.empty())
            return;

        sentence[0] = std::tolower(static_cast<uint8_t>(sentence[0]));
    }

    std::string sing(int from, int downto) {
        assert(from >= downto);
        using namespace std;
        string builder;
        while (from >= downto) {
            builder += verse(from--);
            if (from >= downto)
                builder += "\n";
        }

        return builder;
    }

    std::string verse(int i) {
        assert(i >= 0);

        using namespace std;

        string builder;
        
        auto be = beer_expr(i);
        builder += be + " on the wall, ";

        uncapitalize(be);
        builder += be + ".\n";

        if (i) {
            i -= 1;
            be = beer_expr(i);
            uncapitalize(be);

            if (i)
                builder += "Take one down and pass it around, " + be + " on the wall.\n"; 
            else
                builder += "Take it down and pass it around, " + be + " on the wall.\n"; 
        } else {
            builder += "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }

        return builder;
    }
}
