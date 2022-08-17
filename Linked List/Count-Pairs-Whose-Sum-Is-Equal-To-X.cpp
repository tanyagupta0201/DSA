// https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1?page=2&category[]=Linked%20List&sortBy=submissions


// BRUTE FORCE: Nested loops, comparing each element of list 1 with every element of list 2, TC = O(N ^ 2)


// EFFICIENT APPROACH
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) 
    {
        set<int> s;
        
        while(head1 != NULL)
        {
            s.insert(head1->data);
            head1 = head1->next;
        }
        
        int pairs = 0;
        
        while(head2 != NULL)
        {
            int searchData = x - head2->data;
            
            if(s.find(searchData) != s.end())
            {
                pairs++;
            }
            
            head2 = head2->next;
        }
        
        return pairs;
    }
};
