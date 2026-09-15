class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> dp(4, -1e15);
        for(long long x : b){
            dp[3] = max(dp[3], dp[2] + x * a[3]);
            dp[2] = max(dp[2], dp[1] + x * a[2]);
            dp[1] = max(dp[1], dp[0] + x * a[1]);
            dp[0] = max(dp[0], x * a[0]);
        }

        return dp[3];
    }
};