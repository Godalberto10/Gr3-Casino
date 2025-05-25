#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Usuario {
private://Atributos
	string nombre;
	int edad, id, victoriasW, derrotasW, victoriasBJ, derrotasBJ, empatesBJ, victoriasTP, derrotasTP,
		victoriasTER, derrotasTER, empatesTER, victoriasAhorcado, derrotasAhorcado,victoriasPPT,empatesPPT,derrotaPPT;
	int victoriasPalillos, derrotasPalillos, victoriasRule, derrotasRule;
	double saldo;
public:

	Usuario(){};//Constructores

	Usuario(string nombre, int edad, int id, double saldo);
	Usuario(string nombre, int edad, int id, double saldo, int victoriasW, int derrotasW, int victoriasBJ, int derrotasBJ, int empatesBJ, int victoriasTP,
		int derrotasTP, int victoriasTER, int derrotasTER, int empatesTER, int victoriasAhorcado, int derrotasAhorcado, int victoriasPPT, int empatesPPT, int derrotaPPT);
	
	string getNombre();
	double getSaldo();
	string usuarioToString();//Metodos y getters, explicados en el cpp
	int getID();
	void aumentaVictoriasW();
	void aumentaVictoriasPPT();
	void aumentaVictoriasBJ();
	void aumentaVictoriasTP();
	void aumentaVictoriasTER();
	void aumentaVictoriasAhorcado();
	void aumentaVictoriasPalillos();
	void aumentaVictoriasRule();
	void aumentaDerrotasW();
	void aumentaDerrotasPPT();
	void aumentaDerrotasBJ();
	void aumentaDerrotasTP();
	void aumentaDerrotasTER();
	void aumentaDerrotasAhorcado();
	void aumentaDerrotasPalillos();
	void aumentaDerrotasRule();
	void aumentaEmpatesBJ();
	void aumentaEmpatesTER();
	void aumentaEmpatesPPT();
	int partidasTotales();
	void apuesta(double cantidad);
	void gananciaYannadirFondos(double cantidad);
};
#endif