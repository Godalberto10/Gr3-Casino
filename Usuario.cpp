#include "Usuario.hpp"
	Usuario::Usuario(string nombre, int edad, int id, double saldo) {
			this->nombre = nombre;
			this->edad = edad;
			this->saldo = saldo;
			this->id = id;
			this->victoriasW = 0;
			this->victoriasBJ = 0;
			this->victoriasTP = 0;
			this->victoriasTER = 0;
			this->victoriasAhorcado = 0;
			this->victoriasPalillos = 0;
			this->victoriasRule = 0;
			this->derrotasW = 0;
			this->derrotasBJ = 0;
			this->derrotasTP = 0;
			this->derrotasTER = 0;
			this->derrotasAhorcado = 0;
			this->derrotasPalillos = 0;
			this->derrotasRule = 0;
			this->empatesBJ = 0;
			this->empatesTER = 0;
			this->victoriasPPT = 0;
			this->empatesPPT = 0;
			this->derrotaPPT = 0;
	}
	//Hacer un constructor de usuario igual donde no se 0, donde se le pase todo.

	Usuario::Usuario(string nombre, int edad, int id, double saldo, int victoriasW, int derrotasW, int victoriasBJ, int derrotasBJ, int empatesBJ, int victoriasTP,
		int derrotasTP, int victoriasTER, int derrotasTER, int empatesTER, int victoriasAhorcado, int derrotasAhorcado, int victoriasPPT, int empatesPPT, int derrotaPPT) {
			this->nombre = nombre;
			this->edad = edad;
			this->saldo = saldo;
			this->id = id;
			this->victoriasW = victoriasW;
			this->victoriasBJ = victoriasBJ;
			this->victoriasTP = victoriasTP;
			this->victoriasTER = victoriasTER;
			this->victoriasAhorcado = victoriasAhorcado;
			this->victoriasPalillos = victoriasPalillos;
			this->victoriasRule = victoriasRule;
			this->derrotasW = derrotasW;
			this->derrotasBJ = derrotasBJ;
			this->derrotasTP = derrotasTP;
			this->derrotasTER = derrotasTER;
			this->derrotasAhorcado = derrotasAhorcado;
			this->derrotasPalillos = derrotasPalillos;
			this->derrotasRule = derrotasRule;
			this->empatesBJ = empatesBJ;
			this->empatesTER = empatesTER;
			this->victoriasPPT = victoriasPPT;
			this->empatesPPT = empatesPPT;
			this->derrotaPPT = derrotaPPT;
	}
	
	string Usuario::getNombre() {
		return nombre;
	}
	double Usuario::getSaldo() {
		return saldo;
	}
	string Usuario::usuarioToString() {
		return  nombre + " " + to_string(edad) + " " + to_string(id) + " " + to_string(saldo) + " " + to_string(victoriasW) + " " + to_string(victoriasBJ)
			+ " " + to_string(victoriasTP) + " " + to_string(victoriasTER) + " " + to_string(victoriasAhorcado) + " " + to_string(victoriasPalillos)
			+ " " + to_string(victoriasRule) + " " + to_string(derrotasW) + " " + to_string(derrotasBJ) + " " + to_string(derrotasTP) + " " + to_string(derrotasTER)
			+ " " + to_string(derrotasAhorcado) + " " + to_string(derrotasPalillos) + " " + to_string(derrotasRule) + " " + to_string(empatesBJ) + " " +
			to_string(empatesTER) + " " +to_string(victoriasPPT) + " " + to_string(empatesPPT) + " " + to_string(derrotaPPT);
	}
	int Usuario::getID() {
		return id;
	}

	// SETTERS DE LAS VICTORIAS 
	void Usuario::aumentaVictoriasW(){
		victoriasW++;
	}
	void Usuario::aumentaVictoriasPPT() {
		victoriasPPT++;
	}
	void Usuario::aumentaVictoriasBJ() {
		victoriasBJ++;
	}
	void Usuario::aumentaVictoriasTP() {
		victoriasTP++;
	}
	void Usuario::aumentaVictoriasTER() {
		victoriasTER++;
	}
	void Usuario::aumentaVictoriasAhorcado() {
		victoriasAhorcado++;
	}
	void Usuario::aumentaVictoriasPalillos() {
		victoriasPalillos++;
	}
	void Usuario::aumentaVictoriasRule() {
		victoriasRule++;
	}

	//SETTERS QUE AUMENTAN LAS DERROTAS

	void Usuario::aumentaDerrotasW(){
		derrotasW++;
	}
	void Usuario::aumentaDerrotasPPT() {
		derrotaPPT++;
	}
	void Usuario::aumentaDerrotasBJ() {
		derrotasBJ++;
	}
	void Usuario::aumentaDerrotasTP() {
		derrotasTP++;
	}
	void Usuario::aumentaDerrotasTER() {
		derrotasTER++;
	}
	void Usuario::aumentaDerrotasAhorcado() {
		derrotasAhorcado++;
	}
	void Usuario::aumentaDerrotasPalillos() {
		derrotasPalillos++;
	}
	void Usuario::aumentaDerrotasRule() {
		derrotasRule++;
	}
	void Usuario::aumentaEmpatesBJ() {
		empatesBJ++;
	}
	void Usuario::aumentaEmpatesTER() {
		empatesTER++;
	}
	void Usuario::aumentaEmpatesPPT() {
		empatesPPT++;
	}
	/*Función encargada de calcular las partidas totales del usuario
	*/
	int Usuario::partidasTotales() {
		return derrotasAhorcado + derrotasBJ + derrotasPalillos + derrotasRule 
			+ derrotasTER + derrotasTP + derrotasW + victoriasAhorcado + victoriasBJ 
			+ victoriasPalillos + victoriasRule + victoriasTER + victoriasTP + victoriasW 
			+ empatesBJ + empatesTER + victoriasPPT+empatesPPT+derrotaPPT;
	}

	/*Función encargada de crear un informe con las estadísticas del usuario que se mostrará en un txt
	*/
	void Usuario::informeDelUsuario() {
		ofstream archivo;
		archivo.open("informe" + nombre);
		if (archivo.is_open()) {
			archivo << "--------------------------------------------------" << endl;
			archivo << "                   INFORME GENERAL                " << endl;
			archivo << "--------------------------------------------------" << endl;
			archivo << "| %10-s  cuenta con las siguientes estadisticas:              |" << nombre << endl;
			archivo << "| Partidas jugadas totales:                     %10-d"<< partidasTotales() << endl;
			archivo << "|   Partidas jugadas de Wordle:       %4-d         |" << derrotasW + victoriasW << endl;
			archivo << "|" << nombre << " cuenta con las siguientes estadisticas: |" << endl;
			archivo << "|   Partidas jugadas de Wordle:       " << derrotasW + victoriasW << "     |" << endl;
			archivo << "|   Victorias: " << victoriasW << endl;
			archivo << "|   Derrotas:  " << derrotasW << endl;
			archivo << endl;
			archivo << "|   Partidas jugadas de Ahorcado: " << derrotasAhorcado + victoriasAhorcado << endl;
			archivo << "|   Victorias:  " << victoriasW << endl;
			archivo << "|   Derrotas:   " << derrotasAhorcado << endl;
			archivo << endl;
			archivo << "|    Partidas jugadas del BlackJack: " << derrotasBJ+victoriasBJ+empatesBJ<< endl;
			archivo << "|    Victorias: " << victoriasBJ << endl;
			archivo << "|    Empates:   " << empatesBJ << endl;
			archivo << "|    Derrotas:  " << derrotasBJ << endl;
			archivo << endl;
			archivo << "|    Partidas jugadas de los palillos: " << derrotasPalillos+victoriasPalillos<<endl;
			archivo << "|     Victorias: " << victoriasPalillos;
			archivo << "|     Derrotas:  " << derrotasPalillos;
			archivo << endl;
			archivo << "|     Partidas jugadas de la Ruleta: " << victoriasRule + derrotasRule << endl;
			archivo << "|     Victorias: " << victoriasRule << endl;
			archivo << "|     Derrotas:  " << derrotasRule << endl;
			archivo << endl;
			archivo << "|     Partidas jugadas del TER:  " << victoriasTER + empatesTER + derrotasBJ << endl;
			archivo << "|     Victorias: " << victoriasTER << endl;
			archivo << "|     Empates:   " << empatesTER << endl;
			archivo << "|     Derrotas:  " << derrotasTER << endl;
			archivo << endl;
			archivo << "|     Partidas jugadas de la Tragaperras: " << victoriasTP + derrotasTP << endl;
			archivo << "|     Victorias: " << victoriasTP << endl;
			archivo << "|     Derrotas:  " << derrotasTP << endl;
			archivo << endl;
			archivo << "|     Partidas jugadas Piedra papel tijera: " << victoriasPPT + empatesPPT + derrotaPPT << endl;
			archivo << "|     Victorias: " << victoriasPPT << endl;
			archivo << "|     Empates:   " << empatesPPT << endl;
			archivo << "|     Derrotas:  " << derrotaPPT << endl;
			archivo << "--------------------------------------------------" << endl;
			archivo << "|     ID:     " << id << endl;
			archivo << "|     Saldo:  " << saldo << endl;
			// PENDIENTE DE LA RESPUESTA DE IRINA PARA COMPLETAR EL FORMATO 50 caracteres son en total 
		}
		else
			cout << "Ha habido un error creando el informe del usuario " << endl;
		
	}

	/*Función encargada de quitar el saldo de la cuenta a la hora de hacer una apesta
	*/
	void Usuario::apuesta(double cantidad) {
		saldo -= cantidad;
	}
	/*Función encargada de sumar la cantidad que se ha ganado en la cuenta
	*/
	void Usuario::gananciaYannadirFondos(double cantidad) {
		saldo += cantidad;
	}