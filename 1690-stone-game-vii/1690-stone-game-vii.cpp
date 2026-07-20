class Solution {
    int solve(int left, int right, vector<int>& stones, int sum, vector<vector<int>>& dp){
        if(left > right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans_L = (sum - stones[left]) - solve(left + 1, right, stones, sum - stones[left], dp);
        int ans_R = (sum - stones[right]) - solve(left, right - 1, stones, sum - stones[right], dp);

        return dp[left][right] = max(ans_L, ans_R);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        int sum = 0;
        for(int x : stones){
            sum += x;
        }

        return solve(0, stones.size() - 1, stones, sum, dp);
    }
};