class Solution {
public:
    // Function to merge two sorted linked lists using bottom pointers
    Node* mergeLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeLists(a, b->bottom);
        }
        
        result->next = NULL; // Ensure `next` pointer is not used in the final flattened list
        return result;
    }

    // Function to flatten the multilevel linked list
    Node* flatten(Node* root) {
        if (!root || !root->next) return root; // Base case: empty or single list

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge current list with the flattened next list
        root = mergeLists(root, root->next);

        return root;
    }
};
