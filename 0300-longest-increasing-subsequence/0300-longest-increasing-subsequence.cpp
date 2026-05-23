class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                int inc = 0; 
                if(prev == -1 || nums[prev] < nums[curr]) inc = 1 + dp[curr + 1][curr + 1];
                int exc = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(inc, exc);
            }
        }

        return dp[0][0];
    }
};