
#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "Usuario.hpp"
#include "Juego.hpp"
using namespace std;
class BlackJack : public Juego {
private:
	int totalPuntosUsuario, totalPuntosCroupier, opcion1, cartaX, cartaCroupier, carta1, carta2, num;
	double apuesta;
	bool jugarJ,finalizarTurno;
public:
	void jugar(Usuario u);
	int calculaCartaAleatoria();
	int verificarAs(int num);
	string transformarEnCarta(int num);
	bool volverAJugarDerrota();
	bool volverAJugarEmpate();
	bool volverAJugarVictoria();
	int calcularValorCarta(int num);
};

#endif