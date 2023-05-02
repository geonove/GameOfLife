#include "cell.hpp"
#include <iostream>
Cell::Cell(const sf::Vector2f& size):
        shape(size),
        currState(true),
        nextState(true) {
            setColor();
            sf::Color gray(128, 128, 128);
            shape.setOutlineColor(gray);
            shape.setOutlineThickness(0.5);
        }
void Cell::setPosition(const sf::Vector2f& position) {
    shape.setPosition(position);
}

void Cell::setColor() {
    sf::Color color = currState ? sf::Color::White : sf::Color::Black;
    shape.setFillColor(color);
}

void Cell::draw(sf::RenderWindow& w) const {
    w.draw(shape);
}

bool Cell::getCurrState() const {
    return currState;
}

bool Cell::getNextState() const {
    return nextState;
}

void Cell::setCurrState(bool state) {
    currState = state;
    setColor();
}

void Cell::setNextState(bool state) {
    nextState = state;
}