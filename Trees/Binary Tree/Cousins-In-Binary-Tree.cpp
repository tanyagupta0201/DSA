// https://leetcode.com/problems/cousins-in-binary-tree/

/*
Approach

they can be cousins if they belongs to same level only, real life example you and your uncles children are cousin because both belongs to same generation right? there is no chance that you can be cousin with your uncle :)
Therefore to check same generation or level we can do level order traversal for the tree using queue.

you have check also if they belongs to same parents becuase in that case they would be siblings like you and your sister
Well, i have not used the edge cases like if root is null because it is strictly mentioned in the question that no of nodes will be greater than 2 always
*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            bool flag1 = false, flag2 = false;
            
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->val == x)
                {
                    flag1 = true;
                }
                
                if(node->val == y)
                {
                    flag2 = true;
                }
             
                // Check if they both have same parents 
                // If they have same parents they will be siblings and not cousins
                if(node->left != NULL && node->right != NULL)
                {
                    if( (node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x) )
                         return false;
                }
                if(node->left)
                {
                   q.push(node->left);
                }
            
                if(node->right)
                {
                   q.push(node->right);
                }
            }
            
            if(flag1 && flag2)
                    return true;
        }
           
        return false;
    }
};
