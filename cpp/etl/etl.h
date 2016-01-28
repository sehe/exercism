#include <map>
#include <vector>

namespace etl {
    std::map<char, int> transform(std::map<int, std::vector<char> > const& old) {
        std::map<char, int> result;

        for (auto& oe : old) {
            for (auto& oec : oe.second) {
                auto insertion = result.emplace(std::tolower(static_cast<uint8_t>(oec)), oe.first);

                if (!insertion.second) {
                    throw std::logic_error("score not unique");
                }
            }
        }

        return result;
    }
}

