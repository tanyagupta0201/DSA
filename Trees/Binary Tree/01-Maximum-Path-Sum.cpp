
class Solution
{
public:
    int solve(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        // 0 is taken to avoid negative path sum
        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));

        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;

        solve(root, maxi);
        return maxi;
    }
};