// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// By recursion
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);

        return 1 + max(left_height, right_height);
    }
};

/*
    We can also use level order traversal to find the height of the tree.
    Try to use a variable 'level' which increases by 1 on going left or right, and the highest level will be our answer.
*/