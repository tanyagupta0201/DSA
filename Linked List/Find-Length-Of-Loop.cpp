// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head;
    Node *fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) // loop exists
        {
            // Fix the fast pointer and move slow pointer until they collide again and keep on increasing the length 
            int len = 1;
            slow = slow->next;
            
            while(slow != fast)
            {
                len++;
                slow = slow->next;
            }
            
            return len;
        }
    }
    
    // if there is no loop
    return 0;
}
