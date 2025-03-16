class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        if (!del_node || !del_node->next) return; // Edge case (should never occur)
        
        // Copy the value of the next node into the current node
        del_node->data = del_node->next->data;
        
        // Save the next node to delete it
        Node* temp = del_node->next;
        
        // Change pointer to skip the next node
        del_node->next = del_node->next->next;
        
        // Delete the copied node from memory
        delete temp;
    }
};
