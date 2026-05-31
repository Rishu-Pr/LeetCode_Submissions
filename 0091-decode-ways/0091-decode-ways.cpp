class Solution {
    int solve(string& s, int idx,vector<int>& dp){
        int n = s.size();
        if(idx == n) return 1;
        if(idx > n || s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];

        int step_1 = solve(s, idx + 1, dp);
        int step_2 = 0;
        if(idx <= n - 2)
            if(stoi(s.substr(idx, 2)) <= 26) step_2 = solve(s, idx + 2, dp);
        
        return dp[idx] =  step_1 + step_2;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};