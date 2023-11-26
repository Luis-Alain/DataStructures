#include <iostream> 
using namespace std;

void sumarFilas(int matrix[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        int suma = 0;
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
            suma += matrix[i][j];
        }

        cout << "= " << suma << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    sumarFilas(matrix);
}