class Solution {
  public:
    // Function to remove duplicates from a sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (!head) return nullptr; // If the list is empty, return NULL

        Node* current = head;
        
        while (current && current->next) {
            if (current->data == current->next->data) {
                // Remove the duplicate node
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory of the removed node
            } else {
                // Move to the next distinct node
                current = current->next;
            }
        }

        return head; // Return the modified list
    }
};
