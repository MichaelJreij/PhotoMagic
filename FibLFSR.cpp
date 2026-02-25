// Copyright [2023] <Michael Jreij>"  [legal/copyright]
#include "FibLFSR.hpp"

FibLFSR::FibLFSR(std::string seed) : state(seed) {}

int FibLFSR::generate(int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        int feedback = (state[0]) ^ (state[2]) ^ (state[3]) ^ (state[5]);
        state = state.substr(1) + std::to_string(feedback);
        result = (result << 1) | feedback;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr) {
    os << lfsr.state;
    return os;
}
