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

    string textoCifrado = "";

    for (char c : texto){
        if (isalpha(c)){                                         
            char base = isupper(c) ? 'A' : 'a';                  
            char cifrado = abecedario[(c - base + numero) % 26]; 

            if (isupper(c)){
                cifrado = toupper(cifrado);
            }

            textoCifrado += cifrado;
        }
        else if (isdigit(c)){                                
            char cifrado = numeros[(c - '0' + numero) % 10]; 
            textoCifrado += cifrado;
        }
        else{ 
            textoCifrado += c;
        }
    }

    cout << "Texto cifrado: " << textoCifrado << endl;

    //Descifrar texto
    string textoDescifrado = "";

    for (char c : textoCifrado){
        if (isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            char descifrado = abecedario[(c - base - numero + 26) % 26];

            if (isupper(c)){
                descifrado = toupper(descifrado);
            }

            textoDescifrado += descifrado;
        }
        else if (isdigit(c)){
            char descifrado = numeros[(c - '0' - numero + 10) % 10];
            textoDescifrado += descifrado;
        }
        else{
            textoDescifrado += c;
        }
    }

    cout << "Texto descifrado: " << textoDescifrado << endl;

    return 0;
}