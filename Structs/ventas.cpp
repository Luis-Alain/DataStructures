#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto{
    string nombre;
    int precio;
    int cantidadStock;
    string descripcion;
}producto;

int main(){
    vector <Producto> listaProductos;
    bool agregarProducto = true;

    do
    {
        if (listaProductos.size() < 100){
            cout << "Introduce el nombre del producto: ";
            getline(cin, producto.nombre);
            cout << "Introduce el precio del producto: ";
            cin >> producto.precio;
            cout << "Introduce la cantidad en stock del producto: ";
            cin >> producto.cantidadStock;
            cout << "Introduce una descripcion para el producto: ";
            cin.ignore();
            getline(cin, producto.descripcion);

            listaProductos.push_back(producto);

            cout << "¿Deseas agregar otro producto? (1 para sí, 0 para no): ";
            cin >> agregarProducto;
        }
        else{
            cout << "Se ha alcanzado el límite de productos (100)." << endl;
            agregarProducto = false;
        }

    } while (agregarProducto);
    
    //Mostrar lista de productos
    cout << "Lista de productos" << endl;
    for (int i = 0; i < listaProductos.size(); i++){
        cout << "Nombre del producto: " << producto.nombre << endl;
        cout << "Precio del producto: " << producto.precio << endl;
        cout << "Cantidad en stock del producto: " << producto.cantidadStock << endl;
        cout << "Descripcion del producto: " << producto.descripcion << endl;
    }

    // Comprar productos
    int opcion;
    do
    {
        cout << "¿Desea comprar un producto? (1 para sí, 0 para no): ";
        cin >> opcion;

        if (opcion == 1){
            for (int i = 0; i < listaProductos.size(); i++){
                cout << i << "." << " Nombre del producto: " << producto.nombre << " $" << producto.precio << endl;
            }
            cout << "Ingrese el número de producto que desea comprar: ";
            int numProducto;
            cin >> numProducto;

            if (numProducto >= 0 && numProducto < listaProductos.size()){
                cout << "Producto seleccionado: " << listaProductos[numProducto].nombre << endl;
                cout << "Cantidad en stock: " << listaProductos[numProducto].cantidadStock << endl;

                cout << "Ingrese la cantidad que desea comprar: ";
                int cantidadCompra;
                cin >> cantidadCompra;

                if (cantidadCompra <= listaProductos[numProducto].cantidadStock){
                    listaProductos[numProducto].cantidadStock -= cantidadCompra;
                    cout << "Compra realizada con éxito. Stock actualizado." << endl;
                    cout << "Cantidad de " << listaProductos[numProducto].nombre << " restantes: " << listaProductos[numProducto].cantidadStock << endl;
                }
                else{
                    cout << "No hay suficiente stock disponible para la compra." << endl;
                }
            }
            else{
                cout << "Número de producto no válido. Intente nuevamente." << endl;
            }
        }

    } while (opcion == 1);

    return 0;
}