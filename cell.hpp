#ifndef _CELL_HPP_
#define _CELL_HPP_

#include <SFML/Graphics.hpp>
class Cell {
    public:
        Cell(const sf::Vector2f& size);

        void setPosition(const sf::Vector2f& position);

        void setColor();

        void draw(sf::RenderWindow& w) const;

        bool getCurrState() const;
        bool getNextState() const;
        void setCurrState(bool state);
        void setNextState(bool state);
    private:
        // Cell shape
        sf::RectangleShape shape;
        // Current state
        bool currState; 
        // Next state
        bool nextState; 

};

#endif