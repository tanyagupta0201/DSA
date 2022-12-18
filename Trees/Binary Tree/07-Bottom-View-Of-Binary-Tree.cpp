class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }

        map<int, int> m;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            // The only difference from top view is that we need to override the value of line
            // as it starts from top but we need bottom value
            m[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};