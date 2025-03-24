class Solution
{
public:
    Node* removeDuplicates(Node* head)
    {
        if (!head) return head; // If the list is empty, return NULL

        Node* current = head;

        while (current->next != NULL)
        {
            if (current->data == current->next->data)
            {
                // Duplicate found, remove next node
                Node* duplicate = current->next;
                current->next = duplicate->next;
                
                if (duplicate->next != NULL)
                {
                    duplicate->next->prev = current;
                }

                delete duplicate; // Free memory
            }
            else
            {
                current = current->next; // Move forward
            }
        }
        return head;
    }
};
