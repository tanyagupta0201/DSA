// https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1?

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    Node *fast = head, *slow = head, *prev = NULL;
    
    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next; 
    }
    
    prev->next = slow->next;
    
    return head;
}
