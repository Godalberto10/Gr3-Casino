/*#ifndef REGISTROUSUARIO_HPP
#define REGISTROUSUARIO_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "Juego.hpp"
#include <fstream>

using namespace std;

class RegistroUsuario {
private:
	vector <Usuario> usuarios;
public:
	RegistroUsuario();
	vector <Usuario> getUsuarios();
	void escrituraDatos();
	void cargaDatos();
	void montaUsuario(string nombre, int edad, int id, double saldo);
	void agregaUsuario(Usuario u);
	void eliminarUsuario(Usuario u);
	int buscarPosicionUsuario(int id);
	Usuario buscarUsuario(int id);
	bool compruebaID(int id);
};
#endif*/
#ifndef REGISTROUSUARIO_HPP
#define REGISTROUSUARIO_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "Juego.hpp"
#include <fstream>

using namespace std;

class RegistroUsuario {
private:
	vector <Usuario> usuarios;
public:
	RegistroUsuario();
	vector <Usuario> getUsuarios();
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