#include "game.hpp"
#include <iostream>

Game::Game(int width, 
           int height, 
           const std::string& title, 
           const int cellSize):
            window(sf::VideoMode(width, height), title),
            grid(width / cellSize, height / cellSize, sf::Vector2f(cellSize, cellSize)),
            isRunning(false) {
                window.setFramerateLimit(60);
            } 

void Game::loadGrid() {
    grid.loadGrid();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        if (isRunning)
            update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
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