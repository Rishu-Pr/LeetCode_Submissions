class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int idx1, vector<int>& dp, int bitmask){
        if(idx1 == nums1.size()) return 0;
        if(dp[bitmask] != -1) return dp[bitmask];

        int ans = INT_MAX;
        for(int i = 0; i < nums2.size(); i++){
            if((bitmask & (1 << i)) == 0){
                ans = min(ans, (nums1[idx1] ^ nums2[i]) + solve(nums1, nums2, idx1 + 1, dp, bitmask | (1 << i)));
            }
        }

        return dp[bitmask] = ans;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(1 << 15, -1);

        return solve(nums1, nums2, 0, dp, 0);
    }
};