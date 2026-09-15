class Solution {
    long long solve(vector<int>& a, vector<int>& b, int idx1, int idx2, vector<vector<long long>>& dp){
        if(idx1 >= a.size()){
            return 0;
        }
        if(idx1 < a.size() && idx2 >= b.size()){
            return -1e15;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        long long val = (long long)a[idx1] * b[idx2] + solve(a, b, idx1 + 1, idx2 + 1, dp);
        val = max(val, solve(a, b, idx1, idx2 + 1, dp));

        return dp[idx1][idx2] = val;
    }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(a.size(), vector<long long>(b.size(), -1));
        return solve(a, b, 0, 0, dp);
    }
};