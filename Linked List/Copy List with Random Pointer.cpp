class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;  // Handle empty list

        unordered_map<Node*, Node*> nodeMap;

        // Step 1: Create a copy of each node and store it in the map
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];    // Set the next pointer
            nodeMap[curr]->random = nodeMap[curr->random]; // Set the random pointer
            curr = curr->next;
        }

        return nodeMap[head]; // Return the copied list's head
    }
};
