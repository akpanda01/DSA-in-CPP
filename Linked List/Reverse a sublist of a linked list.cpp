class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        if (!head || a == b) return head; // Edge cases

        Node *dummy = new Node(0); // Dummy node to handle edge cases
        dummy->next = head;
        Node *prev = dummy;

        // Step 1: Move to the (a-1)th node
        for (int i = 1; i < a; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist from a to b
        Node *curr = prev->next, *next = nullptr, *reverseHead = prev->next;
        Node *prevRev = nullptr;
        for (int i = a; i <= b; i++) {
            next = curr->next;
            curr->next = prevRev;
            prevRev = curr;
            curr = next;
        }

        // Step 3: Connect reversed sublist back
        prev->next = prevRev;
        reverseHead->next = curr;

        return dummy->next; // Return the modified list
    }
};
