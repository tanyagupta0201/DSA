// https://practice.geeksforgeeks.org/problems/identical-linked-lists/1?page=2&category[]=Linked%20List&sortBy=submissions

// Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    int l1 = 0, l2 = 0;
    Node *curr1 = head1, *curr2 = head2;
    
    while(curr1)
    {
        l1++;
        curr1 = curr1->next;
    }
    
    while(curr2)
    {
        l2++;
        curr2 = curr2->next;
    }
    
    if(l1 != l2)
       return false;
       
    while(head1 && head2)
    {
        if(head1->data != head2->data)
           return false;
           
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return true;
}
