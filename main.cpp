#include <iostream>
#include "include/tic_tac_toe.hpp"

using namespace std;

int main() {
    Board board;
    Player currentPlayer = Player::X;
    int moves = 0;

    cout << "Bine ai venit la jocul Tic-Tac-Toe!" << endl;
    while (true) {
        printBoard(board);
        int row, col;
        cout << "Jucătorul " << (currentPlayer == Player::X ? "X" : "O") << ", introduceți rândul și coloana (0, 1, 2): ";
        cin >> row >> col;

        if (!makeMove(board, row, col, currentPlayer)) {
            cout << "Mutare invalidă. Încercați din nou." << endl;
            continue;
        }

        moves++;
        Player winner = checkWinner(board);
        if (winner != Player::NONE) {
            printBoard(board);
            cout << "Jucătorul " << (winner == Player::X ? "X" : "O") << " a câștigat!" << endl;
            break;
        } else if (moves == 9) {
            printBoard(board);
            cout << "Jocul s-a terminat la egalitate!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }

    return 0;
}
