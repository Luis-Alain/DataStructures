#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int max = 5;
    int arr[max] = {4, 6, 2, 5, 3};

    cout << "Array original: " << endl;
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    cout << " " << endl; 

    for(int i = 0; i < max -1; i++){
        for(int j = 0; j < max -i -1; j++){
            if (arr[j] < arr[j + 1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }

    cout << "Array ordenado: " << endl;
    for (int i = 0; i < max; i++){
        cout << arr[i] << " ";
    }
    
}
