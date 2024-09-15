#C-

Acesta este un proiect simplu pentru un joc de ,,Tic-Tac-Toe" (sau X ?i O), implementat ?n limbajul C++. Jocul permite doi juc?tori s? joace, plas?nd simbolul "X" sau "O" pe tabla de joc 3x3, p?n? c?nd unul dintre ei c??tig? sau jocul se termin? la egalitate.

## Caracteristici

- Implementarea jocului folosind structuri de baz? ?n C++.
- Reprezentarea tablei de joc ca o matrice 3x3.
- Verificarea st?rii jocului: c??tig, remiz? sau continuarea jocului.
- Alternarea juc?torilor pentru a face mut?ri.
- Codul poate fi extins pentru a include o interfa?? grafic?.

## Structurile de baz? folosite

- `Player`: O enumerare (`enum class`) care reprezint? juc?torii disponibili ?n joc - `NONE`, `X` ?i `O`.
- `Board`: O structur? care con?ine o matrice 3x3 pentru a reprezenta tabla de joc. Ini?ializeaz? tabla de joc astfel ?nc?t toate celulele s? fie goale (`Player::NONE`).

## Cerin?e

Pentru a compila ?i rula proiectul, ve?i avea nevoie de:

- Un compilator C++.
- Un terminal pentru a rula aplica?ia.