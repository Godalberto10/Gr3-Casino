#include "Blackjack.hpp"//Incluye las funciones y estructuras utilizadas

	void BlackJack::jugar(Usuario u) {//El metodo principal
		//string transformarEnCarta(int num);

		cout << "----------------------------Bienvenido al BlackJack-----------------------------" << endl;
		jugarJ = true;
		while (jugarJ) {
			finalizarTurno = false;
			totalPuntosUsuario = 0;//Inicializamos variables al comienzo de cada partida
			totalPuntosCroupier = 0;
			opcion1 = 1;
			do {//Pide al usuario la cantidad para apostar, repite hasta que la apuesta no supere el saldo
			cout << "\n" << " introduzca la cantidad que desea apostar: " << endl;
			try { 
				cin >> apuesta; 
			}
			catch (exception e) {
			};
			if (apuesta > u.getSaldo()) {
				cout << "ERROR, cantidad superior al saldo" << endl;
			}
		} while (apuesta > u.getSaldo());
		u.apuesta(apuesta);//Empieza el juego
			cout << "----------------------------EMPIEZA EL JUEGO-----------------------------" << endl;
			cout << "Tu apuesta: " << apuesta << endl;
			carta1 = calculaCartaAleatoria();//Reparto de la 1ºcarta
			cout << "El valor de la primera carta es: " << transformarEnCarta(carta1) << endl;
			totalPuntosUsuario += verificarAs(carta1);
			carta2 = calculaCartaAleatoria();//Reparto de la 2º
			cout << "El valor de la segunda carta es: " << transformarEnCarta(carta2) << endl;
			totalPuntosUsuario += verificarAs(carta2);
			cartaCroupier = calculaCartaAleatoria();//Reparto del croupier
			totalPuntosCroupier = calcularValorCarta(cartaCroupier);
			cout << "El croupier tiene un " << transformarEnCarta(cartaCroupier) << endl;
			totalPuntosUsuario += calcularValorCarta(carta1) + calcularValorCarta(carta2);
			cout << "En total tienes: " << totalPuntosUsuario << endl;
			while (opcion1 == 1 && totalPuntosUsuario < 21) {
				cout << "\n\n\nQue deseas hacer? (1-Coger otra carta,2-Plantarte)" << endl;
				try {//El jugador puede pedir cartas hasta plantarse o pasarse de 21
					cin >> opcion1;
				}
				catch (exception e) {
				}
				if (opcion1 == 1) {
					cartaX = calculaCartaAleatoria();
					cout << "El valor de la carta es: " << transformarEnCarta(cartaX) << endl;
					totalPuntosUsuario += verificarAs(cartaX);
					totalPuntosUsuario += calcularValorCarta(cartaX);
					cout << "El valor total es: " << totalPuntosUsuario << endl;
				}
			}
			if (totalPuntosUsuario > 21) {//Esto es si el jugador se pasa de 21
				u.aumentaDerrotasBJ();
				jugarJ = volverAJugarDerrota();
			}
			else if (totalPuntosUsuario == 21) {//Esto es si tiene 21 exactos
				u.aumentaVictoriasBJ();
				u.gananciaYannadirFondos(apuesta * 2);
				jugarJ = volverAJugarVictoria();
			}
			else {
				cartaX = calculaCartaAleatoria();//El croupier recibe su 2º carta
				cout << "El croupier ha sacado " << transformarEnCarta(cartaX) << endl;
				totalPuntosCroupier += calcularValorCarta(cartaX);
				do {
					cout << "El croupier tiene " << totalPuntosCroupier << " puntos" << endl;
					if (totalPuntosCroupier > totalPuntosUsuario && totalPuntosCroupier <= 21) {
						u.aumentaDerrotasBJ();//croupier gana
						jugarJ = volverAJugarDerrota();
						finalizarTurno = true;
					}
					else if (totalPuntosCroupier == totalPuntosUsuario) {
						u.aumentaEmpatesBJ();//Empate
						u.gananciaYannadirFondos(apuesta);
						jugarJ = volverAJugarEmpate();
						finalizarTurno = true;
					}
					else if (totalPuntosCroupier < totalPuntosUsuario && totalPuntosCroupier <= 16) {
						cartaX = calculaCartaAleatoria();//El croupier roba otra
						cout << "El croupier ha sacado " << transformarEnCarta(cartaX) << endl;
						totalPuntosCroupier += calcularValorCarta(cartaX);
						finalizarTurno = false;
					}
					else {//El jugador gana
						u.aumentaVictoriasBJ();
						u.gananciaYannadirFondos(apuesta * 2);
						jugarJ = volverAJugarVictoria();
						finalizarTurno = true;
					}
				} while (totalPuntosCroupier <= 21 && !finalizarTurno);
				if (totalPuntosCroupier > 21)
					jugarJ = volverAJugarVictoria();
			}
		}//acaba el metodo jugar
	}

	int BlackJack::calculaCartaAleatoria() {//Genera un numero entre 1 y 12 como valor de carta
		srand((unsigned)time(NULL));
		Sleep(1000);
		return (rand() % 12) + 1;
	}
	int BlackJack::verificarAs(int num) {
		int opcion;//Para decidir si el As vale 1 o 11
		if (num == 1) {
			do {
				cout << "Deseas poner un 1 o un 11? (Pulsa 1 para annadir 1 || Pulsa 2 para annadir 11)" << endl;
				cin >> opcion;
			} while (opcion != 1 && opcion != 2);
			if (opcion == 1) {
				return 1;
			}
			else if (opcion == 2)
				return 10;
		}
		return 0;
	}

	string BlackJack::transformarEnCarta(int num) {
		switch (num) {//Convierte un numero a la carta correspondiente para mostrarla
		case 1: return "As";
		case 11: return "J";
		case 12: return "Q";
		case 13: return "K";
		default: return to_string(num);
		}
	}

	bool BlackJack::volverAJugarDerrota() {//Para preguntarle al jugador si quiere volver a jugar o no
		int opcion2;
		cout << "Has perdido, quieres jugar otra vez? (1-Si/ Presiona cualquier numero para salir)" << endl;
		try {
			cin >> opcion2;
		}
		catch (exception e) {
		}
		if (opcion2 == 1)
			return true;
		else
			return false;
	}

	bool BlackJack::volverAJugarEmpate() {//Para preguntarle al jugador si quiere volver a jugar o no
		int opcion2;
		cout << "Has empatado, quieres jugar otra vez? (1-Si/ Presiona cualquier numero para salir)" << endl;
		try {
			cin >> opcion2;
		}
		catch (exception e) {
		}
		if (opcion2 == 1)
			return true;
		else
			return false;
	}

	bool BlackJack::volverAJugarVictoria() {//Para preguntarle al jugador si quiere volver a jugar o no
		int opcion2;
		cout << "Has ganado! quieres jugar otra vez? (1-Si/ Presiona cualquier numero para salir)" << endl;
		try {
			cin >> opcion2;
		}
		catch (exception e) {
		}
		if (opcion2 == 1)
			return true;
		else
			return false;
	}

	int BlackJack::calcularValorCarta(int num) {//Convierte la carta en los puntos correspondientes
		if (num < 9)
			return num;
		else if (num >= 10 && num <= 13)
			return 10;
		else
			return 0;
	}