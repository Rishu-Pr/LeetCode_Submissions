class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size() + 1, vector<long long>(t.size() + 1, 0));
        for(int i = 0; i <= s.size(); i++) dp[i][t.size()] = 1;

        for(int idx_s = s.size() - 1; idx_s >= 0; idx_s--){
            for(int idx_T = t.size() - 1; idx_T >= 0; idx_T--){
                if(s[idx_s] == t[idx_T]) dp[idx_s][idx_T] = dp[idx_s + 1][idx_T] + dp[idx_s + 1][idx_T + 1];
                else dp[idx_s][idx_T] = dp[idx_s + 1][idx_T];
            }
        }
        return dp[0][0];
    }
};