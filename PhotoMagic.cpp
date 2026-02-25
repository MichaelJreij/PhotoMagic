// Copyright [2023] <Michael Jreij>"  [legal/copyright]
#include "PhotoMagic.hpp"

namespace PhotoMagic {  

    void transform(sf::Image& image, FibLFSR* lfsr) {
        sf::Vector2u size = image.getSize();

        for (unsigned int x = 0; x < size.x; ++x) {
            for (unsigned int y = 0; y < size.y; ++y) {
                sf::Color pixel = image.getPixel(x, y);

                pixel.r ^= lfsr->generate(8);
                pixel.g ^= lfsr->generate(8);
                pixel.b ^= lfsr->generate(8);

                image.setPixel(x, y, pixel);
            }
        }
    }

    void displayImage(const sf::Image& image) {
        sf::RenderWindow window
(sf::VideoMode(image.getSize().x, image.getSize().y), "Transformed Image");

        sf::Texture texture;
        texture.loadFromImage(image);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            window.draw(sprite);
            window.display();
        }
    }

}  //  namespace PhotoMagic
