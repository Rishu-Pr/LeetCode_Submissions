class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums.front();

        for(int i = 0; i < nums.size() - 1; i++){
            int minV = min(nums[i + 1] - k, nums[0] + k);
            int maxV = max(nums.back() - k, nums[i] + k);

            ans = min(ans, maxV - minV);
        }

        return ans;
    }
};