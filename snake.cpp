#include "snake.hpp"

Snake::Snake() {
        st.loadFromFile("res/red.png");
        ss.setTexture(st);
}

Snake::~Snake() {}

void Snake::update() {
        for(int i = num; i > 0; i--) {
                s[i].x = s[i - 1].x;
                s[i].y = s[i - 1].y;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {setDir(1);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {setDir(2);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {setDir(3);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {setDir(0);}

        if(dir == 0) s[0].y += 1;
        if(dir == 1) s[0].x -= 1;
        if(dir == 2) s[0].x += 1;
        if(dir == 3) s[0].y -= 1;

        if(s[0].x > N) s[0].x = 0; if(s[0].x < 0) s[0].x = N;
        if(s[0].y > M) s[0].y = 0; if(s[0].y < 0) s[0].y = M;

        for(int i = 1; i < num; i++) {
                if(s[0].x == s[i].x && s[0].y == s[i].y) {
                        num = i;
                }
        }
}

void Snake::render(sf::RenderWindow *window) {
        for(int i = 0; i < num; i++) {
                ss.setPosition(s[i].x * size, s[i].y * size);
                window->draw(ss);
        }
}

int Snake::getX() {
        return s[0].x;
}

int Snake::getY() {
        return s[0].y;
}

void Snake::setDir(int dir) {
       this->dir = dir;
}

void Snake::upper() {
        this->num++;
}
