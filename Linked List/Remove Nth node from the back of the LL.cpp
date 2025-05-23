class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head); // Dummy node to handle edge cases
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node
        second->next = second->next->next;
        
        return dummy.next;
    }
};
