// https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/

vector<int> PrePostIn(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    vector<int> pre, post, in;

    if (root == NULL)
    {
        return;
    }

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1))
            {
                pre.push_back(it.first - val);
                it.second++;
                st.push(it);

                // Pre order mein root ke baad left aata hai toh wo check kar rahe hain
                // Jitna left jaa sakte ho utna left jaao
                if (it.first->left != NULL))
                    {
                        st.push(it.first->left, 1);
                    }
            }

        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            // Post order mein root ke baad right aata hai toh wo check kar rahe hain
            // Jitna right jaa sakte ho utna right jaao
            if (it.first->right != NULL))
                {
                    st.push(it.first->right, 1);
                }
        }

        else
        {
            post.push(it.first->val);
        }
    }
}
