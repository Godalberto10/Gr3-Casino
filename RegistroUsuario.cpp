#include "RegistroUsuario.hpp"
	RegistroUsuario::RegistroUsuario() {//Constructor por defecto
	}
	vector <Usuario> RegistroUsuario::getUsuarios() {
		return usuarios;//devuelve la lista de usuarios registrados
	}
	void RegistroUsuario::escrituraDatos() {//Escribe los datos en casino.txt
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
	void RegistroUsuario::cargaDatos() {//Carga los datos del archivo casino.txt
		ifstream archivo;
		int contador, id, edad, victoriasW, victoriasBJ, victoriasTP, victoriasTER, victoriasAhorcado, victoriasPalillos, victoriasRule, victoriasPPT,
			derrotasW, derrotasBJ, derrotasTP, derrotasTER, derrotasAhorcado, derrotasPalillos, derrotasRule, derrotaPPT,
			 empatesBJ, empatesTER, empatesPPT;
		double saldo;
		string nombre;
		archivo.open("casino.txt");
		if (archivo.is_open()) {//Reconstruye los objetos usuario con sus estadisticas de juego
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
	int RegistroUsuario::generarNuevoID() {//Genera un nuevo ID de usuario
		int maxID = 0;
		for (Usuario u : usuarios) {
			if (u.getID() > maxID)
				maxID = u.getID();
		}
		return maxID + 1;
	}
	
	
	void RegistroUsuario::montaUsuario(string nombre, int edad, int id, double saldo) {
		Usuario u(nombre, edad, id, saldo);
		agregaUsuario(u);//Crea y agrega un usuario a la lista
	}

	void RegistroUsuario::agregaUsuario(Usuario u) {
		usuarios.push_back(u);//añade un usuario ya creado a usuarios
	}

	void RegistroUsuario::eliminarUsuario(Usuario u) {//elimina a un usuario segun su ID
		usuarios.erase(usuarios.begin() + buscarPosicionUsuario(u.getID()));
	}
	int RegistroUsuario::buscarPosicionUsuario(int id) {//Busca la posicion de un usuario segun su ID
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].getID() == id)
				return i;
		}
		return -1;
	}
	
	
	Usuario RegistroUsuario::buscarUsuario(int id) {//Busca un usuario segun su ID
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return u;
		}
		return {"",-1,-1,-1};
		//return Usuario();
	}
	
	bool RegistroUsuario::compruebaID(int id) {//Comprueba si existe el ID 
		for (Usuario u : usuarios) {
			if (u.getID() == id)
				return true;
		}
		return false;
	}
