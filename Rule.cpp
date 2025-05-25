#include "Rule.hpp"


// Funcion para obtener el color del numero en la ruleta
string Rule :: obtenerColor(int numero) {
	if (numero == 0) return "verde";
	return (numero % 2 == 0) ? "negro" : "rojo";
}

void Rule :: jugar(Usuario u) {
	srand(time(0)); // Inicializar la semilla para numeros aleatorios

	cout << "Bienvenido al Casino - Ruleta" << endl;
	cout << "Tu saldo inicial es: " << u.getSaldo() << " euros." << endl;

	do {
		// Reiniciar valores de apuestas
		apostarNumero = apostarParImpar = apostarColor = false;
		totalApuesta = 0;

		// Apuesta por numero exacto
		cout << "Quieres apostar por un numero exacto? (s/n): ";
		char respuesta;
		cin >> respuesta;
		if (respuesta == 's') {
			cout << "Ingresa el numero por el que quieres apostar (0-36): ";
			cin >> apuestaNumero;//Escoges el numero
			if (apuestaNumero < 0 || apuestaNumero > 36) {
				cout << "Numero fuera de rango. Intentalo de nuevo." << endl;
				continue;
			}
			cout << "Ingresa la cantidad a apostar en el numero: ";
			cin >> montoNumero;//Escoges la cantidad
			if (montoNumero > u.getSaldo() || montoNumero < 0) {
				cout << "Apuesta invalida. No tienes suficiente saldo." << endl;
				continue;
			}
			totalApuesta += montoNumero;
			apostarNumero = true;
		}

		// Apuesta por par o impar
		cout << "Quieres apostar por par o impar? (s/n): ";
		cin >> respuesta;
		if (respuesta == 's') {
			cout << "Apuesta por par (p) o impar (i): ";
			cin >> opcionParImpar;
			if (opcionParImpar != 'p' && opcionParImpar != 'i') {
				cout << "Opcion invalida. Intentalo de nuevo." << endl;
				continue;
			}
			cout << "Ingresa la cantidad a apostar en par/impar: ";
			cin >> montoParImpar;
			if (montoParImpar > u.getSaldo() || montoParImpar < 0) {
				cout << "Apuesta invalida. No tienes suficiente saldo." << endl;
				continue;
			}
			totalApuesta += montoParImpar;
			apostarParImpar = true;
		}

		// Apuesta por color
		cout << "Quieres apostar por color rojo o negro? (s/n): ";
		cin >> respuesta;
		if (respuesta == 's') {
			cout << "Apuesta por rojo (r) o negro (n): ";
			cin >> opcionColor;
			if (opcionColor != 'r' && opcionColor != 'n') {
				cout << "Opcion invalida. Intentalo de nuevo." << endl;
				continue;
			}
			cout << "Ingresa la cantidad a apostar en color: ";
			cin >> montoColor;
			if (montoColor > u.getSaldo() || montoColor < 0) {
				cout << "Apuesta invalida. No tienes suficiente saldo." << endl;
				continue;
			}
			totalApuesta += montoColor;
			apostarColor = true;
		}

		// Verificar si la apuesta total excede el saldo
		if (totalApuesta > u.getSaldo()) {
			cout << "No puedes apostar mas de tu saldo disponible." << endl;
			continue;
		}

		// Descontar el total de apuestas del saldo
		u.apuesta(totalApuesta);

		// Girar la ruleta
		numeroRuleta = rand() % 37; // Generar numero entre 0 y 36
		colorResultado = obtenerColor(numeroRuleta);

		cout << "La ruleta gira... y cae en el " << numeroRuleta << " (" << colorResultado << ")" << endl;

		// Verificar resultados y pagar apuestas ganadas
		if (apostarNumero && apuestaNumero == numeroRuleta) {
			cout << "Felicidades! Has acertado el numero y ganas el doble de tu apuesta." << endl;
			u.gananciaYannadirFondos(montoNumero * 2);
			
		}//Todo se premia con el doble de lo apostado
		if (apostarParImpar && ((opcionParImpar == 'p' && numeroRuleta % 2 == 0) || (opcionParImpar == 'i' && numeroRuleta % 2 != 0))) {
			cout << "Ganaste! Acertaste la paridad y ganas el doble de tu apuesta." << endl;
			u.gananciaYannadirFondos(montoParImpar * 2);
		}
		if (apostarColor && ((opcionColor == 'r' && colorResultado == "rojo") || (opcionColor == 'n' && colorResultado == "negro"))) {
			cout << "Ganaste! Acertaste el color y ganas el doble de tu apuesta." << endl;
			u.gananciaYannadirFondos(montoColor * 2);
		}

		cout << "Tu saldo actual es: " << u.getSaldo() << " unidades." << endl;
		if (u.getSaldo() <= 0) {
			cout << "Te has quedado sin saldo. Fin del juego." << endl;
			break;
		}

		// Preguntar si quiere jugar otra ronda
		cout << "Quieres jugar otra partida? (s/n): ";
		cin >> continuar;
	} while (continuar == 's' && u.getSaldo() > 0);

	cout << "Gracias por jugar. Hasta la proxima!" << endl;
}