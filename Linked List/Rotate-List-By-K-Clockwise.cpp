// https://leetcode.com/problems/rotate-list/description/

// Brute Force

// SC = O(1)
// Reason: No extra data structures is used for computations

// TC = O(n * k)
// Reason: For k times, we are iterating through the entire list to get the last element and move it to first.


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode* curr = head;
        int len = 0;
        
        while(curr != NULL)
        {
            curr = curr->next;
            len += 1;
        }
        
        k = k % len;
        
        
        for(int i = 1; i <= k; i++)
        {
            ListNode* temp = head;

            // reach 2nd last node
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            ListNode* end = temp->next;
            
            end->next = head;
            head = end;
            temp->next = NULL; 
        }
        return head;
    }
};



// Optimised

/*
    Time Complexity: O(length of list) + O(length of list – (length of list%k))
    Reason: O(length of the list) for calculating the length of the list. O(length of the list – (length of list%k)) for breaking link.

    Space Complexity: O(1)
    Reason: No extra data structure is used for computation.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode* t = head;
        int len = 1;
        
        while(t->next != NULL)
        {
            t = t->next;
            len += 1;
        } 
        //cout << "Length: " <<len << endl;
        
        // After this while loop is over, t is at the last node of the singly link list
        // Now make it a circular link list
        t->next = head;    
                
        k = k % len;
        int NewEnd = len - k;
        
        // Now I have to bring t at the new end node 
        while(NewEnd--)
        {
            t = t->next;
        }
        
        // this would be my new head
        head = t->next;
        
        t->next = NULL;
        
        return head;
    }
};
