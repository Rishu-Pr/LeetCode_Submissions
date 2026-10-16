class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j - i <= 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                if(dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]){
                    return true;
                }
            }
        }

        return false;
    }
};