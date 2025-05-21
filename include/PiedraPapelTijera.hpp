
#ifndef PIEDRAPAPELTIJERA_HPP 
#define PIEDRAPAPELTIJERA_HPP
#include <iostream>
#include <random>
#include <fstream>
#include <windows.h> //libreria normal
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() que se utiliza para obtener el tiempo actual en segundos desde el 1 de enero de 1970
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;
class PiedraPapelTijera : public Juego
{
private:
	int opcionJugador, opcionMaquina,i;
	string opciones[3] = { "Piedra","Papel","Tijera" };
public:
	void jugar(Usuario u) override;
};
#endif