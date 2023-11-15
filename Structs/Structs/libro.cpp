#include <iostream>
#include <vector>
using namespace std;

struct Libro{
    string autor;
    string titulo;
    int añoDePublicacion;
};

void imprimirLibro(Libro print) {
    cout << "Titulo: " << print.titulo << endl;
    cout << "Autor: " << print.autor << endl;
    cout << "Año de publicacion: " << print.añoDePublicacion << endl;
}

int main(){
    vector<Libro> libros;
    int cantidad;
    cout << "Introduce la cantidad de libros que deseas introducir: ";
    cin >> cantidad;
    cin.ignore();

    for(int i = 0; i < cantidad; i++){
        Libro libro;
        cout << "Introduce los datos del libro " << i + 1 << endl;
        cout << "Introduce el nombre del libro: ";
        getline(cin, libro.titulo);
        cout << "Introduce el autor del libro: ";
        getline(cin, libro.autor);
        cout << "Introduce el año de publicación del libro: ";
        cin >> libro.añoDePublicacion;
        cin.ignore();

        libros.push_back(libro);
    }

    char answer;
    cout << "Desea ver la informacion de los libros? (Y: cierto, N: falso)" << endl;
    cin >> answer;
    if(answer == 'Y' || answer == 'y'){
        cout << "Información de todos los libros:" << endl;
        for (const Libro &libro : libros){
            imprimirLibro(libro);
            cout << endl;
        }
    }else{
        cout << "Chúpalo entonces" << endl;
    }

    return 0;
}
