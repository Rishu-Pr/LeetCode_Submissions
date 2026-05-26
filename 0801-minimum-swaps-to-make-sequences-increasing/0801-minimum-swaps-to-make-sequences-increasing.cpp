class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, bool swapped, vector<vector<int>>& dp){
        if(idx == nums1.size()) return 0;
        if(dp[idx][swapped] != -1) return dp[idx][swapped];

        int inc = 1e9;
        int exc = 1e9;

        if(nums1[idx - 1] < nums1[idx] && nums2[idx - 1] < nums2[idx])
            exc = solve(nums1, nums2, idx + 1, false, dp);
        
        if(nums1[idx - 1] < nums2[idx] && nums2[idx - 1] < nums1[idx]){
            swap(nums1[idx], nums2[idx]);
            inc = 1 + solve(nums1, nums2, idx + 1, true, dp);
            swap(nums1[idx], nums2[idx]);
        }
        return dp[idx][swapped] = min(inc, exc);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        int ans1 = solve(nums1, nums2, 1, false, dp);
        swap(nums1[0], nums2[0]);

        vector<int> dp2(nums2.size(), -1);
        int ans2 = 1 + solve(nums1, nums2, 1, true, dp);
        swap(nums1[0], nums2[0]);
        return min(ans1, ans2);
    }
};