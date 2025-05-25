
#ifndef RULE_HPP
#define RULE_HPP
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
class Rule : public Juego {
    
private://atributos
    int numeroRuleta, apuestaNumero = -1, montoNumero = 0, montoParImpar = 0, montoColor = 0, totalApuesta = 0, num;
    char opcionParImpar = ' ', opcionColor = ' ';
    bool apostarNumero, apostarParImpar, apostarColor;
    char continuar;
    string colorResultado;

public:

    // Funcion para obtener el color del numero en la ruleta
    string obtenerColor(int numero);
    void jugar(Usuario u);
};


#endif // RULE_HPP