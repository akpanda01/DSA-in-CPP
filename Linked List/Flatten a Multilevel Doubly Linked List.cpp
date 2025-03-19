class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL; // Base case

        flattenHelper(head);
        return head;
    }

private:
    Node* flattenHelper(Node* head) {
        Node* curr = head;
        Node* tail = head;

        while (curr) {
            Node* nextNode = curr->next;

            if (curr->child) {
                Node* childTail = flattenHelper(curr->child); // Flatten child list
                
                // Connect current node to child
                curr->next = curr->child;
                curr->child->prev = curr;

                // Connect child tail to nextNode
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                // Set child pointer to NULL
                curr->child = NULL;

                // Update tail to childTail
                tail = childTail;
            } else {
                tail = curr; // Update tail to current node
            }

            curr = nextNode; // Move to next node
        }
        return tail;
    }
};
