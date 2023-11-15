#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>
#include <conio.h>
using namespace std;

int main(){
	const int longitudMaxima = 10;
	char caracter;
	string resultado;
	vector<char> caracteres;

	cout << "Introduce caracteres uno por uno: ";

	while ((caracter = getch()) != '\r'){
		if (caracteres.size() >= longitudMaxima){
			cout << "Longitud máxima alcanzada." << endl;
			break;
		}
		caracteres.push_back(caracter);
		cout << caracter;
	}

	string cadena(caracteres.begin(), caracteres.end());
	cout << "\nLa cadena introducida es: " << cadena << endl;

	string invertido = cadena;
	reverse(invertido.begin(), invertido.end());

	if (cadena == invertido) {
		cout << "Es palindromo!" << endl;
	} else {
		cout << "No es palindromo!" << endl;
	}

	return 0;
}