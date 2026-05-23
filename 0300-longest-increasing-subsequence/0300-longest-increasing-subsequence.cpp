class Solution {
    int solve(vector<int> &nums, int prev, int curr, vector<vector<int>>& dp){
        if(curr == nums.size()) return 0;
        if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        int inc = 0;
        if(prev == -1 || nums[prev] < nums[curr]) inc = 1 + solve(nums, curr, curr + 1, dp);

        int exc = solve(nums, prev, curr + 1, dp);

        dp[curr][prev + 1] = max(inc, exc);
        return dp[curr][prev + 1];
    }
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, -1, 0, dp);
    }
};