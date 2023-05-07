#include "cell.hpp"
#include <iostream>
Cell::Cell():
        currState(true),
        nextState(true) {}

bool Cell::getCurrState() const {
    return currState;
}

bool Cell::getNextState() const {
    return nextState;
}

void Cell::setCurrState(bool state) {
    currState = state;
}

void Cell::setNextState(bool state) {
    nextState = state;
}

void Cell::updateState() {
    currState = nextState;
}