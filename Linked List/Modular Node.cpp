class Solution {
  public:
    int modularNode(Node *head, int k) {
        if (head == NULL || k <= 0) return -1; // Handle invalid cases

        int index = 1, result = -1;
        Node* temp = head;

        while (temp) {
            if (index % k == 0) {
                result = temp->data; // Update result with modular node value
            }
            temp = temp->next;
            index++;
        }

        return result; // Return last modular node value or -1 if none found
    }
};
