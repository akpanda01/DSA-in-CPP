class Solution {
  public:
    int count(struct Node* head, int key) {
        int count = 0;
        Node* temp = head;
        
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        
        return count;
    }
};
