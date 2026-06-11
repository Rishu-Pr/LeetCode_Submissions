class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<int> dp(m + 1, 0);

        for(int i = m - 1; i >= 0; i--){
            for(int j = 0 ; j <= i; j++){
                int choose_s = nums[j] * multipliers[i] + dp[j + 1];
                int choose_e = nums[n - 1 - (i - j)] * multipliers[i] + dp[j];

                dp[j] = max(choose_s, choose_e);
            }
        }

        return dp[0];
    }
};