// class Solution {
//     bool solve(vector<int>& nums, int m, int sum, int i, int j, vector<vector<int>>& dp){
//         if(i == j){
//             return true;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         bool ans1 = false;
//         bool ans2 = false;
//         if(sum >= m){
//             ans1 = solve(nums, m, sum - nums[i], i + 1, j, dp);
//             ans2 = solve(nums, m, sum - nums[j], i, j - 1, dp);
//         }

//         return dp[i][j] = ans1 || ans2;
//     }
// public:
//     bool canSplitArray(vector<int>& nums, int m) {
//         if(nums.size() <= 2){
//             return true;
//         }
//         int sum = 0;
//         for(int x : nums){
//             sum += x;
//         }
//         vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
//         return solve(nums, m, sum, 0, nums.size() - 1, dp);
//     }
// };
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <= 2){
            return true;
        }

        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] + nums[i - 1] >= m){
                return true;
            }
        }
        return false;
    }
};