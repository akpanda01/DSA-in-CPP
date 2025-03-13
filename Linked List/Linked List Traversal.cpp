class Solution {
public:
    vector<int> LLTraversal(ListNode *head) {
        vector<int> result; // Vector to store the values
        
        ListNode* current = head; // Start from the head
        
        while (current != nullptr) { // Traverse until the end
            result.push_back(current->val); // Store the value
            current = current->next; // Move to the next node
        }
        
        return result; // Return the collected values
    }
};
