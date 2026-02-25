// Copyright [2023] <Michael Jreij>"  [legal/copyright]
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] <<
        " <input_filename> <output_filename> <seed>" << std::endl;
        return 1;
    }

    sf::Image image;
    if (!image.loadFromFile(argv[1])) {
        std::cerr << "Error loading image from file." << std::endl;
        return 1;
    }

    FibLFSR lfsr(argv[3]);
    PhotoMagic::transform(image, &lfsr);

    if (!image.saveToFile(argv[2])) {
        std::cerr << "Error saving image to file." << std::endl;
        return 1;
    }

    PhotoMagic::displayImage(image);

    return 0;
}

// ./PhotoMagic cat.jpg cat-out.bmp 1011011000110110
// ./PhotoMagic cat-out.bmp decoded_output.bmp 1011011000110110
