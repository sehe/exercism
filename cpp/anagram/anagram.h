#pragma once
#include <string>
#include <vector>

namespace anagram {
    struct engine {
        std::string _original;
        std::vector<char> _pool;

        engine(std::string const&);
        std::vector<std::string> matches(std::vector<std::string> const&) const;
    };

    engine anagram(std::string const&);
}
