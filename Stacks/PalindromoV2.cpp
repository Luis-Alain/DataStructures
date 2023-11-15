#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    const int MAX = 20; 
    char caracter;
    int longitud = 0;
    char arregloOriginal[longitud];
    char arregloInvertido[longitud];

    cout << "Introduce una palabra caracter por caracter: ";
    for (int i = 0; i < MAX; i++){
        caracter = getch();
        if (caracter == 13){
            break;
        }
        arregloOriginal[i] = caracter;
        cout << "\nLetra N-" << i + 1 << ": " << caracter;
        longitud++;
    }

    for (int i = 0; i < longitud; i++){
        arregloInvertido[i] = arregloOriginal[longitud - i - 1];
    }

    bool esPalindromo = true;
    for (int i = 0; i < longitud; i++){
        if (arregloInvertido[i] != arregloOriginal[i]){
            esPalindromo = false;
            break;
        }
    }

    if (esPalindromo){
        cout << "\nLa palabra es un palíndromo." << endl;
    }
    else{
        cout << "\nLa palabra no es un palíndromo." << endl;
    }

    return 0;
}
