class Solution {
    int maxLen = 0;
    int solve(string& s, int start, int end, int word1_size, vector<vector<int>>& dp){
        if(start == end) return 1;
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        if(s[start] == s[end]){
            int len = 2 + solve(s, start + 1, end - 1, word1_size, dp);
            if(start < word1_size && end >= word1_size){
                maxLen = max(maxLen, len);
            }

            return dp[start][end] = len;
        }
        int skip_start = solve(s, start + 1, end, word1_size, dp);
        int skip_end = solve(s, start, end - 1, word1_size, dp);

        return dp[start][end] = max(skip_start, skip_end);
    }
public:
    int longestPalindrome(string word1, string word2) {
        string main_Str = word1 + word2;
        vector<vector<int>> dp(main_Str.size(), vector<int>(main_Str.size(), -1));
        solve(main_Str, 0, main_Str.size() - 1, word1.size(), dp);

        return maxLen;
    }
};