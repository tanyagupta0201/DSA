// https://leetcode.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *dummy = new ListNode(-1); // stores the sorted list
        
        while(head != NULL)
        {
            ListNode *N = head->next; // stores the next of the present head
            ListNode *temp = dummy; // temp har baar 1st se start karenge as it is possible we need to insert in between
            
            // Traverse temp till you reach the position where you have to insert new value 
            while(temp->next && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            
            // Insert the node
            head->next = temp->next;
            temp->next = head;
            
            head = N; // new head
        }
        
        // Return the sorted List
        return dummy->next;
    }
};
