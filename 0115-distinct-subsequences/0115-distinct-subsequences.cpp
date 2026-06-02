class Solution {
    int solve(string& s, string& t, int idx_s, int idx_T, vector<vector<int>>& dp){
        if(idx_T == t.size()) return 1;
        if(idx_s == s.size() && idx_T < t.size()) return 0;
        if(dp[idx_s][idx_T] != -1) return dp[idx_s][idx_T];

        int matches = 0;
        if(s[idx_s] == t[idx_T]) matches = solve(s, t, idx_s + 1, idx_T + 1, dp);

        int skip = solve(s, t, idx_s + 1, idx_T, dp);

        return dp[idx_s][idx_T] = matches + skip;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s, t, 0, 0, dp);
    }
};