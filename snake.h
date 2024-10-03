#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h> // Pentru manipularea consolei (funcții precum Sleep)

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitX, fruitY, score;
    Direction dir;
    std::vector<std::pair<int, int>> tail; // Coada șarpelui

    void draw();
    void input();
    void logic();
    void clearScreen();

public:
    SnakeGame();
    void run();
};

#endif
