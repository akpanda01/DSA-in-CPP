class Solution {
  public:
    Node *inPlace(Node *root) {
        if (!root || !root->next) return root;

        // Step 1: Find the middle of the linked list
        Node *slow = root, *fast = root;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        Node *prev = nullptr, *curr = slow, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Step 3: Merge two halves
        Node *first = root, *second = prev;
        while (second->next) {
            Node *temp1 = first->next;
            Node *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }

        return root;
    }
};
