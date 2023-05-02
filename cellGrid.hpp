#ifndef _CELL_GRID_HPP_
#define _CELL_GRID_HPP_

#include <vector>
#include "cell.hpp"
class cellGrid {
    public:
    cellGrid(const int nrows_, const int ncols_, const sf::Vector2f cellSize_);

    void update();
    void randomize(); 
    void resetToEmpty();
    void resetToFull();
    void updateOneCell();
    void draw(sf::RenderWindow& w);
    
    private:
    std::vector<std::vector<Cell>> grid;
    std::size_t nrows;
    std::size_t ncols;

    int countAliveNeighbors(int i, int j) const;
};
#endif