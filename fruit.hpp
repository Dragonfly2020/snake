#ifndef _FRUIT_HPP_
#define _FRUIT_HPP_

#include <SFML/Graphics.hpp>

class Fruit {
public:
        Fruit();
        ~Fruit();

        void update();
        void render(sf::RenderWindow *window);
        int getX();
        int getY();
        void die();

private:
        sf::Texture frt;
        sf::Sprite frs;
        struct fruit {
                int x;
                int y;
        } f;

};

#endif
