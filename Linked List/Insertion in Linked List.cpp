#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

// Function to insert at the head
Node* insertAtHead(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
}

// Function to insert at the tail
Node* insertAtTail(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert at Kth position (1-based index)
Node* insertAtK(Node* head, int x, int k) {
    if (k == 1) return insertAtHead(head, x); // Insert at head

    Node* newNode = new Node(x);
    Node* temp = head;
    for (int i = 1; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to insert after a specific value
Node* insertAfterValue(Node* head, int x, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << value << " not found!" << endl;
        return head;
    }

    Node* newNode = new Node(x);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver Code
int main() {
    Node* head = NULL;

    // Insert at head
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    cout << "After Inserting at Head: ";
    printList(head);

    // Insert at tail
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);
    cout << "After Inserting at Tail: ";
    printList(head);

    // Insert at Kth position (e.g., 2nd position)
    head = insertAtK(head, 25, 2);
    cout << "After Inserting 25 at Position 2: ";
    printList(head);

    // Insert after a specific value (e.g., after 30)
    head = insertAfterValue(head, 35, 30);
    cout << "After Inserting 35 After Value 30: ";
    printList(head);

    return 0;
}
