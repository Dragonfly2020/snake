#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Snake {
public:
        Snake();
        ~Snake();

        void update();
        void render(sf::RenderWindow *window);

        int getX();
        int getY();

        void setDir(int dir);
        void upper();
private:
        sf::Texture st;
        sf::Sprite ss;
        int x;
        int y;
        int dir, num = 4;

        int N = 64, M = 48;
        int size = 16;

        struct snake {
                int x;
                int y;
        } s[100];
};

#endif
