#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int value) {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        if (arr.empty()) return NULL;

        Node* head = new Node(arr[0]);  // Create the head node
        Node* tail = head;  // Pointer to track the last node

        for (int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;  // Move the tail pointer to the new node
        }

        return head;
    }
};

// Function to print the doubly linked list
void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    
    Node* head = sol.constructDLL(arr);
    
    cout << "Doubly Linked List: ";
    printDLL(head);

    return 0;
}
