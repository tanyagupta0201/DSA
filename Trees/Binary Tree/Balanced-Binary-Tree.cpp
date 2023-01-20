// Problem Link: https://leetcode.com/problems/balanced-binary-tree/

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // Agar kisi bhi node par height -1 aa jaye toh -1 return kardo, wahin pata chal jayega ki tree balanced nhi hai
        int left_height = maxDepth(root->left);
        if (left_height == -1)
            return -1;

        int right_height = maxDepth(root->right);
        if (right_height == -1)
            return -1;

        if (abs(right_height - left_height) > 1)
            return -1;

        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode *root)
    {
        return maxDepth(root) != -1;
    }
};