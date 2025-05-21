#include "include/RegistroUsuario.hpp"
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
	}