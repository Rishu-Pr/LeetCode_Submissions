class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        string s_modified = "";
        for(int i = 0; i < s.size(); i++){
            if(i == s.size() - 1 && s[i] == ')') ans++;
            else if(s[i] == ')' && s[i + 1] == ')') i++;
            else if(s[i] == ')' && s[i + 1] != ')') ans++;
            s_modified.push_back(s[i]);
        }

        stack<char> stk;
        for(char c: s_modified){
            if(!stk.empty() && stk.top() == '(' && c == ')') stk.pop();
            else stk.push(c);
        }

        while(!stk.empty()){
            if(stk.top() == '(') ans += 2;
            else ans += 1;
            
            stk.pop();
        }
        return ans;
    }
};