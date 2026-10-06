class Solution {
    int maxOr = 0;
    vector<vector<int>> dp;

    int solve(int i, int currOr, vector<int>& nums) {
        if (i == nums.size()) {
            if (currOr == maxOr) return 1;
            return 0;
        }

        if (dp[i][currOr] != -1) return dp[i][currOr];

        int take = solve(i + 1, currOr | nums[i], nums);
        int notTake = solve(i + 1, currOr, nums);

        return dp[i][currOr] = take + notTake;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        maxOr = 0;
        for (int x : nums) {
            maxOr = maxOr | x;
        }

        dp.assign(nums.size() + 1, vector<int>(maxOr + 1, -1));

        return solve(0, 0, nums);
    }
};