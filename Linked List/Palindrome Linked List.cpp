class Solution {
public:
    Node* reverseLL(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true; // Empty list or single node is always palindrome
        
        // Step 1: Find the middle of the linked list (slow & fast pointers)
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        slow = reverseLL(slow);
        Node* secondHalf = slow; // Store reversed half for restoration

        // Step 3: Compare both halves
        Node* firstHalf = head;
        while (slow) { // Only need to check the reversed half
            if (firstHalf->data != slow->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            slow = slow->next;
        }

        // Optional Step 4: Restore the original list (if needed)
        reverseLL(secondHalf);

        return true; // It's a palindrome
    }
};
