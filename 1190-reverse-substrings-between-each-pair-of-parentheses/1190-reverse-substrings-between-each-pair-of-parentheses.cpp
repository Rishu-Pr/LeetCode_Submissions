class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                string str = "";
                while(stk.top() != '('){
                    str += stk.top();
                    stk.pop();
                }
                stk.pop();

                for(int t = 0; t < str.size(); t++)
                    stk.push(str[t]);
            }
            else stk.push(s[i]);
        }

        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};