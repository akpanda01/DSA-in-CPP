#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

// Function to delete the head node
Node* deleteHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to delete the tail node
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

// Function to delete the Kth node
Node* deleteKthNode(Node* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) return deleteHead(head); // If deleting head

    Node* temp = head;
    for (int i = 1; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return head; // If k is out of bounds

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

// Function to delete a node with a specific value X
Node* deleteByValue(Node* head, int X) {
    if (head == NULL) return NULL;
    if (head->data == X) return deleteHead(head); // If head contains X

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != X) {
        temp = temp->next;
    }

    if (temp->next == NULL) return head; // X not found

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original List: ";
    printList(head);

    // Delete head
    head = deleteHead(head);
    cout << "After Deleting Head: ";
    printList(head);

    // Delete tail
    head = deleteTail(head);
    cout << "After Deleting Tail: ";
    printList(head);

    // Delete Kth node (e.g., 2nd node)
    head = deleteKthNode(head, 2);
    cout << "After Deleting 2nd Node: ";
    printList(head);

    // Delete node by value (e.g., delete node with value 40)
    head = deleteByValue(head, 40);
    cout << "After Deleting Node with Value 40: ";
    printList(head);

    return 0;
}
