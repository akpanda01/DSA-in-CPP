class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* dummy = new Node(0); // Dummy node for the result list
        Node* tail = dummy;
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        
        while (ptr1 && ptr2) {
            if (ptr1->data == ptr2->data) {
                tail->next = new Node(ptr1->data);
                tail = tail->next;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } 
            else if (ptr1->data < ptr2->data) {
                ptr1 = ptr1->next;
            } 
            else {
                ptr2 = ptr2->next;
            }
        }
        
        return dummy->next; // The actual head of the new list
    }
};
