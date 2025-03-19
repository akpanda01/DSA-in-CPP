class Solution {
  public:
    // Function to insert at head
    Node* insertAtHead(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) return newNode; // If list is empty, new node becomes head
        
        newNode->next = head;
        head->prev = newNode;
        return newNode; // New node is the new head
    }

    // Function to insert at tail
    Node* insertAtTail(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) return newNode; // If list is empty, new node becomes head
        
        Node* curr = head;
        while (curr->next) {
            curr = curr->next; // Move to last node
        }

        curr->next = newNode;
        newNode->prev = curr;
        return head; // Head remains the same
    }

    // Function to insert at a given position (1-based index)
    Node* insertAtPosition(Node* head, int value, int x) {
        Node* newNode = new Node(value);
        if (x == 1) return insertAtHead(head, value); // Insert at head

        Node* curr = head;
        for (int i = 1; curr && i < x - 1; i++) {
            curr = curr->next; // Move to (x-1)th node
        }

        if (!curr) return head; // Position out of bounds

        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next) curr->next->prev = newNode;
        curr->next = newNode;

        return head;
    }
};
