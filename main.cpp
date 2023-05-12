#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include <string>
int main (int argc, char* argv[]) {
    int winWidth = 1500;
    int winHeight = 900;
    int cellSize = 5;
    if (argc == 4) {
        
        winWidth = std::atoi(argv[1]);
        winHeight = std::atoi(argv[2]);
        cellSize = std::atoi(argv[3]);
    }
    std::string title = "Game of Life";
    Game game(winWidth, winHeight, title, cellSize);
    game.loadGrid();
    game.run();
    return 0;
}
