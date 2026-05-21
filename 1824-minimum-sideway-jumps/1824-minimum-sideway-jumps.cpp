class Solution {
    int solve(vector<int>& obstacles, int idx, int lane, vector<vector<int>>& dp){
        while(idx < obstacles.size() - 1 && obstacles[idx + 1] != lane) idx++;
        if(idx >= obstacles.size() - 1) return 0;

        if(dp[idx][lane - 1] != -1) return dp[idx][lane - 1];

        int ans = 1e9;
        for(int i = 1; i < 4; i++)
            if(i != obstacles[idx] && i != obstacles[idx + 1])
                ans = min(ans, 1 + solve(obstacles, idx + 1, i, dp));

        dp[idx][lane - 1] = ans;
        return dp[idx][lane - 1];

    }
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, -1));
        return solve(obstacles, 0, 2, dp);
    }
};