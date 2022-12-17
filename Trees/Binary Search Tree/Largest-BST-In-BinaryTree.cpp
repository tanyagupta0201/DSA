// Time Complexity : O(n)
// Space complexity: O(n) For call stack since using recursion

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    vector<int> solve(Node *root)
    {
        // 1st edge case
        // if any node is not having either left node or right node
        if(root == NULL)
           return {1, 0, INT_MAX, INT_MIN};
           
        // 2nd edge case
        // if a node is leaf node -> it is always a BST
        if(!root->left && !root->right)
           return {1, 1, root->data, root->data};
           
        
        // we will find recursively from left as well as right
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        // if both left and right can form BST then there is a chance for the current node to form a BST
        if(l[0] == 1 && r[0] == 1)
        {
            int currVal = root->data;
            
            if(currVal > l[3] && currVal < r[2])
            {
                int mini = l[2], maxi = r[3];
                
                if(mini == INT_MAX)
                   mini = root->data;
                   
                if(maxi == INT_MIN)
                   maxi = root->data;
                
                return {1, l[1] + r[1] + 1, mini, maxi};
            }
            
        }
        
        // else portion
        return {0, max(l[1], r[1]), 0, 0};
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	// we are maintaining four things for each node
    	// { BST, size, min val, max val }
    	vector<int> v = solve(root);
    	
    	return v[1]; // returns the size
    }
};
