#include "cellGrid.hpp"

cellGrid::cellGrid(const int nrows_, 
                   const int ncols_, 
                   const sf::Vector2f cellSize_):
                
                grid(nrows_, std::vector<Cell>(ncols_, cellSize_)), 
                nrows(nrows_),
                ncols(ncols_) {
                    for (int i = 0; i < nrows; i++) {
                        for (int j = 0; j < ncols; j++) {
                            grid[i][j].setPosition(sf::Vector2f(i * cellSize_.x, j * cellSize_.y));
                            grid[i][j].setColor();
                        }
                    }
                }

void cellGrid::update() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            int count = countAliveNeighbors(i,j);
            if (grid[i][j].getCurrState()) {
                if (count < 2 || count > 3)
                    grid[i][j].setNextState(false); 
            }
            else if (!grid[i][j].getCurrState() && count == 3)
                grid[i][j].setNextState(true);
        }
    }
}

void cellGrid::randomize() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid[i][j].setCurrState(false);
            grid[i][j].setNextState(false);
            
            if (rand() % 10 == 0) {
                grid[i][j].setCurrState(true);
                grid[i][j].setNextState(true);
            }
        }
    }
}

void cellGrid::resetToEmpty() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid[i][j].setCurrState(false);
            grid[i][j].setNextState(false);
        }
    }
}

void cellGrid::resetToFull() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid[i][j].setCurrState(true);
            grid[i][j].setNextState(true);
        }
    }
}


void cellGrid::draw(sf::RenderWindow& w) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid[i][j].draw(w);
            grid[i][j].setCurrState(grid[i][j].getNextState());
        }
    }
}

int cellGrid::countAliveNeighbors(int i, int j) const {
    int count = 0; 
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (i+x >= 0 && i+x < nrows && j+y >= 0 && j+y < ncols && !(x == 0 && y == 0))
                count += grid[i+x][j+y].getCurrState();
        }
    }
    return count;
}