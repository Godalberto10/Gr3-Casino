
#ifndef JUEGOPALILLOS_HPP
#define JUEGOPALILLOS_HPP
#include <iostream>
#include <random>
#include <fstream>
#include <windows.h> //libreria normal
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() que se utiliza para obtener el tiempo actual en segundos desde el 1 de enero de 1970
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;
class JuegoPalillos : public Juego {
private:
    enum class Turno { ORDENADOR, USUARIO };//Definimos un enum para los turnos del juego
    int num, max, numPalillos, jugarOtraVez, quitaPalillos;
    Turno turno;
public:
    int pedirNumero(int min, int max);
    void escribeJuego(int numPalillos);
    int juegaOrdenador(int numPalillos);
    int juegaUsuario(int numPalillos);
    void jugar(Usuario u);

};

#endif