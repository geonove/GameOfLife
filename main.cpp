#include <SFML/Graphics.hpp>

#include "game.hpp"
#include <string>
int main () {
    const int winWidth = 500;
    const int winHeight = 500;
    const int cellSize = 5;
    std::string title = "Game of Life";
    Game game(winWidth, winHeight, title, cellSize);
    game.run();
    return 0;
}
