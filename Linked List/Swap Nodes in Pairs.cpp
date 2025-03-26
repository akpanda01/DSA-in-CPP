class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head; // Base case: if the list is empty or has only one node
        
        ListNode* newHead = head->next; // The second node will become the new head
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next; // Store the next pair's first node
            ListNode* second = curr->next; // Second node of the current pair
            
            // Swapping
            second->next = curr;
            curr->next = nextPair;
            
            // Updating the previous node to point to the new head of this swapped pair
            if (prev) {
                prev->next = second;
            }
            
            // Move to the next pair
            prev = curr;
            curr = nextPair;
        }
        
        return newHead; // Return the new head of the modified list
    }
};
