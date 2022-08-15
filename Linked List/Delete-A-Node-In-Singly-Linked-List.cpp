// https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

Node* deleteNode(Node *head, int x)
{
    //Your code here
    Node* prev = head;
    
    // if we have to delete first node ie. head
    if(x == 1)
    {
        return head->next;
    }
    
    for(int i = 1; i < x - 1; i++)
    {
        prev = prev->next; 
    }
    //cout << prev->data << endl;
    
    prev->next = prev->next->next;
    return head;
}
