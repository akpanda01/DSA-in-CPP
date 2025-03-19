class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head; // Edge case: empty or single node list

        int count0 = 0, count1 = 0, count2 = 0;
        Node* temp = head;

        // Step 1: Count 0s, 1s, and 2s
        while (temp) {
            if (temp->data == 0) count0++;
            else if (temp->data == 1) count1++;
            else count2++;
            temp = temp->next;
        }

        // Step 2: Modify the list in-place
        temp = head;
        while (count0--) temp->data = 0, temp = temp->next;
        while (count1--) temp->data = 1, temp = temp->next;
        while (count2--) temp->data = 2, temp = temp->next;

        return head;
    }
};
