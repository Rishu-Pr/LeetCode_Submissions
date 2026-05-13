class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ')'){
                if(!stk.empty() && s[stk.top()] == '(' && s[i] == ')') stk.pop();
                else stk.push(i);
            }
        }

        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--){
            if(!stk.empty() && i == stk.top()) stk.pop();
            else ans.push_back(s[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};