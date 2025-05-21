#include "PiedraPapelTijera.hpp"


void PiedraPapelTijera::jugar(Usuario u) {
	srand(time(0)); //esto es para que el programa sea siempre aleatorio, utilizando la hora para escoger una opcion distinta
	i = 1;
	while (i != 0) {

		cout << "Introduzca una cantidad para apostar: " << endl;
		cin >> apuesta;
		u.apuesta(apuesta);

		cout << "JUEGO DE PIEDRA, PAPEL O TIJERA" << endl;
		cout << "Elige una opcion" << endl;
		cout << "1.Piedra" << endl;
		cout << "2.Papel" << endl;
		cout << "3.Tijera" << endl;
		cout << "0.Finalizar" << endl;
		cout << "Tu eleccion: " << endl;

		cin >> opcionJugador;

		if (opcionJugador < 0 || opcionJugador > 3) {
			cout << "Opcion no valida, intentalo de nuevo" << endl;
		}
		else {
			if (opcionJugador == 0) {
				i = 0;
			}
			else {
				opcionMaquina = (rand() % 3) + 1; //el %3 te puede devolver un 0, 1 o 2, por lo que se suma 1 para que sea 1, 2 o 3

				cout << "Tu elegiste: " << opciones[opcionJugador - 1] << endl; //Ya que el array empieza en 0
				cout << "La maquina eligio: " << opciones[opcionMaquina - 1] << endl;

				if (opcionJugador == opcionMaquina) {
					cout << "Empate!" << endl;
					u.aumentaEmpatesPPT();
					u.gananciaYannadirFondos(apuesta);
				}
				else if ((opcionJugador == 1 && opcionMaquina == 3) || (opcionJugador == 2 && opcionMaquina == 1) || (opcionJugador == 3 && opcionMaquina == 2)) {
					cout << "Ganaste!" << endl;
					u.aumentaVictoriasPPT();
					u.gananciaYannadirFondos(apuesta * 1.5);
				}
				else {
					cout << "Perdiste..." << endl;
					u.aumentaDerrotasPPT();
				}
			}
		}
	}

}