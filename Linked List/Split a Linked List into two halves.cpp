class Solution {
  public:
    // Function to find the middle node of the circular linked list
    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to split the circular linked list into two halves
    pair<Node*, Node*> splitList(Node* head) {
        if (!head || !head->next) return {head, nullptr}; // Edge case: empty or single-node list

        Node* mid = findMid(head);
        Node* newHead = mid->next;
        mid->next = head; // Making the first half circular
        
        // Finding the last node of the second half
        Node* tail = newHead;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newHead; // Making the second half circular
        
        return {head, newHead};
    }
};
