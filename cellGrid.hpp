#ifndef _CELL_GRID_HPP_
#define _CELL_GRID_HPP_

#include <vector>
#include "cell.hpp"
class cellGrid : public sf::Drawable, public sf::Transformable{
    public:
    cellGrid(const int nrows_, const int ncols_, const sf::Vector2f cellSize_);

    void loadGrid();
    void update();
    void randomize(); 
    void resetToEmpty();
    void resetToFull();
    void updateOneCell();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates) const override;
    
    private:
    std::vector<std::vector<Cell>> grid;
    sf::VertexArray drawableGrid;
    std::size_t nrows;
    std::size_t ncols;
    sf::Vector2f cellSize;

    int countAliveNeighbors(int i, int j) const;
};
#endif