class Solution {
    int solve(string& s, int start, int end, vector<vector<int>>& dp){
        if(start == end) return 1;
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int matches = 0;
        if(s[start] == s[end]) matches = 2 + solve(s, start + 1, end - 1, dp);
        int skip_start = solve(s, start + 1, end, dp);
        int skip_end = solve(s, start, end - 1, dp);

        return dp[start][end] = max(matches, max(skip_start, skip_end));
    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solve(s, 0, s.size() - 1, dp);
    }
};