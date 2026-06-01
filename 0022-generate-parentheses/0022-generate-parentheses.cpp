class Solution {
    void solve(int open, int close, vector<string>& Ans,string str){
        if(open == 0 && close == 0){
            Ans.push_back(str);
            return;
        }
        if(open < 0 || close < 0) return;

        solve(open - 1, close, Ans, str + '(');
        if(close > open) solve(open, close - 1, Ans, str + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> Ans;
        solve(n, n, Ans, "");
        return Ans;
    }
};