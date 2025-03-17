class Solution {
  public:
    bool isCircular(Node *head) {
        // Step 1: Handle the case where the list is empty
        if(head == NULL){
            return true;
        }
        // Step 2: Initialize a temporary pointer to traverse the list
        Node* temp = head->next;
        // Step 3: Traverse the list until we reach NULL (not circular) or back to head (circular)
        while(temp != NULL && temp != head){
            temp = temp->next;
        }
        // Step 4: If we reached NULL, the list is not circular
        if(temp == NULL){
            return false;
        }
        // Step 5: If we returned to head, the list is circular
        return true;
    }
};
