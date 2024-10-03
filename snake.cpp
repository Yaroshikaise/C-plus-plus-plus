#include "Snake.h"

SnakeGame::SnakeGame() : gameOver(false), x(width / 2), y(height / 2), score(0), dir(STOP) {
    // Setăm poziția inițială a fructului la o locație random
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void SnakeGame::draw() {
    clearScreen(); // Curăță ecranul
    for (int i = 0; i < width + 2; ++i) std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0) std::cout << "#"; // Peretele din stânga

            if (i == y && j == x)
                std::cout << "O"; // Capul șarpelui
            else if (i == fruitY && j == fruitX)
                std::cout << "F"; // Fructul
            else {
                bool print = false;
                for (auto &t : tail) {
                    if (t.first == j && t.second == i) {
                        std::cout << "o"; // Coada șarpelui
                        print = true;
                        break;
                    }
                }
                if (!print) std::cout << " ";
            }

            if (j == width - 1) std::cout << "#"; // Peretele din dreapta
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; ++i) std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void SnakeGame::input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': dir = LEFT; break;
        case 'd': dir = RIGHT; break;
        case 'w': dir = UP; break;
        case 's': dir = DOWN; break;
        case 'x': gameOver = true; break; // Buton pentru a ieși din joc
        }
    }
}

void SnakeGame::logic() {
    // Stochează poziția capului anterior pentru a actualiza coada
    int prevX = x;
    int prevY = y;

    // Mișcarea șarpelui în funcție de direcția aleasă
    switch (dir) {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    default: break;
    }

    // Dacă șarpele mănâncă fructul
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail.push_back({ prevX, prevY });
    }

    // Actualizează coada
    if (!tail.empty()) {
        tail.insert(tail.begin(), { prevX, prevY });
        tail.pop_back();
    }

    // Verifică coliziunile cu peretele sau cu propria coadă
    if (x >= width || x < 0 || y >= height || y < 0) gameOver = true;
    for (auto &t : tail) {
        if (t.first == x && t.second == y) gameOver = true;
    }
}

void SnakeGame::run() {
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Încetinire a jocului pentru a fi jucabil
    }
}

void SnakeGame::clearScreen() {
    // Comandă pentru a șterge ecranul
    system("cls");
}
