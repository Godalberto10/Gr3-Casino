#include "Wordle.hpp"


	/**
	Array constante declarado en el ámbito global, cuyo contenido es un diccionario
	con 1390 palabras de 5 letras en español.
	*/
	

	void Wordle::jugar(Usuario u)  // Función que desarrolla todo el proceso del juego  el & apunta a la dirección de memoria
	{
		cout << "------------ BIENVENIDO AL WORDLE ------------" << endl;
		bool jugarJ = true;
		while (jugarJ) {
			do {
				cout << "\n" << u.getNombre() << " introduzca la cantidad que desea apostar: " << endl;
				cin >> apuesta;

				if (apuesta > u.getSaldo()) {
					cout << "ERROR, cantidad superior al saldo" << endl;
				}
			} while (apuesta > u.getSaldo());
			u.apuesta(apuesta);
			srand((unsigned)time(NULL));        // Generamos la semilla para obtener la palabra
			int adivinanza = rand() % T_DIC;   // Se escoge una palabra de entre las 1390 del diccionario


			palabraobjetivo = diccionario[adivinanza];    // Se guarda la palabra objetivo
			distribucion[5];                              // Se establecen las letras que tiene que tener la palabra intentada por el jugador
			acierto = false;

			palabra;
			for (int intento = 0; intento < 5; intento++) { //Primer for que establece el número de intentos y empieza el código
				cout << "Introduzca una palabra (recuerda,el maximo de letras es 5): " << endl;
				cin >> palabra;
				if (palabra.length() != 5) {
					cout << "Introduzca una palabra (recuerda,el maximo de letras es 5 y el minimo también): " << endl; //En caso de que la palabra tenga más o menos de 5 letras salta este aviso
					intento--;  //Se le resta uno al número de intentos ya que esto no cuenta
					continue;   //Función con la misma utilidad que el break
				}
				if (!buscarPalabra(palabra)) {
					cout << "La palabra no esta en el diccionario,intente otra " << endl;       //En caso de que la palabra no esté en el diccionaro 
					intento--;
					continue;
				}
				distribucion[intento] = compruebaPalabra(palabra, palabraobjetivo, acierto);  //Contiene las palabras intentadas
				cout << distribucion[intento] << endl;
				if (acierto) {     // en caso de que el jugador acierte 
					cout << "Has ganado!,la palabra era: " << palabraobjetivo << " y el numero de intentos ha sido: " << intento << endl;
					u.gananciaYannadirFondos(apuesta * 2);
					u.aumentaVictoriasW();
					break;
				}
			}
			cout << "La palabra era: " << palabraobjetivo << endl;     // En caso de que el jugador no acierte la palabra
			mostrarDistribucion(distribucion, 5);
			u.aumentaDerrotasW();
			int de;
			cout << "¿Quieres volver a jugar? (Si - 1/No - 0)" << endl;
			cin >> de;
			if(de == 1)
				jugarJ = true;
			else
				jugarJ = false;
		}
	}
	string Wordle :: obtenerPalabraMarcada(Letra l[5], string palabra) {  //Función encargada de marcar,letra tiene un 5 para que marque las 5 letras
		string resultado = "";                                  // Se define e inicializa la función que marca las palabras
		for (int i = 0; i < palabra.length(); i++)
		{            // Bucle encargado de marcar todas las letras de la palabra 
			if (l[i] == CORRECTA)
				resultado += "[" + string(1, palabra[i]) + "]"; // += ya que empieza desde 0 y así se le suma 1 (concatenar caracteres) (string 1 lo convierte en una cadena de caracteres)
			else if (l[i] == POSICION_INCORRECTA)
				resultado += "(" + string(1, palabra[i]) + ")";
			else
				resultado += palabra[i];
		}
		return resultado;
	}
	bool Wordle::buscarPalabra(string palabra) {     // Función encargada de mirar si la palabra intentada está dentro del diccionario 
		for (int i = 0; i < T_DIC; i++) {    // Bucle que comprueba todas las palabras del diccionario 
			if (diccionario[i] == palabra)
				return true;
		}
		return false;
	}
	void Wordle :: mostrarDistribucion(string distrib[], int intentos) {   //Muestra los intentos totales guardados 
		for (int i = 0; i < intentos; i++)
			cout << distrib[i] << endl;
	}
	string Wordle :: compruebaPalabra(string palabra, string wordle, bool& acierto) {   // Función que comprueba si la posición de la letra es correcta o no 
		 Letra marcado[5] = { INCORRECTA,INCORRECTA,INCORRECTA,INCORRECTA,INCORRECTA };     //Inicializa las letras desde un principio como incorrectas
		if (palabra == wordle)                                                           // Bucle que comprueba si la palabra intentada es igual a la palabra objetivo 
			acierto = true;
		else {
			for (int i = 0; i < palabra.length(); i++) {                                 //Primer bucle que recorre la intentada buscando algún parecido con la palabra objetivo
				for (int j = 0; j < wordle.length(); j++) {                             //Bucle anidado que recorre la palabra objetivo 
					if (palabra[i] == wordle[j]) {
						if (i == j)
							marcado[i] = CORRECTA;
						else
							marcado[i] = POSICION_INCORRECTA;
					}
				}
			}
		}
		return obtenerPalabraMarcada(marcado, palabra);                  //Sabiendo ya las letras que son correctas e incorrectas hacemos una llamada a la función para marcar las funciones
	}