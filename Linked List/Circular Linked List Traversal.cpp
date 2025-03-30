void printList(struct Node *head) {
    if (head == nullptr) return; // Empty list
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again
    
}
