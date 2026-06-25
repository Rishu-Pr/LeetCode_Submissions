class Solution {
    // int solve(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, vector<vector<int>>& dp){
    //     if(idx1 == nums1.size() || idx2 == nums2.size()) return -1e7;
    //     if(dp[idx1][idx2] != -1e9) return dp[idx1][idx2];

    //     int ans = (nums1[idx1] * nums2[idx2]);
    //     if(idx1 < nums1.size() - 1 && idx2 < nums2.size() - 1)
    //         ans += max(0, solve(nums1, nums2, idx1 + 1, idx2 + 1, dp));
    //     int skip_idx1 = solve(nums1, nums2, idx1 + 1, idx2, dp);
    //     int skip_idx2 = solve(nums1, nums2, idx1, idx2 + 1, dp);

    //     return dp[idx1][idx2] = max(ans, max(skip_idx1, skip_idx2));
    // }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for(int i = 0; i <= nums1.size(); i++) dp[i][nums2.size()] = -1e9;
        for(int j = 0; j <= nums2.size(); j++) dp[nums1.size()][j] = -1e9;

        for(int i = nums1.size() - 1; i >= 0; i--){
            for(int j = nums2.size() - 1; j >= 0; j--){
                int took = nums1[i] * nums2[j];
                if(i < nums1.size() - 1 && j < nums2.size() - 1)
                    took += max(0, dp[i + 1][j + 1]);
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max(took, max(skip1, skip2));
            }
        }

        return dp[0][0];
    }
};