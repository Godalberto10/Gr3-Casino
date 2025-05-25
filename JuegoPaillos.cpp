#include "JuegoPalillos.hpp"


int JuegoPalillos :: pedirNumero(int min, int max) { //Esta funcion pide un numero entre el rango min y max, si no se introduce un numero en ese rango, vuelve a pedirlo
	do {
		cout << "Introduzca un numero en el rango " << min << "-" << max << ": " << endl;
		cin >> num;
		if (num<min || num>max) {
			cout << "Introduce un numero en el rango indicado " << endl;
		}
	} while (num < min || num > max);
	return num;
}

void JuegoPalillos :: escribeJuego(int numPalillos) {//Esta funcion escribe el estado del juego, es decir, cuantos palillos quedan y los muestra
	cout << "Quedan: " << numPalillos << " palillos" << endl;
	for (int i = 0; i < numPalillos; i++) {
		cout << "|";
	}
	cout << endl;
}

int JuegoPalillos :: juegaOrdenador(int numPalillos) {//Esta funcion hace que el ordenador juegue, es decir, quita palillos
	num = (numPalillos - 1) % 4;
	if (num == 0) {
		num = rand() % min(3, numPalillos) + 1;
	}
	cout << "He quitado " << num << " palillos" << endl;
	return num;
}

int JuegoPalillos :: juegaUsuario(int numPalillos) {//Esta funcion hace que el usuario juegue, es decir, quita palillos
	cout << "Es tu turno, Cuantos palillos quitas?: ";
	return pedirNumero(1, min(3, numPalillos));//esta funcion lo que hace es pedir un numero entre el rango 1 y min(3,numPalillos)
}//min(3,numPalillos) lo que devuelve es el menor de esos valores, si es 3 pues devuelve 3 como el menor valor y si hay menos de 3 palillos devuelve ese numero

void JuegoPalillos::jugar(Usuario u) {//Esta es la funcion principal del juego, donde se desarrolla todo el juego
	jugarOtraVez = 1;
	while (jugarOtraVez == 1) {
		cout << "Bienvenido al juego de los palillos" << endl;
		do {
			cout << "Introduzca la cantidad a apostar: ";
			cin >> apuesta;
		} while (u.getSaldo() < apuesta || apuesta < 0);
		u.apuesta(apuesta);
		srand(time(nullptr));//nullptr sirve para no guardar ese resultado del time(), ya que si pones time() no compilaria
		numPalillos = rand() % (50 - 15 + 1) + 15; //Para una num entre 15-50

		if (rand() % 2 == 0) {
			turno = Turno::ORDENADOR;
		}
		else {
			turno = Turno::USUARIO;
		}

		do {
			escribeJuego(numPalillos);

			if (turno == Turno::ORDENADOR) {
				quitaPalillos = juegaOrdenador(numPalillos);
			}
			else {
				quitaPalillos = juegaUsuario(numPalillos);
			}

			numPalillos -= quitaPalillos;

			if (turno == Turno::USUARIO) {
				turno = Turno::ORDENADOR;
			}
			else {
				turno = Turno::USUARIO;
			}
		} while (numPalillos > 0);

		if (turno == Turno::ORDENADOR) {
			cout << "Has ganado!" << endl;
			u.gananciaYannadirFondos(apuesta * 1.5);
			u.aumentaVictoriasPalillos();
		}
		else {
			cout << "Has perdido..." << endl;
			u.aumentaDerrotasPalillos();
		}
		cout << "Quieres jugar otra vez? Si=1 - No=0" << endl;
		cin >> jugarOtraVez;
	}
}
