class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (!head) return NULL; // Empty list

        DLLNode* current = head;
        DLLNode* temp = NULL;

        while (current) {
            temp = current->prev;  // Store previous pointer
            current->prev = current->next;  // Swap next and prev
            current->next = temp;  
            
            head = current;  // Move head to the new front
            current = current->prev;  // Move to the next node (originally prev)
        }

        return head;
    }
};
