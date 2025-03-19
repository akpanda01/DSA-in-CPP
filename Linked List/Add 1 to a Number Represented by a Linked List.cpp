class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to add one to the linked list
    Node* addOne(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Add 1 to the first node
        Node* curr = head;
        int carry = 1;
        
        while (curr) {
            int sum = curr->data + carry;
            curr->data = sum % 10; // Update the current node
            carry = sum / 10; // Carry for the next node

            // If there is no carry left, we can stop
            if (carry == 0) break;
            
            // Move to the next node
            if (!curr->next && carry) {
                curr->next = new Node(carry); // Add a new node if needed
                carry = 0; // No more carry left
            }
            curr = curr->next;
        }

        // Step 3: Reverse the list back to original order
        return reverse(head);
    }
};
