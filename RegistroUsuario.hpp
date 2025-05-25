#ifndef REGISTROUSUARIO_HPP
#define REGISTROUSUARIO_HPP
#include <iostream>
#include <vector>//Librerias
#include <string>
#include "Usuario.hpp"
#include "Juego.hpp"
#include <fstream>

using namespace std;

class RegistroUsuario {
private://Atributo
	vector <Usuario> usuarios;
public://Metodos
	RegistroUsuario();//Contructor por defecto
	vector <Usuario> getUsuarios();//Descritos en el cpp
	void escrituraDatos();
	void cargaDatos();
	void montaUsuario(string nombre, int edad, int id, double saldo);
	void agregaUsuario(Usuario u);
	void eliminarUsuario(Usuario u);
	int buscarPosicionUsuario(int id);
	Usuario buscarUsuario(int id);
	//Usuario& buscarUsuario(int id);
	bool compruebaID(int id);
	int generarNuevoID();
};
#endif