//Desarrolla una aplicacion que permita al usuario introducir una cadena de caracteres (uno por uno), minetras la cadena no llegue al maximo de su tamaño o se precione la tecla enter.

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    const int max_length = 5;   // Longitud máxima de la cadena
    char cadena[max_length + 1]; // +1 para el carácter nulo de terminación
    int posicion = 0;            // Posición actual en la cadena

    cout << "Introduce la cadena de caracteres (presiona Enter o alcanza el límite de caracteres para finalizar):\n";

    char caracter;
    while (posicion < max_length && cin.get(caracter) && caracter != '\n'){
        cadena[posicion] = caracter;
        posicion++;

        if (posicion == max_length){
            break; // Salir del bucle si se alcanza la longitud máxima
        }
    }

    cadena[posicion] = '\0'; // Agregar carácter nulo de terminación al final

    cout << "\nCadena introducida: " << cadena << endl;

    return 0;
}