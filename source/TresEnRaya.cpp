#include "include/TresEnRaya.hpp"

char tablero[TAMANO][TAMANO]= {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};


// Mostrar el tablero actual
void TresEnRaya :: mostrarTablero() {
    cout << "-------------" << endl;
    for (int i = 0; i < TAMANO; i++) {
        cout << "| ";
        for (int j = 0; j < TAMANO; j++) {
            cout << tablero[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Mostrar las posiciones de 1 a 9
void TresEnRaya:: mostrarPosiciones() {
    cout << "Posiciones del tablero:" << endl;
    contador = 1;
    for (int i = 0; i < TAMANO; i++) {
        cout << "-------------" << endl << "| ";
        for (int j = 0; j < TAMANO; j++) {
            cout << contador++ << " | ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

// Convierte una posición 1-9 a fila y columna
void TresEnRaya :: convertirPosicion(int posicion, int& fila, int& columna) {
    fila = (posicion - 1) / TAMANO;
    columna = (posicion - 1) % TAMANO;
}

// Verifica si hay un ganador
char TresEnRaya :: verificarGanador() {
    for (int i = 0; i < TAMANO; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return tablero[i][0];
        if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return tablero[0][i];
    }
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return tablero[0][0];
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return tablero[0][2];

    return ' ';
}

// Verifica si el tablero está lleno (empate)
bool TresEnRaya :: tableroLleno() {
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            if (tablero[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// La máquina intenta bloquear al jugador si está a punto de ganar
bool TresEnRaya :: bloquearJugador() {
    // Filas
    for (int i = 0; i < TAMANO; i++) {
        int xCount = 0, emptyCount = 0, emptyCol = -1;
        for (int j = 0; j < TAMANO; j++) {
            if (tablero[i][j] == 'X') xCount++;
            if (tablero[i][j] == ' ') { emptyCount++; emptyCol = j; }
        }
        if (xCount == 2 && emptyCount == 1) {
            tablero[i][emptyCol] = 'O';
            return true;
        }
    }

    // Columnas
    for (int j = 0; j < TAMANO; j++) {
        int xCount = 0, emptyCount = 0, emptyRow = -1;
        for (int i = 0; i < TAMANO; i++) {
            if (tablero[i][j] == 'X') xCount++;
            if (tablero[i][j] == ' ') { emptyCount++; emptyRow = i; }
        }
        if (xCount == 2 && emptyCount == 1) {
            tablero[emptyRow][j] = 'O';
            return true;
        }
    }

    // Diagonal principal
    int xCount = 0, emptyCount = 0, emptyPos = -1;
    for (int i = 0; i < TAMANO; i++) {
        if (tablero[i][i] == 'X') xCount++;
        if (tablero[i][i] == ' ') { emptyCount++; emptyPos = i; }
    }
    if (xCount == 2 && emptyCount == 1) {
        tablero[emptyPos][emptyPos] = 'O';
        return true;
    }

    // Diagonal secundaria
    xCount = 0; emptyCount = 0;
    int emptyRow = -1, emptyCol = -1;
    for (int i = 0; i < TAMANO; i++) {
        if (tablero[i][TAMANO - 1 - i] == 'X') xCount++;
        if (tablero[i][TAMANO - 1 - i] == ' ') {
            emptyCount++;
            emptyRow = i;
            emptyCol = TAMANO - 1 - i;
        }
    }
    if (xCount == 2 && emptyCount == 1) {
        tablero[emptyRow][emptyCol] = 'O';
        return true;
    }

    return false;
}

// Movimiento de la máquina
void TresEnRaya :: turnoMaquina() {
    cout << "Turno de la máquina (O)..." << endl;
    if (bloquearJugador()) {
        cout << "La máquina ha bloqueado tu jugada." << endl;
        return;
    }

    // Si no hay amenaza, juega aleatoriamente
    int fila, columna;
    srand(time(0));
    do {
        fila = rand() % TAMANO;
        columna = rand() % TAMANO;
    } while (tablero[fila][columna] != ' ');

    tablero[fila][columna] = 'O';
}

// Función principal
void TresEnRaya :: jugar(Usuario u) {
    jugador = 'X';
    ganador = ' ';
    primerTurno = true;

    cout << "¡Bienvenido al juego de Tres en Raya!" << endl;
    do {
        cout << "Introduzca la cantidad a apostar";
        cin >> apuesta;
    } while (u.getSaldo() < apuesta || apuesta < 0);
    u.apuesta(apuesta);
    while (true) {
        if (primerTurno) {
            mostrarTablero();
            mostrarPosiciones();
            primerTurno = false;
        }
        else {
            mostrarTablero();
        }

        if (jugador == 'X') {
            cout << "Tu turno (X). Elige una posición (1-9): ";
            cin >> posicion;

            if (posicion < 1 || posicion > 9) {
                cout << "Posición inválida. Intenta de nuevo." << endl;
                continue;
            }

            convertirPosicion(posicion, fila, columna);

            if (tablero[fila][columna] != ' ') {
                cout << "Casilla ocupada. Intenta de nuevo." << endl;
                continue;
            }

            tablero[fila][columna] = 'X';
        }
        else {
            turnoMaquina();
        }

        ganador = verificarGanador();
        if (ganador != ' ') {
            mostrarTablero();
            if (ganador == 'X') {
                cout << "¡Felicidades! ¡Has ganado!" << endl;
                u.aumentaVictoriasTER();
                u.gananciaYannadirFondos(apuesta * 1.5);
            }
            else {
                cout << "¡La máquina ha ganado!" << endl;
                u.aumentaDerrotasTER();
            }
            break;
        }

        if (tableroLleno()) {
            mostrarTablero();
            cout << "¡Es un empate!" << endl;
            u.gananciaYannadirFondos(apuesta);
            u.aumentaEmpatesTER();
            break;
        }

        jugador = (jugador == 'X') ? 'O' : 'X';
    }
}