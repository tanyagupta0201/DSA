// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?

// Solution 1: Using an externally linked list to store answers.

// TC = O(N + M)
// Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N + M)

// SC = O(N + M)
// We are creating another linked list that contains the (N+M) number of nodes in the list. So, space complexity is O(N+M).

/*
    Step 1: Create a new dummy node. It will have the value 0 and will point to NULL respectively. This will be the head of the new list. Another pointer to keep track of traversals in the new list.

    Step 2:  Find the smallest among two nodes pointed by the head pointer of both input lists, and store that data in a new list created.

    Step 3: Move the head pointer to the next node of the list whose value is stored in the new list.

    Step 4: Repeat the above steps till any one of the head pointers stores NULL. Copy remaining nodes of the list whose head is not NULL in the new list.

*/
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *dummy = new Node(0);
    Node *temp = dummy;
    
    Node *h1 = head1;
    Node *h2 = head2;
    
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            temp->next = new Node(head1->data);
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = new Node(head2->data);
            temp = temp->next;
            head2 = head2->next; 
        }
    }
    
    while(!head1 && head2)
    {
        temp->next = new Node(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }
    
    while(head1 && !head2)
    {
        temp->next = new Node(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }
    
    return dummy->next;
}  


// Solution 2: Inplace method without using extra space.

// TC = O(N + M) - Traversing both the lists till end
// SC = O(1) - No extra space used

//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // when list1 is empty then our output will be same as list2
    if(head1 == NULL)
       return head2;
       
    // when list2 is empty then our output will be same as list1
    if(head2 == NULL)
       return head1;
       
    // head1 will always be smaller
    if(head1->data > head2->data)
    {
        swap(head1, head2);
    }
    
    Node *res = head1; // acts as the head of the final merged list
    
    while(head1 != NULL && head2 != NULL)
    {
        Node *temp = NULL;
        
        while(head1 != NULL && head1->data <= head2->data)
        {
            temp = head1; // stores the last sorted node
            head1 = head1->next;
        }
        
        // link previous sorted node with 
        // next larger node in list2
        temp->next = head2;
        swap(head1, head2);
    }
    
    return res;
    
} 
