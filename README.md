Tic-Tac-Toe Game
Acest proiect este o implementare simplă a jocului clasic Tic-Tac-Toe, dezvoltat în C++. Jocul se desfășoară pe o tablă de 3x3, iar scopul este de a forma o linie de trei simboluri identice pe orizontală, verticală sau diagonală. Este ideal pentru cei care vor să se familiarizeze cu concepte de bază în programarea C++ și manipularea structurilor de date simple.

Caracteristici
Doi jucători: Jocul suportă doi jucători (X și O) care joacă alternativ până când unul dintre ei câștigă sau jocul se termină la egalitate.
Tabla de joc: Tablă de 3x3 pentru plasarea simbolurilor, cu opțiuni pentru introducerea rândului și a coloanei.
Verificarea câștigătorului: Jocul detectează automat când unul dintre jucători a format o linie de trei simboluri identice sau dacă jocul s-a terminat la egalitate.
Interfață în linia de comandă: Simplă și ușor de utilizat, destinată rulării în mediul de consolă.
Cum funcționează
Jocul începe prin afișarea tablei de joc goală.
Jucătorii introduc pe rând poziția (rândul și coloana) unde doresc să-și plaseze simbolul.
Programul verifică dacă mutarea este validă:
Dacă poziția este deja ocupată sau este în afara limitelor tablei, jucătorul va fi rugat să introducă o altă poziție.
După fiecare mutare, programul verifică dacă există un câștigător (trei simboluri identice în linie) sau dacă s-a ajuns la egalitate (toate spațiile sunt ocupate fără un câștigător).
Jocul se încheie când un jucător câștigă sau când se termină la egalitate, afișând un mesaj corespunzător.

Structura proiectului main.cpp: Acest fișier conține logica principală a jocului, gestionează intrările utilizatorilor și alternează între cei doi jucători.
include/tic_tac_toe.hpp: Definițiile structurilor de bază, cum ar fi tabla de joc și jucătorii, precum și declarațiile funcțiilor folosite în joc.
src/tic_tac_toe.cpp: Implementarea funcțiilor definite în tic_tac_toe.hpp, incluzând inițializarea tablei, gestionarea mutărilor jucătorilor și verificarea câștigătorului.

Cerințe pentru rularea proiectului
Un compilator C++ pentru a compila și a rula codul.
Un mediu de execuție în linia de comandă pentru interacțiunea cu jocul.
