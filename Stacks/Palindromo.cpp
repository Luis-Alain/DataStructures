#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int main(){
    char caracter;
    char original[20] = "";
    char invertida[20] = "";
    int longitud = 0;
    bool esPalindromo = true;

    cout << "Ingrese la palabra letra por letra.";
    for (int i = 0; i < 20; i++){
        caracter = getch();
        if (caracter == 13){
            break;
        }
        original[i] = caracter;
        cout << "\nLetra N-" << i + 1 << ": " << caracter;
        longitud++;
    }

    longitud -= 1;

    for (int i = 0; i < longitud; i++){
        invertida[i] = original[longitud - i];
        if (invertida[i] != original[i]){
            esPalindromo = false;
            break;
        }
    }

    if (esPalindromo == false){
        cout << "\nSu palabra no es palindromo.";
    }
    else{
        cout << "\nSu palabra es palindromo.";
    }

    return 0;
}