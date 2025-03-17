#include <unordered_set>

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if (!head) return nullptr; // If the list is empty, return NULL
        
        std::unordered_set<int> seen; // Hash set to store unique values
        Node* current = head;
        Node* prev = nullptr; // Previous node tracker
        
        while (current) {
            if (seen.find(current->data) != seen.end()) {
                // Duplicate found: Remove current node
                prev->next = current->next;
                delete current; // Free memory
            } else {
                // New unique value: Add to set
                seen.insert(current->data);
                prev = current; // Move prev forward
            }
            current = prev->next; // Move current forward
        }
        
        return head; // Return the modified list
    }
};
