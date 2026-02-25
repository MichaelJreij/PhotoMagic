// Copyright [2023] <Michael Jreij>"  [legal/copyright]
#pragma once

#include <algorithm>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
    void transform(sf::Image& image, FibLFSR* lfsr);
    void displayImage(const sf::Image& image);
}
