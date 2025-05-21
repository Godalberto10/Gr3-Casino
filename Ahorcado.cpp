#include "Ahorcado.hpp"


void Ahorcado :: jugar(Usuario u) {
    vector<string> palabras = cargarPalabras("palabras_rae_l.txt");
    if (palabras.empty()) {
        cout << "Error: No se pudieron cargar palabras desde el archivo." << endl;

    }


    while (partidaActiva) {
        vida = 6;
        pal = "";
        fallos = "";
        clear();
        cout << "\t-----A H O R C A D O-----" << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion1;

        switch (opcion1) {
        case '1':
            jugarPartida(palabras, u);
            break;
        case '2':
            partidaActiva = FALSE;

            break;

        default:
            cout << "Algo va mal" << endl;
            break;
        }
    }
}

vector<string> Ahorcado :: cargarPalabras(const string& nombreArchivo) {
    vector<string> palabras;
    ifstream archivo(nombreArchivo);
    string palabra;

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return palabras;
    }

    while (archivo >> palabra) {
        palabras.push_back(palabra);
    }
    archivo.close();
    return palabras;
}

void Ahorcado :: jugarPartida(const vector<string>& palabras,Usuario u) {
    do {
        cout << "Introduzca la cantidad a apostar";
        cin >> apuesta;
    } while (u.getSaldo() < apuesta || apuesta < 0);
    u.apuesta(apuesta);

    srand((int)time(NULL));
    numRan = rand() % palabras.size();

    for (size_t i = 0; i < palabras[numRan].size(); i++) {
        pal += "-";
    }

    while (vida > 0) {
        clear();
        cout << "\t-A-H-O-R-C-A-D-O-" << endl;
        dibujar();
        cout << "Fallos: " << fallos << endl;
        cout << "Progreso: " << pal << endl;
        cout << "Ingrese una letra: " << endl;
        cin >> opcion;

        correcta = false;
        for (size_t i = 0; i < palabras[numRan].size(); i++) {
            if (palabras[numRan][i] == opcion) {
                pal[i] = opcion;
                correcta = true;
            }
        }
        if (!correcta) {
            vida--;
            fallos += opcion;
        }
        completa = true;
        for (size_t i = 0; i < pal.size(); i++) {
            if (pal[i] == '-') {
                completa = false;
            }
        }
        if (completa) {
            clear();
            cout << "\t-A-H-O-R-C-A-D-O-" << endl;
            dibujar();
            cout << "Palabra: " << palabras[numRan] << endl;
            u.aumentaVictoriasAhorcado();
            u.gananciaYannadirFondos(apuesta * 2);
            cout << "Ganaste. Ingresa un caracter para continuar: " << endl;
            cin >> opcion;
            return;
        }
    }
    clear();
    cout << "\t-A-H-O-R-C-A-D-O-" << endl;
    dibujar();
    u.aumentaDerrotasAhorcado();
    cout << "Palabra: " << palabras[numRan] << endl;
    cout << "Perdiste. Ingresa un caracter para continuar: " << endl;
    cin >> opcion;
}

void Ahorcado :: clear() {
    if (system("cls") == -1) {
        cout << "Error al limpiar la pantalla" << endl;
    }
}

void Ahorcado :: dibujar() {
    switch (vida) {
    case 6:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 5:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 4:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |       |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 3:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 2:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 1:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |      /" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    case 0:
        cout << "  ---------" << endl;
        cout << "  |       |" << endl;
        cout << "  |       O" << endl;
        cout << "  |      /|\\" << endl;
        cout << "  |      / \\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " ===" << endl;
        break;
    }
}