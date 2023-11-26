#include <iostream>
#include <string>
using namespace std;

const int NUM_MATERIAS = 3;
const int NUM_ESTUDIANTES = 10;

struct Estudiante{
    string nombre;
    string cedula;
    int calificaciones[NUM_MATERIAS];
    double promedio; 
    char notaFinal;
}estudiante;

int main(){
    string materias[NUM_MATERIAS] = {"Matemáticas", "Ciencias", "Historia"};
    Estudiante estudiantes[NUM_ESTUDIANTES];
    int numEstudiantes = 0;

    bool agregarEstudiante = true;

    do{
        if (numEstudiantes < NUM_ESTUDIANTES){
            cout << "Ingresa el nombre del estudiante: ";
            getline(cin, estudiante.nombre);
            cout << "Ingresa la cédula de " << estudiante.nombre << ": ";
            getline(cin, estudiante.cedula);

            for (int i = 0; i < NUM_MATERIAS; ++i){
                cout << "Ingrese la calificación de " << materias[i] << ": ";
                cin >> estudiante.calificaciones[i];
                cin.ignore();
            }

            double sumaCalificaciones;
            for (int i = 0; i < NUM_MATERIAS; i++){
                sumaCalificaciones += estudiante.calificaciones[i];
            }

            estudiante.promedio = sumaCalificaciones / NUM_MATERIAS;

            if (estudiante.promedio >= 91.0){
                estudiante.notaFinal = 'A';
            }
            else if (estudiante.promedio < 91.0){
                estudiante.notaFinal = 'B';
            }
            else if (estudiante.promedio < 81.0){
                estudiante.notaFinal = 'C';
            }
            else if (estudiante.promedio < 71.0){
                estudiante.notaFinal = 'D';
            }
            else if (estudiante.promedio < 61.0){
                estudiante.notaFinal = 'F';
            }

            estudiantes[numEstudiantes] = estudiante;
            numEstudiantes++;
        }else{
            cout << "Se ha alcanzado el número máximo de estudiantes (" << NUM_ESTUDIANTES << ")." << endl;
            agregarEstudiante = false;
        }

        cout << "¿Desea agregar otro estudiante? (1 para sí, 0 para no): ";
        cin >> agregarEstudiante;
        cin.ignore();

    } while (agregarEstudiante);

    for (int i = 0; i < numEstudiantes; i++){
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Cédula: " << estudiantes[i].cedula << endl;
        cout << "Calificaciones: " << endl;
        for (int j = 0; j < NUM_MATERIAS; j++){
            cout << materias[j] << ": " << estudiante.calificaciones[j] << "%" << endl; 
        }
        cout << "Promedio: " << estudiantes[i].promedio << "%" << endl;
        cout << "Nota final: " << estudiantes[i].notaFinal << endl;
    }
}