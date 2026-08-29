class Solution {
    int shift;
    int solve(vector<vector<int>>& pairs, int idx, int prev, vector<vector<int>>& dp){
        if(dp[idx][prev + shift] != -1){
            return dp[idx][prev + shift];
        }

        if(idx == pairs.size()){
            return 0;
        }

        int ans = 0;
        if(pairs[idx][0] > prev){
            ans = 1 + solve(pairs, idx + 1, pairs[idx][1], dp);
        }
        ans = max(ans, solve(pairs, idx + 1, prev, dp));

        return dp[idx][prev + shift] = ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        int l = pairs[0][0];
        // int r = pairs[n - 1][1];
        shift = abs(l);

        vector<vector<int>> dp(n + 2, vector<int>(2001, -1));
        int ans = 0;
        for(int i = 0; i < pairs.size(); i++){
            ans = max(ans, 1 + solve(pairs, i + 1, pairs[i][1], dp));
        }

        return ans;
    }
};