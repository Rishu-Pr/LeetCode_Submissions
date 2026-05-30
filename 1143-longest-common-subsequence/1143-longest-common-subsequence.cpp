class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int matches = (text1[j] == text2[i]) ? 1 + dp[i + 1][j + 1] : 0;
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max(matches, max(skip1, skip2));
            }
        }

        return dp[0][0];
    }
};