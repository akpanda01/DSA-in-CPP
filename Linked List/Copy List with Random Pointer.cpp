class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;  // Handle empty list

        // Step 1: Create interleaved copy nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers to copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the copied list from the original
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;
        
        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;
            
            copyCurr = copyCurr->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
