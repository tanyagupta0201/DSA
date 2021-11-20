// https://leetcode.com/problems/rotate-list/description/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        // Edge Cases
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        // Find the length of the linked list
        ListNode *curr = head;
        int len = 1;

        while (curr->next && ++len)
            curr = curr->next;

        // Now the last node points to starting node(head)
        curr->next = head;

        k = k % len;
        k = len - k;

        while (k--)
        {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = NULL;

        return head;
    }
};