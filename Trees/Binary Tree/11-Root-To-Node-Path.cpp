// https://www.interviewbit.com/problems/path-to-given-node/

// Inorder Traversal
bool getPath(TreeNode *root, int x, vector<int> &arr)
{
    if (root == NULL)
        return false;

    arr.push_back(root->val);

    if (root->val == x)
        return true;

    if (getPath(root->left, x, arr) || getPath(root->right, x, arr))
        return true;

    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> arr;

    if (A == NULL)
    {
        return arr;
    }

    getPath(A, B, arr);
    return arr;
}
