# Snake Game in C++

## Descriere
Acest proiect este o implementare simplă a jocului **Snake**, un joc clasic în care jucătorul controlează un șarpe care se mișcă pe ecran. Scopul jocului este să colectezi puncte (mâncare) pentru a-ți lungi șarpele, în timp ce eviți coliziunile cu pereții jocului sau cu propriul corp. Această versiune a jocului este dezvoltată în C++ și utilizează concepte de programare orientată pe obiect.

## Scopul Proiectului
Proiectul își propune să demonstreze următoarele:
- Utilizarea conceptelor de programare orientată pe obiect pentru a structura jocul.
- Gestionarea input-ului de la tastatură pentru a controla mișcarea șarpelui.
- Implementarea logicii jocului, inclusiv gestionarea coliziunilor și a scorului.
- Crearea unei interfețe simple de utilizator prin terminal.

## Structura Proiectului
Proiectul este organizat în mai multe fișiere, fiecare având un rol specific în funcționarea jocului. Structura directorului este următoarea:

## Cerințe
Pentru a compila și rula acest proiect, ai nevoie de:

- **Compilator C++**: `g++` (sau alt compilator C++)
- **MSYS2/MinGW** sau alte tool-uri pentru dezvoltarea C++ în Windows (dacă este cazul)
- Un terminal compatibil (ex. `bash`, `cmd`, `powershell`)

## Instrucțiuni de Compilare și Rulare
Există două metode principale de a compila și rula jocul: utilizând un fișier `Makefile` sau compilând manual cu `g++`.

### Metoda 1: Utilizarea `Makefile`
Dacă folosești `Makefile`, urmează acești pași:

1. Deschide terminalul în directorul principal al proiectului (`SnakeGame/`).
2. Rulează comanda:

   ```bash
   make

Aceasta va compila toate fișierele sursă din src/ și va crea un executabil numit snake.exe.

Metoda 2: Compilare manuală folosind g++
Dacă preferi să compilezi manual, urmează acești pași:

Deschide terminalul și navighează la directorul SnakeGame/.

Compilează fișierele .cpp în fișiere obiect:
g++ -std=c++11 -Wall -c src/main.cpp -o src/main.o
g++ -std=c++11 -Wall -c src/Snake.cpp -o src/Snake.o
g++ -std=c++11 -Wall -c src/Game.cpp -o src/Game.o


Interfața Jocului
Jocul este prezentat în terminal, iar jucătorul controlează șarpele utilizând tastele săgeată. Odată ce șarpele mănâncă mâncarea, acesta devine mai lung și scorul crește. Jucătorul pierde jocul dacă șarpele se lovește de marginea ferestrei sau de el însuși. Scorul final este afișat la sfârșitul jocului.

Fișier .gitignore
Fișierul .gitignore este configurat pentru a ignora următoarele tipuri de fișiere:

Fișiere obiect (*.o): fișiere generate în timpul compilării.
Executabile (*.exe): fișierele binare rezultate.
Fișiere temporare (*.tmp, *.log): fișiere create temporar de sistem.
Fișiere de configurare ale editorilor de text (ex. .vscode/).
