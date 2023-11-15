#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
    string abecedario = "abcdefghijklmnopqrstuvwxyz";
    string numeros = "0123456789";

    string texto;
    int numero;

    cout << "Introduce el texto: ";
    getline(cin, texto);

    cout << "Introduce un número entre 3 y 9: ";
    cin >> numero;

    if (numero < 3 || numero > 9){
        cout << "Número fuera de rango. Debe estar entre 3 y 9." << endl;
        return 1;
    }

    for (char &caracter : texto){
        if (isalpha(caracter)){
            bool es_mayuscula = isupper(caracter);
            caracter = tolower(caracter);

            if (caracter >= 'a' && caracter <= 'z'){
                int posicion = abecedario.find(caracter);
                char nuevo_caracter = abecedario[(posicion + numero) % 26];

                if (es_mayuscula){
                    nuevo_caracter = toupper(nuevo_caracter);
                }

                caracter = nuevo_caracter;
            }
        }
        else if (isdigit(caracter)){
            int posicion = numeros.find(caracter);
            caracter = numeros[(posicion + numero) % 10];
        }
    }

    cout << "Texto cifrado: " << texto << endl;

    for (char &caracter : texto){
        if (isalpha(caracter)){
            bool es_mayuscula = isupper(caracter);
            caracter = tolower(caracter);

            if (caracter >= 'a' && caracter <= 'z'){
                int posicion = abecedario.find(caracter);
                char nuevo_caracter = abecedario[(posicion - numero + 26) % 26];

                if (es_mayuscula){
                    nuevo_caracter = toupper(nuevo_caracter);
                }

                caracter = nuevo_caracter;
            }
        }
        else if (isdigit(caracter)){
            int posicion = numeros.find(caracter);
            caracter = numeros[(posicion - numero + 10) % 10];
        }
    }

    cout << "Texto descifrado: " << texto << endl;

    return 0;
}
