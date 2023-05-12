#include "game.hpp"
#include <iostream>


Game::Game(int width, 
           int height, 
           const std::string& title, 
           const int cellSize):
            window(sf::VideoMode(width, height), title),
            grid(height / cellSize, width / cellSize, sf::Vector2f(cellSize, cellSize)),
            isRunning(false) {
                //window.setFramerateLimit(60);
            } 

void Game::loadGrid() {
    grid.loadGrid();
}

void Game::run() {
    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        float fps = 1.0f / time;
        //std::cout << fps << " fps" << std::endl;
        processEvents();
        if (isRunning)
            update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (!isRunning && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) 
                grid.randomize();
            if (!isRunning && sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
                grid.resetToEmpty();
            if (!isRunning && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) 
                grid.resetToFull();
            if (!isRunning && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                isRunning = true;
            if (isRunning && sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                isRunning = false;
        }
        if (event.type == sf::Event::MouseButtonPressed || sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {
            if (!isRunning ) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                
                Cell* pointedCell = grid.getCellFromMouse(mousePosition);
                if (checkMousePosition(mousePosition) && visited.find(pointedCell) == visited.end()) {
                    pointedCell->setCurrState(!pointedCell->getCurrState());
                    pointedCell->setNextState(pointedCell->getCurrState());
                    visited.insert(pointedCell);
                }
            }
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            visited.erase(visited.begin(), visited.end());
        }
        
    }
}

void Game::update() {
    grid.update();
}

void Game::render() {
    window.clear();
    grid.loadGrid();
    window.draw(grid);
    window.display();
}

bool Game::checkMousePosition(sf::Vector2i mousePos) {
    return mousePos.x >= 0 && mousePos.x <= window.getSize().x && mousePos.y >= 0 && mousePos.y <= window.getSize().y;
}