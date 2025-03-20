#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() { head = NULL; }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (!head) {  // If the list is empty
            head = newNode;
            head->next = head;  // Circular reference
        } else {
            Node* temp = head;
            while (temp->next != head)  // Traverse to last node
                temp = temp->next;

            temp->next = newNode;  // Last node points to new node
            newNode->next = head;  // New node points to head
        }
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList cl;
    
    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);
    
    cl.display();  // Output: 10 -> 20 -> 30 -> (head)

    return 0;
}
