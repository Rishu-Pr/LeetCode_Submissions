class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxV = 0;
        int minV = 1e9;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxV) maxV = nums[i];
            if(nums[i] < minV) minV = nums[i];
        }

        return 1LL * (maxV - minV) * k;
    }
};