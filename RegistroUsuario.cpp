#include "RegistroUsuario.hpp"

#include "RegistroUsuario.hpp"
	RegistroUsuario::RegistroUsuario() {
	}
	vector <Usuario> RegistroUsuario::getUsuarios() {
		return usuarios;
	}
	void RegistroUsuario::escrituraDatos() {
		ofstream archivo;
		archivo.open("casino.txt");
		if (archivo.is_open()) {
			archivo << usuarios.size() << endl;
			for (Usuario u : usuarios)
				archivo << u.usuarioToString() << endl;
			archivo.close();
		}else 
			cout << "Error en la escritura de archivos" << endl;
	}
	void RegistroUsuario::cargaDatos() {
		ifstream archivo;
		int contador, id, edad, victoriasW, victoriasBJ, victoriasTP, victoriasTER, victoriasAhorcado, victoriasPalillos, victoriasRule, victoriasPPT,
			derrotasW, derrotasBJ, derrotasTP, derrotasTER, derrotasAhorcado, derrotasPalillos, derrotasRule, derrotaPPT,
			 empatesBJ, empatesTER, empatesPPT;
		double saldo;
		string nombre;
		archivo.open("casino.txt");
		if (archivo.is_open()) {
			archivo >> contador;
			for (int i = 0; i < contador; i++) {
				archivo >> nombre >> edad >> id >> saldo >> victoriasW >> victoriasBJ >> victoriasTP >> victoriasTER >> victoriasAhorcado >> victoriasPalillos >> victoriasRule
					>> derrotasW >> derrotasBJ >> derrotasTP >> derrotasTER >> derrotasAhorcado >> derrotasPalillos >> derrotasRule
					>> empatesBJ >> empatesTER >> victoriasPPT >> empatesPPT >> derrotaPPT; 
				usuarios.emplace_back( nombre,  edad,  id,  saldo,  victoriasW,  derrotasW,  victoriasBJ,  derrotasBJ,  empatesBJ,  victoriasTP,
						 derrotasTP,  victoriasTER,  derrotasTER,  empatesTER,  victoriasAhorcado,  derrotasAhorcado,  victoriasPPT,  empatesPPT,  derrotaPPT); 
			}
			archivo.close();
		}
		else
			cout << "Error en la carga de datos " << endl;
	}

	// NUEVO
	int RegistroUsuario::generarNuevoID() {
		int maxID = 0;
		for (Usuario u : usuarios) {
			if (u.getID() > maxID)
				maxID = u.getID();
		}
		return maxID + 1;
	}
	
	
	void RegistroUsuario::montaUsuario(string nombre, int edad, int id, double saldo) {
		Usuario u(nombre, edad, id, saldo);
		agregaUsuario(u);
	}

	void RegistroUsuario::agregaUsuario(Usuario u) {
		usuarios.push_back(u);
	}

	void RegistroUsuario::eliminarUsuario(Usuario u) {
		usuarios.erase(usuarios.begin() + buscarPosicionUsuario(u.getID()));
	}
	int RegistroUsuario::buscarPosicionUsuario(int id) {
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].getID() == id)
				return i;
		}
		return -1;
	}
	
	
	Usuario RegistroUsuario::buscarUsuario(int id) {
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return u;
		}
		return {"",-1,-1,-1};
		//return Usuario();
	}

	/*
	Usuario& RegistroUsuario::buscarUsuario(int id){
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return u;
		}
		throw runtime_error("Usuario no encontrado");
	}
	*/
	
	
	bool RegistroUsuario::compruebaID(int id) {
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return true;
		}
		return false;
	}

	/*RegistroUsuario::RegistroUsuario() {}
	vector <Usuario> RegistroUsuario::getUsuarios() {
		return usuarios;
	}*/
	/*int RegistroUsuario::generarNuevoID() {
		int maxID = 0;
		for (Usuario u : usuarios) {
			if (u.getID() > maxID)
				maxID = u.getID();
		}
		return maxID + 1;
	}
	void RegistroUsuario::escrituraDatos() {
		ofstream archivo;
		archivo.open("casino.txt");
		if (archivo.is_open()) {
			archivo << usuarios.size() << endl;
			for (Usuario u : usuarios)
				archivo << u.usuarioToString() << endl;
			archivo.close();
		}else 
			cout << "Error en la escritura de archivos" << endl;
	}
	void RegistroUsuario::cargaDatos() {
		ifstream archivo;
		int contador, id, edad;
		double saldo;
		string nombre;
		archivo.open("casino.txt");
		if (archivo.is_open()) {
			archivo >> contador;
			for (int i = 0; i < contador; i++) {
				archivo >> nombre >> edad >> id >> saldo; 
				usuarios.emplace_back(nombre, edad, id, saldo); 
			}
			archivo.close();
		}
		else
			cout << "Error en la carga de datos " << endl;
	}

	
	void RegistroUsuario::montaUsuario(string nombre, int edad, int id, double saldo) {
		Usuario u(nombre, edad, id, saldo);
		agregaUsuario(u);
	}

	void RegistroUsuario::agregaUsuario(Usuario u) {
		usuarios.push_back(u);
	}

	void RegistroUsuario::eliminarUsuario(Usuario u) {
		usuarios.erase(usuarios.begin() + buscarPosicionUsuario(u.getID()));
	}
	int RegistroUsuario::buscarPosicionUsuario(int id) {
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].getID() == id)
				return i;
		}
		return -1;
	}
	Usuario RegistroUsuario::buscarUsuario(int id) {
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return u;
		}
		return {"",-1,-1,-1};
		//return Usuario();
	}
	bool RegistroUsuario::compruebaID(int id) {
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return true;
		}
		throw invalid_argument("Este ID ya existe");
	}*/