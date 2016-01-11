#include "nucleotide_count.h"

namespace dna {
    counter::counter(std::string const& dna_sequence) 
        : _counts { {'A',0}, {'C',0}, {'G',0}, {'T',0} }
    {
        for (auto nucleotide : dna_sequence) {
            auto match = _counts.find(nucleotide);
            if (match != _counts.end()) {
                match->second++;
            }
        }
    }

    size_t counter::count(char nucleotide) const {
        auto match = _counts.find(nucleotide);
        if (match == _counts.end())
            throw std::invalid_argument("nucleotide");
        return _counts.at(nucleotide); 
    } 
}
