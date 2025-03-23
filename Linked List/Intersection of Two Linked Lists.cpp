class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            // Move to the next node, or switch to the head of the other list
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA; // Either intersection node or nullptr
    }
};
