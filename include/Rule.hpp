
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
    //Pequeños cambios de excepciones: Cada vez que se pone una respuesta diferente a las que te piden y salta la excepcion,
    //da igual el paso en el que te encuentres (par impar, rojo negro) que te manda a empezar desde el princpio sin guardar los nuevos valores.
private:
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