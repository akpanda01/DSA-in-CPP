class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode = new Node(x); // Create a new node
        
        if (head == nullptr) { // If list is empty, newNode becomes head
            return newNode;
        }
        
        Node* current = head;
        while (current->next != nullptr) { // Traverse to the last node
            current = current->next;
        }
        
        current->next = newNode; // Link last node to new node
        return head; // Return the (unchanged) head of the linked list
    }
};
