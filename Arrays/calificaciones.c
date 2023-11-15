/* En una universidad, el promedio de pruebas parciales de un curso para un estudiante, se calcula en base a cuatro pruebas parciales calificadas, de las cuales, al estudiante se le elimina la nota menor que sacó y se promedian las tres siguientes notas más altas.Realiza un algoritmo que determine la nota menor eliminada y calcule el promedio de las otras tres notas.Toma en cuenta que las calificaciones de las 4 pruebas parciales se deben introducir;
y que cada una debe estar en un rango de 0 a 100 puntos, si no es así, envía mensaje de error.*/

#include <stdio.h>
#define SIZE 4

int main(){
    int array[SIZE];
    int i, minIndex, minValue;
    float sum = 0.0;

    printf("Ingrese sus 4 calificaciones:\n");
    for (i = 0; i < SIZE; i++){
        int number;
        scanf("%d", &number);

        // Validación de rango
        if (number < 0 || number > 100){
            printf("Los datos ingresados son incorrectos. Vuelva a intentarlo.\n");
            i--; // Restar 1 al contador para repetir la entrada del número inválido
            continue;
        }
        array[i] = number;
    }

    minIndex = 0;
    minValue = array[0];

    // Encuentra el índice del número menor
    for (i = 1; i < SIZE; i++){
        if (array[i] < minValue){
            minIndex = i;
            minValue = array[i];
        }
    }

    // Crea un nuevo array para almacenar los números restantes
    int newArray[SIZE - 1];
    int newIndex = 0;

    // Copia los elementos restantes al nuevo array y suma los valores para el cálculo del promedio
    for (i = 0; i < SIZE; i++){
        if (i != minIndex){
            newArray[newIndex] = array[i];
            sum += newArray[newIndex];
            newIndex++;
        }
    }

    printf("Se tomaran en cuenta las calificaciones mas altas: \n");
    for (i = 0; i < SIZE - 1; i++){
        printf("%d", newArray[i]);
        printf("\n");
    }

    float promedio = sum / (SIZE - 1);

    printf("El promedio es: %.2f\n", promedio);
    printf("\n");

    return 0;
}