#include <iostream>
#include "Casino.hpp"//Librerias

using namespace std;

int main()
{
	Casino casino;//se crea casino	
	casino.menu();//se llama al metodo menu
	cout << "Gracias por jugar " << endl;
	return 0;
}