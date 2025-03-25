class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* temp = head;
        int count = 0;
        
        // Check if there are at least k nodes in the list
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // If less than k nodes, return head as it is
            temp = temp->next;
        }

        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        int i = 0;
        while (curr && i < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            i++;
        }

        // Recursively reverse the rest of the list
        if (nextNode) {
            head->next = reverseKGroup(nextNode, k);
        }

        return prev; // New head after reversal
    }
};
