class Solution {
  public:
    // Function to check if two linked lists are identical
    bool areIdentical(Node *head1, Node *head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;

        // Traverse both lists simultaneously
        while (temp1 && temp2) {
            if (temp1->data != temp2->data) {
                return false; // If data mismatch, return false
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // If both lists reach NULL simultaneously, they are identical
        return (temp1 == NULL && temp2 == NULL);
    }
};
