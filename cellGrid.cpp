#include "cellGrid.hpp"
#include <iostream>
cellGrid::cellGrid(const int nrows_, 
                   const int ncols_, 
                   const sf::Vector2f cellSize_):
                grid(nrows_, std::vector<Cell>(ncols_)), 
                drawableGrid(sf::Quads, nrows_ * ncols_ * 4),
                nrows(nrows_),
                ncols(ncols_),
                cellSize(cellSize_) {}

void cellGrid::loadGrid() {
    for (int i = 0; i < ncols; i++) {
        for (int j = 0; j < nrows; j++) {
            bool state = grid[i][j].getCurrState();
            
            sf::Vertex* quad = &drawableGrid[(i + j * ncols) * 4];
            
            quad[0].position = sf::Vector2f(i * cellSize.x + 0.5, j * cellSize.y + 0.5);
            quad[1].position = sf::Vector2f((i + 1) * cellSize.x - 0.5, j * cellSize.y + 0.5);
            quad[2].position = sf::Vector2f((i + 1) * cellSize.x - 0.5, (j + 1) * cellSize.y - 0.5);
            quad[3].position = sf::Vector2f(i * cellSize.x + 0.5, (j + 1) * cellSize.y - 0.5);
            sf::Color color = state ? sf::Color::White : sf::Color::Black;
            quad[0].color = color;
            quad[1].color = color;
            quad[2].color = color;
            quad[3].color = color;
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

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            grid[i][j].updateState();
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


void cellGrid::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    states.transform *= getTransform();
    
    window.draw(drawableGrid);
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