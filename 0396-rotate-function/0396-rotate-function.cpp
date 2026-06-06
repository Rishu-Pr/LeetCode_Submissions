class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> dp(nums.size(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++) {
            dp[0] += i * nums[i];
        }

        for(int i = 1; i < nums.size(); i++) 
            dp[i] = dp[i - 1] + (nums.size() * nums[i - 1]) - sum;

        int maxV = dp[0];
        for(int i = 1; i < dp.size(); i++) maxV = max(maxV, dp[i]); 
        return maxV;
    }
};