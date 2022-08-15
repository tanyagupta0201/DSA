// https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1?

// TC = O(N)
// SC = O(1)

struct Node* partition(struct Node* head, int x) 
{
    Node *smaller = new Node(-1);
    Node *equal = new Node(-1);
    Node *greater = new Node(-1);
    
    Node *s = smaller;
    Node *e = equal;
    Node *g = greater;
    
    while(head != NULL)
    {
        if(head->data < x)
        {
            s->next = head;
            s = s->next;
            head = head->next;
        }
        else if(head->data == x)
        {
            e->next = head;
            e = e->next;
            head = head->next;
        }
        else
        {
            g->next = head;
            g = g->next;
            head = head->next;
        }
    }
    
    g->next = NULL;
    e->next = greater->next;
    s->next = equal->next;
    
    return smaller->next; 
    
}
