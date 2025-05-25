#ifndef CASINO_HPP
#define CASINO_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "RegistroUsuario.hpp"
#include "TresEnRaya.hpp"
#include "Juego.hpp"//Librerias
#include "Wordle.hpp"
#include "Ahorcado.hpp"
#include "PiedraPapelTijera.hpp"
#include "BlackJack.hpp"
#include "JuegoPalillos.hpp"
#include "Rule.hpp"
#include "Tragaperras.hpp"
using namespace std;

class Casino {//Clase que gestiona el casino

    private:
        RegistroUsuario listaUsuarios;//atributos
        Usuario usuarioActual;
        int opcionJuego;
        int opcionMenu;
        int opcionMenuUsuario;

    public://Metodos
        void menu();
        void muestraMenú2();
        void muestraMenúUsuario();
        void creaUsuario(RegistroUsuario &listaUsuarios);
        

};

#endif