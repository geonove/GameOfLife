#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include <string>
int main () {
    const int winWidth = 1000;
    const int winHeight = 1000;
    const int cellSize = 10;
    std::string title = "Game of Life";
    Game game(winWidth, winHeight, title, cellSize);
    game.loadGrid();
    game.run();
    return 0;
}
