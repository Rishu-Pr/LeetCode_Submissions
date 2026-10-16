class Solution {
    int solve(string& s, int i, vector<vector<bool>>& dp, vector<int>& dp1, int& k){
        if(dp1[i] != -1){
            return dp1[i];
        }

        if(i == s.size()){
            return 0;
        }

        int ans = 0;
        int last_palin = i;
        ans = max(ans, solve(s, i + 1, dp, dp1, k));  // Skip

        for(int j = i; j < s.size(); j++){            // Choose
            if(dp[i][j] && (j - i + 1 >= k)){
                last_palin = j;
                ans = max(ans, 1 + solve(s, j + 1, dp, dp1, k));
            }
        }

        return dp1[i] = ans;
    }
public:
    int maxPalindromes(string s, int k) {
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

        return solve(s, 0, dp, dp1, k);
    }
};