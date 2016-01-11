#include "anagram.h"
#include <algorithm>
#include <iostream>

namespace anagram {
    engine::engine(std::string const &seed)
        : _original(seed),
          _pool(seed.begin(), seed.end())
    {
        std::for_each(_pool.begin(), _pool.end(), [](char& ch) { ch = std::tolower(static_cast<uint8_t>(ch)); });
        std::sort(_pool.begin(), _pool.end()); 
    }

    std::vector<std::string> engine::matches(std::vector<std::string> const &candidates) const {
        std::vector<std::string> result;
        std::copy_if(candidates.begin(), candidates.end(), back_inserter(result), [this](std::string s) {
            if (s.size() != _pool.size())
                return false;

            std::for_each(s.begin(), s.end(), [](char& ch) { ch = std::tolower(static_cast<uint8_t>(ch)); });
            if (s == _original)
                return false;

            std::sort(s.begin(), s.end()); 
            
            return s.size() == _pool.size() && std::equal(s.begin(), s.end(), _pool.begin());
        });

        return result;
    }

    engine anagram(std::string const &s) { return { s }; }
}
