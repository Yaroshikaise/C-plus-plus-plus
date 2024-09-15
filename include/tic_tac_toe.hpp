#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

enum class Player { NONE, X, O };

struct Board {
    Player cells[3][3]; // Tabla de joc

    Board(); // Constructor pentru inițializarea tablei
};

void printBoard(const Board &board);
Player checkWinner(const Board &board);
bool makeMove(Board &board, int row, int col, Player player);

#endif
