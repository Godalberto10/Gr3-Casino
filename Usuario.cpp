#include "Usuario.hpp"
	Usuario::Usuario(string nombre, int edad, int id, double saldo) {//Consturctor 	ue inicializa al usuario con las estadisticas a 0
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
	
	string Usuario::getNombre() {//Devuelve el nombre
		return nombre;
	}
	double Usuario::getSaldo() {//Devuelve el saldo
		return saldo;
	}
	string Usuario::usuarioToString() {//Lo convierte en un string, se usa para guardar en casino.txt
		return  nombre + " " + to_string(edad) + " " + to_string(id) + " " + to_string(saldo) + " " + to_string(victoriasW) + " " + to_string(victoriasBJ)
			+ " " + to_string(victoriasTP) + " " + to_string(victoriasTER) + " " + to_string(victoriasAhorcado) + " " + to_string(victoriasPalillos)
			+ " " + to_string(victoriasRule) + " " + to_string(derrotasW) + " " + to_string(derrotasBJ) + " " + to_string(derrotasTP) + " " + to_string(derrotasTER)
			+ " " + to_string(derrotasAhorcado) + " " + to_string(derrotasPalillos) + " " + to_string(derrotasRule) + " " + to_string(empatesBJ) + " " +
			to_string(empatesTER) + " " +to_string(victoriasPPT) + " " + to_string(empatesPPT) + " " + to_string(derrotaPPT);
	}
	int Usuario::getID() {//Devuelve el id
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