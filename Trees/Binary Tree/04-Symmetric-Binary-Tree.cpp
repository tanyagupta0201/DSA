class Solution
{
public:
    bool check(TreeNode *root1, TreeNode *root2)
    {
        if (!root1)
            return !root2;

        if (!root2)
            return !root1;

        // Dono taraf se ek saath traverse karenge
        return (root1->val == root2->val) && check(root1->left, root2->right) && check(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return check(root->left, root->right);
    }
};