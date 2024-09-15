#include <iostream>
#include "tic_tac_toe.hpp"

Board::Board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = Player::NONE;
}

void printBoard(const Board &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.cells[i][j] == Player::X)
                std::cout << "X ";
            else if (board.cells[i][j] == Player::O)
                std::cout << "O ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

Player checkWinner(const Board &board) {
    for (int i = 0; i < 3; ++i) {
        if (board.cells[i][0] == board.cells[i][1] && board.cells[i][1] == board.cells[i][2] && board.cells[i][0] != Player::NONE)
            return board.cells[i][0];
        if (board.cells[0][i] == board.cells[1][i] && board.cells[1][i] == board.cells[2][i] && board.cells[0][i] != Player::NONE)
            return board.cells[0][i];
    }

    if (board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2] && board.cells[0][0] != Player::NONE)
        return board.cells[0][0];
    if (board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0] && board.cells[0][2] != Player::NONE)
        return board.cells[0][2];

    return Player::NONE;
}

bool makeMove(Board &board, int row, int col, Player player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board.cells[row][col] != Player::NONE)
        return false;
    board.cells[row][col] = player;
    return true;
}
