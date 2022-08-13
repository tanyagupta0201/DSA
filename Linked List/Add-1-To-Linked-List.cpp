// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* N;
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL)
        {
            N = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = N;
        }
        
        head = prev;
        return head;
    }
    
    Node* add(Node* head)
    {
        Node* dummy = new Node(0);
        Node* t = dummy;
        
        int carry = 1; // we need to add 1 initially
        
        while(carry != 0 || head != NULL)
        {
            int sum = 0;
            
            if(head != NULL)
            {
                sum += head->data;
                head = head->next;
            }
            
            sum += carry;
            
            carry = sum / 10;
            
            Node* newNode = new Node(sum % 10);
            t->next = newNode;
            t = t->next;
        }
        
        return dummy->next;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        
        head = add(head);
        
        return reverse(head);
    }
};
