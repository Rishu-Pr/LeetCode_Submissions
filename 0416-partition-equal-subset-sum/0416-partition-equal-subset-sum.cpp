class Solution {
    bool isfirstHalf(vector<int>& nums, int idx, int total, vector<vector<int>>& dp){
        if(total == 0) return true;
        if(total < 0 || idx >= nums.size()) return false;
        
        if(dp[idx][total] != -1) return dp[idx][total];

        bool ans = false;

        for(int i = idx; i < nums.size(); i++)
            if(isfirstHalf(nums, i + 1, total - nums[i], dp)) 
                return dp[idx][total] = 1;
        
        return dp[idx][total] = 0;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(sum % 2) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return isfirstHalf(nums, 0, sum / 2, dp);
    }
};