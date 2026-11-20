class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() <= 3){
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minV = INT_MAX;
        minV = min(minV, nums[n - 1] - nums[2]);
        minV = min(minV, nums[n - 2] - nums[1]);
        minV = min(minV, nums[n - 3] - nums[0]);

        return minV;

    }
};