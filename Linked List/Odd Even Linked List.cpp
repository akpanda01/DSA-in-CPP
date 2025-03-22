class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Edge case: empty list or single node
        
        ListNode* odd = head;           // Points to the first odd-indexed node
        ListNode* even = head->next;    // Points to the first even-indexed node
        ListNode* evenHead = even;      // Stores the head of even list
        
        while (even && even->next) {
            odd->next = even->next;    // Connect odd node to the next odd node
            odd = odd->next;           // Move odd pointer forward
            
            even->next = odd->next;    // Connect even node to the next even node
            even = even->next;         // Move even pointer forward
        }
        
        odd->next = evenHead; // Connect odd list to the even list
        return head;
    }
};
