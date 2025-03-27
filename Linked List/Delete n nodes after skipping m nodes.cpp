class Solution {
  public:
    Node* linkdelete(Node* head, int m, int n) {
        Node* curr = head;
        
        while (curr) {
            // Skip m nodes
            for (int i = 1; i < m && curr; i++) {
                curr = curr->next;
            }
            
            // If we reach the end, stop
            if (!curr) break;
            
            // Start deleting n nodes
            Node* temp = curr->next;
            for (int i = 0; i < n && temp; i++) {
                Node* nextNode = temp->next;
                delete temp; // Free memory
                temp = nextNode;
            }
            
            // Connect the remaining list
            curr->next = temp;
            
            // Move to the next segment
            curr = temp;
        }
        
        return head;
    }
};
