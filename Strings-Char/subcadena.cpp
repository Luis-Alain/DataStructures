//Desarrolla una aplicacion que permita al usuario sustraer una subcadena de 8 caracteres de la cadena osiginal, a partir del caracter 5. La cadena original tiene un maximo de 25 caracteres.

#include <iostream>
#include <string>
using namespace std;

int main(){
    string original;
    string input;

    cout << "Introduce una cadena de caracteres: ";
    cin >> input;

    size_t startIndex = 5;
    size_t charactersToRemove = 8;

    input.erase(startIndex, charactersToRemove);
    cout << "Cadena resultante: " << input << endl;

    return 0;
}