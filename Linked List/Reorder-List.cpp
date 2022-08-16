// https://leetcode.com/problems/reorder-list/

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
    // Reverse the Linked List
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *N;
        
        while(curr != NULL)
        {
            N = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = N;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        // Step 1: Find Middle of the Linked List
        // 1st List - till middle, 2nd list - after middle
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second linked list
        ListNode *second = reverse(slow->next);
        slow->next = NULL;
        
        ListNode *first = head; // 1st List
        
        // Step 3: Merge both the lists
        while(second != NULL)
        {
            // store the next of both the lists so that it is not lost
            ListNode *t1 = first->next;
            ListNode *t2 = second->next;
            
            // Now point the nodes
            first->next = second;
            second->next = t1;
            
            // move forward the first and second 
            first = t1;
            second = t2;
        }
        
    }
};
