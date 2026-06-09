class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxV = 0;
        long long minV = 1e9;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxV) maxV = nums[i];
            if(nums[i] < minV) minV = nums[i];
        }

        return (maxV - minV) * k;
    }
};