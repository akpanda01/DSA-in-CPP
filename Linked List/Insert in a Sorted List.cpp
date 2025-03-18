class Solution {
  public:
    // Function to insert a node in a sorted doubly linked list
    Node* sortedInsert(Node* head, int key) {
        Node* newNode = new Node(key);  // Create the new node

        // Case 1: If list is empty, new node becomes the head
        if (!head) return newNode;

        // Case 2: Insert at the beginning if key is smaller than head
        if (key < head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;  // New node becomes the head
        }

        Node* curr = head;
        
        // Traverse to find the correct position
        while (curr->next && curr->next->data < key) {
            curr = curr->next;
        }

        // Case 3: Insert at the end
        if (!curr->next) {
            curr->next = newNode;
            newNode->prev = curr;
        }
        // Case 4: Insert in the middle
        else {
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode;
            curr->next = newNode;
        }

        return head;  // Return the head of the modified list
    }
};
