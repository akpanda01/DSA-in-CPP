class Solution {
  public:
    Node* swapKthNode(Node* head, int k) {
        if (!head) return nullptr;  // Edge case: empty list

        Node* temp = head;
        int length = 0;

        // Step 1: Calculate the length of the linked list
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: Check if k is valid
        if (k > length) return head;

        // If the kth node from start and end are the same, no need to swap
        if (2 * k - 1 == length) return head;

        // Step 3: Find the kth node from start and end
        Node *firstK = head, *prev1 = nullptr;
        for (int i = 1; i < k; i++) {
            prev1 = firstK;
            firstK = firstK->next;
        }

        Node *secondK = head, *prev2 = nullptr;
        for (int i = 1; i < length - k + 1; i++) {
            prev2 = secondK;
            secondK = secondK->next;
        }

        // Step 4: Swap the nodes
        if (prev1) prev1->next = secondK;
        if (prev2) prev2->next = firstK;

        // Swap their next pointers
        Node* tempNext = firstK->next;
        firstK->next = secondK->next;
        secondK->next = tempNext;

        // If k is 1, update the head
        if (k == 1) head = secondK;
        if (k == length) head = firstK;

        return head;
    }
};
