#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include "cellGrid.hpp"
#include <vector>
#include <string>

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


        void processEvents();
        void update();
        void render();
};
#endif