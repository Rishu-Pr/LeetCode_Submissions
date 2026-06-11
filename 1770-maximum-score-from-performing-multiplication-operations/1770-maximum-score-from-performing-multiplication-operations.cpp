class Solution {
    int solve(vector<int>& nums, vector<int>& multipliers, int idx1_s, int idx1_e, int idx2, vector<vector<int>>& dp){
        if(idx1_s > idx1_e || idx2 == multipliers.size()) return 0;
        if(dp[idx1_s][idx2] != -1e7) return dp[idx1_s][idx2];

        int ans = -1e7;

        int choose_s = nums[idx1_s] * multipliers[idx2] + solve(nums, multipliers, idx1_s + 1, idx1_e, idx2 + 1, dp);
        int choose_e = nums[idx1_e] * multipliers[idx2] + solve(nums, multipliers, idx1_s, idx1_e - 1, idx2 + 1, dp);

        return dp[idx1_s][idx2] = max(choose_s, choose_e);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, -1e7));
        return solve(nums, multipliers, 0, nums.size() - 1, 0, dp);
    }
};