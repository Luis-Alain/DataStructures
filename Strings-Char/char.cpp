#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char caracteres[10];
    char resultado[30] = ""; // String para almacenar el resultado
    int vocal = 0;
    int consonante = 0;
    int seminconsonante = 0;

    cout << "Introduce 10 caracteres:\n";

    for (int i = 0; i < 10; i++){
        char caracter;
        cout << "Carácter " << i + 1 << ": ";
        cin >> caracter;

        // Convertir el carácter a minúscula
        caracter = tolower(caracter);

        // Concatenar el carácter al resultado
        strncat(resultado, &caracter, 1);

        // Determinar si es vocal, consonante o semiconsonante
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' ||
            caracter == 'o' || caracter == 'u'){
            vocal++; // Vocal
        }
        else if (caracter >= 'a' && caracter <= 'z' && caracter != 'y'){
            consonante++; // Consonante
        }
        else if (caracter == 'y'){
            seminconsonante++; // Semiconsonante (y)
        }
        else{
            cout << "Caracter inválido!" << endl; // Carácter no reconocido
        }
    }

    cout << "Resultado: " << resultado << endl;
    cout << "Vocales: " << vocal << endl;
    cout << "Consonantes: " << consonante << endl;
    cout << "Semiconsonantes: " << seminconsonante << endl;

    return 0;
}