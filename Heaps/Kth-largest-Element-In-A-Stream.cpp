// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

/*
BRUTE FORCE

A Simple Solution is to keep an array of size k. The idea is to keep the array sorted increasing order so that the k'th largest element can be found in O(1) time.
  
How to process a new element of stream?
-> For every new element in stream, check if the new element is smaller than current k'th largest element. 
  If yes, then ignore it. If no, then remove the smallest element from array and insert new element in sorted order. 
  Time complexity of processing a new element becomes O(k).
  
*/

// EFFICIENT SOLUTION: USE MIN HEAP
// TC = The k’th largest element is always at root and can be found in O(1) time.
// Compare the new element with root of heap. If new element is smaller, then ignore it. 
// Otherwise replace root with new element and call heapify for the root of modified heap. 
// Time complexity of finding the k’th largest element is O(Logk).


class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) 
    {
        priority_queue<int, vector<int>, greater<int>> pq; // Min heap
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
        {
            if(pq.size() < k)
            {
                pq.push(arr[i]);
            }
            else
            {
                if(arr[i] > pq.top()) // new element > smallest in pq
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            
            if(pq.size() < k)
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};
