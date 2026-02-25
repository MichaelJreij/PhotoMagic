// Copyright [2023] <Michael Jreij>"  [legal/copyright]
#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <string>

class FibLFSR {
 public:
    FibLFSR(std::string seed);
    int generate(int k);

    friend std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);

 private:
    std::string state;
};

#endif  // FIBLFSR_H
