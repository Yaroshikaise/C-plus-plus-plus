#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

enum class Player { NONE, X, O };

struct Board {
    Player cells[3][3]; // Matrice 3x3 pentru tabla de joc

    Board() {
        // Inițializează tabla de joc cu NONE
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cells[i][j] = Player::NONE;
    }
};

#endif // TIC_TAC_TOE_HPP