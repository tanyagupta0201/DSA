class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; // to store the top view of the tree

        if (root == NULL)
            return ans;

        map<int, int> m; // (line number, node)

        queue<pair<Node *, int>> q; // (node, line number)

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            // agar map mein pehle se koi line present hai toh phir se nahi karenge
            if (m.find(line) == m.end())
            {
                m[line] = node->data; // uss line ke coressponding jo data hai wo daal denge
            }

            // Abb pehle left aur phir right check karenge
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