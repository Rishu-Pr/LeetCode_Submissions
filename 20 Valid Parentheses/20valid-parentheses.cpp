class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        for (int i = 0; i < s.length(); i++) {
            if (st1.empty())
                st1.push(s[i]);

            else if (st1.top() == '(' && s[i] == ')')
                st1.pop();

            else if (st1.top() == '{' && s[i] == '}')
                st1.pop();

            else if (st1.top() == '[' && s[i] == ']')
                st1.pop();

            else
                st1.push(s[i]);
        }
        return st1.empty();
    }
};