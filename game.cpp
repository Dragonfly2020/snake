#include "game.hpp"
#include <SFML/Window/Keyboard.hpp>

Game::Game() {
        std::cout << "start game applicateon..." << std::endl;
        window.create(sf::VideoMode(1024, 768), "Snake Game...");
        field.loadFromFile("res/white.png");
        spf.setTexture(field);
}

Game::~Game() {
        std::cout << "stop game application..." << std::endl;
}

void Game::update() {
        snake.update();
        fruit.update();

        if(snake.getX() == fruit.getX() && snake.getY() == fruit.getY()) {
                fruit.die();
                snake.upper();
        }
}

void Game::render() {
        for(int i = 0; i < 64; i++) {
                for(int j = 0; j < 48; j++) {
                        spf.setPosition(i * 16, j * 16);
                        window.draw(spf);
                }
        }
        snake.render(&window);
        fruit.render(&window);
}

void Game::run() {

        time = clock.getElapsedTime();

        while(window.isOpen()) {
                while(window.pollEvent(event)) {
                        if(event.type == sf::Event::Closed) {
                                window.close();
                        }
                }
                window.clear();
                //
                update();
                render();
                //
                window.display();
                
                time = clock.getElapsedTime();
                if(time.asMilliseconds() < FPS) {
                        sf::sleep(sf::milliseconds(FPS - time.asMilliseconds()));
                }
                clock.restart();

        }
}

