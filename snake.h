
#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "GameObject.h" 

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame : public GameObject { 
private:
    bool gameOver;
    int width, height;
    int x, y, fruitX, fruitY, score;
    Direction dir;
    std::vector<std::pair<int, int>> tail;

    void clearScreen(); 

public:
    SnakeGame(); 
    SnakeGame(int width, int height); 
    SnakeGame(const SnakeGame& other); 

    SnakeGame& operator=(const SnakeGame& other);
    bool operator==(const SnakeGame& other) const; 

    friend std::istream& operator>>(std::istream& in, SnakeGame& game); 
    friend std::ostream& operator<<(std::ostream& out, const SnakeGame& game); 

    void run(); 
    void draw() override; 
    void update() override; 
};

#endif
