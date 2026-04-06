class Solution {
public:
    string removeOuterParentheses(string s) {
        string Ans = "";
        stack<char> stk;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                if(!stk.empty()) Ans.push_back(s[i]);
                stk.push(s[i]);
            }
            else{
                stk.pop();
                if(!stk.empty()) Ans.push_back(s[i]);
            }
        }

        return Ans;
    }
};