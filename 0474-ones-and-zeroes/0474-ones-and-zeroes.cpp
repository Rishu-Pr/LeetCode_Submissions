class Solution {
    int solve(vector<string>& strs, int idx, int m, int n, vector<vector<vector<int>>> &dp){
        if(idx >= strs.size()){
            return 0;
        }
        if(dp[idx][m][n] != -1){
            return dp[idx][m][n];
        }
        int cnt0 = 0;
        int cnt1 = 0;  

        for(char x : strs[idx]){
            if(x == '1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }

        int pick = 0;
        int Npick = 0;
        if(m >= cnt0 && n >= cnt1){
            pick = 1 + solve(strs, idx + 1, m - cnt0, n - cnt1, dp);
        }
        
        Npick = solve(strs, idx + 1, m, n, dp);

        return dp[idx][m][n] = max(pick, Npick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, 0, m, n, dp);
    }
};