#include "fruit.hpp"
#include <time.h>

Fruit::Fruit() {
        frt.loadFromFile("res/green.png");
        frs.setTexture(frt);
        srand(time(0));
        die();
}
Fruit::~Fruit() {}

void Fruit::update() {}

void Fruit::render(sf::RenderWindow *window) {
        frs.setPosition(f.x * 16, f.y * 16);
        window->draw(frs);
}

int Fruit::getX() {
        return f.x;
};

int Fruit::getY() {
        return f.y;
};

void Fruit::die() {
        f.x = rand() % 64;
        f.y = rand() % 48;
}

