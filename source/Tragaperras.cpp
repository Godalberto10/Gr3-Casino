#include "include/Tragaperras.hpp"

/*girarCarrete= Función de tipo String que mediante un número al azar dentro del size del Vector Simbolos, elige uno de estos 
*/ 
string Tragaperras :: girarCarrete() {
    return simbolos[rand() % simbolos.size()];/*
    /Utiliza el "%" para que el número aleatorio que está buscando la función rand, esté dentro del rango del
    vector símbolos
    */
}

/*
verificarGanador= Función que devuelve un booleano para verificar si el jugador ganó (los 3 carretes deben coincidir) 
Utiliza los carretes sacados de la función jugarTragaperras  y verifica mediante comparaciones si los tres carretes son iguales
*/ 
bool Tragaperras :: verificarGanador(string carrete1, string carrete2, string carrete3) {
    return (carrete1 == carrete2 && carrete2 == carrete3);
}

/*
jugarTragaperras= Función que devuelve un entero que simula jugar a la tragaperras, necesita el saldo y la apuesta que 
la saca del main. Para ganar se necesita que los tres carretes sean iguales, y en ese caso la apuesta se multiplica por 5 y se añade de nuevo al saldo. 
En el caso de que los tres carretes no sean iguales, simplemente la apuesta se vuelve 0 y como ya habíamos quitado la apuesta del saldo,
no se vuelve a añadir. 
String carrete1 = Utilizando la función girarCarrete damos el valor de esta variable de tipo String
String carrete2 = Utilizando la función girarCarrete damos el valor de esta variable de tipo String
String carrete3 = Utilizando la función girarCarrete damos el valor de esta variable de tipo String

*/ 
int Tragaperras :: jugarTragaperras(Usuario u, int apuesta) {
    if (apuesta > u.getSaldo()) {
        cout << "Saldo insuficiente.\n";
        return u.getSaldo();
    }
    
    u.apuesta(apuesta); // Restar la apuesta del saldo
    string carrete1 = girarCarrete();
    string carrete2 = girarCarrete();
    string carrete3 = girarCarrete();
    
    // Mostrar el resultado del giro
    cout << "\n " << carrete1 << " | " << carrete2 << " | " << carrete3 << "\n";
    
    if (verificarGanador(carrete1, carrete2, carrete3)) {
        int premio = apuesta * 5;  // Gana 5 veces la apuesta si coincide
        u.gananciaYannadirFondos(premio);//Añade el premio al saldo que tenemos
        cout << "¡Ganaste " << premio << " monedas! \n";
        u.aumentaVictoriasTP();
    } else {
        cout << "No ganaste esta vez.\n";
        u.aumentaDerrotasTP();
    }
    
    cout << "Saldo actual: " << u.getSaldo() << " monedas\n";
    return u.getSaldo();
}
/*
srand(time(0))= Inicialización del generador de números aleatorios
int saldo = Saldo inicial del jugador
int apuesta= Inicializamos la variable apuesta que deben poner los jugadores de cuanto quieren que sea la apuesta
*/
void Tragaperras :: jugar(Usuario u) {
    srand(time(0));  
      
   
    while (u.getSaldo() > 0) {
        cout << "\nIngresa tu apuesta o pulsa 0 para salir: ";
        cin >> apuesta;
        
        if (apuesta == 0) {
            cout << "Gracias por jugar. ¡Hasta la próxima! \n";
            break;
        }
        
        jugarTragaperras(u, apuesta);
    }
    
}