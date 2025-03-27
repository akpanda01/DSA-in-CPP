class Solution {
  public:
    Node* deleteMid(Node* head) {
        // Edge case: If the list is empty or has only one node
        if (!head || !head->next) 
            return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr; // To keep track of the previous node of slow
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Remove the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
