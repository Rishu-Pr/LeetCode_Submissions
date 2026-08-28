class Solution {
    void solve(int open, int close, vector<string>& Ans, string& temp){
        if(open == 0 && close == 0){
            Ans.push_back(temp);
            return;
        }
        if(open < 0 || close < 0) return;

        temp += '(';
        solve(open - 1, close, Ans, temp);
        temp.pop_back();
        
        if(close > open) {
            temp += ')';
            solve(open, close - 1, Ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> Ans;
        string temp = "";
        solve(n, n, Ans, temp);
        return Ans;
    }
};