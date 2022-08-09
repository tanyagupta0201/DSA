// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

// Brute Force
// TC = O(n), SC = O(1)

// Find three nodes -> Kth node, (K + 1)th node and the last node
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* t = head;
        int count = 1;
        
        // Find the Kth Node
        while(count < k && t != NULL)
        {
            count++;
            t = t->next;
        }
                  
        Node* KNode = t;
        
        // Now find the last node
        while(t->next != NULL)
        {
            t = t->next;
        }
        
        // make the linked list circular by pointing last node to the first node
        t->next = head;
        
        // New head will be (K + 1)th node
        head = KNode->next;
        // Kth node will become the last node
        KNode->next = NULL;
        
        return head;
    }
};





// Optimised
// TC = O(n), SC = O(1)

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* t = head;
        int len = 1;
        
        while(t->next != NULL)
        {
            len++;
            t = t->next;
        }
        
        // make the linked list circular by pointing last node to the first node
        t->next = head;
        
        k = k % len;
        
        // Now move to (k-1)th node
        while(k--)
        {
            t = t->next; 
        }
        
        // Kth node will be the new head of the linked list
        head = t->next;
      
        // (K-1) th node will be the last node so make its next as null 
        t->next = NULL;
        
        return head;
    }
};
   
