class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return nullptr; // Handle empty array case
        
        Node* head = new Node(arr[0]); // Create head node
        Node* current = head;
        
        for (int i = 1; i < arr.size(); i++) {
            current->next = new Node(arr[i]); // Correct index usage
            current = current->next; // Move to the next node
        }
        
        return head;
    }
};
