
#ifndef TRESENRAYA_HPP
#define TRESENRAYA_HPP
#include <iostream>
#include <random>
#include <fstream>
#include <windows.h> //libreria normal
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() que se utiliza para obtener el tiempo actual en segundos desde el 1 de enero de 1970
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;
const int TAMANO = 3;
extern char tablero[TAMANO][TAMANO];
class TresEnRaya: public Juego{
private:
    int posicion, fila, columna,contador;
    char jugador, ganador;
    bool primerTurno;
public:
    void mostrarTablero();
    void mostrarPosiciones();
    void convertirPosicion(int posicion, int& fila, int& columna);
    char verificarGanador();
    bool tableroLleno();
    bool bloquearJugador();
    void turnoMaquina();
    void jugar(Usuario u);
};
#endif // !TRESENRAYA_HPP