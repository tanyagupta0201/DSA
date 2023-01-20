class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        bool LeftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int index = (LeftToRight) ? i : (size - i - 1);

                // Value insert karate jaao one by one aur uska left aur right exist karta hai toh unhe queue mein daalte jao
                row[index] = node->val;

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // After this level
            LeftToRight = !LeftToRight;

            res.push_back(row);
        }
        return res;
    }
};