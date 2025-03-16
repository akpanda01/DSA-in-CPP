class Solution {
public:
    int getKthFromLast(Node *head, int k) {
        // Step 1: Count the total number of nodes
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: Check if k is valid
        if (k > count) return -1; // If k is greater than the length of the list, return -1

        // Step 3: Find the (count - k + 1)th node from the beginning
        temp = head;
        for (int i = 0; i < count - k; i++) {
            temp = temp->next;
        }

        return temp->data; // Return the data of the K-th node from the end
    }
};
