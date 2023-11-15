#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main(){
    string abecedario = "abcdefghijklmnopqrstuvwxyz";
    string numeros = "0123456789";

    char texto[1000];
    int numero;

    cout << "Introduce el texto: ";
    cin.getline(texto, sizeof(texto));

    cout << "Introduce un número entre 3 y 9: ";
    cin >> numero;

    if (numero < 3 || numero > 9){
        cout << "Número fuera de rango. Debe estar entre 3 y 9." << endl;
        return 1;
    }

    int longitud = strlen(texto);

    for (int i = 0; i < longitud; i++){
        char caracter = texto[i];

        if (isalpha(caracter)){
            bool es_mayuscula = isupper(caracter);

            if (es_mayuscula){
                caracter = tolower(caracter);
            }

            if (caracter >= 'a' && caracter <= 'z'){
                int posicion = abecedario.find(caracter);
                char nuevo_caracter = abecedario[(posicion + numero) % 26];

                if (es_mayuscula){
                    nuevo_caracter = toupper(nuevo_caracter);
                }

                texto[i] = nuevo_caracter;
            }
        }
        else if (isdigit(caracter)){
            int posicion = numeros.find(caracter);
            char nuevo_caracter = numeros[(posicion + numero) % 10];
            texto[i] = nuevo_caracter;
        }
    }

    cout << "Texto cifrado: " << texto << endl;

    for (int i = 0; i < longitud; i++){
        char caracter = texto[i];

        if (isalpha(caracter)){
            bool es_mayuscula = isupper(caracter);

            if (es_mayuscula){
                caracter = tolower(caracter);
            }

            if (caracter >= 'a' && caracter <= 'z'){
                int posicion = abecedario.find(caracter);
                char nuevo_caracter = abecedario[(posicion - numero + 26) % 26];

                if (es_mayuscula){
                    nuevo_caracter = toupper(nuevo_caracter);
                }

                texto[i] = nuevo_caracter;
            }
        }
        else if (isdigit(caracter)){
            int posicion = numeros.find(caracter);
            char nuevo_caracter = numeros[(posicion - numero + 10) % 10];
            texto[i] = nuevo_caracter;
        }
    }

    cout << "Texto descifrado: " << texto << endl;

    return 0;
}