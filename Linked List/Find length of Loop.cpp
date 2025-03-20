class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if (!head) return 0;

        Node *slow = head, *fast = head;

        // Detect loop using Floyd’s cycle-finding algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Loop detected
                int count = 1;
                Node *temp = slow->next;

                while (temp != slow) { // Count loop nodes
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }
        return 0; // No loop
    }
};
