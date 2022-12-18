// Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/submissions/

class Solution
{
public:
    int maxDepth(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;

        int left_height = maxDepth(root->left, diameter);
        int right_height = maxDepth(root->right, diameter);

        diameter = max(diameter, left_height + right_height);

        return 1 + max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
};