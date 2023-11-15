#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string frase;

    cout << "Ingrese una frase con palabras en minúscula: ";
    getline(cin, frase);

    size_t i = 0;
    while (i < frase.length()){
        while (i < frase.length() && isspace(frase[i])){
            i++;
        }

        if (i < frase.length()){
            frase[i] = toupper(frase[i]);

            while (i < frase.length() && !isspace(frase[i])){
                i++;
            }
        }
    }

    cout << "Frase con las primeras letras en mayúscula: " << frase << endl;

    return 0;
}