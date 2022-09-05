// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            
            while(n--)
            {
                Node* temp = q.front();
                q.pop();
                
                for(auto child : temp->children)
                {
                    q.push(child);
                }
                
                level.push_back(temp->val);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};
