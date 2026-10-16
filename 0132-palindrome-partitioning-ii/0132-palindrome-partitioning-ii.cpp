class Solution {
    int solve(string& s, int i, vector<vector<bool>>& dp, vector<int>& dp1){
        if(dp1[i] != -1){
            return dp1[i];
        }

        if(i == s.size()){
            return 0;
        }

        int ans = s.size();
        int last_palin = i;
        for(int j = i; j < s.size(); j++){
            if(dp[i][j]){
                last_palin = j;
                ans = min(ans, 1 + solve(s, j + 1, dp, dp1));
            }
        }
        return dp1[i] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> dp1(n + 1, -1);
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

        return solve(s, 0, dp, dp1) - 1;
    }
};