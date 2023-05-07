#ifndef _CELL_HPP_
#define _CELL_HPP_

#include <SFML/Graphics.hpp>
class Cell {
    public:
        Cell();

        bool getCurrState() const;
        bool getNextState() const;
        void setCurrState(bool state);
        void setNextState(bool state);
        void updateState();
    private:
        // Current state
        bool currState; 
        // Next state
        bool nextState; 

};

#endif