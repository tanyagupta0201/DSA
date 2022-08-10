// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?


// Solution 1
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        Node *zero = new Node(-1);
        Node *one = new Node(-1);
        Node *two = new Node(-1);
        
        Node *z = zero;
        Node *o = one;
        Node *t = two;
        
        while(head != NULL)
        {
            
            if(head->data == 0)
            {
                z->next = head;
                z = z->next;
            }
            else if(head->data == 1)
            {
                o->next = head;
                o = o->next;
            }
            else
            {
                t->next = head;
                t = t->next;
            }
            
            head = head->next;
        }
        
        t->next = NULL;
        o->next = two->next;
        z->next = one->next;
        
        return zero->next;
    }
};



// Solution 2
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        int zero = 0, one = 0, two = 0;
        
        Node *curr = head;
        
        while(curr != NULL)
        {
            if(curr->data == 0)
            {
                zero++;
            }
            else if(curr->data == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
            
            curr = curr->next;
        }
        
        curr = head;
        
        while(zero--)
        {
            curr->data = 0;
            curr = curr->next;
        }
        
        while(one--)
        {
            curr->data = 1;
            curr = curr->next;
        }
        
        while(two--)
        {
            curr->data = 2;
            curr = curr->next;
        }
        
        return head;
    }
};
