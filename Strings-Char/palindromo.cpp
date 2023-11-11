#include <iostream>
#include <cstring>
using namespace std;

bool esPalindromo(char palabra[]){
    size_t longitud = strlen(palabra);

    // Invertir la cadena
    for (size_t i = 0, j = longitud - 1; i < j; ++i, --j){
        char temp = palabra[i];
        palabra[i] = palabra[j];
        palabra[j] = temp;
    }

    // Comparar la cadena original con la cadena invertida
    return (strcmp(palabra, palabra) == 0);
}

int main(){
    const int tamanoMaximo = 10;
    char palabra[tamanoMaximo + 1];

    cout << "Introduce una palabra letra por letra (hasta " << tamanoMaximo << " caracteres): ";

    // Leer caracteres uno por uno
    for (int i = 0; i < tamanoMaximo; i++){
        char caracter = getchar();
        if (caracter == '\n'){
            // Salir del bucle si se presiona Enter
            break;
        }
        palabra[i] = caracter;
    }

    // Agregar el carácter nulo al final de la cadena
    palabra[strlen(palabra)] = '\0';

    // Verificar si es un palíndromo
    if (esPalindromo(palabra)){
        cout << palabra << " es palindromo." << endl;
    }
    else{
        cout << palabra << " no es palindromo." << endl;
    }

    return 0;
}