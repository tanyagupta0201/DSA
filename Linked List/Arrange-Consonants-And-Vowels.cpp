// https://practice.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1?

struct Node* arrange(Node *head)
{
   Node *v = new Node('a');
   Node *c = new Node('b');
   
   Node *vhead = v;
   Node *chead = c;
   
   while(head != NULL)
   {
       char ch = head->data;
       
       if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
       {
           vhead->next = new Node(ch);
           vhead = vhead->next;
       }
       else
       {
           chead->next = new Node(ch);
           chead = chead->next;
       }
       
       head = head->next;
   }
   
   chead->next = NULL;
   vhead->next = c->next;
   
   return v->next;
}
