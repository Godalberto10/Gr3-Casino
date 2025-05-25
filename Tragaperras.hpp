#ifndef TRAGAPERRAS_HPP
#define TRAGAPERRAS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Usuario.hpp"
#include "Juego.hpp"

using namespace std;


class Tragaperras : public Juego {
	private:
		string carrete1, carrete2, carrete3;
		
		vector<string> simbolos = { "1", "2", "3", "4", "5" };// Simbolos de la tragaperras
		int premio, saldo = 300,apuesta;// Atributos de la clase Tragaperras
	public:
		
		string girarCarrete();
		bool verificarGanador(string carrete1, string carrete2, string carrete3);
		int jugarTragaperras(Usuario u, int apuesta);
		void jugar(Usuario u);
};
#endif