class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> Stack;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = Stack.back();
                Stack.pop_back();
                int a = Stack.back();
                Stack.pop_back();
                switch (tokens[i][0])
                {
                case '+':
                    a += b;
                    break;
                case '-':
                    a -= b;
                    break;
                case '*':
                    a *= b;
                    break;
                case '/':
                    a /= b;
                    break;
                }
                Stack.push_back(a);
            }
            else
            {
                Stack.push_back(stoi(tokens[i]));
            }
        }
        return Stack.front();
    }
};