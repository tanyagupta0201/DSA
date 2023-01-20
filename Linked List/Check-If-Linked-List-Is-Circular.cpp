// https://practice.geeksforgeeks.org/problems/circular-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   Node *t = head;
   
   while(t)
   {
       if(t->next == head)
          return true;
       
       t = t->next;
   }
   
   return false;
}
