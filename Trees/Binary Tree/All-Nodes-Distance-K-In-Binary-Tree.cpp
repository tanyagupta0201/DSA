/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    EXPLANATION:
    
    1) We cannot traverse in the upward direction
    2) So, we map each node with its parent
    3) Now we will perform BFS from target node for reaching to the nodes which are at distance K from the target node
    4) We will maintain a visited array to keep the track of all the nodes that are already visited
    5) Now perform simple level order traversal and check if the target's parent, left child and right child exists and push them into the queue and them visited. 
    6) Now check for other nodes present in the queue.
    7) Take a variable currLevel which is initially 0 and keep on increasing its value with the increasing level
    8) As soon as the value of currLevel becomes equal to K, come out of the loop.
    9) The nodes that would remain inside the queue after we come out of loop will be the nodes present at distance K
    9) Pop these nodes from the queue one by one and store them into a vector
    10) Return the vector.
    
*/
class Solution {
public:
    void markParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                parent_track[curr->left] = curr;
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent_track[curr->right] = curr;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*, TreeNode*> parent_track; // marks child node to parent node
        markParent(root, target, parent_track);
        
        unordered_map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        q.push(target);
        
        vis[target] = 1;
        
        int curr_level = 0;
        
        
        // BFS For going to the Kth level from the target node
        while(!q.empty())
        {
            int sz = q.size();
            
            if(curr_level == k)
                break;
            
            curr_level++;
            
            for(int i = 0; i < sz; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && vis[curr->left] == 0)
                {
                    q.push(curr->left);
                    vis[curr->left] = 1;
                }
                
                if(curr->right && vis[curr->right] == 0)
                {
                    q.push(curr->right);
                    vis[curr->right] = 1;
                }
                
                if(parent_track[curr] && vis[parent_track[curr]] == 0)
                {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = 1;
                }
            }  
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            ans.push_back(node->val);
        }
        
        return ans;
    }
};
