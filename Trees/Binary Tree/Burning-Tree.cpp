/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* parentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent){
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
         TreeNode* res = NULL;
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if (target == front->val)
                 res = front;
            
            if(front->left){
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            
            if(front->right){
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }
        return res;
    }
    
    int burningTime(TreeNode*root, map<TreeNode*, TreeNode*>nodeToParent)
    {
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        int cnt = 0;
        
        q.push(root);
        visited[root] = 1;
        
        while(!q.empty()){
            bool flag = 0;
            
            int size = q.size();
            for(int i = 0; i<size; i++){
            TreeNode* front = q.front();
                q.pop();
            
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
                
            }
            if(flag == 1)
             cnt++;
        }
        
        return cnt;
        
    }
    int amountOfTime(TreeNode* root, int target)
    {
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = parentMapping(root, target, nodeToParent);
        int ans = burningTime(targetNode, nodeToParent);
        return ans;
    }
};
