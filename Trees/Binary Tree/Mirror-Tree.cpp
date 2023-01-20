class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        // Just Swapping left and right children while traversal.
        if (node == NULL)
            return;

        swap(node->left, node->right);

        mirror(node->left);
        mirror(node->right);
    }
};
