class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head || !head->next) return head; // If list is empty or has only one node

        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        
        do {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;  
            curr = next;  
        } while (curr != head); 
        
        head->next = prev; // Adjust the last node's next pointer
        return prev; // New head of reversed list
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (!head) return nullptr; // Empty list

        Node *curr = head, *prev = nullptr;

        // If head itself holds the key and there are multiple nodes
        if (head->data == key) {
            if (head->next == head) return nullptr; // Single node case
            
            // Find the last node to update its next pointer
            Node* temp = head;
            while (temp->next != head) temp = temp->next;

            temp->next = head->next;
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        // Search for the node to be deleted
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;
            }
        } while (curr != head);

        return head; // Key not found, return unchanged list
    }
};
