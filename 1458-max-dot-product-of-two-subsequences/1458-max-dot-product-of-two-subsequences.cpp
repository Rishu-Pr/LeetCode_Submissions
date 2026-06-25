class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 == nums1.size() || idx2 == nums2.size()) return -1e7;
        if(dp[idx1][idx2] != -1e9) return dp[idx1][idx2];

        int ans = (nums1[idx1] * nums2[idx2]);
        if(idx1 < nums1.size() - 1 && idx2 < nums2.size() - 1)
            ans += max(0, solve(nums1, nums2, idx1 + 1, idx2 + 1, dp));
        int skip_idx1 = solve(nums1, nums2, idx1 + 1, idx2, dp);
        int skip_idx2 = solve(nums1, nums2, idx1, idx2 + 1, dp);

        return dp[idx1][idx2] = max(ans, max(skip_idx1, skip_idx2));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1e9));
        return solve(nums1, nums2, 0, 0, dp);
    }
};