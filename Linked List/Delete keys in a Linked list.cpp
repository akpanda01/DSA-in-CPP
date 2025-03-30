Node* deleteAllOccurances(Node *head, int x) {
    // Step 1: Remove leading occurrences of x
    while (head && head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    // Step 2: Remove occurrences in the rest of the list
    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (curr->data == x) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}
