// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

// Method 1: Recursive
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        helper(root->left, v);
        helper(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        helper(root, v);
        return v;
    }
};

// Method 2: Using 2 Stacks

// Pehle initially stack 1 mein root daalo, wo stack ka top element hai usko stack 2 mein daal do
// uss root ka pehle left aur phir right element stack 1 mein daalo
// Jab bhi next iteration shuru hogi, stack 1 ka top element stack 2 mein daal do
// jab stack 1 empty ho jaaye toh stack 2 se saare elements pop karte raho aur postorder naam ki vector mein daal do

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;

        if (root == NULL)
            return postorder;

        stack<TreeNode *> s1, s2;

        s1.push(root);

        while (!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);

            if (root->left != NULL)
                s1.push(root->left);

            if (root->right != NULL)
                s1.push(root->right);
        }

        while (!s2.empty())
        {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }

        return postorder;
    }
};

// Method 3: Using 1 stack
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

vector<int> postOrderTrav(node *cur)
{

    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;

    stack<node *> st;
    while (cur != NULL || !st.empty())
    {

        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> postOrder;
    postOrder = postOrderTrav(root);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
    return 0;
}
