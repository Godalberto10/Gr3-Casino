// CasinoProyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "RegistroUsuario.hpp"
#include "TresEnRaya.hpp"
#include "Juego.hpp"
#include "Wordle.hpp"
#include "Ahorcado.hpp"
#include "PiedraPapelTijera.hpp"
#include "BlackJack.hpp"
#include "JuegoPalillos.hpp"
#include "Rule.hpp"
#include "Tragaperras.hpp"
using namespace std;

void muestraMenú2();
void muestraMenúUsuario();
void menu();
//void creaUsuario(RegistroUsuario &listaUsuarios);


int main()
{
	menu();
	return 0;
}

void muestraMenú2() {
	cout << "-------------------------------   CASINO    ------------------------------------------" << endl;
	cout << "Que desea hacer? \n1-Ver mi perfil \n2-Jugar al casino\n3-Volver atras \n4-Salir" << endl;
}

void muestraMenúUsuario() {
	cout << "-------------------------------   Mi perfil    ------------------------------------------" << endl;
	cout << "1. Generar informe" << endl;
	cout << "2. Añadir fondos " << endl;
	cout << "3. Sacar dinero" << endl;
	cout << "4. Volver al menu anterior" << endl;
}

void creaUsuario(RegistroUsuario &listaUsuarios) {
	string nombreU;
	int edad,id;
	double saldo;
	cout << "Introduzca el nombre del usuario: " << endl;
	cin >> nombreU;
	cout << "Introduzca la edad del usuario: " << endl;
		cin >> edad;
		if (edad < 18)
			throw runtime_error("El usuario debe de ser mayor de edad");
	do {
		cout << "Introduzca el id del usuario: " << endl;
		cin >> id;
		if (listaUsuarios.compruebaID(id)) {
			cout << "Ese ID ya está registrado, introduzca otro" << endl;
		}
	} while (listaUsuarios.compruebaID(id));
	do {
		cout << "Introduzca la cantidad de salario deseada: " << endl;
		cin >> saldo;
		if (saldo <= 0)
			cout << "Introduzca una cantidad lógica" << endl;
	} while (saldo <= 0);
	listaUsuarios.montaUsuario(nombreU, edad, id, saldo);
}

void menu() {
	int opcion, opcion2, opcionJuego, opcionPerfil, id, edad;
	double saldo,cantidad;
	string nombreU;
	RegistroUsuario listaUsuarios;
	listaUsuarios.cargaDatos();
	do {
		cout << "-------------------------------BIENVENIDO AL CASINO------------------------------------------" << endl; // debe de ser 50 caracteres 
		cout << "Que deseas hacer? (0-Salir,1-Iniciar Sesion,2-Registrarse,3-Eliminar Usuario)" << endl;
		cin >> opcion;
		switch (opcion) {
		case 0:
			break;
		case 1:
		{
			cout << "Introduzca el ID del usuario:  " << endl;
			cin >> id;
			Usuario usuarioActual = listaUsuarios.buscarUsuario(id);
			if (usuarioActual.getID() == -1) {
				cout<<"El ID no existe, por favor registrese" << endl;
				break;
			}
			do {
				muestraMenú2();
				cin >> opcion2;
				switch (opcion2) {
				case 1:
					do {
						muestraMenúUsuario();
						cin >> opcionPerfil;
						switch (opcionPerfil) {							
						case 1:
							usuarioActual.informeDelUsuario();
						case 2:
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.gananciaYannadirFondos(cantidad);
							break;
						case 3: 
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.apuesta(cantidad);
							break;
						case 4:
							break;
						}
					} while (opcionPerfil != 4);
					break;
				case 2:
					do {
						cout << "------------------------BIENVENIDO AL MENÚ DE JUEGOS-----------------------" << endl;
						cout << "A que quieres jugar?" << endl;
						cout << "1.Piedra Papel o Tijera \n2.Tres en raya \n3.Wordle \n4.Juego de los palillos \n5.Maquina Tragaperras \n6.Ruleta \n7.Bingo \n8.BlackJack \n9.Salir" << endl;
						cin >> opcionJuego;
						switch (opcionJuego)
						{
						case 1:
						{
							PiedraPapelTijera ppt;
							ppt.jugar(usuarioActual);
							break;
						}
						case 2:
						{
							TresEnRaya ter;
							ter.jugar(usuarioActual);
							break;
						}
						case 3:
						{
							Wordle wordle;
							wordle.jugar(usuarioActual);
						}
						case 4:
						{
							JuegoPalillos palillos;
							palillos.jugar(usuarioActual);
						}
						case 5:
						{
							Tragaperras tp;
							tp.jugar(usuarioActual);
							break;
						}
						case 6:
						{
							Rule rule;
							rule.jugar(usuarioActual);
							break;
						}
						case 7:
						{
							Ahorcado ahorcado;
							ahorcado.jugar(usuarioActual);
							break;
						}
						case 8:
						{
							BlackJack blackjack;
							blackjack.jugar(usuarioActual);
							break;
						}
						case 9:
							break;
						default:
							break;
						}

					} while (opcionJuego != 9);
					break;
				case 3:
					cout << "Volviendo atras..." << endl;
					break;
				case 4:
					break;
				}

			} while (opcion2 != 4);
			break;
		}

		case 2:
			try {
				creaUsuario(listaUsuarios);
			}
			catch (runtime_error e) {
				cout << "Error: " << e.what() << endl;
			}
			catch (invalid_argument e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		case 3:
			cout << "Introduzca el id del Usuario: " << endl;
			cin >> id;
			listaUsuarios.eliminarUsuario(listaUsuarios.buscarUsuario(id));
			break;
		default:
			cout << "Elija una opcion valida" << endl;
		}
	} while (opcion != 0);
	listaUsuarios.escrituraDatos();
	cout << "Gracias por jugar, vuelva pronto" << endl;
}*/

// CasinoProyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include "Usuario.hpp"
#include "RegistroUsuario.hpp"
#include "TresEnRaya.hpp"
#include "Juego.hpp"
#include "Wordle.hpp"
#include "Ahorcado.hpp"
#include "PiedraPapelTijera.hpp"
#include "BlackJack.hpp"
#include "JuegoPalillos.hpp"
#include "Rule.hpp"
#include "Tragaperras.hpp"
using namespace std;

void muestraMenú2();
void muestraMenúUsuario();
void menu();
//void creaUsuario(RegistroUsuario &listaUsuarios);


int main()
{
	menu();
	cout << "Gracias por jugar " << endl;
	return 0;
}

void muestraMenú2() {
	cout << "-------------------------------   CASINO    ------------------------------------------" << endl;
	cout << "Que desea hacer? \n1-Ver mi perfil \n2-Jugar al casino\n3-Volver atras \n4-Salir" << endl;
}

void muestraMenúUsuario() {
	cout << "-------------------------------   Mi perfil    ------------------------------------------" << endl;
	cout << "1. Generar informe" << endl;
	cout << "2. Añadir fondos " << endl;
	cout << "3. Sacar dinero" << endl;
	cout << "4. Volver al menu anterior" << endl;
}

// N
void creaUsuario(RegistroUsuario &listaUsuarios) {
	string nombreU;
	int edad;
	double saldo;
	cout << "Introduzca el nombre del usuario: " << endl;
	cin >> nombreU;

	cout << "Introduzca la edad del usuario: " << endl;
	cin >> edad;
	if (edad < 18)
		throw runtime_error("El usuario debe de ser mayor de edad");

	int id = listaUsuarios.generarNuevoID();
	cout << "ID generado para el usuario: " << id << endl;

	do {
		cout << "Introduzca la cantidad de salario deseada: " << endl;
		cin >> saldo;
		if (saldo <= 0)
			cout << "Introduzca una cantidad lógica" << endl;
	} while (saldo <= 0);

	listaUsuarios.montaUsuario(nombreU, edad, id, saldo);
	listaUsuarios.escrituraDatos();
}

void menu() {
	int opcion, opcion2, opcionJuego, opcionPerfil, id, edad;
	double saldo,cantidad;
	string nombreU;
	RegistroUsuario listaUsuarios;
	listaUsuarios.cargaDatos();
	do {
		cout << "-------------------------------BIENVENIDO AL CASINO------------------------------------------" << endl; // debe de ser 50 caracteres 
		cout << "Que deseas hacer? (0-Salir,1-Iniciar Sesion,2-Registrarse,3-Eliminar Usuario)" << endl;
		cin >> opcion;
		switch (opcion) {
		case 0:
			break;
		case 1:
		{
			cout << "Introduzca el ID del usuario:  " << endl;
			cin >> id;
			Usuario usuarioActual = listaUsuarios.buscarUsuario(id);
			// Usuario& usuarioActual = listaUsuarios.buscarUsuario(id);
			if (usuarioActual.getID() == -1) {
				cout<<"El ID no existe, por favor registrese" << endl;
				break;
			}
			do {
				muestraMenú2();
				cin >> opcion2;
				switch (opcion2) {
				case 1:
					do {
						muestraMenúUsuario();
						cin >> opcionPerfil;
						switch (opcionPerfil) {							
						case 1:
							usuarioActual.informeDelUsuario();
						case 2:
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.gananciaYannadirFondos(cantidad);
							break;
						case 3: 
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.apuesta(cantidad);
							break;
						case 4:
							break;
						}
					} while (opcionPerfil != 4);
					break;
				case 2:
					do {
						cout << "------------------------BIENVENIDO AL MENÚ DE JUEGOS-----------------------" << endl;
						cout << "A que quieres jugar?" << endl;
						cout << "1.Piedra Papel o Tijera \n2.Tres en raya \n3.Wordle \n4.Juego de los palillos \n5.Maquina Tragaperras \n6.Ruleta \n7.Bingo \n8.BlackJack \n9.Salir" << endl;
						cin >> opcionJuego;
						switch (opcionJuego)
						{
						case 1:
						{
							PiedraPapelTijera ppt;
							ppt.jugar(usuarioActual);
							break;
						}
						case 2:
						{
							TresEnRaya ter;
							ter.jugar(usuarioActual);
							break;
						}
						case 3:
						{
							Wordle wordle;
							wordle.jugar(usuarioActual);
						}
						case 4:
						{
							JuegoPalillos palillos;
							palillos.jugar(usuarioActual);
						}
						case 5:
						{
							Tragaperras tp;
							tp.jugar(usuarioActual);
							break;
						}
						case 6:
						{
							Rule rule;
							rule.jugar(usuarioActual);
							break;
						}
						case 7:
						{
							Ahorcado ahorcado;
							ahorcado.jugar(usuarioActual);
							break;
						}
						case 8:
						{
							BlackJack blackjack;
							blackjack.jugar(usuarioActual);
							break;
						}
						case 9:
							break;
						default:
							break;
						}

					} while (opcionJuego != 9);
					break;
				case 3:
					cout << "Volviendo atras..." << endl;
					break;
				case 4:
					break;
				}

			} while (opcion2 != 4);
			//actualizar
			// listaUsuarios.escrituraDatos();

			break;
		}

		case 2:
			try {
				creaUsuario(listaUsuarios);
			}
			catch (runtime_error e) {
				cout << "Error: " << e.what() << endl;
			}
			catch (invalid_argument e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		case 3:
			cout << "Introduzca el id del Usuario: " << endl;
			cin >> id;
			listaUsuarios.eliminarUsuario(listaUsuarios.buscarUsuario(id));
			cout << "Usuario eliminado" << endl;
		default:
			cout << "Elija una opcion valida" << endl;
		}
	} while (opcion != 0);
	listaUsuarios.escrituraDatos();
}