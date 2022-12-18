// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

// Method 1: Recursive
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        helper(root, v);
        return v;
    }
};

// Method 2: Using stacks
class Solution
{
public:
    // Preorder: Root left right
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == NULL)
            return preorder;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);

            /* preorder mein pehle left aata hai par yahan pehle right dekh rahe hain kyuki Stack LIFO par kaam karta hai */
            if (root->right != NULL)
            {
                st.push(root->right);
            }

            if (root->left != NULL)
            {
                st.push(root->left);
            }
        }
        return preorder;
    }
};
