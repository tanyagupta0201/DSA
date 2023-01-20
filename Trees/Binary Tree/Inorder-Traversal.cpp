// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

// Method 1: Recursive
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> v;
        helper(root, v);
        return v;
    }
};

// Method 2: Using Stacks
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *node = root;
        stack<TreeNode *> st;
        vector<int> inorder;

        while (1)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;

                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};