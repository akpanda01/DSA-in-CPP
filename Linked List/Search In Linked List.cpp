bool searchLinkedList(Node *head, int x)
{
    //Your code here
    Node* temp = head;
    while(temp){
        if(temp->data == x){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
