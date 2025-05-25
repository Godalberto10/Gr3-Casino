#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Usuario.hpp"


class Juego{
protected:
	double apuesta;//atributo
public:
	virtual void jugar(Usuario u) = 0;//metodo que hace que jugar sea abstracta

};

#endif