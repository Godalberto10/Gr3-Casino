#include "Casino.hpp"


void Casino :: muestraMenú2() {//Muestra las opciones principales
	cout << "-------------------------------   CASINO    ------------------------------------------" << endl;
	cout << "Que desea hacer? \n1-Ver mi perfil \n2-Jugar al casino\n3-Volver atras \n4-Salir" << endl;
}

void Casino :: muestraMenúUsuario() {//Permite al usuario gestionar su cuenta
	cout << "-------------------------------   Mi perfil    ------------------------------------------" << endl;
	cout << "1. Anadir fondos " << endl;
	cout << "2. Sacar dinero" << endl;
	cout <<"3. Ver saldo actual"<<endl;
	cout << "4. Volver al menu anterior" << endl;
}


void Casino :: creaUsuario(RegistroUsuario &listaUsuarios) {//Crea un nuevo usuario
	string nombreU;
	int edad;
	double saldo;
	cout << "Introduzca el nombre del usuario: " << endl;
	cin >> nombreU;

	cout << "Introduzca la edad del usuario: " << endl;
	cin >> edad;
	if (edad < 18)//Debe de ser mayor de edad 
		throw runtime_error("El usuario debe de ser mayor de edad");

	int id = listaUsuarios.generarNuevoID();
	cout << "ID generado para el usuario: " << id << endl;

	do {
		cout << "Introduzca la cantidad de salario deseada: " << endl;
		cin >> saldo;
		if (saldo <= 0)
			cout << "Introduzca una cantidad lógica" << endl;
	} while (saldo <= 0);

	listaUsuarios.montaUsuario(nombreU, edad, id, saldo);//Se crea el usuario
	listaUsuarios.escrituraDatos();
}

void Casino :: menu() {
	int opcion, opcion2, opcionJuego, opcionPerfil, id, edad;
	double saldo,cantidad;
	string nombreU;
	RegistroUsuario listaUsuarios;
	listaUsuarios.cargaDatos();
	do {//Opciones
		cout << "-------------------------------BIENVENIDO AL CASINO------------------------------------------" << endl; 
		cout << "Que deseas hacer? (0-Salir,1-Iniciar Sesion,2-Registrarse,3-Eliminar Usuario)" << endl;
		cin >> opcion;
		switch (opcion) {
		case 0:
			break;
		case 1:
		{
			cout << "Introduzca el ID del usuario:  " << endl;
			cin >> id;
			Usuario usuarioActual = listaUsuarios.buscarUsuario(id);//Se busca el usuario por su id
			//Usuario& usuarioActual = listaUsuarios.buscarUsuario(id);
			if (usuarioActual.getID() == -1) {
				cout<<"El ID no existe, por favor registrese" << endl;//Si no se encuentra
				break;
			}
			do {//Si se encuentra el usuario
				muestraMenú2();
				cin >> opcion2;
				switch (opcion2) {
				case 1://Para el menu de usuario
					do {
						muestraMenúUsuario();
						cin >> opcionPerfil;
						switch (opcionPerfil) {							
					
						//Distintas configuraciones/Opciones que tiene el usuario
						case 1:
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.gananciaYannadirFondos(cantidad);
							listaUsuarios.escrituraDatos();
							break;
						case 2: 
							cout << "Introduzca una cantidad: " << endl;
							cin >> cantidad;
							usuarioActual.apuesta(cantidad);
							listaUsuarios.escrituraDatos();
							break;
						case 3:
							cout << "Su saldo actual es: " << usuarioActual.getSaldo() << endl;
							break;
						case 4:
							break;
						}
					} while (opcionPerfil != 4);
					break;
				case 2://Para el menu de juegos
					do {//Los distintos juegos 
						cout << "------------------------BIENVENIDO AL MENU DE JUEGOS-----------------------" << endl;
						cout << "A que quieres jugar?" << endl;
						cout << "1.Piedra Papel o Tijera \n2.Tres en raya \n3.Wordle \n4.Juego de los palillos \n5.Maquina Tragaperras \n6.Ruleta \n7.Ahorcado \n8.BlackJack \n9.Salir" << endl;
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
							break;
						}
						case 4:
						{
							JuegoPalillos palillos;
							palillos.jugar(usuarioActual);
							break;
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
			 listaUsuarios.escrituraDatos();

			break;
		}

		case 2://Para crear un nuevo usuario
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
		case 3://Para eliminar un usuario existente 
			cout << "Introduzca el id del Usuario: " << endl;
			cin >> id;
			listaUsuarios.eliminarUsuario(listaUsuarios.buscarUsuario(id));
			cout << "Usuario eliminado" << endl;
		default:
			cout << "Elija una opcion valida" << endl;
		}
	} while (opcion != 0);//Cierre del programa
	listaUsuarios.escrituraDatos();
}