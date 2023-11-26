#include <iostream>
using namespace std;

// Creating a node
class Node {
public:
    int value;
    Node *next;
};

int main() {
    //crear los nodos
    Node *head;
    Node *one = NULL;
    Node *two = NULL;
    Node *three = NULL;

    // colocar los nodos en la lista
    one = new Node();
    two = new Node();
    three = new Node();

    // asignar valores a cada nodo
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Conectar los nodos
    one->next = two;
    two->next = three;
    three->next = NULL;
    head = one;

    // imprimir los valores de la lista
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }
}