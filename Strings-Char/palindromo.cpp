#include <iostream>
#include <cstring>
using namespace std;

int main(){
    const int MAX = 10;
    char palabra[MAX + 1]; // +1 Para el carácter nulo

    cout << "Introduce una palabra letra por letra (hasta " << MAX << " caracteres): ";

    for (int i = 0; i < MAX; i++) {
        char result = getchar();

        if (result == '\n'){
            break;
        }

        palabra[i] = result;
    }

    palabra[strlen(palabra)] = '\0';

    cout << "Palabra ingresada: " << palabra << endl;

    return 0;
}