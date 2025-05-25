
#ifndef AHORCADO_HPP
#define AHORCADO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <windows.h> //libreria normal
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() que se utiliza para obtener el tiempo actual en segundos desde el 1 de enero de 1970
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;

class Ahorcado : public Juego {
private:

    string pal;
    string fallos;
    int numRan;
    int vida;
    bool correcta;
    bool completa;
    char opcion;
    bool partidaActiva = TRUE;
    char opcion1;

public:

    void jugar(Usuario u);// Método que inicia el juego de ahorcado
    vector<string> cargarPalabras(const string& nombreArchivo);
    void jugarPartida(const vector<string>& palabras,Usuario u);
    void clear();
    void dibujar();
};
#endif