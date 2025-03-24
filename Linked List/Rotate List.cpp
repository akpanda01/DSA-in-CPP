class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the linked list
        int length = 1;  
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Optimize k
        k = k % length;
        if (k == 0) return head; // No rotation needed

        // Step 3: Find the new tail (at position length - k - 1)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // Step 4: Update the new head and break the cycle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head; // Connect old tail to old head

        return newHead;
    }
};
