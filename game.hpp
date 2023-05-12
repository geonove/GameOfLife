#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "cellGrid.hpp"
#include <vector>
#include <string>
#include <unordered_set>

class Game {
    public: 
        Game(int width, 
             int height,
             const std::string& title,
             const int cellSize);

        void loadGrid();
        void run();
        
    private:
        // Window
        sf::RenderWindow window;
        // Cells grid
        cellGrid grid;
        // Game state
        bool isRunning; 
        // Clock to compute frame rate
        sf::Clock clock;

        // Visited cells
        std::unordered_set<Cell*> visited;

        void processEvents();
        void update();
        void render();
        bool checkMousePosition(sf::Vector2i mousePos);
};
#endif