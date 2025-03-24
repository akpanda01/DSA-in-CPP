class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> result;

        // Find the last node (right pointer)
        Node *right = head;
        while (right->next != NULL)
        {
            right = right->next;
        }

        // Left pointer starts from head
        Node *left = head;

        // Two-pointer approach
        while (left != right && left->prev != right)
        {
            int sum = left->data + right->data;

            if (sum == target)
            {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return result;
    }
};
