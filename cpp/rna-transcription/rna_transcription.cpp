#include "rna_transcription.h"
#include <stdexcept>

namespace transcription {
    char to_rna(char n) {
        switch(n) {
            case 'A': return 'U';
            case 'C': return 'G';
            case 'G': return 'C';
            case 'T': return 'A';
        }
        throw std::invalid_argument("n");
    }

    std::string to_rna(std::string s) {
        for (auto& c : s)
            c = to_rna(c);
        return s;
    }
}

