class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case: empty or single-node list
        
        // Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // Cut the list into two halves
        
        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Merge sorted halves
        return merge(left, right);
    }
    
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
