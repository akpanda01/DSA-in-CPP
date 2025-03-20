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

    // Insert at the head (beginning)
    void insertAtHead(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (!head) {  // If list is empty
            head = newNode;
            head->next = head;  // Circular reference
        } else {
            Node* temp = head;
            while (temp->next != head)  // Traverse to last node
                temp = temp->next;

            newNode->next = head;  // New node points to current head
            temp->next = newNode;   // Last node points to new node
            head = newNode;         // Update head to new node
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
    
    cl.insertAtHead(30);
    cl.insertAtHead(20);
    cl.insertAtHead(10);
    
    cl.display();  // Output: 10 -> 20 -> 30 -> (head)

    return 0;
}
