// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


// TC = O(N), SC = O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& arr, int n) 
    {
        // code here 
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            st.push(i); // push all the index of the matrix
        }
        
        // Always put out 2 indices and pop the one which cannot be a celebrity
        while(st.size() >= 2)
        {
            int x = st.top();
            st.pop();
            
            int y = st.top();
            st.pop();
            
            if(arr[x][y] == 1)
            {
                // x knows y 
                // it means x cannot be celebrity
                st.push(y);
            }
            else
            {
                // x does not know y
                // y cannot be celebrity
                st.push(x);
            }
        }
        
        int potentialCeleb = st.top(); // this can be the celebrity but not sure, we need to check its row and col for it
        st.pop();
        
        
        for(int i = 0; i < n; i++)
        {
            if(i != potentialCeleb) // because we need to check for all others
            {
                // if someone does not know potentialCeleb OR the potentialCeleb knows someone, he cannot become celebrity
                if(arr[i][potentialCeleb] == 0 || arr[potentialCeleb][i] == 1)
                   return -1;
            }
        }
        
        return potentialCeleb;
    }
};
