#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
};

void insertNodeAtBeginning(Node *&head, int val) {
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = head; 
    head = newNode; 
}

void insertNodeAtEnd(Node *&head, int val) {
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = NULL; // The new node will be the last, so its next is NULL

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newNode;
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Set the next pointer of the last node to the new node
    }
}

void printList(Node *head) {
    printf("\nList elements are: \n");
    while (head != NULL) {
        printf("%d ---> ", head->value);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;

    insertNodeAtBeginning(head, 3);
    insertNodeAtBeginning(head, 2);
    insertNodeAtBeginning(head, 1);
    insertNodeAtEnd(head, 4);
    insertNodeAtEnd(head, 5);

    printList(head);

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
