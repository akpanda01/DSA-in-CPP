class Solution {
  public:
    struct Node* partition(struct Node* head, int x) {
        if (!head) return head; // Edge case: Empty list
        
        // Dummy nodes for three separate lists
        Node *lessHead = new Node(0), *equalHead = new Node(0), *greaterHead = new Node(0);
        Node *less = lessHead, *equal = equalHead, *greater = greaterHead;
        
        // Step 1: Traverse the original list and classify nodes
        Node *curr = head;
        while (curr) {
            if (curr->data < x) {
                less->next = curr;
                less = less->next;
            } else if (curr->data == x) {
                equal->next = curr;
                equal = equal->next;
            } else {
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }
        
        // Step 2: Merge the three lists
        greater->next = nullptr; // End greater list
        equal->next = greaterHead->next; // Connect equal list to greater list
        less->next = equalHead->next ? equalHead->next : greaterHead->next; // Connect less list to equal list or greater list

        // Step 3: Return the new head (excluding dummy nodes)
        return lessHead->next;
    }
};
