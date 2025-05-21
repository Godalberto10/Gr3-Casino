#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Usuario.hpp"


class Juego{
protected:
	double apuesta;
public:
	virtual void jugar(Usuario u) = 0;

};

#endif