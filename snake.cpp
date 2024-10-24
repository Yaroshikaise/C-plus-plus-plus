#include "Snake.h"
#include <cstdlib> 
#include <ctime>   


SnakeGame::SnakeGame()
    : gameOver(false), width(20), height(20), x(width / 2), y(height / 2),
      score(0), dir(STOP) {
    srand(static_cast<unsigned>(time(0))); 
    fruitX = rand() % width;
    fruitY = rand() % height;
}


SnakeGame::SnakeGame(int w, int h)
    : gameOver(false), width(w), height(h), x(w / 2), y(h / 2), score(0), dir(STOP) {
    fruitX = rand() % width;
    fruitY = rand() % height;
}


SnakeGame::SnakeGame(const SnakeGame& other)
    : gameOver(other.gameOver), width(other.width), height(other.height),
      x(other.x), y(other.y), fruitX(other.fruitX), fruitY(other.fruitY),
      score(other.score), dir(other.dir), tail(other.tail) {}


SnakeGame& SnakeGame::operator=(const SnakeGame& other) {
    if (this != &other) {
        gameOver = other.gameOver;
        width = other.width;
        height = other.height;
        x = other.x;
        y = other.y;
        fruitX = other.fruitX;
        fruitY = other.fruitY;
        score = other.score;
        dir = other.dir;
        tail = other.tail;
    }
    return *this;
}


bool SnakeGame::operator==(const SnakeGame& other) const {
    return width == other.width &&
           height == other.height &&
           gameOver == other.gameOver &&
           x == other.x && y == other.y &&
           fruitX == other.fruitX && fruitY == other.fruitY &&
           score == other.score &&
           dir == other.dir &&
           tail == other.tail;
}


std::ostream& operator<<(std::ostream& out, const SnakeGame& game) {
    out << "Width: " << game.width << ", Height: " << game.height << '\n';
    out << "Position: (" << game.x << ", " << game.y << ")\n";
    out << "Fruit: (" << game.fruitX << ", " << game.fruitY << ")\n";
    out << "Score: " << game.score << '\n';
    out << "Direction: " << game.dir << '\n';
    out << "Game Over: " << (game.gameOver ? "Yes" : "No") << '\n';
    out << "Tail: ";
    for (const auto& t : game.tail) {
        out << "(" << t.first << ", " << t.second << ") ";
    }
    out << '\n';
    return out;
}


std::istream& operator>>(std::istream& in, SnakeGame& game) {
    std::cout << "Enter width and height: ";
    in >> game.width >> game.height;
    std::cout << "Enter snake position (x, y): ";
    in >> game.x >> game.y;
    std::cout << "Enter fruit position (x, y): ";
    in >> game.fruitX >> game.fruitY;
    std::cout << "Enter score: ";
    in >> game.score;
    std::cout << "Enter direction (0=STOP, 1=LEFT, 2=RIGHT, 3=UP, 4=DOWN): ";
    int dir;
    in >> dir;
    game.dir = static_cast<Direction>(dir);
    std::cout << "Game over? (1=Yes, 0=No): ";
    in >> game.gameOver;

    game.tail.clear();
    std::cout << "Enter tail size: ";
    int tailSize;
    in >> tailSize;
    for (int i = 0; i < tailSize; ++i) {
        std::pair<int, int> segment;
        std::cout << "Enter segment " << i + 1 << " (x, y): ";
        in >> segment.first >> segment.second;
        game.tail.push_back(segment);
    }
    return in;
}


void SnakeGame::draw() {
    clearScreen();
    for (int i = 0; i < width + 2; ++i) std::cout << "#";
    std::cout << '\n';

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0) std::cout << "#"; 
            if (i == y && j == x) std::cout << "O"; 
            else if (i == fruitY && j == fruitX) std::cout << "F"; 
            else {
                bool print = false;
                for (auto& t : tail) {
                    if (t.first == j && t.second == i) {
                        std::cout << "o"; 
                        print = true;
                        break;
                    }
                }
                if (!print) std::cout << " "; 
            }
            if (j == width - 1) std::cout << "#"; 
        }
        std::cout << '\n';
    }
    for (int i = 0; i < width + 2; ++i) std::cout << "#"; 
    std::cout << "\nScore: " << score << '\n'; 
}


void SnakeGame::update() {
    int prevX = x, prevY = y; 
    switch (dir) {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    default: break;
    }

    
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail.push_back({ prevX, prevY }); 
    }

    
    if (!tail.empty()) {
        tail.insert(tail.begin(), { prevX, prevY });
        tail.pop_back();
    }

    
    if (x >= width || x < 0 || y >= height || y < 0) gameOver = true;
    for (auto& t : tail) {
