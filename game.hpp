#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

class Game {
public:
        Game();
        ~Game();

        void update();
        void render();
        void run();
private:
        sf::Texture field;
        sf::Sprite spf;
        const float FRAMERATE = 5;
        const float FPS = 1000 / FRAMERATE;
        sf::Clock clock;
        sf::Time time;
        sf::RenderWindow window;
        sf::Event event;
        Snake snake;
        Fruit fruit;
};

#endif
