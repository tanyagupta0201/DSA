// Problem Link: https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property-set-2/
// https://youtu.be/fnmisPM6cVo

void reorder(node *root)
{
    if (root == NULL)
        return;

    int sum = 0;

    if (root->left)
    {
        sum += root->left->data;
    }

    if (root->right)
    {
        sum += root->right->data;
    }

    if (sum >= root->data)
    {
        root->data = sum; // simply update the root's value
    }
    else
    {
        // Update the value of the root's left and right
        if (root->left)
        {
            root->left->data = root->data;
        }

        if (root->right)
        {
            root->right->data = root->data;
        }

        // we need to traverse through the left and right
        reorder(root->left);
        reorder(root->right);

        // When we come back after backtracking we need to sum up left and right nodes and update the root(parent).
        int total = 0;

        if (root->left)
            total += root->left->data;

        if (root->right)
            total += root->right->data;

        // We only have to update the value of the root
        // So we have checked that it is not a leaf node
        if (root->left || root->right)
            root->data = total;
    }
}

void ChangeTree(node *root);
{
    reorder(root);
}