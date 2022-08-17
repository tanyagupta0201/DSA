// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* curr = head;
        
        if(curr == NULL)
            return NULL;
        
        while(curr->next != NULL)
        {
            if(curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                // curr is only incremented when the next element is not same as the curr
                curr = curr->next;
            }
        }
        return head;
    }
};
