// https://leetcode.com/problems/validate-binary-search-tree/


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
class Solution
{
public:
    bool isValid(TreeNode *root, long min_bound, long max_bound)
    {
        if (root == NULL)
            return true;

        if (root->val <= min_bound || root->val >= max_bound) // Out of bound condition
            return false;

        // Here, min and max are two upper and lower bounds being used to compare.
        // root->left will be bounded by (min_bound) to (root->val)
        // root->right will be bounded by (root->val) to (max_bound)

        return (isValid(root->left, min_bound, root->val) && isValid(root->right, root->val, max_bound));
    }

    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
