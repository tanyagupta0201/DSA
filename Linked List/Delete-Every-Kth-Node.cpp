// https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1?page=3&category[]=Linked%20List&sortBy=submissions

Node* deleteK(Node *head,int K)
{
    if(K == 1)
       return NULL;
       
    Node *curr = head;
    Node *prev = NULL;
    int pos = 0;
    
    while(curr != NULL)
    {
        pos++;
        
        if(pos == K)
        {
            prev->next = curr->next;
            pos = 0;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    return head;
}
