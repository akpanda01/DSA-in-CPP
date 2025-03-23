class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if (*head_ref == nullptr) return;

        Node* current = *head_ref;

        while (current) {
            if (current->data == x) {
                Node* temp = current;
                
                // If deleting the head node
                if (current == *head_ref) {
                    *head_ref = current->next;
                    if (*head_ref) (*head_ref)->prev = nullptr;
                } 
                // If deleting a middle or tail node
                else {
                    if (current->prev) current->prev->next = current->next;
                    if (current->next) current->next->prev = current->prev;
                }

                // Move to the next node before deleting
                current = current->next;
                delete temp;
            } 
            else {
                current = current->next;
            }
        }
    }
};
