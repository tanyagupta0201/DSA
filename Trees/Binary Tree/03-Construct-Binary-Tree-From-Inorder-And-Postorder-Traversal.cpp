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
    TreeNode *Construct(vector<int> &postorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, map<int, int> &mp)
    {
        if (pStart > pEnd || iStart > iEnd)
            return NULL;

        // Construct root
        TreeNode *root = new TreeNode(postorder[pEnd]);

        int inRoot = mp[postorder[pEnd]];
        int numsLeft = inRoot - iStart;

        root->left = Construct(postorder, pStart, pStart + numsLeft - 1, inorder, iStart, inRoot - 1, mp);

        root->right = Construct(postorder, pStart + numsLeft, pEnd - 1, inorder, inRoot + 1, iEnd, mp);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size())
            return NULL;

        int pStart = 0, pEnd = postorder.size() - 1;
        int iStart = 0, iEnd = inorder.size() - 1;

        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return Construct(postorder, pStart, pEnd, inorder, iStart, iEnd, mp);
    }
};