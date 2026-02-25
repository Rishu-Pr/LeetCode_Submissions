class Solution {
public:
    string decodeString(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
                stk.push(s[i]);

            else
            {
                string ans = "";
                while (stk.top() != '[')
                {
                    ans = stk.top() + ans;
                    stk.pop();
                }
                stk.pop();

                string num = "";
                while (!stk.empty() && isdigit(stk.top()))
                {
                    num = stk.top() + num;
                    stk.pop();
                }
                int numDig = stoi(num);
                while (numDig--)
                {
                    for (int j = 0; j < ans.size(); j++)
                        stk.push(ans[j]);
                }
            }
        }
        string str_Ans = "";
        while (!stk.empty())
        {
            str_Ans = stk.top() + str_Ans;
            stk.pop();
        }
        return str_Ans;
    }
};