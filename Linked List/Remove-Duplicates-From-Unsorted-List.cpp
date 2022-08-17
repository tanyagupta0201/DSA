// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

/*
METHOD 1 (Using two loops) - TC = O(N ^ 2)
  
This is the simple way where two loops are used.
Outer loop is used to pick the elements one by one and the inner loop compares the picked element with the rest of the elements. 

*/

void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    // Pick elements one by one
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        // Compare the picked element with rest of the elements
        while (ptr2->next != NULL)
        {
            // If duplicate then delete it
            if (ptr1->data == ptr2->next->data)
            {
                // sequence of steps is important here
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            { /* This is tricky */
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}


/*
METHOD 2:
Time Complexity: O(N) on average 
(assuming that hash table access time is O(1) on average).  

Auxiliary Space : O(N)
As extra space is used to store the elements in the stack.

*/
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
         map<int,int> m;
         Node* curr = head;
         // Put the first node in the map with a freq 1
         m[curr->data] = 1;
      
         Node* prev = curr;
         curr = curr->next;
         
         while(curr != NULL)
         {
             // if a value already exists
             if(m[curr->data])
             {
                 // Point the prev node to the next node of curr node
                 prev->next = curr->next;
                 // Delete the curr node
                 free(curr);
             }
             else
             {
                 // If the value does not exists, simply insert it into the map
                 m[curr->data] = 1;
                 prev = curr;
             }
             
             curr = prev->next;
         }
      
         return head;
    }
};


