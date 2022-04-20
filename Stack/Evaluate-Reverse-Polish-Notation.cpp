class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                st.push(first + second);
            }

            else if (tokens[i] == "-")
            {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                st.push(first - second);
            }

            else if (tokens[i] == "*")
            {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                st.push(first * second);
            }

            else if (tokens[i] == "/")
            {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                st.push(first / second);
            }

            else
            {
                st.push(stoi(tokens[i]));
            }
        }

        if (!st.empty())
            return st.top();
        else
            return 0;
    }
};