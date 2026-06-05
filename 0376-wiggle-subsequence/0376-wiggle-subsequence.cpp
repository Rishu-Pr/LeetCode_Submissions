class Solution {
    int solve(vector<int>& nums, int idx, int choice, int prev_idx, vector<vector<vector<int>>>& dp) {
        if (idx == nums.size()) return 0;

        int choice_memo = choice + 1;
        int prev_memo = prev_idx + 1;

        if (dp[idx][choice_memo][prev_memo] != -1) {
            return dp[idx][choice_memo][prev_memo];
        }

        int skip = solve(nums, idx + 1, choice, prev_idx, dp);

        int take = 0;
        
        if (choice == -1) {
            take = 1 + max(solve(nums, idx + 1, 0, idx, dp), solve(nums, idx + 1, 1, idx, dp));
        } 
        else if (choice == 1 && nums[idx] > nums[prev_idx]) {
            take = 1 + solve(nums, idx + 1, 0, idx, dp);
        } 
        else if (choice == 0 && nums[idx] < nums[prev_idx]) {
            take = 1 + solve(nums, idx + 1, 1, idx, dp);
        }

        return dp[idx][choice_memo][prev_memo] = max(skip, take);
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        
        return solve(nums, 0, -1, -1, dp);
    }
};