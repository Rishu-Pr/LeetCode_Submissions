class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(),nums.end());

        int maxDiff = nums[1] - nums[0];
        for(int i = 2; i < nums.size(); i++)
            maxDiff = max(maxDiff,nums[i]-nums[i-1]);

        return maxDiff;
    }
};