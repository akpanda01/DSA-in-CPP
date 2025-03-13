class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return; // Safety check
        
        node->val = node->next->val;   // Copy next node's value into the current node
        ListNode* temp = node->next;   // Store next node in a temporary pointer
        node->next = node->next->next; // Remove next node from the list
        delete temp;                   // Delete the next node
    }
};
