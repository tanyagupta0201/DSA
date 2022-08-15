// https://practice.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1?

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
      
        /*
        Node* left = head, *right = head;
        
        for(int i = 1; i < m; i++)
        {
            left = left->next;
        }
        cout << left->data << endl;
        for(int i = 1; i < n; i++)
        {
            right = right->next;
        }
        
        cout << right->data <<endl;
       
        */
        
       if(head == NULL)
       {
           return NULL;
       }
       
       Node *dummy = new Node(0);
       Node *prev = dummy;
       dummy->next = head;
       
       for(int i = 1; i < m; i++)
       {
           prev = prev->next;
       }
       
       Node *start = prev->next;
       Node *next = start->next;
       
       for(int i = 1; i <= n - m; i++)
       {
           start->next = next->next;
           next->next = prev->next;
           prev->next = next;
           next = start->next;
       }
       
       return dummy->next;
    }
};
