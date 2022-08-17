// https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1? 

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
         int c;
         Node *t;
         Node *curr = head;
         
         while(curr)
         {
             // Skip M nodes
             for(c = 1; c < M && curr != NULL; c++)
             {
                 curr = curr->next;
             }
             
             // If we have reached the end of the linked list
             if(curr == NULL)
                return;
             
             t = curr->next;
             
             // Delete N nodes
             for(c = 1; c <= N && t != NULL; c++)
             {
                 Node *temp = t;
                 t = t->next;
                 free(temp);
             }
             
             // Set current pointer for next iteration 
             curr->next = t;
             
             curr = t;
         }
    }
};
