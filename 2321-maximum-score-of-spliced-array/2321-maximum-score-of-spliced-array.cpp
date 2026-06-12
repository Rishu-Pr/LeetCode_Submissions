class Solution {
    int maxVal = -1e7;
    int memo[100005][3];
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, int flip){
        if(idx == nums1.size() && flip <= 2){
            return 0;
        }
        if(idx == nums1.size()) return -1e7;
        if(memo[idx][flip] != -1) return memo[idx][flip];
        

        int Nonflip_sum = nums1[idx] + solve(nums1, nums2, idx + 1, flip);
        int flip_sum = -1e7;
        if(flip < 2){
            flip_sum = nums2[idx] + solve(nums2, nums1, idx + 1, flip + 1);
        }
        return memo[idx][flip] = max(Nonflip_sum, flip_sum);;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        memset(memo, -1, sizeof(memo));
        int ans1 = solve(nums1, nums2, 0, 0);
        
        memset(memo, -1, sizeof(memo));
        int ans2 = solve(nums2, nums1, 0, 0);
        
        maxVal = max(ans1, ans2);
        return maxVal;
    }
};