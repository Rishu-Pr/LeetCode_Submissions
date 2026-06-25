class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 == nums1.size() || idx2 == nums2.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(nums1[idx1] == nums2[idx2]){
            return dp[idx1][idx2] = 1 + solve(nums1, nums2, idx1 + 1, idx2 + 1, dp);
        }

        else{
            return dp[idx1][idx2] = max(solve(nums1, nums2, idx1 + 1, idx2, dp), solve(nums1, nums2, idx1, idx2 + 1, dp));
        }
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int size_R = nums1.size();
        int size_C = nums2.size();
        vector<vector<int>> dp(size_R + 1, vector<int>(size_C + 1, 0));

        int max_len = 0;
        for(int i = 1; i <= size_R; i++){
            for(int j = 1; j <= size_C; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    max_len = max(max_len, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        return max_len;
    }
};