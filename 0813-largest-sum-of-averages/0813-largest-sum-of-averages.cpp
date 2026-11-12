class Solution {
    double solve(vector<int>& nums, int i, int k, vector<vector<double>>& dp) {
        if(k < 0 || i == nums.size()){
            return 0;
        }
        if(k == 0){
            return -1e5;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        double sum = 0;
        double ans = 0;

        for(int x = i; x < nums.size(); x++){
            sum += nums[x];
            ans = max(ans, (sum / (x - i + 1) )+ solve(nums, x + 1, k - 1, dp));
        }

        return dp[i][k] = ans;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<double>> dp(n, vector<double>(k + 2, -1.0));
        return solve(nums, 0, k, dp);
    }
};